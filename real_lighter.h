#ifndef READ_LIGHTER_H
#define READ_LIGHTER_H

#include "lighter.h"

class RealLighter : public Lighter {
  public:
    RealLighter(const int* pins, int num_pins) : pins_(pins), num_pins_(num_pins) {
      for (int i = 0; i < num_pins_; ++i) {
        pinMode(pins_[i], OUTPUT);
      }
    }

    void Led(int index, bool on) override {
      if (index < 0 || index >= num_pins_) return;
      digitalWrite(pins_[index], on ? HIGH : LOW);
    }

    int num_leds() const override { return num_pins_; }

  private:
    const int* pins_;
    const int num_pins_;
};

#endif
