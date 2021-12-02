#ifndef KEY_MAP_H
#define KEY_MAP_H

#ifndef LAYOUT_US_ENGLISH
#define LAYOUT_US_ENGLISH
#endif
#include "keylayouts.h"

// Key codes of printable characters are their ASCII codes.
enum KeyCode : unsigned char {
  bks = 8,   // backspace
  tab = 9,   // tab
  ent = 13,  // enter
  esc = 27,  // escape
  spc = 32,  // or just ' '

  ctl = 128, // control
  shf,       // shift
  alt,       // alt
  gui,       // windows
  lct,       // left control
  lsh,       // left shift
  lal,       // left alt
  lgu,       // left windows
  rct,       // right windows
  rsh,       // right shift
  ral,       // right alt
  rgu,       // right windows

  up = 140,  // up
  dn,        // down
  lt,        // left
  rt,        // right
  hom,       // home
  end,       // end
  pgu,       // page up
  pgd,       // page down
  ins,       // insert
  del,       // delete
  cap,       // capslock

  f1 = 151,
  f2,
  f3,
  f4,
  f5,
  f6,
  f7,
  f8,
  f9,
  f10,
  f11,
  f12,
  f13,
  f14,
  f15,

  mnu = 166,  // menu/application
  prt,        // print screen

  mlc = 171,  // mouse left click
  mmc,        // mouse middle click
  mrc,        // mouse right click
  mdc,        // mouse double click
  msu,        // mouse scroll up
  msd,        // mouse scroll down

  pdn = 181,  // system power down
  slp,        // system sleep
  wak,        // system wake up
  ply,        // play
  pau,        // pause
  rec,        // record
  ffw,        // fast forward
  rew,        // rewind
  ntk,        // next track
  ptk,        // previous track
  stp,        // stop
  ejt,        // eject
  rpl,        // random play
  ppa,        // play pause
  psk,        // play skip
  mut,        // mute
  vup,        // volume up
  vdn,        // volume down

  kn1 = 201,  // keypad 1
  kn2 = 202,  // keypad 2
  kn3 = 203,  // keypad 3
  kn4 = 204,  // keypad 4
  kn5 = 205,  // keypad 5
  kn6 = 206,  // keypad 6
  kn7 = 207,  // keypad 7
  kn8 = 208,  // keypad 8
  kn9 = 209,  // keypad 9
  kn0 = 210,  // keypad 0
  kpr = 211,  // keypad period
  ken = 212,  // keypad enter
  kpl = 213,  // keypad plus
  kmn = 214,  // keypad minus
  kas = 215,  // keypad asterix
  ksl = 216,  // keypad slash
  nml = 217,  // num lock
  scl = 218,  // scroll lock

  l0 = 240,   // layer 0
  l1,
  l2,
  l3,
  l4,
  l5,
  l6,
  l7,
  l8,
  l9,         // layer 9

  fnl = 254,  // lock to fn layer
  fn          // shift to fn layer
};

// Negative values represent shifted keys like '!' and '{' which are shift-'1' and
// shift-'[' respectively. Names are from https://en.wikipedia.org/wiki/ASCII.
enum ShiftedKeys {
  KEY_EXCLAMATION = -KEY_1,
  KEY_AT = -KEY_2,
  KEY_HASH = -KEY_3,
  KEY_DOLLAR = -KEY_4,
  KEY_PERCENT = -KEY_5,
  KEY_CARET = -KEY_6,
  KEY_AMPERSAND = -KEY_7,
  KEY_ASTERIX = -KEY_8,
  KEY_LEFT_PAREN = -KEY_9,
  KEY_RIGHT_PAREN = -KEY_0,
  KEY_UNDERLINE = -KEY_MINUS,
  KEY_PLUS = -KEY_EQUAL,
  KEY_LEFT_CURLY = -KEY_LEFT_BRACE,
  KEY_RIGHT_CURLY = -KEY_RIGHT_BRACE,
  KEY_PIPE = -KEY_BACKSLASH,
  KEY_COLON = -KEY_SEMICOLON,
  KEY_DOUBLE_QUOTE = -KEY_QUOTE,
  KEY_LESS_THAN = -KEY_COMMA,
  KEY_GREATER_THAN = -KEY_PERIOD,
  KEY_QUESTION = -KEY_SLASH,
  // KEY_TILDE is mapped to '`' instead of '~' by Teensy.
  KEY_WAVE = -KEY_TILDE,
};

