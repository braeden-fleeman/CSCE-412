#include <chrono>
#include <iostream>
#include <queue>
#include "webServer.h"
using namespace std;
using std::chrono::high_resolution_clock, std::chrono::duration_cast;

int main() {
    // Get execution parameters from user
    int executionTimeInt;
    int numRequests;
    cout << "Enter How Long Balancer Will Run (in seconds): ";
    cin >> executionTimeInt;
    cout << "Enter How Many Requests to Generate: ";
    cin >> numRequests;
    std::chrono::seconds executionTime(executionTimeInt);

    // Set the seed for random request variables
    srand(time(NULL));

    /* Execute Load Balancing */
    // Load Queue
    queue<Request> requestQueue;

    // Run Balancer
    auto startTime = high_resolution_clock::now();
    while (duration_cast<std::chrono::seconds>(high_resolution_clock::now() - startTime) < executionTime) {

    }
}