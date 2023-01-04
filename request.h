#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request
{
public:
    Request();
    std::string ip_in;
    std::string ip_out;
    int time; 
private:
};

#endif