#include "controller.h"

#include <assert.h>
#include "fake_clock.h"
#include "fake_scanner.h"
#include "fake_sender.h"

void test_with_fn() {
  constexpr int R = 2, C = 2;

  Layer<R,C> layers[] = {
    { "qwerty", l0, l1, "",
      {
        {'q','w'},
        {shf,fn}
      }
    },
    { "fn1", l1, l1, "",
      {
        {l0,esc},
        {l2,fn}
      }
    },
    { "dvorak", l2, l3, "",
      {
        {'d','v'},
        {'o',fn}
      }
    },
    { "fn2", l3, l3, "",
      {
        {l0,ent},
        {l2,fn}
      }
    }
  };

  Layout<R,C> layout(4, layers, nullptr);

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
    {0,0, true},
    {1,1, true},
    {0,0, false},
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
}

void test_with_fnl() {
  constexpr int R = 2, C = 2;

  Layer<R,C> layers[] = {
    { "qwerty", l0, l1, "",
      {
        {'q','w'},
        {shf,fnl}
      }
    },
    { "fn1", l1, l1, "",
      {
        {l0,esc},
        {l2,fnl}
      }
    },
    { "dvorak", l2, l3, "",
      {
        {'d','v'},
        {'o',fnl}
      }
    },
    { "fn2", l3, l3, "",
      {
        {l0,ent},
        {l2,fnl}
      }
    }
  };

  Layout<R,C> layout(4, layers, nullptr);

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
    {1,0, true},
    {1,0, false},

    {1,1, true},
    {0,1, true},
    {1,1, false},
    {0,1, false},

    {1,1, true},
    {1,1, false},

    {0,0, true},
    {0,1, true},
    {0,1, false},
    {1,0, true},
    {0,0, false},
    {1,0, false},

    // switch back to l1
    {1,1, true},
    {1,1, false},
    {0,0, true},
    {0,0, false},
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
}

void test_with_vi() {
  constexpr int R = 2, C = 2;

  Layer<R,C> layers[] = {
    { "qwerty", l0, l1, "",
      {
        {'1',fnl},
        {'c','w'}
      }
    },
    { "vi-emu", l1, l1, "vi",
      {
        {'2',fnl},
        {'c','w'}
      }
    }
  };

  FakeClock clock;
  ViTranslator translator(&clock);
  Layout<R,C> layout(2, layers, &translator);

  Entry entries[] = {
    // switch to l1
    {0,1, true},
    {0,1, false},
    // c
    {1,0, true},
    {1,0, false},
    // w
    {1,1, true},
    {1,1, false},
    // 1
    {0,0, true},
    {0,0, false},
    // switch to l1 again
    {0,1, true},
    {0,1, false},
    // 2
    {0,0, true},
    {0,0, false},
    // w
    {1,1, true},
    {1,1, false},
  };

  int num_entries = sizeof(entries)/sizeof(entries[0]);
  FakeScanner<R,C> scanner(num_entries, entries);
  FakeSender sender;

  Controller<R,C> controller(&layout, &scanner, &sender);
  for (int i = 0; i < num_entries * 2; ++i) {
    clock.set_time(i*200);
    controller.Scan();
    translator.AutoRepeat();
  }

  auto events = sender.events();
  assert(events.modifiers == 0);
  for (int i = 0; i < kMaxEvents; ++i) {
    assert(events.keys[i].key == 0);
  }
}

int main() {
  puts("test_with_fn");
  test_with_fn();
  puts("test_with_fnl");
  test_with_fnl();
  puts("test_with_vi");
  test_with_vi();
  puts("PASSED");
  return 0;
}
