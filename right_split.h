constexpr int R = 6, C = 9;
const int row_pins[R] = { 21, 22, 14, 20, 19, 8 };
const int col_pins[C] = { 9, 7, 23, 18, 17, 15, 10, 11, 12 };
Layer<R,C> layers[] = {
  { "qwerty", l0, l1,
    {
      {  f6,  f7,  f8,  f9, f10, f11, f12, mlc, mrc },
      { '6', '7', '8', '9', '0', '-', '=', del, hom },
      { 'y', 'u', 'i', 'o', 'p', '[', ']',   0, end },
      { 'h', 'j', 'k', 'l', ';', ent,   0, bks, pgu },
      { 'n', 'm', ',', '.', '/', rsh,   0,  up, pgd },
      { spc,   0, ral, rct,   0,  fn,  lt,  dn,  rt },
    }
  },
  { "fn", l1, l1,
    {
      {  f6,  f7,  f8,  f9, f10, f11, f12,  l0,  l2 },
      { '6', '7', '8', '9', '0', '-', '=', del, hom },
      { 'y', 'u', 'i', 'o', 'p', '[', ']',   0, end },
      { 'h', 'j', 'k', 'l', ';', ent,   0, bks, pgu },
      { 'n', 'm', ',', '.', '/', rsh,   0,  up, pgd },
      { spc,   0, ral, rct,   0,  fn,  lt,  dn,  rt },
    }
  },
  { "dvorak", l2, l3,
    {
      {  f6,  f7,  f8,  f9, f10, f11, f12, mlc, mrc },
      { '6', '7', '8', '9', '0', '-', '=', del, hom },
      { 'f', 'g', 'c', 'r', 'l', '[', ']',   0, end },
      { 'd', 'h', 't', 'n', 's', ent,   0, bks, pgu },
      { 'b', 'm', 'w', 'v', 'z', rsh,   0,  up, pgd },
      { spc,   0, ral, rct,   0,  fn,  lt,  dn,  rt },
    }
  },
  { "dvorak-fn", l3, l3,
    {
      {  f6,  f7,  f8,  f9, f10, f11, f12,  l0,  l2 },
      { '6', '7', '8', '9', '0', '-', '=', del, hom },
      { 'f', 'g', 'c', 'r', 'l', '[', ']',   0, end },
      { 'd', 'h', 't', 'n', 's', ent,   0, bks, pgu },
      { 'b', 'm', 'w', 'v', 'z', rsh,   0,  up, pgd },
      { spc,   0, ral, rct,   0,  fn,  lt,  dn,  rt },
    }
  },
};
