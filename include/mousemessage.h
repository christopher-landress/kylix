#ifndef _MOUSEMESSAGE_H_
#define _MOUSEMESSAGE_H_

#include "message.h"

class MouseMessage : public Message
{
public:
  MouseMessage(int id) : Message(MSG_MOUSE, id) {}
};

#endif