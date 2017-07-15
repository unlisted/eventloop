#pragma once

#include <queue>
#include <thread>

namespace  eventloop {
class Event;

class Processor {
public:
    Processor(std::queue<Event> &q);
    void Run();
    void Stop();

    ~Processor();

private:
    std::queue<Event> &_q;
    std::thread _t;
    bool _isRunning = false;

    void DoLoop();
};

}
