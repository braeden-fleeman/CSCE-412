#ifndef LOADBALANCER
#define LOADBALANCER

#include <queue>
#include "request.h"
#include "webServer.h"

using namespace std;

class LoadBalancer {
private:
    int current_time;
    int num_servers;
    queue<Request> requestQueue;
    vector<WebServer> serverList;
public:
    LoadBalancer(int numRequests, int numServers);
    void checkServers();
    void giveServerJob(WebServer& server);
    void runLoadBalancer(int runTime);
};

#endif