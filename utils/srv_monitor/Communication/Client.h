#pragma once

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <strings.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 5000
#define BUF_SIZE 450
#define DOCKER_IP_ADDR "0.0.0.0"
#define LOCALHOST_IP_ADDR "127.0.0.1"
#define ALT_DOCKER_IP_ADDR "172.17.0.1"

using std::string;
using std::cerr;
using std::endl;

class Client{
private:
    int _cli_fd;
    sockaddr_in _srv_sock_addr;
    void srv_sock_init(int port);

public:
    Client();
    Client(int port);
    ~Client();
    string monitor_read();
    int monitor_write(string msg);

};

