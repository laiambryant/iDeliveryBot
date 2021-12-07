#include "../srv_monitor.h"

int main(int argc, char const *argv[])
{
    std::cerr<< "Testing monitor..." <<endl;

    srv_monitor monitor = srv_monitor();
    monitor.monitor_metadata(cerr);
    monitor.send_msg("HELLO", login);
    std::cerr << "[Server]: " << monitor.get_msg() << endl;

    return 0;
}
