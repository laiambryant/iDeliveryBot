#include "../srv_monitor.h"


int main(int argc, char const *argv[])
{
    std::cerr<< "Testing monitor..." <<endl;

    srv_monitor monitor = srv_monitor();
    monitor.monitor_metadata(cerr);
    std::cerr << "[Server]: " << monitor.get_last_msg() << endl;

    return 0;
}