static const int key_map[256] = {
  0,  // 0
  0,  // 1
  0,  // 2
  0,  // 3
  0,  // 4
  0,  // 5
  0,  // 6
  0,  // 7
  KEY_BACKSPACE,  // 8
  KEY_TAB,  // 9
  0,  // 10
  0,  // 11
  0,  // 12
  KEY_ENTER,  // 13
  0,  // 14
  0,  // 15
  0,  // 16
  0,  // 17
  0,  // 18
  0,  // 19
  0,  // 20
  0,  // 21
  0,  // 22
  0,  // 23
  0,  // 24
  0,  // 25
  0,  // 26
  KEY_ESC,  // 27
  0,  // 28
  0,  // 29
  0,  // 30
  0,  // 31
  KEY_SPACE,  // 32
  KEY_EXCLAMATION,  // 33
  KEY_DOUBLE_QUOTE,  // 34
  KEY_HASH,  // 35
  KEY_DOLLAR,  // 36
  KEY_PERCENT,  // 37
  KEY_AMPERSAND,  // 38
  KEY_QUOTE,  // 39
  KEY_LEFT_PAREN,  // 40
  KEY_RIGHT_PAREN,  // 41
  KEY_ASTERIX,  // 42
  KEY_PLUS,  // 43
  KEY_COMMA,  // 44
  KEY_MINUS,  // 45
  KEY_PERIOD,  // 46
  KEY_SLASH,  // 47
  KEY_0,  // 48
  KEY_1,  // 49
  KEY_2,  // 50
  KEY_3,  // 51
  KEY_4,  // 52
  KEY_5,  // 53
  KEY_6,  // 54
  KEY_7,  // 55
  KEY_8,  // 56
  KEY_9,  // 57
  KEY_COLON,  // 58
  KEY_SEMICOLON,  // 59
  KEY_LESS_THAN,  // 60
  KEY_EQUAL,  // 61
  KEY_GREATER_THAN,  // 62
  KEY_QUESTION,  // 63
  KEY_AT,  // 64
  -KEY_A,  // 65
  -KEY_B,  // 66
  -KEY_C,  // 67
  -KEY_D,  // 68
  -KEY_E,  // 69
  -KEY_F,  // 70
  -KEY_G,  // 71
  -KEY_H,  // 72
  -KEY_I,  // 73
  -KEY_J,  // 74
  -KEY_K,  // 75
  -KEY_L,  // 76
  -KEY_M,  // 77
  -KEY_N,  // 78
  -KEY_O,  // 79
  -KEY_P,  // 80
  -KEY_Q,  // 81
  -KEY_R,  // 82
  -KEY_S,  // 83
  -KEY_T,  // 84
  -KEY_U,  // 85
  -KEY_V,  // 86
  -KEY_W,  // 87
  -KEY_X,  // 88
  -KEY_Y,  // 89
  -KEY_Z,  // 90
  KEY_LEFT_BRACE,  // 91
  KEY_BACKSLASH,  // 92
  KEY_RIGHT_BRACE,  // 93
  KEY_CARET,  // 94
  KEY_UNDERLINE,  // 95
  KEY_TILDE,  // 96
  KEY_A,  // 97
  KEY_B,  // 98
  KEY_C,  // 99
  KEY_D,  // 100
  KEY_E,  // 101
  KEY_F,  // 102
  KEY_G,  // 103
  KEY_H,  // 104
  KEY_I,  // 105
  KEY_J,  // 106
  KEY_K,  // 107
  KEY_L,  // 108
  KEY_M,  // 109
  KEY_N,  // 110
  KEY_O,  // 111
  KEY_P,  // 112
  KEY_Q,  // 113
  KEY_R,  // 114
  KEY_S,  // 115
  KEY_T,  // 116
  KEY_U,  // 117
  KEY_V,  // 118
  KEY_W,  // 119
  KEY_X,  // 120
  KEY_Y,  // 121
  KEY_Z,  // 122
  KEY_LEFT_CURLY,  // 123
  KEY_PIPE,  // 124
  KEY_RIGHT_CURLY,  // 125
  KEY_WAVE,  // 126
  0,  // 127
  MODIFIERKEY_CTRL,  // 128
  MODIFIERKEY_SHIFT,  // 129
  MODIFIERKEY_ALT,  // 130
  MODIFIERKEY_GUI,  // 131
  MODIFIERKEY_LEFT_CTRL,  // 132
  MODIFIERKEY_LEFT_SHIFT,  // 133
  MODIFIERKEY_LEFT_ALT,  // 134
  MODIFIERKEY_LEFT_GUI,  // 135
  MODIFIERKEY_RIGHT_CTRL,  // 136
  MODIFIERKEY_RIGHT_SHIFT,  // 137
  MODIFIERKEY_RIGHT_ALT,  // 138
  MODIFIERKEY_RIGHT_GUI,  // 139
  KEY_UP,         // 140
  KEY_DOWN,       // 141
  KEY_LEFT,       // 142
  KEY_RIGHT,      // 143
  KEY_HOME,       // 144
  KEY_END,        // 145
  KEY_PAGE_UP,    // 146
  KEY_PAGE_DOWN,  // 147
  KEY_INSERT,     // 148
  KEY_DELETE,     // 149
  KEY_CAPS_LOCK,  // 150
  KEY_F1,   // 151
  KEY_F2,   // 152
  KEY_F3,   // 153
  KEY_F4,   // 154
  KEY_F5,   // 155
  KEY_F6,   // 156
  KEY_F7,   // 157
  KEY_F8,   // 158
  KEY_F9,   // 159
  KEY_F10,  // 160
  KEY_F11,  // 161
  KEY_F12,  // 162
  KEY_F13,  // 163
  KEY_F14,  // 164
  KEY_F15,  // 165
  KEY_MENU,  // 166
  KEY_PRINTSCREEN,  // 167
  0,  // 168
  0,  // 169
  0,  // 170
  mlc,  // 171
  mmc,  // 172
  mrc,  // 173
  mdc,  // 174
  msu,  // 175
  msd,  // 176
  0,  // 177
  0,  // 178
  0,  // 179
  0,  // 180
  KEY_SYSTEM_POWER_DOWN,  // 181
  KEY_SYSTEM_SLEEP,  // 182
  KEY_SYSTEM_WAKE_UP,  // 183
  KEY_MEDIA_PLAY,  // 184
  KEY_MEDIA_PAUSE,  // 185
  KEY_MEDIA_RECORD,  // 186
  KEY_MEDIA_FAST_FORWARD,  // 187
  KEY_MEDIA_REWIND,  // 188
  KEY_MEDIA_NEXT_TRACK,  // 189
  KEY_MEDIA_PREV_TRACK,  // 190
  KEY_MEDIA_STOP,  // 191
  KEY_MEDIA_EJECT,  // 192
  KEY_MEDIA_RANDOM_PLAY,  // 193
  KEY_MEDIA_PLAY_PAUSE,  // 194
  KEY_MEDIA_PLAY_SKIP,  // 195
  KEY_MEDIA_MUTE,  // 196
  KEY_MEDIA_VOLUME_INC,  // 197
  KEY_MEDIA_VOLUME_DEC,  // 198
  0,  // 199
  0,  // 200
  KEYPAD_1,  // 201
  KEYPAD_2,  // 202
  KEYPAD_3,  // 203
  KEYPAD_4,  // 204
  KEYPAD_5,  // 205
  KEYPAD_6,  // 206
  KEYPAD_7,  // 207
  KEYPAD_8,  // 208
  KEYPAD_9,  // 209
  KEYPAD_0,  // 210
  KEYPAD_PERIOD ,  // 211
  KEYPAD_ENTER ,  // 212
  KEYPAD_PLUS,  // 213
  KEYPAD_MINUS ,  // 214
  KEYPAD_ASTERIX ,  // 215
  KEYPAD_SLASH ,  // 216
  KEY_NUM_LOCK,  // 217
  KEY_SCROLL_LOCK,  // 218
  0,  // 219
  0,  // 220
  0,  // 221
  0,  // 222
  0,  // 223
  0,  // 224
  0,  // 225
  0,  // 226
  0,  // 227
  0,  // 228
  0,  // 229
  0,  // 230
  0,  // 231
  0,  // 232
  0,  // 233
  0,  // 234
  0,  // 235
  0,  // 236
  0,  // 237
  0,  // 238
  0,  // 239
  l0,  // 240
  l1,  // 241
  l2,  // 242
  l3,  // 243
  l4,  // 244
  l5,  // 245
  l6,  // 246
  l7,  // 247
  l8,  // 248
  l9,  // 249
  0,  // 250
  0,  // 251
  0,  // 252
  0,  // 253
  fnl,  // 254
  fn   // 255
};

#endif
