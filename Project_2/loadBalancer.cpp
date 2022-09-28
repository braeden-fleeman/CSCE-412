#include <chrono>
#include <iostream>
#include <queue>
#include "request.h"
#include "webServer.h"
using std::cout, std::cin, std::endl, std::queue;
using std::chrono::high_resolution_clock, std::chrono::duration_cast;

int main() {
    // Get execution parameters from user
    int executionTimeInt;
    cout << "Enter How Long Balancer Will Run (in seconds): ";
    cin >> executionTimeInt;
    std::chrono::seconds executionTime(executionTimeInt);

    // Set the seed for random request variables
    srand(time(NULL));

    // Execute Load Balancing
    queue<Request> requestQueue;
    auto startTime = high_resolution_clock::now();
    while (duration_cast<std::chrono::seconds>(high_resolution_clock::now() - startTime) < executionTime) {

    }
}