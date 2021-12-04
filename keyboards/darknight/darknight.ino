#include <keyboard-firmware.h>

// The layout has 5 rows and 12 columns.
constexpr int R = 5, C = 12;

// The row pins, to be modified according to the exact wiring.
const int row_pins[R] = {18, 17, 16, 15, 14};

// The column pins, to be modified according to the exact wiring.
const int col_pins[C] = {0, 1, 2, 3, 4, 5, 11, 10, 9, 8, 7, 6};

// LED pins are for displaying the active layer with binary code.
// High bits are not displayed when there are not enough LEDs.
// Pin 13 is for the built-in LED with Teensy LC, 3.2 and 4.0.
// Make sure it's not already used by one of the rows/columns.
// Set an empty initializer {} to disable this feature.
const int led_pins[] = {13};

// Layers of this layout. The keyboard always loads layer 0 to start.
// See key_map.h for definitions of keys, e.g. lsh <=> left shift.
Layer<R,C> layers[] = {
  { "darknight",  // name of this layer
    l0,  // this is layer 0
    l2,  // Fn layer is layer 2
    "",  // use no translator
    {
      {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
      {tab, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p','\''},
      {lct, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', rct},
      {lsh, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', rsh},
      {lgu, '`', mlc, mrc, lal,  fn, spc, ral, '[', ']','\\', del},
    },
    // Tapping on modifiers to get normal keys.
    { {fn,  bks}, {lct, esc}, {rct, ent} }
  },
  { "darknight-vi",  // name of this layer
    l1,  // this is layer 1
    l2,  // Fn layer is layer 2
    "vi",  // use vi translator
    {
      {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
      {tab, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p','\''},
      {lct, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', rct},
      {lsh, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', rsh},
      {lgu, '`', mlc, mrc, lal,  fn, spc, ral, '[', ']','\\', del},
    },
    // Tapping on modifiers to get normal keys.
    { {fn,  bks}, {lct, esc}, {rct, ent} }
  },
  { "darknight-fn",
    l2,  // this is layer 2
    l2,  // Fn layer is itself
    "",  // use no translator
    {
      { f1,  f2,  f3,  f4,  f5,  f6,  f7,  f8,  f9, f10, f11, f12},
      {tab,   0, mut, vdn, vup,   0,   0,   0,   0,   0,   0, cap},
      {lct, ply, pau, rew, ffw, rec,  lt,  dn,  up,  rt,   0, rct},
      {lsh,   0, stp, ptk, ntk, ejt, hom, pgd, pgu, end,   0, rsh},
      {lgu,  l0,  l1,  l2, lal,  fn, bks, ral,  l3,  l4,  l5, del},
    },
    // Tapping on modifiers to get normal keys.
    { {fn,  bks}, {lct, esc}, {rct, ent} }
  },
  { "darknight-dbg",
    l3,  // this is layer 3
    l2,  // Fn layer is layer 2
    "dbg",  // use debug translator
    {
      {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
      {tab, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p','\''},
      {lct, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', rct},
      {lsh, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', rsh},
      {lgu, '`', mlc, mrc, lal,  fn, spc, ral, '[', ']','\\', del},
    },
  },
  { "darknight-mod-fn",  // name of this layer
    l4,  // this is layer 4
    l4,  // Fn layer is itself
    "",  // use no translator
    {
      {0,  f1,  f2,  f3,  f4,  f5,  f6,  f7,  f8,  f9, f10, 0},
      {0, '~', '"', '+', '_', '|', hom, pgd, pgu, end, f11, 0},
      {0, '`','\'', '=', '-','\\',  lt,  dn,  up,  rt, f12, 0},
      {0, lgu, lsh, lct,   0,   0,   0,   0, rct, rsh, rgu, 0},
      {0,  l0,  l1,  l2, lal, lfn, bks, rfn,  l3,  l4,  l5, 0},
    },
  },
  { "darknight-mod",  // name of this layer
    l5,  // this is layer 5
    l4,  // Fn layer is layer 4
    "",  // use no translator
    {
      {0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 0},
      {0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 0},
      {0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 0},
      {0, 'z', lsh, lct, 'v', 'b', 'n', 'm', rct, rsh, '/', 0},
      {0, tab, mlc, mrc, lal, lfn, spc, rfn, '[', ']', del, 0},
    },
    // Tapping on modifiers to get normal keys.
    { {lfn, bks}, {lct, 'c'}, {lsh, 'x'}, {lal, esc},
      {rfn, ent}, {rct, ','}, {rsh, '.'} }
  },
};

#include <keyboard-firmware.cc>
