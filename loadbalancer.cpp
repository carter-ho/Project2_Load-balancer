#include <iostream>
#include <random>
#include "loadbalancer.h"

using namespace std;

Loadbalancer::Loadbalancer(int queue_size, int max_time, float probability){
    
	// Initializes a Loadbalancer with all of its parameterized attributes and created all requests to add to the queue
	max_cycles = max_time;
    new_request_probability = probability;
    for(int i = 0; i < queue_size; i++){
        Request r;
        request_queue.push(r);
    }
}

Request Loadbalancer::getRequest(){
	
	// Stores and pops the request at the front of the queue
    Request r = request_queue.front();
    request_queue.pop();
    return r;
}

bool Loadbalancer::isNotEmpty()
{
	// Returns whether the queue is empty or not
    if(request_queue.empty())
    {
        return false;
    } 
    return true;
}

bool Loadbalancer::addRequest(){
    
	// Creates a random number to test against probability threshold
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_num = dis(gen);

	// Determines if random number meets probability threshold and adds a new request if threshold is met
    if(random_num > (100 - new_request_probability)){
        Request f;
        request_queue.push(f);
        return true;
    }
    return false;
}