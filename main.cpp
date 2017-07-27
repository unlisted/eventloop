#include "event.h"
#include "processor.h"
#include "scheduler.h"

using namespace std;
using namespace eventloop;

int main(int argc, char *argv[]) { 
    
    SynchEventQueue q1;
    queue<Event> q;
    Processor p{q1};
    Scheduler s{q};
    

    while(true) {
        s.AddImmediate(Event {"test"});
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    
    return 0; 
}
