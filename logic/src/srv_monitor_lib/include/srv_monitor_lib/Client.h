#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <strings.h>
#include <ros/ros.h>
#include <vector>
#include <unistd.h>

#define DEFAULT_PORT 5000
#define BUF_SIZE 450

using std::string;
using std::cerr;
using std::endl;
using std::vector;

class Client{
private:
    int _cli_fd;
    sockaddr_in _srv_sock_addr;

//FUNCS--------------------------------------------------------------------------------------------------

    //Initializes serversocket
    void srv_sock_init(int port);

public:
//CTORS--------------------------------------------------------------------------------------------------

    //Default ctor
    Client();
    //Ctor to bind client to specific port
    Client(int port);
    ~Client();

//FUNCS--------------------------------------------------------------------------------------------------

    //Reads from monitor
    string monitor_read();

    //Writes message on monitor
    int monitor_write(string msg);

};

