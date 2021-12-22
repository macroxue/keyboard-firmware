#include <firmware.h>

// The layout has 5 rows and 12 columns.
constexpr int R = 5, C = 12;

// The row pins, to be modified according to the exact wiring.
const int row_pins[R] = { 20, 19, 18, 17, 16 };

// The column pins, to be modified according to the exact wiring.
const int col_pins[C] = { 1, 2, 3, 4, 5, 6, 12, 11, 10, 9, 8, 7 };

// LED pins are for displaying the active layer with binary code.
// High bits are not displayed when there are not enough LEDs.
// Pin 13 is for the built-in LED with Teensy LC, 3.2 and 4.0.
// Make sure it's not already used by one of the rows/columns.
// Set an empty initializer {} to disable this feature.
const int led_pins[] = { 13 };

// Layers of this layout. The keyboard always loads layer 0 to start.
// See key_map.h for definitions of keys, e.g. lsh <=> left shift.
Layer<R,C> layers[] = {
  { "q",  // name of this layer
    l0,  // this is layer 0
    l1,  // Fn layer is layer 1
    "",  // use no translator
    {
      {'1', '2', '3', '4', '5',   0,   0, '6', '7', '8', '9', '0'},
      {'q', 'w', 'e', 'r', 't',   0,   0, 'y', 'u', 'i', 'o', 'p'},
      {'a', 's', 'd', 'f', 'g',   0,   0, 'h', 'j', 'k', 'l', ';'},
      {'z', lsh, 'c', 'v', 'b',   0,   0, 'n', 'm', ',', rsh, '/'},
      {lgu, mlc, mrc, lal, lfn, lct, rct, spc, rfn, '[', ']', ral},
    },
    // Tapping on modifiers to get normal keys.
    { {lfn, bks}, {rfn, ent}, {lct, tab},
      {lsh, 'x'}, {rsh, '.'}, {lal, esc}, {ral, del} }
  },
  { "q-fn",  // name of this layer
    l1,  // this is layer 1
    l1,  // Fn layer is itself
    "",  // use no translator
    {
      { f1,  f2,  f3,  f4,  f5,   0,   0,  f6,  f7,  f8,  f9, f10},
      {'~', '"', '+', '_', '|',   0,   0, mdc, mlc, mmc, mrc, f11},
      {'`','\'', '=', '-','\\',   0,   0,  lt,  dn,  up,  rt, f12},
      {  0, lsh, vdn, vup, mut,   0,   0, hom, pgd, pgu, rsh,   0},
      {lgu,  l0,  l1, lal, lfn, lct, rct, bks, rfn,   0,   0, ral},
    },
    // Tapping on modifiers to get normal keys.
    { {lfn, bks}, {rfn, ent}, {lct, tab},
      {lsh, cap}, {rsh, end}, {lal, esc}, {ral, del} }
  },
};

#include <firmware.cc>
