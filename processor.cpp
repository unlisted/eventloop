#include <chrono>
#include <iostream>
#include <thread>
#include "event.h"
#include "processor.h"

namespace eventloop {

Processor::Processor(std::queue<Event> &q) : _q(q) {
    Run();
    _t = std::thread(&Processor::DoLoop, this);
}

void Processor::Run() {
    _isRunning = true;
}

void Processor::Stop() {
    _isRunning = false;
}

void Processor::DoLoop() {
    while(_isRunning) {
        std::cout << "q size: " << _q.size() << std::endl;
        if (!_q.empty()) {
            auto evt = _q.front();
            evt();
            _q.pop();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

Processor::~Processor() {
    _t.join();
}
}

