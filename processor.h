#pragma once

#include <queue>
#include "event.h"

namespace  eventloop {

class Processor {
public:
    Processor();
    void Run();

private:
    std::queue<Event> _q;
    bool _isRunning = false;
};

}
