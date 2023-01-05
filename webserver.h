#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

class Webserver
{
public:
    Webserver();
    void processRequests(Request r);
    
private:
    int timeLeft;

};

#endif