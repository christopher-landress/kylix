#ifndef _OBSERVED_H_
#define _OBSERVED_H_

#include "messagingbase.h"
#include "keyboardmessage.h"
#include "mousemessage.h"

class Observed : public MessagingBase
{
public:
  void RaiseKey(int id) { SendMessage(KeyboardMessage(id)); }
  void RaiseMouse(int id) { SendMessage(MouseMessage(id)); }
};

#endif