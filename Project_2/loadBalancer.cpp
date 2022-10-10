#include "loadBalancer.h"

LoadBalancer::LoadBalancer(): current_time(0) {}

void LoadBalancer::loadRequestQueue(int numRequests) {}

Request LoadBalancer::giveRequest() {
    // if (!requestQueue.empty()) {
    //     return requestQueue.pop();
    // }
}

void LoadBalancer::runLoadBalancer(int runTime) {
    int startTime = 0;
    while (startTime < runTime) {
        startTime++;
    }

}