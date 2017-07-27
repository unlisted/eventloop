#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>

namespace eventloop {

template<typename T>
class SynchQueue {
public:

private:
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cv;

};


}
