#include "loadbalancer.h"

Loadbalancer::Loadbalancer(int queue_size, int max_time, float probability){
    max_cycles = max_time;
    new_request_probability = probability;
    for(int i =0; i < queue_size; i++){
        Request r;
        request_queue.push(r);
    }
}

Request Loadbalancer::getRequest(){
    Request r = request_queue.front();
    request_queue.pop();
    return r;
}