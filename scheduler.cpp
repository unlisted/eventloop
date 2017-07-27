#include <boost/log/trivial.hpp>

#include "event.h"
#include "scheduler.h"

namespace eventloop {
    Scheduler::Scheduler(std::queue<Event> &q) : _q(q)
    {
    }

    void Scheduler::AddImmediate(const Event &evt) {
        BOOST_LOG_TRIVIAL(debug) << "qeueu size: " << _q.size();
        _q.push(evt);
    }
}
