#ifndef REAL_CLOCK_H
#define REAL_CLOCK_H

class RealClock : public Clock {
  public:
    unsigned Milliseconds() override { return millis(); }
};

#endif
