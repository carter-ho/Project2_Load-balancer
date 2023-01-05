#include <iostream>
#include <random>
#include "loadbalancer.h"

using namespace std;

Loadbalancer::Loadbalancer(int queue_size, int max_time, float probability){
    max_cycles = max_time;
    new_request_probability = probability;
    for(int i = 0; i < queue_size; i++){
        Request r;
        request_queue.push(r);
    }
}

Request Loadbalancer::getRequest(){
    Request r = request_queue.front();
    request_queue.pop();
    return r;
}

bool Loadbalancer::isNotEmpty()
{ 
    if(request_queue.empty())
    {
        return false;
    } 
    return true;
}

void Loadbalancer::addRequest(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_num = dis(gen);

    if(random_num > (100 - new_request_probability)){
        Request f;
        request_queue.push(f);
    }
}