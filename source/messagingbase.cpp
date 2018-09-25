#include "../include/messagingbase.h"

MessagingBase::~MessagingBase()
{
    while (!m_Bindings.empty())
    {
        Binding binding = m_Bindings.back();
        m_Bindings.pop_back();
        binding.m_Observed->Unbind(this);
        binding.m_Observer->Unbind(this);
    };
}

void MessagingBase::SendMessage(const Message &msg)
{
    for (size_t i = 0; i < m_Bindings.size(); ++i)
        if (m_Bindings[i].m_Type == MSG_UNKNOWN || m_Bindings[i].m_Type == msg.m_Type)
            m_Bindings[i].m_Handler(m_Bindings[i].m_Observer, msg);
}

template <typename Object, typename Param, void (Object::*Method)(const Param &param)>
void MessagingBase::Bind(MessageType type, Object *observer)
{
    Binding binding(type, observer, this, &Binder<Object, const Param &, Method>);
    m_Bindings.push_back(binding);
    observer->m_Bindings.push_back(binding);
}

template <typename Object, typename Param, void (Object::*Method)(const Param &param)>
void MessagingBase::Unbind(MessageType type, Object *observer)
{
    Handler handler = &Binder<Object, const Param &, Method>;
    auto i = m_Bindings.begin();
    while (i != m_Bindings.end())
        if (i->m_Type == type && i->m_Observer == observer && i->m_Handler == handler)
            i = m_Bindings.erase(i);
        else
            ++i;
}

void MessagingBase::Unbind(const MessagingBase *object)
{
    auto i = m_Bindings.begin();
    while (i != m_Bindings.end())
        if (i->m_Observed == object || i->m_Observer == object)
            i = m_Bindings.erase(i);
        else
            ++i;
}