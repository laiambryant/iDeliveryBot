#include "../../Monitor_thread.h"

int main(int argc, char const *argv[]){
    
    Monitor_thread t = Monitor_thread();

    t.start();
    //t.join();

    return 0;
}
