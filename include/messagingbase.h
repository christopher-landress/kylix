#ifndef _MESSAGINGBASE_H_
#define _MESSAGINGBASE_H_

#include <vector>
#include "message.h"

class MessagingBase
{
	typedef void (*Handler)(MessagingBase *, const Message &);

	struct Binding
	{
		MessageType m_Type;
		MessagingBase *m_Observer;
		MessagingBase *m_Observed;
		Handler m_Handler;

		Binding(MessageType type, MessagingBase *observer,
				MessagingBase *observed, Handler handler) : m_Type(type), m_Observer(observer), m_Observed(observed),
															m_Handler(handler) {}
	};

	std::vector<Binding> m_Bindings;

  public:
	~MessagingBase();

	template <typename Object, typename Param, void (Object::*Method)(const Param &param)>
	void Bind(MessageType type, Object *observer);
	template <typename Object, typename Param, void (Object::*Method)(const Param &param)>
	void Unbind(MessageType type, Object *observer);
	void Unbind(const MessagingBase *object);

  protected:
	void SendMessage(const Message &msg);

  private:
	template <typename Object, typename Param, void (Object::*Method)(Param param)>
	static void Binder(MessagingBase *observer, const Message &message)
	{
		(static_cast<Object *>(observer)->*Method)(static_cast<const Param &>(message));
	}
};

#endif