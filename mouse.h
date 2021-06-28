#ifndef MOUSE_H
#define MOUSE_H

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>

CGPoint *get_current_mouse_location();

void move_mouse(CGPoint* p, size_t maxHeight, size_t maxWidth);

#endif
