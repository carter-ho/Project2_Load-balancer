#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include <queue>
#include "request.h"

class Loadbalancer
{
public:
    Loadbalancer(int queue_size, int max_time);
    Request getRequest();
private:
    std::queue<Request> webserver_queue;
    int current_cycle = 0;
    int max_cycles;
};


#endif