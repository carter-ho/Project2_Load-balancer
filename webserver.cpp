#include "webserver.h"

Webserver::Webserver(){
    timeLeft = 0;
}



void Webserver::processRequests(Request r){
	
	timeLeft = r.getTime();
	
	while(timeLeft > 0){
		
		timeLeft--;
	}
	
}