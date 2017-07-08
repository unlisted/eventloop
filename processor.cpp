#include <chrono>
#include <thread>
#include "processor.h"

namespace eventloop {

Processor::Processor() {
    _q.push(Event("test"));
    _q.push(Event("foo"));
    _q.push(Event("bar"));

    Run();

}

void Processor::Run() {
    _isRunning = true;

    while(_isRunning) {
        if (!_q.empty()) {
            auto evt = _q.front();
            evt();
            _q.pop();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

}

