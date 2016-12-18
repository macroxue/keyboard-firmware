constexpr int R = 6, C = 7;
const int row_pins[R] = { 1, 0, 2, 7, 9, 22 };
const int col_pins[C] = { 3, 8, 19, 23, 18, 20, 21 };
Layer<R,C> layers[] = {
  { "qwerty", l0, l1,
    {
      { cap, prt,  f1,  f2,  f3,  f4,  f5 },
      {'\\', '`', '1', '2', '3', '4', '5' },
      { esc,'\'', 'q', 'w', 'e', 'r', 't' },
      { tab,   0, 'a', 's', 'd', 'f', 'g' },
      { lsh,   0, 'z', 'x', 'c', 'v', 'b' },
      { lgu,  fn, lct,   0, lal, bks,   0 },
    }
  },
  { "qwerty-fn", l1, l1,
    {
      {  l0,  l2,  f1,  f2,  f3,  f4,  f5 },
      {'\\', '`', '1', '2', '3', '4', '5' },
      { esc,'\'', 'q', 'w', 'e', 'r', 't' },
      { tab,   0, 'a', 's', 'd', 'f', 'g' },
      { lsh,   0, 'z', 'x', 'c', 'v', 'b' },
      { lgu,  fn, lct,   0, lal, bks,   0 },
    }
  },
  { "dvorak", l2, l3,
    {
      { cap, prt,  f1,  f2,  f3,  f4,  f5 },
      {'\\', '`', '1', '2', '3', '4', '5' },
      { esc, '/','\'', ',', '.', 'p', 'y' },
      { tab,   0, 'a', 'o', 'e', 'u', 'i' },
      { lsh,   0, ';', 'q', 'j', 'k', 'x' },
      { lgu,  fn, lct,   0, lal, bks,   0 },
    }
  },
  { "dvorak-fn", l3, l3,
    {
      {  l0,  l2,  f1,  f2,  f3,  f4,  f5 },
      {'\\', '`', '1', '2', '3', '4', '5' },
      { esc, '/','\'', ',', '.', 'p', 'y' },
      { tab,   0, 'a', 'o', 'e', 'u', 'i' },
      { lsh,   0, ';', 'q', 'j', 'k', 'x' },
      { lgu,  fn, lct,   0, lal, bks,   0 },
    }
  },
};
