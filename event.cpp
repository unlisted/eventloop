#include "event.h"
#include <iostream>

namespace eventloop {

std::string asString(const std::chrono::system_clock::time_point &tp) {
  // convert to system time:
  std::time_t t = std::chrono::system_clock::to_time_t(tp);
  std::string ts = std::ctime(&t); // convert to calendar time
  ts.resize(ts.size() - 1);        // skip trailing newline
  return ts;
}

Event::Event(const std::string &p) : _payload(p) {
    _ts = std::chrono::system_clock::now();
}

void Event::operator()() {
    std::cout << asString(_ts) << ": " << _payload <<  std::endl;
}

}
