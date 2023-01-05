#include "loadbalancer.h"

Loadbalancer::Loadbalancer(int queue_size, int max_time){
    max_cycles = max_time;
    for(int i =0; i < queue_size; i++){
        Request r;
        webserver_queue.push(r);
    }
}

Request Loadbalancer::getRequest(){
    Request r = webserver_queue.front();
    webserver_queue.pop();
    return r;
}