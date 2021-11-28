#ifndef FAKE_LIGHTER_H
#define FAKE_LIGHTER_H

#include <sstream>

#include "lighter.h"

class FakeLighter : public Lighter {
  public:
    void Led(int index, bool on) override {
      if (index < 0 || index >= num_pins_) return;
      stream_ << "LED " << index << " " << (on ? "on" : "off") << '\n';
    }

    int num_leds() const override { return num_pins_; }
    std::string stream() const { return stream_.str(); }

  private:
    const int num_pins_ = 2;
    std::stringstream stream_;
};

#endif
