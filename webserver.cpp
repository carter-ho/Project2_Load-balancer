#include <iostream>
#include "webserver.h"

using namespace std;

/**
 * @brief Construct a new Webserver object
 * 
 * @param n A char value used to name and represent an individual webserver
 */
Webserver::Webserver(char n){
    name = n; // Assigns each webserver a letter value as an identifier
    isAvailable = true; // Each webserver is available to process a request when initialized
}

/**
 * @brief Function used to give a webserver a request and set it as unavailable to take more requests
 * 
 * @param r A request object
 * @param init_t The current time of the clock when the function is called
 */
void Webserver::takeRequest(Request r, int init_t){
	current_request = r;
	init_time = init_t;
    isAvailable = false; // Webserver status is set to busy when processing a request
}

/**
 * @brief Function that checks to see if a request has been completed. Outputs a completion message if true.
 * 
 * @param current_time The current time of the clock when the function is called
 */
void Webserver::update(int current_time){
    int p = current_time - init_time;
    if(p == current_request.getTime()){ // Checks to see if request has been fully processed
        isAvailable = true; // Webserver status is set to available once previous request has been fully process
        cout << "Server " << name << " has completed a request from " << current_request.getIPin() << " to " << current_request.getIPout() << " taking " << current_request.getTime() << " cycles" << endl;
    }
}