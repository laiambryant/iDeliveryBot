#include <iostream>
#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define OUT_PIPE_PATH "../../products/srv_fifo"
#define IN_PIPE_PATH "../../products/cli_fifo"
#define LOG_PATH "../../products/log.txt"
#define MSG_MAX_SIZE 500

using std::cerr;
using std::endl;
using std::cout;

enum out_mode{
    cerr_out, cout_out, log_out
};

class srv_monitor{
private:
    int out_pipe_fd_;
    int in_pipe_fd_;
    char* msg_buf_[MSG_MAX_SIZE];
    void clear_msg_buff();
    
public:
    srv_monitor();
    ~srv_monitor();
    bool write_to_pipe(char* msg);
    bool read_from_pipe();
    char* get_last_msg();
    void monitor_metadata(out_mode out_mode_);
};
