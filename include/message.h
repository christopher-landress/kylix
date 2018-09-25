#ifndef _MESSAGE_H_
#define _MESSAGE_H_

enum MessageType
{
    MSG_UNKNOWN = 0,
    MSG_KEY,
    MSG_MOUSE
};

class Message
{
  public:
    MessageType m_Type;
    int m_Id;
    Message(MessageType type, int id) : m_Type(type), m_Id(id) {}
};

#endif