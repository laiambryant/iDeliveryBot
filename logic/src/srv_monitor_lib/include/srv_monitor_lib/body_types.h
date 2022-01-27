#pragma once

#include <iostream>
#include <array>

#include "str_utils.h"

using namespace std;
using coordinates_3D = array<float,3>;

//generic body, does not contain any significant fields 
class generic_body{
protected:
    string _body_str;
    
public:
//CTORS--------------------------------------------------------------------------------------------------

    generic_body(){_body_str ="";}
    generic_body(string body_str_):_body_str(body_str_){};

//FUNCS--------------------------------------------------------------------------------------------------

    //Parses body 
    virtual void parse();
    //Prints metadata on stream 
    virtual void print(ostream &stream){
        stream << _body_str << endl;
    }

//GETTERS------------------------------------------------------------------------------------------------
    
    virtual string get_username(){return "";};
    virtual string get_password(){return "";};
    virtual coordinates_3D get_coords(){return {0.0,0.0,0.0};};
    virtual int get_robot_id(){return 0;};

};

//body for requests containing a robot id 
class r_id_body:public generic_body{
protected:
    int _robot_id;
public:
//CTORS--------------------------------------------------------------------------------------------------

    r_id_body(string body_str_):generic_body(body_str_),_robot_id(0){parse();}
    
//FUNCS--------------------------------------------------------------------------------------------------
    
    //Parses body 
    void parse() override;
    //Prints metadata on stream 
    void print(ostream &stream) override {
        stream << _body_str << endl;
        stream << "Robot_id:\t" << _robot_id << endl;
    }

//GETTERS------------------------------------------------------------------------------------------------

    int get_robot_id() override {return _robot_id;}
};

//body for requests containing a robot id and coordinates (for robot or user depending on type)
class coord_body:public r_id_body{
protected:
    coordinates_3D _coordinates; // [x, y, z]
public:
//CTORS--------------------------------------------------------------------------------------------------

    coord_body(string body_str_):r_id_body(body_str_),_coordinates({0.0,0.0,0.0}){parse();}
    
//FUNCS--------------------------------------------------------------------------------------------------

    //Parses body    
    void parse() override;
    //Prints metadata on stream 
    void print(ostream &stream) override {
        stream << _body_str << endl;
        stream << "Robot_id:\t" << _robot_id << endl;
        stream << "X:\t\t" << _coordinates[0]<<endl;
        stream << "Y:\t\t" << _coordinates[1] <<endl;
        stream << "Z:\t\t" << _coordinates[2] <<endl;
    }

//GETTERS------------------------------------------------------------------------------------------------

    coordinates_3D get_coords() override {return _coordinates;}

//SETTERS------------------------------------------------------------------------------------------------

    void set_coords(float x, float y, float z){
        _coordinates[0]=x;_coordinates[1]=y;_coordinates[2]=z; 
    }

};

class login_body:public generic_body{
private:
    string _username;
    string _password;
    coordinates_3D _coordinates; // [x, y, z]

public:
//CTORS--------------------------------------------------------------------------------------------------

    login_body(string body_str_):generic_body(body_str_), _username(""), _password(""),_coordinates({0.0,0.0,0.0}){parse();}
    
//FUNCS--------------------------------------------------------------------------------------------------
    
    //Parses body    
    void parse() override;

    //Prints metadata on stream 
    void print(ostream &stream)override {
        stream << _body_str << endl;
        stream << "Username:\t" << _username << endl;
        stream << "Password:\t" << _password << endl;
        stream << "X:\t\t" << _coordinates[0]<<endl;
        stream << "Y:\t\t" << _coordinates[1] <<endl;
        stream << "Z:\t\t" << _coordinates[2] <<endl;
    }
    
//GETTERS------------------------------------------------------------------------------------------------

    string get_username() override {return _username;}
    string get_password() override {return _password;}
    coordinates_3D get_coords() override {return _coordinates;}
    
//SETTERS------------------------------------------------------------------------------------------------

    void set_coords(float x, float y, float z){_coordinates[0]=x;_coordinates[1]=y;_coordinates[2]=z; }
};


class call_body:public coord_body{
public:
//CTORS--------------------------------------------------------------------------------------------------

    call_body(string body_str_):coord_body(body_str_){}; 
};

class priority_call_body:public coord_body{
public:
//CTORS--------------------------------------------------------------------------------------------------

    priority_call_body(string body_str_):coord_body(body_str_){};
};

class arrived_body:public coord_body{
public:
//CTORS--------------------------------------------------------------------------------------------------

    arrived_body(string body_str_):coord_body(body_str_){};
};

class obj_sent_body:public r_id_body{
public:
//CTORS--------------------------------------------------------------------------------------------------

    obj_sent_body(string body_str_):r_id_body(body_str_){};
};

class obj_rcvd_body:public r_id_body{
public:
//CTORS--------------------------------------------------------------------------------------------------

    obj_rcvd_body(string body_str_):r_id_body(body_str_){};
};

class cancel_body:public r_id_body{
public:
//CTORS--------------------------------------------------------------------------------------------------

    cancel_body(string body_str_):r_id_body(body_str_){};
};

class timeout_body:public r_id_body{
public:
//CTORS--------------------------------------------------------------------------------------------------

    timeout_body(string body_str_):r_id_body(body_str_){};
};

class invalid_body:public generic_body{
public:    
//CTORS--------------------------------------------------------------------------------------------------

    invalid_body(string body_str_):generic_body(body_str_){};
};    