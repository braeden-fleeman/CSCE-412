#ifndef LOADBALANCER
#define LOADBALANCER

#include <queue>
#include "request.h"
#include "webServer.h"

using namespace std;
/**
 * Handles Giving Out Requests.
 * The Load Balancer has three responsibilities, giving out requests to servers,
 * keeping track of the time, and generating requests. After initial request
 * generation it will randomly generate requests with a 1/35 chance every 10 cycles.
 * The number of new request that can be added is 1 to 2*(# of servers).
*/
class LoadBalancer {
private:
    int current_time; /**< The current time in the load balancer*/
    int num_servers; /**< The number of servers to be made. Provided by user*/
    queue<Request> requestQueue; /**< Queue that holds requests to be processed*/
    vector<WebServer> serverList; /**< List of all the servers in the load balancer*/
public:
    LoadBalancer(int numRequests, int numServers);
    void checkServers(ofstream& outputWriter);
    void giveServerJob(WebServer& server);
    void runLoadBalancer(int runTime);
};

#endif