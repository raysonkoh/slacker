#include "mouse.h"
#include <iostream>

int main() {
  CGPoint *p = get_current_mouse_location();
  std::cout << "x: " << p->x << " y: " << p->y << std::endl;
  delete p;
}