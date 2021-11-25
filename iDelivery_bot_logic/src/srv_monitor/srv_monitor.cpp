#include "srv_monitor.h"

srv_monitor::srv_monitor(){
    
    out_pipe_fd_ = mkfifo(OUT_PIPE_PATH, O_WRONLY);
    in_pipe_fd_ = mkfifo(IN_PIPE_PATH, O_RDONLY);
    if((out_pipe_fd_ == -1) || (in_pipe_fd_ == -1)){
        perror("srv_monitor::srv_monitor(): ");
    }
}

srv_monitor::~srv_monitor(){
    if(close(in_pipe_fd_)==-1 || close(out_pipe_fd_)==-1){
        perror("srv_monitor::~srv_monitor()-CLOSE: ");
    }
    if(unlink(IN_PIPE_PATH)==-1 || unlink(OUT_PIPE_PATH)==-1){
        perror("srv_monitor::~srv_monitor()-UNLINK: ");
    }
}

bool srv_monitor::write_to_pipe(char* msg){
    if(write(out_pipe_fd_, msg, sizeof(msg))==-1){
        perror("srv_monitor::write_to_pipe(char* msg): ");
    }
}

bool srv_monitor::read_from_pipe(){
    if(read(in_pipe_fd_, msg_buf_, MSG_MAX_SIZE)==-1){
        perror("srv_monitor::read_from_pipe(): ");
        return false;
    } else {
        return true;
    }
}

char* srv_monitor::get_last_msg(){
    return *msg_buf_;
}


void srv_monitor::monitor_metadata(out_mode out_mode_){
    std::fstream file; 
    switch (out_mode_){
    case log_out:
        file.open(LOG_PATH);
        file << "Out_pipe_fd: [" << out_pipe_fd_ << "] Out_pipe_path:[" << OUT_PIPE_PATH << "]"<<endl;
        file << "In_pipe_fd: [" << in_pipe_fd_ << "] In_pipe_path:[" << IN_PIPE_PATH << "]"<<endl;   
        file << "MSG_Buffer content: [" << msg_buf_ << "]" <<endl;     
        file.close();
        break;

    case cerr_out:
        cerr << "Out_pipe_fd: [" << out_pipe_fd_ << "] Out_pipe_path:[" << OUT_PIPE_PATH << "]"<<endl;
        cerr << "In_pipe_fd: [" << in_pipe_fd_ << "] In_pipe_path:[" << IN_PIPE_PATH << "]"<<endl;   
        cerr << "MSG_Buffer content: [" << msg_buf_ << "]" <<endl;     
        break;
    
    case cout_out:
        cout << "Out_pipe_fd: [" << out_pipe_fd_ << "] Out_pipe_path:[" << OUT_PIPE_PATH << "]"<<endl;
        cout << "In_pipe_fd: [" << in_pipe_fd_ << "] In_pipe_path:[" << IN_PIPE_PATH << "]"<<endl;   
        cout << "MSG_Buffer content: [" << msg_buf_ << "]" <<endl;
        break;
    }
}
