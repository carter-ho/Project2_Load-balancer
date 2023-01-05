#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <vector>
#include <queue>

#include "webserver.h"
#include "loadbalancer.h"
#include "request.h"

using namespace std;

// Function that checks that status of all servers in order to determine if all requests are complete
bool allServersAvailable(vector<Webserver> s){
	for(int i = 0; i < s.size(); i++){
		if(s[i].getStatus() == false){
			return false;
		}
	}
	return true;
}

int main(){

	// initialize values
	int num_servers = 10;
	int num_clock_cycles = 10000;
	float new_request_probability = 1;
	vector<Webserver> webservers;
	// String to easily generate names for webservers, can support up to 52
	const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

	// Create and name webservers
	for(int i = 0; i < num_servers; i++){
		char c = alphabet.at(i);
		Webserver w(c);
		webservers.push_back(w);
	}

	int num_requests = num_servers * 20;

	// initialize Loadbalancer with parameters
	Loadbalancer l(num_requests, num_clock_cycles, new_request_probability);

	// keep track of new requests
	int requestsAdded = 0;
	// Main loop
	for(int i = 0; i < num_clock_cycles; i++){
		for(int j = 0; j < num_servers; j++){
			// Check if current webserver is available
			if(webservers[j].getStatus()){
				// Make sure queue is nonempty
				if(l.isNotEmpty()) {
					// Pass request from queue to webserver
					webservers[j].takeRequest(l.getRequest(), i);
				}

			}
			// Check webservers, see if request is complete
			webservers[j].update(i);
    	}
		// If queue and all webservers complete, exit early
		if(!l.isNotEmpty() && allServersAvailable(webservers)){
			cout << "Queue empty and all requests have been completed" << endl;
			break;
		}
		// Randomly add a new request, if new request added, increment tracker
		bool newRequest = l.addRequest();
		if(newRequest){
			requestsAdded += 1;
		}

	}
	// Output logs
	cout << "Process complete" << endl;
	cout << "Queue began with " << num_requests << " requests" << endl;
	cout << "Queue ended with " << l.queueSize() << " requests" << endl;
	cout << "Requests added to queue during process: " << requestsAdded << endl;
	cout << "Range for task times: [2, 500]" << endl;

    return 0;
}