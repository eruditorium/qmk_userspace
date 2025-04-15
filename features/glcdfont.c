#include "progmem.h"

// based on https://en.wikipedia.org/wiki/Code_page_437
// converted using https://joric.github.io/qle/
// See https://gist.github.com/pichfl/b008fd530b23a0fe1f6d7e1e766764fb for documentation

// static const unsigned char PROGMEM font[] = {
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//     0x3E, 0x41, 0x55, 0x71, 0x55, 0x41, 0x3E, 0x00,
//     0x3E, 0x7F, 0x6B, 0x4F, 0x6B, 0x7F, 0x3E, 0x00,
//     0x0C, 0x1E, 0x3E, 0x7C, 0x3E, 0x1E, 0x0C, 0x00,
//     0x00, 0x1C, 0x3E, 0x7F, 0x3E, 0x1C, 0x00, 0x00,
//     0x1C, 0x54, 0x5F, 0x7D, 0x5F, 0x54, 0x1C, 0x00,
//     0x08, 0x5C, 0x4E, 0x7F, 0x4E, 0x5C, 0x08, 0x00,
//     0x00, 0x00, 0x18, 0x3C, 0x18, 0x00, 0x00, 0x00,
//     0xFF, 0xFF, 0xE7, 0xC3, 0xE7, 0xFF, 0xFF, 0x00,
//     0x18, 0x1C, 0x76, 0x43, 0x76, 0x1C, 0x18, 0x00,
//     0x08, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x08, 0x00,
//     0x36, 0x55, 0x7F, 0x14, 0x7F, 0x55, 0x36, 0x00,
//     0x01, 0x01, 0x07, 0x3E, 0x70, 0x41, 0x41, 0x00,
//     0x20, 0x70, 0x70, 0x3F, 0x06, 0x0C, 0x08, 0x00,
//     0x20, 0x70, 0x3F, 0x03, 0x13, 0x3B, 0x1F, 0x00,
//     0x08, 0x2A, 0x14, 0x63, 0x14, 0x2A, 0x08, 0x00,
//     0x7F, 0x7F, 0x3E, 0x3E, 0x1C, 0x1C, 0x08, 0x00,
//     0x08, 0x1C, 0x1C, 0x3E, 0x3E, 0x7F, 0x7F, 0x00,
//     0x00, 0x14, 0x36, 0x7F, 0x7F, 0x36, 0x14, 0x00,
//     0x6F, 0x6F, 0x00, 0x6F, 0x6F, 0x00, 0x00, 0x00,
//     0x0E, 0x1F, 0x1B, 0x51, 0x7F, 0x41, 0x7F, 0x00,
//     0x00, 0x4E, 0x5F, 0x55, 0x7D, 0x39, 0x00, 0x00,
//     0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x00,
//     0x40, 0x52, 0x73, 0x7F, 0x73, 0x52, 0x40, 0x00,
//     0x00, 0x04, 0x06, 0x7F, 0x7F, 0x06, 0x04, 0x00,
//     0x00, 0x10, 0x30, 0x7F, 0x7F, 0x30, 0x10, 0x00,
//     0x18, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00,
//     0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00,
//     0x78, 0x78, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00,
//     0x18, 0x3C, 0x7E, 0x18, 0x7E, 0x3C, 0x18, 0x00,
//     0x60, 0x78, 0x7E, 0x7F, 0x7E, 0x78, 0x60, 0x00,
//     0x03, 0x0F, 0x3F, 0x7F, 0x3F, 0x0F, 0x03, 0x00,
//     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//     0x00, 0x00, 0x06, 0x6F, 0x6F, 0x06, 0x00, 0x00,
//     0x00, 0x03, 0x07, 0x00, 0x07, 0x03, 0x00, 0x00,
//     0x14, 0x14, 0x7F, 0x14, 0x7F, 0x14, 0x14, 0x00,
//     0x00, 0x24, 0x2A, 0x7F, 0x7F, 0x2A, 0x12, 0x00,
//     0x67, 0x75, 0x3B, 0x1C, 0x6E, 0x57, 0x73, 0x00,
//     0x36, 0x7F, 0x49, 0x7F, 0x36, 0x78, 0x4C, 0x00,
//     0x00, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
//     0x00, 0x1C, 0x3E, 0x63, 0x41, 0x00, 0x00, 0x00,
//     0x00, 0x00, 0x41, 0x63, 0x3E, 0x1C, 0x00, 0x00,
//     0x08, 0x5A, 0x7E, 0x3C, 0x7E, 0x5A, 0x10, 0x00,
//     0x18, 0x18, 0x7E, 0x7E, 0x18, 0x18, 0x00, 0x00,
//     0x40, 0x70, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
//     0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00,
//     0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//     0x60, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x00,
//     0x1C, 0x3E, 0x63, 0x49, 0x63, 0x3E, 0x1C, 0x00,
//     0x00, 0x44, 0x46, 0x7F, 0x7F, 0x40, 0x40, 0x00,
//     0x62, 0x73, 0x79, 0x5D, 0x4F, 0x67, 0x62, 0x00,
//     0x22, 0x63, 0x49, 0x49, 0x6B, 0x7F, 0x36, 0x00,
//     0x18, 0x1C, 0x56, 0x53, 0x7F, 0x7F, 0x40, 0x00,
//     0x37, 0x77, 0x45, 0x45, 0x45, 0x7D, 0x39, 0x00,
//     0x3E, 0x7F, 0x49, 0x49, 0x49, 0x7B, 0x32, 0x00,
//     0x03, 0x03, 0x71, 0x79, 0x1D, 0x0F, 0x07, 0x00,
//     0x3A, 0x7F, 0x4D, 0x49, 0x4D, 0x7F, 0x3A, 0x00,
//     0x26, 0x6F, 0x49, 0x49, 0x49, 0x7F, 0x3E, 0x00,
//     0x00, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00,
//     0x00, 0x76, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00,
//     0x00, 0x08, 0x1C, 0x3E, 0x63, 0x41, 0x00, 0x00,
//     0x00, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0x00, 0x00,
//     0x00, 0x41, 0x63, 0x3E, 0x1C, 0x08, 0x00, 0x00,
//     0x00, 0x02, 0x03, 0x69, 0x6D, 0x0F, 0x07, 0x00,
//     0x1C, 0x3E, 0x63, 0x49, 0x5D, 0x5F, 0x1E, 0x00,
//     0x7C, 0x7E, 0x13, 0x11, 0x13, 0x7E, 0x7C, 0x00,
//     0x7F, 0x7F, 0x45, 0x45, 0x4F, 0x7A, 0x30, 0x00,
//     0x3E, 0x7F, 0x63, 0x41, 0x41, 0x63, 0x22, 0x00,
//     0x7F, 0x7F, 0x41, 0x41, 0x63, 0x3E, 0x1C, 0x00,
//     0x3E, 0x7F, 0x6B, 0x49, 0x49, 0x49, 0x40, 0x00,
//     0x7E, 0x7F, 0x0B, 0x09, 0x09, 0x01, 0x01, 0x00,
//     0x3E, 0x7F, 0x41, 0x49, 0x49, 0x7B, 0x3A, 0x00,
//     0x7F, 0x7F, 0x08, 0x08, 0x08, 0x7F, 0x7F, 0x00,
//     0x00, 0x41, 0x7F, 0x7F, 0x41, 0x00, 0x00, 0x00,
//     0x20, 0x60, 0x41, 0x7F, 0x3F, 0x01, 0x00, 0x00,
//     0x7F, 0x7F, 0x08, 0x1C, 0x36, 0x63, 0x63, 0x00,
//     0x7F, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00,
//     0x7F, 0x7F, 0x06, 0x1C, 0x06, 0x7F, 0x7F, 0x00,
//     0x7F, 0x7F, 0x02, 0x0C, 0x30, 0x7F, 0x7F, 0x00,
//     0x3E, 0x7F, 0x41, 0x41, 0x41, 0x7F, 0x3E, 0x00,
//     0x7F, 0x7F, 0x11, 0x11, 0x1F, 0x0E, 0x00, 0x00,
//     0x3E, 0x7F, 0x41, 0x41, 0x61, 0xFF, 0xDE, 0x00,
//     0x7F, 0x7F, 0x09, 0x19, 0x3F, 0x6E, 0x44, 0x00,
//     0x26, 0x6F, 0x49, 0x49, 0x49, 0x7B, 0x32, 0x00,
//     0x01, 0x01, 0x7F, 0x7F, 0x01, 0x01, 0x00, 0x00,
//     0x3F, 0x7F, 0x40, 0x40, 0x40, 0x7F, 0x3F, 0x00,
//     0x0F, 0x1F, 0x30, 0x60, 0x30, 0x1F, 0x0F, 0x00,
//     0x1F, 0x3F, 0x60, 0x3C, 0x60, 0x3F, 0x1F, 0x00,
//     0x63, 0x63, 0x36, 0x1C, 0x36, 0x67, 0x63, 0x00,
//     0x07, 0x0F, 0x08, 0x78, 0x78, 0x0F, 0x07, 0x00,
//     0x71, 0x79, 0x59, 0x5D, 0x4D, 0x4F, 0x47, 0x00,
//     0x00, 0x7F, 0x7F, 0x41, 0x41, 0x41, 0x00, 0x00,
//     0x00, 0x03, 0x0F, 0x1C, 0x78, 0x60, 0x00, 0x00,
//     0x00, 0x41, 0x41, 0x41, 0x7F, 0x7F, 0x00, 0x00,
//     0x00, 0x04, 0x06, 0x03, 0x06, 0x04, 0x00, 0x00,
//     0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00,
//     0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
//     0x38, 0x7C, 0x44, 0x44, 0x28, 0x7C, 0x7C, 0x00,
//     0x7F, 0x7F, 0x28, 0x44, 0x44, 0x7C, 0x38, 0x00,
//     0x38, 0x7C, 0x6C, 0x44, 0x44, 0x6C, 0x28, 0x00,
//     0x38, 0x7C, 0x44, 0x44, 0x28, 0x7F, 0x7F, 0x00,
//     0x38, 0x7C, 0x54, 0x54, 0x54, 0x5C, 0x58, 0x00,
//     0x08, 0x08, 0x7E, 0x7F, 0x09, 0x0B, 0x02, 0x00,
//     0x2C, 0x5E, 0x52, 0x52, 0x52, 0x7E, 0x3C, 0x00,
//     0x7F, 0x7F, 0x0C, 0x04, 0x04, 0x7C, 0x78, 0x00,
//     0x00, 0x40, 0x7B, 0x7B, 0x40, 0x00, 0x00, 0x00,
//     0x00, 0x60, 0xC0, 0xFB, 0x7B, 0x00, 0x00, 0x00,
//     0x7F, 0x7F, 0x10, 0x38, 0x38, 0x2C, 0x4C, 0x00,
//     0x00, 0x3D, 0x7F, 0x40, 0x60, 0x20, 0x00, 0x00,
//     0x7C, 0x7C, 0x08, 0x7C, 0x0C, 0x78, 0x7C, 0x00,
//     0x7C, 0x7C, 0x08, 0x0C, 0x04, 0x7C, 0x78, 0x00,
//     0x38, 0x7C, 0x44, 0x44, 0x44, 0x7C, 0x38, 0x00,
//     0xFC, 0xFC, 0x18, 0x2C, 0x24, 0x3C, 0x18, 0x00,
//     0x18, 0x3C, 0x24, 0x24, 0x18, 0xFC, 0xFC, 0x00,
//     0x7C, 0x7C, 0x08, 0x0C, 0x0C, 0x0C, 0x00, 0x00,
//     0x48, 0x5C, 0x5C, 0x54, 0x74, 0x74, 0x24, 0x00,
//     0x04, 0x04, 0x3F, 0x7F, 0x44, 0x04, 0x00, 0x00,
//     0x3C, 0x7C, 0x40, 0x40, 0x40, 0x7C, 0x3C, 0x00,
//     0x0C, 0x1C, 0x30, 0x60, 0x30, 0x1C, 0x0C, 0x00,
//     0x1C, 0x3C, 0x60, 0x78, 0x60, 0x3C, 0x1C, 0x00,
//     0x6C, 0x6C, 0x38, 0x10, 0x38, 0x6C, 0x6C, 0x00,
//     0x0C, 0x9C, 0x90, 0x90, 0xF0, 0x7C, 0x1C, 0x00,
//     0x64, 0x74, 0x54, 0x54, 0x54, 0x5C, 0x4C, 0x00,
//     0x00, 0x08, 0x3E, 0x77, 0x41, 0x41, 0x00, 0x00,
//     0x00, 0x00, 0x77, 0x77, 0x00, 0x00, 0x00, 0x00,
//     0x00, 0x41, 0x41, 0x77, 0x3E, 0x08, 0x00, 0x00,
//     0x02, 0x03, 0x01, 0x02, 0x03, 0x01, 0x00, 0x00,
//     0x78, 0x7C, 0x46, 0x43, 0x46, 0x7C, 0x78, 0x00,
//     0x0E, 0x3F, 0xB3, 0xE1, 0xE1, 0x33, 0x12, 0x00,
//     0x38, 0x7A, 0x42, 0x40, 0x42, 0x7A, 0x38, 0x00,
//     0x38, 0x7C, 0x56, 0x57, 0x55, 0x5C, 0x58, 0x00,
//     0x30, 0x78, 0x4A, 0x4B, 0x31, 0x7B, 0x7A, 0x00,
//     0x30, 0x7A, 0x4A, 0x48, 0x32, 0x7A, 0x78, 0x00,
//     0x30, 0x78, 0x49, 0x4B, 0x32, 0x78, 0x78, 0x00,
//     0x30, 0x78, 0x4B, 0x4B, 0x33, 0x78, 0x78, 0x00,
//     0x10, 0x38, 0xB8, 0xE8, 0x68, 0x28, 0x28, 0x00,
//     0x38, 0x7C, 0x55, 0x55, 0x55, 0x5C, 0x58, 0x00,
//     0x3C, 0x7D, 0x55, 0x54, 0x55, 0x5D, 0x58, 0x00,
//     0x38, 0x7C, 0x55, 0x57, 0x56, 0x5C, 0x58, 0x00,
//     0x00, 0x02, 0x7A, 0x78, 0x02, 0x02, 0x00, 0x00,
//     0x00, 0x02, 0x7B, 0x7B, 0x02, 0x00, 0x00, 0x00,
//     0x00, 0x00, 0x7A, 0x7A, 0x00, 0x00, 0x00, 0x00,
//     0x70, 0x79, 0x2D, 0x24, 0x2D, 0x79, 0x70, 0x00,
//     0x70, 0x78, 0x2D, 0x25, 0x2D, 0x78, 0x70, 0x00,
//     0x7C, 0x7C, 0x56, 0x57, 0x55, 0x44, 0x44, 0x00,
//     0x74, 0x54, 0x7C, 0x38, 0x54, 0x5C, 0x00, 0x00,
//     0x7E, 0x7F, 0x09, 0x7E, 0x7F, 0x49, 0x41, 0x00,
//     0x30, 0x7A, 0x4B, 0x49, 0x4B, 0x7A, 0x30, 0x00,
//     0x30, 0x7A, 0x4A, 0x48, 0x4A, 0x7A, 0x30, 0x00,
//     0x30, 0x78, 0x49, 0x4B, 0x4A, 0x78, 0x30, 0x00,
//     0x38, 0x7A, 0x43, 0x41, 0x43, 0x7A, 0x38, 0x00,
//     0x38, 0x78, 0x41, 0x43, 0x42, 0x78, 0x38, 0x00,
//     0x18, 0xBA, 0xA2, 0xA0, 0xE2, 0x7A, 0x38, 0x00,
//     0x38, 0x7D, 0x45, 0x44, 0x45, 0x7D, 0x38, 0x00,
//     0x3C, 0x7D, 0x61, 0x40, 0x61, 0x7D, 0x3C, 0x00,
//     0x44, 0x00, 0x11, 0x00, 0x44, 0x00, 0x11, 0x00,
//     0x88, 0x55, 0x22, 0x55, 0x88, 0x55, 0x22, 0x55,
//     0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55,
//     0xAA, 0xFF, 0xAA, 0xFF, 0xAA, 0xFF, 0xAA, 0xFF,
//     0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
// };

static const unsigned char PROGMEM font[] = {
  // Zeichen: '-' (ASCII 45)
  0x00, 0x08, 0x08, 0x08, 0x00,

  // Zeichen: 'C' (ASCII 67)
  0x3C, 0x42, 0x40, 0x42, 0x3C,

  // Zeichen: 'A' (ASCII 65)
  0x7E, 0x09, 0x09, 0x09, 0x7E,

  // Zeichen: 'S' (ASCII 83)
  0x26, 0x49, 0x49, 0x49, 0x32,

  // Zeichen: 'W' (ASCII 87)
  0x7F, 0x20, 0x18, 0x20, 0x7F,
};
