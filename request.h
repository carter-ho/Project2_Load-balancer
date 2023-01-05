#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @brief Object that contains information regarding a request
 * 
 */
class Request
{
public:
    Request();
    /**
     * @brief Returns the source IP address of the request
     * 
     * @return std::string 
     */
    std::string getIPin() {return ip_in; }
    /**
     * @brief Returns the destination IP address of the request
     * 
     * @return std::string 
     */
    std::string getIPout() {return ip_out; }
    /**
     * @brief Get the time of the request
     * 
     * @return int 
     */
    int getTime() {return time; }

private:
    std::string generate_ipv4_address();
    std::string ip_in;
    std::string ip_out;
    int time; 
};

#endif