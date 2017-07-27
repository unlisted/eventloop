#pragma once

//#include <queue>
#include <thread>

#include "synch_queue.h"

namespace  eventloop {
class Event;

class Processor {
public:
    Processor(SynchEventQueue &q);
    void Run();
    void Stop();

    ~Processor();

private:
    SynchEventQueue &_q;
    std::thread _t;
    bool _isRunning = false;

    void DoLoop();
};

}
