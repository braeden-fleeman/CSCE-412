#include <queue>
#include "request.h"

using namespace std;

class LoadBalancer {
private:
    queue<Request> requestQueue;
    int current_time;
public:
    LoadBalancer();
    void loadRequestQueue(int numRequests);
    Request giveRequest();
    void runLoadBalancer(int runTime);
};
