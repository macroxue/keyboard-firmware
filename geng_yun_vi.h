constexpr int R = 6, C = 14;
const int row_pins[R] = { 7, 8, 9, 10, 11, 12 };
const int col_pins[C] = { 14, 15, 16, 17, 18, 19, 20, 0, 1, 2, 3, 4, 5, 6};
Layer<R,C> layers[] = {
  { "qwerty",  // name of this layer
    l0,  // this is layer 0
    l1,  // Fn layer is layer 1
    "",  // use no translator
    {
      {   0,  f1,  f2,  f3,  f4,  f5,  f6,  f7,  f8,  f9, f10, f11, f12,   0 },
      { cap, '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0','\\', del },
      { tab, '=', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']' },
      { esc, '-', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';','\'', ent },
      {   0, lsh, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', rsh,   0 },
      { fnl, lgu,   0, lct,   0, lal, bks, spc, ral,   0, rct,   0, mnu, fnl },
    }
  },
  { "vi-emu",  // name of this layer
    l1,  // this is layer 1
    l1,  // Fn layer is itself
    "vi",  // use vi translator
    {
      {   0,  f1,  f2,  f3,  f4,  f5,  f6,  f7,  f8,  f9, f10, f11, f12,   0 },
      { cap, '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0','\\', del },
      { tab, '=', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']' },
      { esc, '-', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';','\'', ent },
      {   0, lsh, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', rsh,   0 },
      { fnl, lgu,   0, lct,   0, lal, bks, spc, ral,   0, rct,   0, mnu, fnl },
    }
  },
};
