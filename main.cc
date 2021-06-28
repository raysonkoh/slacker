#include "activity.h"
#include "display.h"
#include "mouse.h"
#include <chrono>
#include <iostream>
#include <thread>

size_t maxHeight, maxWidth;
int TEN_MINUTE = 60 * 10;

void printPoint(CGPoint *p) {
  std::cout << "x: " << p->x << " y: " << p->y << std::endl;
}

int main() {
  maxHeight = get_display_height();
  maxWidth = get_display_width();
  std::cout << "maxHeight: " << maxHeight << " maxWidth: " << maxWidth << std::endl;

  while (true) {
    auto idleTime = get_user_idle_time();
    std::cout << "idleTime: " << idleTime << std::endl;

    while (idleTime < TEN_MINUTE) {
      std::this_thread::sleep_for(std::chrono::minutes(10)); // update here for interval between mouse_move
      idleTime = get_user_idle_time();
      std::cout << "idleTime: " << idleTime << std::endl;
    }

    CGPoint *p = get_current_mouse_location();
    printPoint(p);
    move_mouse(p, maxHeight, maxWidth);
    delete p;

    p = get_current_mouse_location();
    printPoint(p);
    delete p;
  }
}
