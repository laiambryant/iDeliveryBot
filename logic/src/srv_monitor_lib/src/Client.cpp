#include "../include/srv_monitor_lib/Client.h"

Client::Client(){
    _cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(_cli_fd<0){
        perror("Socket");
        exit(-1);
    }
    srv_sock_init(DEFAULT_PORT);
    if(connect(_cli_fd, (const struct sockaddr*)&_srv_sock_addr, (sizeof(_srv_sock_addr)))<0){
        perror("Connect");
        exit(-1);
    }
}

void Client::srv_sock_init(int port){
    _srv_sock_addr = sockaddr_in();
    _srv_sock_addr.sin_family = AF_INET;
    _srv_sock_addr.sin_port = htons(port);
    _srv_sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

Client::Client(int port){
    _cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    srv_sock_init(port);
    connect(_cli_fd, (const struct sockaddr*)&_srv_sock_addr, (sizeof(_srv_sock_addr)));
}

Client::~Client(){
    
}

string Client::monitor_read(){
    char* _in_string = new char[BUF_SIZE];
    bzero(_in_string, BUF_SIZE);
    int recieved, total_size = 0;
    int size_recv; bzero(_in_string , BUF_SIZE);
    //NOTE: recv function on OSX does not support flag MSG_WAITFORONE. Only works on linux > 2.6.3
    #ifdef __linux__
    size_recv = recv(_cli_fd, &_in_string[total_size], BUF_SIZE, MSG_WAITFORONE);
    #elif __APPLE__
    size_recv = recv(_cli_fd, &_in_string[total_size], BUF_SIZE, 0x10000);
    #endif
    return _in_string;
}

int Client::monitor_write(string msg){
    int ret = send(_cli_fd, msg.data(), msg.size(), 0);
    if(ret<0){
        perror("Send:");
        exit(EXIT_FAILURE);
    } 
    return ret;
}
   