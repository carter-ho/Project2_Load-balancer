#include "webserver.h"

Webserver::Webserver(){
    isAvailable = true;
}

void Webserver::processRequests(){
    isAvailable = false;
    // Do thing
    isAvailable = true;
}