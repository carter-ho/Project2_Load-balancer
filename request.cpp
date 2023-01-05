#include "request.h"
#include <iostream>
#include <random>
#include <string>

using std::cin, std::cout, std::endl, std::string;

Request::Request(){
    ip_in = generate_ipv4_address(); /// Calls random funtion to create a random ip in address
    ip_out = generate_ipv4_address(); /// Calls random funtion to create a random ip out address

    
	/// Creates a random clock cycle
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(2, 500);
    time = dis(gen);
}



/// Randomized IP Address generator function created by ChatGPT
std::string Request::generate_ipv4_address() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 255);

  return std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen));
}

