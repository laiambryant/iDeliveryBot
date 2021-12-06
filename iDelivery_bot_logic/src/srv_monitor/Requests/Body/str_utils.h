#pragma once
#include <iostream>

using namespace std;

static string my_substr(string original, string start, string end){
    int start_idx= original.find(start)+start.length();
    int end_idx = original.find_last_of(end);
    return original.substr(start_idx, end_idx-start_idx);
}