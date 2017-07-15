#include "event.h"
#include "scheduler.h"

namespace eventloop {
    Scheduler::Scheduler(std::queue<Event> &q) : _q(q)
    {
    }

    void Scheduler::AddImmediate(const Event &evt) {
        _q.push(evt);
    }
}
