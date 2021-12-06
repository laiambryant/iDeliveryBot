#pragma once

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>

#define DEFAULT_PORT 6000

using std::string;

class Client{
private:
    int _cli_fd;
    sockaddr_in _srv_sock_addr;
    void srv_sock_init(int port);

public:
    Client();
    Client(int port);
    ~Client();
    string read();
    void write(string msg);

};

/*
Create a socket with the socket() system call
Connect the socket to the address of the server using the connect() system call
Send and receive data. There are a number of ways to do this, but the simplest is to use the read() and write() system calls.
*/
