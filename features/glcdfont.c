#include "progmem.h"

// based on https://en.wikipedia.org/wiki/Code_page_437
// converted using https://joric.github.io/qle/
// See https://gist.github.com/pichfl/b008fd530b23a0fe1f6d7e1e766764fb for documentation

static const unsigned char PROGMEM font[] = {
  // ASCII 65 'A'
  0b00011000,
  0b00111100,
  0b01100110,
  0b01111110,
  0b01100110,
  0b01100110,
  0b01100110,
  0b00000000,

  // ASCII 66 'B'
  0,0,0,0,0,0,0,0,  // leer

  // ASCII 67 'C'
  0b00111110,
  0b01100011,
  0b11000000,
  0b11000000,
  0b11000000,
  0b01100011,
  0b00111110,
  0b00000000,

  // ASCII 68–82
  [ (68 - 65) * 8 ... (82 - 65) * 8 + 7 ] = 0x00,

  // ASCII 83 'S'
  0b00111110,
  0b01100011,
  0b01100000,
  0b00111100,
  0b00000110,
  0b01100011,
  0b00111110,
  0b00000000,

  // ASCII 84–86
  [ (84 - 65) * 8 ... (86 - 65) * 8 + 7 ] = 0x00,

  // ASCII 87 'W'
  0b01100011,
  0b01100011,
  0b01100011,
  0b01101011,
  0b01111111,
  0b00111110,
  0b00000000,
  0b00000000,
};
