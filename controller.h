#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <atomic>

#ifndef LAYOUT_US_ENGLISH
#define LAYOUT_US_ENGLISH
#endif
#include "keylayouts.h"

#include "key_map.h"
#include "matrix.h"
#include "layout.h"

template <int R, int C>
class Scanner {
  public:
    virtual ~Scanner() {}
    virtual Matrix<R,C> Scan() = 0;
};

class Sender {
  public:
    virtual ~Sender() {}
    virtual void Send(const Events& events) = 0;
};

template <int R, int C>
class Controller {
  public:
    Controller(Layout<R,C>* layout, Scanner<R,C>* scanner, Sender* sender)
      : layout_(layout), scanner_(scanner), sender_(sender) {}

    void Scan() {
      Matrix<R, C> new_matrix = scanner_->Scan();
      Entry entries[kMaxEvents];
      int num_entries = matrix_.Difference(new_matrix, kMaxEvents, entries);
      if (num_entries > 0) {
        Events events = layout_->Interpret(num_entries, entries);
        sender_->Send(events);
      }
    }

  private:
    Layout<R,C>* const layout_;
    Scanner<R,C>* const scanner_;
    Sender* const sender_;

    Matrix<R,C> matrix_;
};

#endif
