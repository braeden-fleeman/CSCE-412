#include <cstdlib>
#include "request.h"

using std::rand, std::to_string;

/**
 * This function randomly generates an IPv4 address.
 * Used in Request constructor
*/
string Request::rand_IP() {
    string ip = "";
    for (int i = 0; i < 4; i++) {
        ip += i == 3 ? to_string(rand() % 256) : to_string(rand() % 256) + ".";
    }
    return ip;
}

/**
 * Constructor for the Request. Randomly generates the IPs.
 * The request time is also randomly set between 1 and 1000 cycles
*/
Request::Request(): ip_in(rand_IP()), ip_out(rand_IP()), requestTime(1 + (rand() % 1000)) {
}

/**
 * Retrieves the in or out IP based on input
 * @param ipType can be IN or OUT. Returns respective IP
*/
string Request::getIP(string ipType) {
    return ipType == "IN" ? ip_in : ip_out;
}

/**
 * Returns the requestTime data member
*/
int Request::getRequestTime() {
    return requestTime;
}

/**
 * Turns the request object into a Bad Request
*/
void Request::makeBadRequest() {
    requestTime = -1;
    ip_in = "-1";
    ip_out = "-1";
}