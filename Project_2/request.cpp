#include <cstdlib>
#include "request.h"

using std::rand, std::to_string;

string rand_IP() {
    string ip = "";
    for (int i = 0; i < 4; i++) {
        ip += i == 3 ? to_string(rand() % 256) : to_string(rand() % 256) + ".";
    }
    return ip;
}

Request::Request() : ip_in(rand_IP()), ip_out(rand_IP()), requestTime(1 + (rand() % 100000)) {
}

string Request::getIP(string ipType) {
    return ipType == "IN" ? ip_in : ip_out;
}

int Request::getRequestTime() {
    return requestTime;
}