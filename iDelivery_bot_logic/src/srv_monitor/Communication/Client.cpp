#include "Client.h"

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

std::string Client::read(){
    return "OLLARE";
}

void Client::write(string msg){
    send(_cli_fd, &msg, sizeof(msg), 0);
}
   