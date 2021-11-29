#include "srv_monitor.h"


int main(int argc, char const *argv[])
{
    std::cerr<< "Testing monitor..." <<endl;

    srv_monitor monitor = srv_monitor();
    monitor.monitor_metadata(log_out);

    return 0;
}
