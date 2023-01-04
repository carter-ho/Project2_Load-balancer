#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <queue>
using std::cin, std::cout, std::endl, std::string;

int main(){


    //int numServers = 50;
    int numServers;
	cout << "Input number of servers: "; // Type a number and press enter
    cin >> numServers; // Get user input from the keyboard
    cout << "Number of servers is: " << numServers << endl; // Display the input value

	/*
	for(int i = 0; i < numServers; i++){
		
		//Initialize Server
		
	}
	*/

    //int timesRun = 20;
	int timesRun;
	cout << "Input the time you want to run the load balancer : "; // Type a number and press enter
    cin >> timesRun; // Get user input from the keyboard
    cout << "The time you want to run the load balancer is: " << timesRun << endl; // Display the input value

	int fullQueue = numServers * 20;
	
	cout << "The Full Queue is "<< fullQueue << endl;

    return 0;
}