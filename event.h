#pragma once

#include <chrono>
#include <string>

namespace eventloop {

class Event {
public:
  Event(const std::string &p);  
  void operator()();

private:
  std::chrono::system_clock::time_point _ts;
  std::string _payload;
};
}

