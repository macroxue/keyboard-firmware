#ifndef REAL_CONTROLLER_H
#define REAL_CONTROLLER_H

template <int R, int C>
class RealScanner : public Scanner<R,C> {
  public:
    RealScanner(const int row_pins[R], const int col_pins[C]) {
      for (int r = 0; r < R; ++r) row_pins_[r] = row_pins[r];
      for (int c = 0; c < C; ++c) col_pins_[c] = col_pins[c];
    }

    Matrix<R,C> Scan() override {
      Matrix<R,C> matrix;
#if 1
      for (int c = 0; c < C; ++c) {
        pinMode(col_pins_[c], INPUT_PULLUP);
      }
      for (int r = 0; r < R; ++r) {
        pinMode(row_pins_[r], OUTPUT);
        digitalWrite(row_pins_[r], LOW);
        for (int c = 0; c < C; ++c) {
          if (digitalRead(col_pins_[c]) == LOW) matrix.Press(r, c);
        }
        digitalWrite(row_pins_[r], HIGH);
        pinMode(row_pins_[r], INPUT);
      }
#else
      for (int r = 0; r < R; ++r) {
        pinMode(row_pins_[r], INPUT_PULLUP);
      }
      for (int c = 0; c < C; ++c) {
        pinMode(col_pins_[c], OUTPUT);
        digitalWrite(col_pins_[c], LOW);
        for (int r = 0; r < R; ++r) {
          if (digitalRead(row_pins_[r]) == LOW) matrix.Press(r, c);
        }
        digitalWrite(col_pins_[c], HIGH);
        pinMode(col_pins_[c], INPUT);
      }
#endif
      return matrix;
    }

  private:
    int row_pins_[R];
    int col_pins_[C];
};

class RealSender : public Sender {
  public:
    void Send(const Events& events) override {
      if (events.modifiers) {
        Keyboard.set_modifier(events.modifiers | 0xE000);
      } else {
        Keyboard.set_modifier(0);
      }
      Keyboard.set_key1(events.keys[0].key);
      Keyboard.set_key2(events.keys[1].key);
      Keyboard.set_key3(events.keys[2].key);
      Keyboard.set_key4(events.keys[3].key);
      Keyboard.set_key5(events.keys[4].key);
      Keyboard.set_key6(events.keys[5].key);
      Keyboard.send_now();

      Mouse.set_buttons(events.buttons[0], events.buttons[1], events.buttons[2]);
      if (events.buttons[mdc - mlc]) {
        Mouse.click();
        Mouse.click();
      }
      if (events.buttons[msu - mlc]) {
        Mouse.scroll(5);
      }
      if (events.buttons[msd - mlc]) {
        Mouse.scroll(-5);
      }
    }
};

#endif
