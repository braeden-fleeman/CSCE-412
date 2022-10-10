#include <chrono>
#include <iostream>
#include "webServer.h"
#include "loadBalancer.h"

using namespace std;

int main() {
    /* Get execution parameters from user */
    int executionTime;
    int numServers;
    cout << "Enter How Long Balancer Will Run (in clock cycles): ";
    cin >> executionTime;
    cout << "Enter Number of WebServers to Make: ";
    cin >> numServers;
    int numRequests = numServers * 2;

    // Set the seed for random request variables
    srand(time(NULL));

    /* Execute Load Balancing */
    LoadBalancer balancer(numRequests, numServers);

    balancer.runLoadBalancer(executionTime);
}