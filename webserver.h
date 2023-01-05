#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include "request.h"

/**
 * @brief Object that processes Request objects
 * 
 */
class Webserver
{
public:
    Webserver(char n);
    /**
     * @brief Get the status of the webserver
     * 
     * @return true 
     * @return false 
     */
    bool getStatus() {return isAvailable;}
    /**
     * @brief Get the name of the webserver
     * 
     * @return char 
     */
    char getName(){return name;}
    void takeRequest(Request r, int t);
    /**
     * @brief Get the request currently being processed by the webserver
     * 
     * @return Request 
     */
    Request getCurrentRequest(){return current_request;}
    void update(int current_time);
    
private:
    Request current_request;
    int init_time;
    bool isAvailable;
    char name;

};

#endif