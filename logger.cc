#include "logger.h"

void log(std::string s) {
  auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  auto now_string = std::string(std::ctime(&now));
  now_string = now_string.substr(0, now_string.length() - 1);
  std::cout << "[" << now_string << "]: " << s << std::endl;
}
