#include "vi_translator.h"

#include <assert.h>
#include <stdio.h>
#include "events.h"
#include "fake_clock.h"
#include "fake_sender.h"

class Tester {
  public:
    Tester() : translator_(&clock_) {}

    bool Emit(int key) {
      bool exit_layer = Press(key);
      Release(key);
      return exit_layer;
    }

    bool Press(int key) {
      events_.keys[0].key = key;
      bool exit_layer = translator_.Input(events_, &sender_);
      if (exit_layer) puts("exit");
      translator_.AutoRepeat();
      translator_.AutoRepeat();
      return exit_layer;
    }

    bool Release(int key) {
      events_.keys[0].key = 0;
      bool exit_layer = translator_.Input(events_, &sender_);
      translator_.AutoRepeat();
      translator_.AutoRepeat();
      return exit_layer;
    }

    bool PressModifier(int modifier) {
      events_.modifiers |= modifier;
      bool exit_layer = translator_.Input(events_, &sender_);
      translator_.AutoRepeat();
      translator_.AutoRepeat();
      return exit_layer;
    }

    bool ReleaseModifier(int modifier) {
      events_.modifiers &= ~modifier;
      bool exit_layer = translator_.Input(events_, &sender_);
      translator_.AutoRepeat();
      translator_.AutoRepeat();
      return exit_layer;
    }

    FakeClock& clock() { return clock_; }

  private:
    Events events_;
    FakeClock clock_;
    FakeSender sender_;
    ViTranslator translator_;
};

void test_commands() {
  Tester t;
  puts("> 0");
  assert(t.Emit(KEY_0) == false);
  puts("> i");
  assert(t.Emit(KEY_I) == true);
  puts("> a");
  assert(t.Emit(KEY_A) == true);
  puts("> o");
  assert(t.Emit(KEY_O) == true);

  puts("> 3s");
  assert(t.Emit(KEY_3) == false);
  assert(t.Emit(KEY_S) == true);

  puts("> 2c3h");
  assert(t.Emit(KEY_2) == false);
  assert(t.Emit(KEY_C) == false);
  assert(t.Emit(KEY_3) == false);
  assert(t.Emit(KEY_H) == true);

  puts("> 2dd");
  assert(t.Emit(KEY_2) == false);
  assert(t.Emit(KEY_D) == false);
  assert(t.Emit(KEY_D) == false);

  puts("> dk");
  assert(t.Emit(KEY_D) == false);
  assert(t.Emit(KEY_K) == false);

  puts("> Gygg");
  assert(t.PressModifier(MODIFIERKEY_SHIFT) == false);
  assert(t.Emit(KEY_G) == false);
  assert(t.ReleaseModifier(MODIFIERKEY_SHIFT) == false);
  assert(t.Emit(KEY_Y) == false);
  assert(t.Emit(KEY_G) == false);
  assert(t.Emit(KEY_G) == false);

  puts("> 3yy");
  assert(t.Emit(KEY_3) == false);
  assert(t.Emit(KEY_Y) == false);
  assert(t.Emit(KEY_Y) == false);

  puts("> 3y2k");
  assert(t.Emit(KEY_3) == false);
  assert(t.Emit(KEY_Y) == false);
  assert(t.Emit(KEY_2) == false);
  assert(t.Emit(KEY_K) == false);

  puts("> 2p");
  assert(t.Emit(KEY_2) == false);
  assert(t.Emit(KEY_P) == false);

  puts("> P");
  assert(t.PressModifier(MODIFIERKEY_SHIFT) == false);
  assert(t.Emit(KEY_P) == false);
  assert(t.ReleaseModifier(MODIFIERKEY_SHIFT) == false);

  puts("> 3y2 esc");
  assert(t.Emit(KEY_3) == false);
  assert(t.Emit(KEY_Y) == false);
  assert(t.Emit(KEY_2) == false);
  assert(t.Emit(KEY_ESC) == false);

  puts("> C");
  assert(t.PressModifier(MODIFIERKEY_SHIFT) == false);
  assert(t.Emit(KEY_C) == true);
  assert(t.ReleaseModifier(MODIFIERKEY_SHIFT) == false);

  puts("> spc bks");
  assert(t.Emit(KEY_SPACE) == false);
  assert(t.Emit(KEY_BACKSPACE) == false);
}

void test_repetition() {
  Tester t;
  t.clock().set_time(1000);

  puts("> j*");
  assert(t.Press(KEY_J) == false);
  t.clock().set_time(1001);
  assert(t.Press(KEY_J) == false);
  t.clock().set_time(1002);
  assert(t.Press(KEY_J) == false);
  t.clock().set_time(2000);
  assert(t.Press(KEY_J) == false);
  t.clock().set_time(2001);
  assert(t.Press(KEY_J) == false);
  t.clock().set_time(2100);
  assert(t.Press(KEY_J) == false);
  assert(t.Release(KEY_J) == false);

  puts("> j* time wrapped");
  t.clock().set_time(-10);
  assert(t.Press(KEY_J) == false);
  t.clock().set_time(10);
  assert(t.Press(KEY_J) == false);
  t.clock().set_time(1000);
  assert(t.Press(KEY_J) == false);

  puts("> j*k");
  t.clock().set_time(-10);
  assert(t.Press(KEY_J) == false);
  t.clock().set_time(10000);
  assert(t.Press(KEY_J) == false);
  t.clock().set_time(20000);
  assert(t.Press(KEY_K) == false);
  t.clock().set_time(20010);
  assert(t.Press(KEY_K) == false);
}

int main() {
  test_commands();
  test_repetition();
  puts("PASSED");
  return 0;
}
