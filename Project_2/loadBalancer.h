#include <chrono>
#include <iostream>
#include <queue>
#include "webServer.h"

using namespace std;

class LoadBalancer {
private:
    queue<Request> requestQueue;
public:
    LoadBalancer(/* args */);
    void loadRequestQueue(int numRequests);
    Request giveRequest(WebServer server);
};
