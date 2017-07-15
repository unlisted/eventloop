#include "processor.h"
#include "scheduler.h"
#include "event.h"

using namespace std;
using namespace eventloop;

int main(int argc, char *argv[]) { 
    
    queue<Event> q;
    Processor p{q};
    Scheduler s{q};
    
    s.AddImmediate(Event {"test"});

    while(true) {
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    
    return 0; 
}
