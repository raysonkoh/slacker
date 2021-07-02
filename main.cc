#include "activity.h"
#include "display.h"
#include "logger.h"
#include "mouse.h"
#include <chrono>
#include <iostream>
#include <thread>

size_t maxHeight, maxWidth;
int TIMEOUT = 60 * 2; // 2mins, update here for interval between mouse_move

CGPoint *p;

int main() {
  maxHeight = get_display_height();
  maxWidth = get_display_width();

  log("maxHeight: " + std::to_string(maxHeight) + " maxWidth: " + std::to_string(maxWidth));

  while (true) {
    while (get_user_idle_time() < TIMEOUT) {
      std::this_thread::sleep_for(std::chrono::seconds(TIMEOUT / 2));
    }
    log("idleTime: " + std::to_string(get_user_idle_time()) + "s");

    p = get_current_mouse_location();
    log("from: (" + std::to_string(p->x) + ", " + std::to_string(p->y) + ")");
    move_mouse(p, maxHeight, maxWidth);
    delete p;

    p = get_current_mouse_location();
    log("to: (" + std::to_string(p->x) + ", " + std::to_string(p->y) + ")");
    delete p;

    std::this_thread::sleep_for(std::chrono::seconds(TIMEOUT));
  }
}
