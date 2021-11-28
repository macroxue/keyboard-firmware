#ifndef LIGHTER_H
#define LIGHTER_H

class Lighter {
  public:
    virtual ~Lighter() {}

    virtual void Led(int index, bool on) = 0;
    virtual int num_leds() const = 0;
};

#endif
