#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ros/ros.h>

#include "body_types.h"

using namespace std;

static string my_substr(string original, string start, string end){
    int start_idx= original.find(start)+start.length();
    int end_idx = original.find_last_of(end);
    return original.substr(start_idx, end_idx-start_idx);
}

//Checks if user data is correct, returns "desk" position <x:float, y:float, z:float>
static array<float,3> csv_login(string username, string password){
    ifstream pw_csv; pw_csv.open("users.csv", ios::in);
    vector<string> row; string line="", word, temp; bool found=false;
    int l_n = 0;
    
    if(pw_csv.fail()){
        perror("Open");
        exit(EXIT_FAILURE);
    }
    while(pw_csv.good()){
        row.clear();
        getline(pw_csv, line);
        stringstream s(line);

        while (getline(s, word, ',')) {
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
        l_n++;
        if(username == row.at(0)&& password == row.at(1)){
            cerr << "Found" << endl;
            found = true;
            break;
        }
    }   

    if(!found)return array<float,3> ();
    else {
        array<float,3> ret;
        ret[0]=stof(row.at(2));
        ret[1]=stof(row.at(3));
        ret[2]=stof(row.at(4));
        return ret;
    }

}  