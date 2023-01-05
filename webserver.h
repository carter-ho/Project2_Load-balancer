#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include "request.h"

class Webserver
{
public:
    Webserver(char n);
    bool getStatus() {return isAvailable;}
    char getName(){return name;}
    void takeRequest(Request r, int t);
    Request getCurrentRequest(){return current_request;}
    void update(int current_time);
    
private:
    Request current_request;
    int init_time;
    bool isAvailable;
    char name;

};

#endif