#include <assert.h>
#include "controller.h"

template <int R, int C>
class FakeScanner : public Scanner<R,C> {
  public:
    FakeScanner(int num_entries, const Entry* entries)
      : num_entries_(num_entries), entries_(entries) {}

    Matrix<R,C> Scan() override {
      if (step_ < num_entries_) {
        if (entries_[step_].pressed) {
          matrix_.Press(entries_[step_].row, entries_[step_].col);
        } else {
          matrix_.Release(entries_[step_].row, entries_[step_].col);
        }
        ++step_;
      }
      return matrix_;
    }

  private:
    const int num_entries_;
    const Entry* entries_;

    int step_ = 0;
    Matrix<R,C> matrix_;
};

class FakeSender : public Sender {
  public:
    void Send(const Events& events) override {
      auto modifiers = events.modifiers & ~0xE000;
      if (modifiers & MODIFIERKEY_LEFT_CTRL) printf("lC-");
      if (modifiers & MODIFIERKEY_LEFT_SHIFT) printf("lS-");
      if (modifiers & MODIFIERKEY_LEFT_ALT) printf("lA-");
      if (modifiers & MODIFIERKEY_LEFT_GUI) printf("lG-");
      if (modifiers & MODIFIERKEY_RIGHT_CTRL) printf("rC-");
      if (modifiers & MODIFIERKEY_RIGHT_SHIFT) printf("rS-");
      if (modifiers & MODIFIERKEY_RIGHT_ALT) printf("rA-");
      if (modifiers & MODIFIERKEY_RIGHT_GUI) printf("rG-");
      for (int i = 0; i < kMaxEvents; ++i) {
        if (events.keys[i].key == 0) continue;

        int ch;
        for (ch = 0; ch < 256 && key_map[ch] != events.keys[i].key; ++ch);
        if (32 <= ch && ch <= 127) putchar(ch);
        else printf("\\%d", ch);
      }
      putchar('\n');

      events_ = events;
    }

    Events events() const { return events_; }

  private:
    Events events_;
};

int main() {
  constexpr int R = 2, C = 2;

  Layer<R,C> layers[] = {
    { "qwerty", l0, l1,
      {
        {'q','w'},
        {shf,fn}
      }
    },
    { "fn1", l1, l1,
      {
        {l0,esc},
        {l2,fn}
      }
    },
    { "dvorak", l2, l3,
      {
        {'d','v'},
        {'o',fn}
      }
    },
    { "fn2", l3, l3,
      {
        {l0,ent},
        {l2,fn}
      }
    }
  };

  Layout<R,C> layout(4, layers);

  Entry entries[] = {
    // l1
    {1,1, true},
    {0,0, true},
    {0,0, false},
    {1,1, false},

    {0,0, true},
    {0,1, true},
    {0,1, false},
    {1,0, true},
    {0,0, false},
    {1,0, false},

    {1,1, true},
    {0,1, true},
    {1,1, false},
    {0,1, false},

    // l2
    {1,1, true},
    {1,0, true},
    {1,0, false},
    {1,1, false},

    {1,1, true},
    {0,1, true},
    {1,1, false},
    {0,1, false},

    {0,0, true},
    {0,1, true},
    {0,1, false},
    {1,0, true},
    {0,0, false},
    {1,0, false},

    // switch back to l1
    {1,0, true},
    {1,1, true},
    {1,0, false},
    {1,1, false},
  };

  int num_entries = sizeof(entries)/sizeof(entries[0]);
  FakeScanner<R,C> scanner(num_entries, entries);
  FakeSender sender;

  Controller<R,C> controller(&layout, &scanner, &sender);
  for (int i = 0; i < num_entries * 2; ++i) {
    controller.Scan();
  }

  auto events = sender.events();
  assert(events.modifiers == 0);
  for (int i = 0; i < kMaxEvents; ++i) {
    assert(events.keys[i].key == 0);
  }

  return 0;
}
