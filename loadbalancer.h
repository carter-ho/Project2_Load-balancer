#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include <queue>
#include "request.h"
#include "webserver.h"

class Loadbalancer
{
public:
    Loadbalancer(int queue_size, int max_time, float probability);
    Request getRequest();
    void update();
private:
    std::queue<Request> request_queue;
    std::vector<Webserver> webservers;
    int current_cycle = 0;
    int max_cycles;
    float new_request_probability;
};


#endif