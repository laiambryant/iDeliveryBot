#include "srv_monitor.h"

srv_monitor::srv_monitor(){

    msg_factory = message_creator();
    out_stream_.open(OUT_PATH, fstream::out);

    if(out_stream_.fail()){
        perror("srv_monitor::srv_monitor()");
        exit(EXIT_FAILURE);
    }

    in_stream_.open(IN_PATH, fstream::in);
    while(in_stream_.fail()){   
        in_stream_.open(IN_PATH, fstream::in);
    }

}

srv_monitor::~srv_monitor(){
    in_stream_.close(); out_stream_.close();
    if(in_stream_.fail() || out_stream_.fail()){
        perror("srv_monitor::~srv_monitor()-CLOSE ");
        //exit(EXIT_FAILURE);
    }
}

srv_monitor::srv_monitor(const srv_monitor &other){
 
}

bool srv_monitor::write_to_fstream(string msg, msg_type type){
    if(out_stream_.is_open()){
        out_stream_ << msg_factory.create(msg, type) <<endl;
        if(out_stream_.fail()){
            perror("srv_monitor::write_to_socket(char* msg)");
            return false;
        } else return true;
    }
    return true;
}

bool srv_monitor::read_from_fstream(){
    if(in_stream_.is_open()){
        while(!in_stream_.eof()){
            getline(in_stream_, msg_buf_);
        }
        if(in_stream_.fail()){
            perror("srv_monitor::read_from_fstream()");
            return false;
        } else return true;
    }
}

string srv_monitor::get_last_msg(){
    string ret;
    if(in_stream_.is_open()){
        if(!in_stream_.eof()){
            getline(in_stream_, ret);
        }
        if(in_stream_.fail()){
            perror("srv_monitor::read_from_fstream()");
            return "";
        } else return ret;
    }
}


void srv_monitor::monitor_metadata(ostream &stream){
    stream << "Out_pipe_fd: ["  << "] out_socket_port:["  << "]"<<endl;
    stream << "In_pipe_fd: ["  << "] in_socket_port:["  << "]"<<endl;  
    stream << "MSG_Buffer content: [" << msg_buf_ << "]" <<endl;     
}
