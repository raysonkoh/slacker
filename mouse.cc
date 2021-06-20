#include "mouse.h"

CGPoint *get_current_mouse_location() {
  CGEventRef event = CGEventCreate(NULL);
  CGPoint cursor = CGEventGetLocation(event);
  CGPoint *res = new CGPoint(cursor);
  return res;
}
