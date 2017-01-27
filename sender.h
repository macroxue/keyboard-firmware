#ifndef SENDER_H
#define SENDER_H

#include "events.h"

class Sender {
  public:
    virtual ~Sender() {}
    virtual void Send(const Events& events) = 0;
};

#endif
