#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <iostream>
#include "message.h"
#include "messagingbase.h"
#include "keyboardmessage.h"
#include "mousemessage.h"

class Observer : public MessagingBase
{
public:
  void OnMessage(const Message &msg) { std::cout << "Got message id " << msg.m_Id << " of type " << msg.m_Type << std::endl; }
  void OnKeyboard(const KeyboardMessage &msg) { std::cout << "Got key message id " << msg.m_Id << std::endl; }
  void OnMouse(const MouseMessage &msg) { std::cout << "Got mouse message id " << msg.m_Id << std::endl; }
};

#endif