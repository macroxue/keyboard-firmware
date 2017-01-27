#ifndef EVENTS_H
#define EVENTS_H

#include "key_map.h"

static const int kMaxEvents = 6;
static const int kMaxButtons = msd - mlc + 1;

struct Events {
  Events() { Reset(); }

  void Reset() {
    modifiers = 0;
    for (int i = 0; i < kMaxEvents; ++i) keys[i].key = 0;
    for (int i = 0; i < kMaxButtons; ++i) buttons[i] = 0;
  }

  int modifiers = 0;
  struct {
    int key;
    int row;
    int col;
    bool repeated = false;
    unsigned send_time;
  } keys[kMaxEvents];
  int buttons[msd - mlc + 1];
};

#endif
