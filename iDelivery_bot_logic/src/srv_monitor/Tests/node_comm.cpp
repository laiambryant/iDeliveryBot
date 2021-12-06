#include "../Communication/Client.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Client cli = Client();
    std::cerr << cli.read() << std::endl;
    cli.write("HELLO");
    return 0;
}
