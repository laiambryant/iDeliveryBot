#include "srv_monitor/srv_monitor.h"

#include <unistd.h>
#include <thread>

class Monitor_thread{
private:
    srv_monitor _monitor;
    req_parser _parser;

public:
    Monitor_thread():_monitor(srv_monitor()), _parser(req_parser()){
    }
    void monitor_act(int seconds);
    void start();
    //void join();

};