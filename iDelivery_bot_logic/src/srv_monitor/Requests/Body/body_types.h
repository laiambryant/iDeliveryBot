#pragma once

#include <iostream>
#include <list>

#include "str_utils.h"

#ifndef OUT_MODE
#define OUT_MODE
enum out_mode{
    cerr_out, cout_out, log_out
};
#endif

using namespace std;

class generic_body{
private:
    string _body_str;
public:
    generic_body(string body_str_):_body_str(body_str_){};
    virtual void parse();
    virtual void print(out_mode out){
        switch(out){
            case cerr_out:
                cerr << _body_str << endl;
                break;
            case cout_out:
                cout << _body_str << endl;
                break;
            case log_out:
                break;
        }
    };

};

class login_body:public generic_body{
private:
    string _body_str;
    string _username;
    string _password;

public:
    login_body(string body_str_):generic_body(body_str_),_body_str(body_str_), _username(""), _password(""){parse();};
    void parse();
    void print(out_mode out){
        switch(out){
            case cerr_out:
                cerr << _body_str << endl;
                cerr << "Username:\t" << _username << endl;
                cerr << "Password:\t" << _password << endl;
                break;
            case cout_out:
                cout << _body_str << endl;
                cout << "Username:\t" << _username << endl;
                cout << "Password:\t" << _password << endl;
                break;
            case log_out:
                break;
        }
    }

};

class call_body:public generic_body{
private:
    string _body_str;
    array<float,3> _coordinates; // [x, y, z]
    int _robot_id;
public:
    call_body(string body_str_):generic_body(body_str_),_body_str(body_str_), _coordinates({1.0,1.0,1.0}), _robot_id(0){}; 
    void parse();
    void print(out_mode out){
        switch(out){
            case cerr_out:
                cerr << _body_str << endl;
                cerr << "Robot_id:\t" << _robot_id << endl;
                cerr << "X:\t\t" << _coordinates[0]<<endl;
                cerr << "Y:\t\t" << _coordinates[1] <<endl;
                cerr << "Z:\t\t" << _coordinates[2] <<endl;
                break;
            case cout_out:
                cout << _body_str << endl;
                cout << "Robot_id:\t" << _robot_id << endl;
                cout << "X:\t\t" << _coordinates.front()<<endl;
                cout << "Y:\t\t" << _coordinates.front() <<endl;
                cout << "Z:\t\t" << _coordinates.front() <<endl;
                break;
            case log_out:
                break;
        }
    }

};

class priority_call_body:public call_body{
private:
    string _body_str;
    list<float> _coordinates; // [x, y, z]
    int _robot_id;
public:
    priority_call_body(string body_str_):call_body(body_str_),_body_str(body_str_){};
    
};

class arrived_body:public generic_body{
private:
    int _robot_id;
    string _body_str;

public:
    arrived_body(string body_str_):generic_body(body_str_),_body_str(body_str_), _robot_id(0){};
    void parse();

};

class obj_sent_body:public generic_body{
private:
    string _body_str;
    int _robot_id;

public:
    obj_sent_body(string body_str_):generic_body(body_str_),_body_str(body_str_), _robot_id(0){};
    void parse();

};

class obj_rcvd_body:public generic_body{
private:
    string _body_str;
    int _robot_id;

public:
    obj_rcvd_body(string body_str_):generic_body(body_str_),_body_str(body_str_), _robot_id(0){};
    void parse();

};

class cancel_body:public generic_body{
private:
    string _body_str;
    int _robot_id;

public:
    cancel_body(string body_str_):generic_body(body_str_),_body_str(body_str_), _robot_id(0){};
    void parse();

};

class timeout_body:public generic_body{
private:
    string _body_str;

public:
    timeout_body(string body_str_):generic_body(body_str_){};
    void parse();

};

class invalid_body:public generic_body{
private:
    string _body_str;

public:
    invalid_body(string body_str_):generic_body(body_str_){};
    void parse();

};
/*
class _body:generic_body{
private:

public:
*/