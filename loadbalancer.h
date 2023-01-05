#ifndef LOADBALANCER_H
#define LOADBALANCER_H
    #include "request.h"
#include <queue>

class Loadbalancer
{
public:
    Loadbalancer();
private:
    std::queue<Request> webserver_queue;
};


#endif