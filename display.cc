#include "display.h"

size_t get_display_height() {
  return CGDisplayPixelsHigh(kCGDirectMainDisplay);
}

size_t get_display_width() {
  return CGDisplayPixelsWide(kCGDirectMainDisplay);
}
