#include <condition_variable>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <thread>

#include <boost/log/trivial.hpp>

#include "event.h"
#include "processor.h"

namespace eventloop {
std::mutex mtx;
std::condition_variable cv;

Processor::Processor(SynchEventQueue &q) : _q(q) {
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
        // 1. lock the mutex
        // 2. wait on condition ()
        //   
        //if (!_q.empty()) {I#

        std::unique_lock<std::mutex> lk(mtx);

        BOOST_LOG_TRIVIAL(debug) << "Waiting on condition..";
        cv.wait(lk);

        BOOST_LOG_TRIVIAL(debug) << "Locking mutex..";
        auto evt = _q.front();
        evt();
        _q.pop();
        //}

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

Processor::~Processor() {
    _t.join();
}
}

