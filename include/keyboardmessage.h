#ifndef _KEYBOARDMESSAGE_H_
#define _KEYBOARDMESSAGE_H_

#include "message.h"

class KeyboardMessage : public Message
{
public:
  KeyboardMessage(int id) : Message(MSG_KEY, id) {}
};

#endif