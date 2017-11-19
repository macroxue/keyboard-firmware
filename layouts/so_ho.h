// The layout has 6 rows and 14 columns.
constexpr int R = 6, C = 14;

// The row pins, to be modified according to the exact wiring.
const int row_pins[R] = { 7, 8, 9, 10, 11, 12 };

// The column pins, to be modified according to the exact wiring.
const int col_pins[C] = { 14, 15, 16, 17, 18, 19, 20, 0, 1, 2, 3, 4, 5, 6};

// Layers of this layout. The keyboard always loads layer 0 to start.
// See key_map.h for definitions of keys, e.g. lsh <=> left shift.
Layer<R,C> layers[] = {
  { "gengyun",  // name of this layer
    l0,  // this is layer 0
    l2,  // Fn layer is layer 2
    "",  // use no translator
    {
      {   0,  f1,  f2,  f3,  f4,  f5,  f6,  f7,  f8,  f9, f10, f11, f12,   0 },
      { esc, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', del },
      { tab,'\\', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']' },
      { lct, '`', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';','\'', ent },
      {   0, lsh, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', rsh,   0 },
      { fnl, lgu,   0, lct,   0, lal, bks, spc, ral,   0, rct,   0,  l1,  l0 },
    }
  },
  { "gengyun-vi",  // name of this layer
    l1,  // this is layer 1
    l2,  // Fn layer is layer 2
    "vi",  // use vi translator
    {
      {   0,  f1,  f2,  f3,  f4,  f5,  f6,  f7,  f8,  f9, f10, f11, f12,   0 },
      { esc, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', del },
      { tab,'\\', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']' },
      { lct, '`', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';','\'', ent },
      {   0, lsh, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', rsh,   0 },
      { fnl, lgu,   0, lct,   0, lal, bks, spc, ral,   0, rct,   0,  l1,  l0 },
    }
  },
  { "gengyun-fn",
    l2,  // this is layer 2
    l2,  // Fn layer is itself
    "",  // use no translator
    {
      {   0,  f1,  f2,  f3,  f4,  f5,  f6,  l0,  l1,  l2,  l3,  l4,  l5,   0 },
      { esc, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', del },
      { tab,'\\',   0, mut, vdn, vup,   0, mdc, mlc, mmc, mrc,   0, '[', ']' },
      { lct, '`', ply, pau, rew, ffw, rec,  lt,  dn,  up,  rt,   0,'\'', ent },
      {   0, lsh,   0, stp, ptk, ntk, ejt, hom, pgd, pgu, end,   0, rsh,   0 },
      { fnl, lgu,   0, lct,   0, lal, bks, spc, ral,   0, rct,   0,  l1,  l0 },
    }
  },
  { "soho",  // name of this layer
    l3,  // this is layer 3
    l5,  // Fn layer is layer 5
    "",  // use no translator
    {
      {   0,  f1,  f2,  f3,  f4,  f5,  f6,  f7,  f8,  f9, f10, f11, f12,   0 },
      { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=','\\' },
      { tab,'\'', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']' },
      {  fn, lct, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', rct, del },
      { lgu, lsh, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', rsh, rgu },
      { hom, pgd, pgu, end,   0, lal, bks, spc, ral,   0,  lt,  dn,  up,  rt },
    }
  },
  { "soho-vi",  // name of this layer
    l4,  // this is layer 4
    l5,  // Fn layer is layer 5
    "",  // use no translator
    {
      {   0,  f1,  f2,  f3,  f4,  f5,  f6,  f7,  f8,  f9, f10, f11, f12,   0 },
      { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=','\\' },
      { tab,'\'', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']' },
      {  fn, lct, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', rct, del },
      { lgu, lsh, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', rsh, rgu },
      { hom, pgd, pgu, end,   0, lal, bks, spc, ral,   0,  lt,  dn,  up,  rt },
    }
  },
  { "soho-fn",
    l5,  // this is layer 5
    l5,  // Fn layer is itself
    "",  // use no translator
    {
      {   0,  f1,  f2,  f3,  f4,  f5,  f6,  l0,  l1,  l2,  l3,  l4,  l5,   0 },
      { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=','\\' },
      { tab,'\'',   0, mut, vdn, vup,   0, mdc, mlc, mmc, mrc,   0, '[', ']' },
      {  fn, lct, ply, pau, rew, ffw, rec,  lt,  dn,  up,  rt,   0, rct, del },
      { lgu, lsh,   0, stp, ptk, ntk, ejt, hom, pgd, pgu, end,   0, rsh, rgu },
      { hom, pgd, pgu, end,   0, lal, bks, spc, ral,   0,  lt,  dn,  up,  rt },
    }
  },
};
