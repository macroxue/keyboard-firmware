#include "dbg_translator.h"

#include <assert.h>
#include <stdio.h>

#include "events.h"
#include "fake_sender.h"
#include "layouts/darknight.h"

int main() {
  int num_layers = sizeof(layers) / sizeof(layers[0]);
  DbgTranslator<R, C> translator(row_pins, col_pins, num_layers, layers);
  FakeSender sender;
  Events events;

  // Show pins.
  events.keys[0].key = KEY_P;
  translator.Input(events, &sender);

  // Show layers.
  events.keys[0].key = KEY_L;
  translator.Input(events, &sender);

  // Show heat map.
  layers[0].freq[0][0] = 99;
  layers[num_layers - 1].freq[R - 1][C - 1] = 88;
  events.keys[0].key = KEY_H;
  translator.Input(events, &sender);

  puts("PASSED");
  return 0;
}
