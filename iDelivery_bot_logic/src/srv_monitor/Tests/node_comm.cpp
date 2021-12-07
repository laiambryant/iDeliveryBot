#include "../Communication/Client.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Client cli = Client();
    string str = "Hello everyone W.D. Gaster here";
    
    cli.monitor_write(str);

    std::cerr << "[Read]: " << (cli.monitor_read()) <<std::endl;

    return 0;
}
