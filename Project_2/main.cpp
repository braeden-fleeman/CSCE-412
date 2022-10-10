#include <chrono>
#include <iostream>
#include "webServer.h"
using namespace std;
using std::chrono::high_resolution_clock, std::chrono::duration_cast;

int main() {
    /* Get execution parameters from user */
    int executionTime;
    int numRequests;
    int numServers;
    cout << "Enter How Long Balancer Will Run (in clock cycles): ";
    cin >> executionTime;
    cout << "Enter How Many Requests to Generate: ";
    cin >> numRequests;
    cout << "Enter Number of WebServers to Make: ";
    cin >> numServers;
    // std::chrono::seconds executionTime(executionTimeInt);

    // Set the seed for random request variables
    srand(time(NULL));

    /* Execute Load Balancing */
    // Load Queue

    // Run Balancer
    // auto startTime = high_resolution_clock::now();
}