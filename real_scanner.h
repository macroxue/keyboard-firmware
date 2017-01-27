#ifndef REAL_SCANNER_H
#define REAL_SCANNER_H

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

#endif
