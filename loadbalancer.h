#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include <queue>
#include "request.h"
#include "webserver.h"

/**
 * @brief Object that contains and controls the request queue
 * 
 */
class Loadbalancer
{
public:
    Loadbalancer(int queue_size, float probability);
    Request getRequest();
    bool isNotEmpty();
    bool addRequest();
    /**
     * @brief Returns the current size of the request queue
     * 
     * @return int 
     */
    int queueSize(){return request_queue.size(); }
private:
    std::queue<Request> request_queue;
    std::vector<Webserver> webservers;
    float new_request_probability;
};


#endif