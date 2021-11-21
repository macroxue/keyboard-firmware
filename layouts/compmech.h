
constexpr int R = 5, C = 19;

// The row pins, to be modified according to the exact wiring.
const int row_pins[R] = { 20, 21, 22, 23, 24 };

// The column pins, to be modified according to the exact wiring.
const int col_pins[C] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

Layer<R,C> layers[] = {
  { "qwerty", l0, l1, "",
    {
      {   f1,  f2, esc,  '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',   '-',   '=',   bks,  nml,  scl,  kmn },
      {   f3,  f4, tab,  'q',  'w',  'e',  'r',  't',  'y',  'u',  'i',  'o',  'p',   '[',   ']',   ent,  kn7,  kn8,  kn9 },
      {   f5,  f6, cap,  'a',  's',  'd',  'f',  'g',  'h',  'j',  'k',  'l',  ';',  '\'',   '`',   kmt,  kn4,  kn5,  kn6 },
      {   f7,  f8, lal, '\\',  'z',  'x',  'c',  'v',  'b',  'n',  'm',  ',',  '.',   '/',   rct,   kdl,  kn1,  kn2,  kn3 },
      {   f9, f10, lsh ,  0 ,   0 ,   0 ,   0 ,   0 ,  spc,   0 ,   0 ,   0 ,   0 ,    0 ,   rsh,   0,    0,    kn0,  pls },
    }
  },
  { "fn-media", l1, l1, "",
    {
      {   f1,  f2, esc,  '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',   '-',   '=',   bks,  nml,  scl,  kmn },
      {   f3,  f4, tab,  'q',  'w',  'e',  'r',  't',  'y',  'u',  'i',  'o',  'p',   '[',   ']',   ent,  kn7,  kn8,  kn9 },
      {   f5,  f6, cap,  'a',  's',  'd',  'f',  'g',  'h',  'j',  'k',  'l',  ';',  '\'',   '`',   kmt,  kn4,  kn5,  kn6 },
      {   f7,  f8, lal, '\\',  'z',  'x',  'c',  'v',  'b',  'n',  'm',  ',',  '.',   '/',   rct,   kdl,  kn1,  kn2,  kn3 },
      {   f9, f10, lsh ,  0 ,   0 ,   0 ,   0 ,   0 ,  spc,   0 ,   0 ,   0 ,   0 ,    0 ,   rsh,   0,    0,    kn0,  pls },
    }
  },
};   
