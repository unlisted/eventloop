#pragma once
#include <queue>

namespace eventloop {
class Event;

class Scheduler {
public:
    Scheduler(std::queue<Event> &q);
    void AddImmediate(const Event &evt);

private:
    std::queue<Event> &_q;
};
}
