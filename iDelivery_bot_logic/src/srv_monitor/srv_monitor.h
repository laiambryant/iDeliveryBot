#include <iostream>
#include <fstream>

#include "message_creator.h"
#ifndef LOG_PATH
#define LOG_PATH "products/log.txt"
#endif
#define OUT_PATH "products/out.txt"
#define IN_PATH "products/in.txt"
#define MSG_MAX_SIZE 500

using namespace std;
#ifndef OUT_MODE
#define OUT_MODE
enum out_mode{
    cerr_out, cout_out, log_out
};
#endif
//Monitor creates two streams: one to read one to write
class srv_monitor{

private:
    ofstream out_stream_;
    ifstream in_stream_;
    string msg_buf_;
    message_creator msg_factory;

    void clear_msg_buff();
     
public:
    srv_monitor();
    ~srv_monitor();
    srv_monitor(const srv_monitor &other);
    bool write_to_fstream(string msg, msg_type type); //bool write_to_sock(char* msg); 
    bool read_from_fstream(); //bool read_from_sock();
    string get_last_msg();  //gets last msg from input_stream
    void monitor_metadata(out_mode out_mode_);

};
