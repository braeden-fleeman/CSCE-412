#include <chrono>
#include <iostream>
#include "webServer.h"
#include "loadBalancer.h"

using namespace std;
/**
 * Main function for the program.
 * Gets user inout and starts the load balancer
*/
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