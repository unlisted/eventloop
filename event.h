#pragma once

#include <chrono>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>

#include "synch_queue.h"

namespace eventloop {
class Event;
using SynchEventQueue = SynchQueue<Event>;

class Event {
public:
  Event(const std::string &p);  
  void operator()();

private:
  std::chrono::system_clock::time_point _ts;
  std::string _payload;
};

}

