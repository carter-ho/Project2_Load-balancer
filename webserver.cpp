#include <iostream>
#include "webserver.h"

using namespace std;

Webserver::Webserver(char n){
    name = n;
    isAvailable = true;
}



void Webserver::takeRequest(Request r, int init_t){
	current_request = r;
	init_time = init_t;
    isAvailable = false;
}

void Webserver::update(int current_time){
    int p = current_time - init_time;
    if(p == current_request.getTime()){
        isAvailable = true;
        cout << "Server " << name << " has completed a request from " << current_request.getIPin() << " to " << current_request.getIPout() << " taking " << current_request.getTime() << " cycles" << endl;
    }
}