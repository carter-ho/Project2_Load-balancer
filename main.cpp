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


int main(){

	int num_webservers;
	int num_requests = num_webservers * 20;
	int num_clock_cycles;
	float new_request_probability;
	vector<Webserver> webservers;

    //int numServers = 50;
    int numServers;
	cout << "Input number of servers: "; // Type a number and press enter
    cin >> numServers; // Get user input from the keyboard
    cout << "Number of servers is: " << numServers << endl; // Display the input value

	for(int i = 0; i < num_webservers; i++){
		
	}

    //int timesRun = 20;
	int timesRun;
	cout << "Input the time you want to run the load balancer : "; // Type a number and press enter
    cin >> timesRun; // Get user input from the keyboard
    cout << "The time you want to run the load balancer is: " << timesRun << endl; // Display the input value


	Loadbalancer l(num_requests, num_clock_cycles, new_request_probability);


	for(int i = 0; i < num_clock_cycles; i++){
		for(auto server : webservers){
			if(server.)
        	server.processRequests(l.getRequest());
    }
	}

    return 0;
}