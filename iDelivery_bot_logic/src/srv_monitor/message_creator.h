
#include <iostream>
using std::string;

class message_creator{
private:
    int _msg_no;
public:
    message_creator();
    ~message_creator();
    string create(string msg);
};