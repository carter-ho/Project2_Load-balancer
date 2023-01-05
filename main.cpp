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

	int num_servers = 5;
	int num_clock_cycles = 10000;
	float new_request_probability = 10;
	vector<Webserver> webservers;
	const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	/*
	cout << "Input number of servers: "; // Type a number and press enter
    cin >> num_servers; // Get user input from the keyboard
    cout << "Number of servers is: " << num_servers << endl; // Display the input value
*/

	for(int i = 0; i < num_servers; i++){
		char c = alphabet.at(i);
		Webserver w(c);
		webservers.push_back(w);
	}

	int num_requests = num_servers * 20;

	/*
	cout << "Input the time you want to run the load balancer : "; // Type a number and press enter
    cin >> num_clock_cycles; // Get user input from the keyboard
    cout << "The time you want to run the load balancer is: " << num_clock_cycles << endl; // Display the input value
*/

	Loadbalancer l(num_requests, num_clock_cycles, new_request_probability);

	for(int i = 0; i < num_clock_cycles; i++){
		for(int j = 0; j < num_servers; j++){
			if(webservers[j].getStatus()){
				if(l.isNotEmpty()) {
					webservers[j].takeRequest(l.getRequest(), i);
				}
			}
			webservers[j].update(i);
			l.addRequest();
    	}
	}

    return 0;
}