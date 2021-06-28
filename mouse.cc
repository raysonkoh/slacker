#include "mouse.h"

CGPoint *get_current_mouse_location() {
  CGEventRef event = CGEventCreate(NULL);
  CGPoint cursor = CGEventGetLocation(event);
  CGPoint *res = new CGPoint(cursor);
  return res;
}

void move_mouse(CGPoint *p, size_t maxHeight, size_t maxWidth) {
  CGPoint p2;
  p2.x = p->x + 1.0, p2.y = p->y + 1.0;

  if (p2.x >= maxWidth)
    p2.x -= maxWidth;
  if (p2.y >= maxHeight)
    p2.y -= maxHeight;

  // note: right-click is ignored, thus it is safe
  CGEventRef mouseMoveEvent = CGEventCreateMouseEvent(NULL, kCGEventMouseMoved, p2, kCGMouseButtonRight);
  CGEventPost(kCGHIDEventTap, mouseMoveEvent);
  CFRelease(mouseMoveEvent);

  // CGDisplayMoveCursorToPoint(kCGDirectMainDisplay, p2);
  // CGDisplayShowCursor(kCGDirectMainDisplay);
}
