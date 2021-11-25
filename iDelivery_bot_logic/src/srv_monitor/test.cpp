#include "srv_monitor.h"


int main(int argc, char const *argv[])
{
    std::cerr<< "Testing monitor..." <<endl;

    srv_monitor monitor = srv_monitor();
    monitor.write_to_pipe("HELLO PIPE\n");
    while(monitor.read_from_pipe() == false){
        
    }
    std::cerr << monitor.get_last_msg() << endl;

    return 0;
}
