#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request
{
public:
    Request();
    std::string getIPin() {return ip_in; }
    std::string getIPout() {return ip_out; }
    int getTime() {return time; }

private:
    std::string generate_ipv4_address();
    std::string ip_in;
    std::string ip_out;
    int time; 
};

#endif