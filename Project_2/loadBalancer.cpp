#include <iostream>
#include "loadBalancer.h"

LoadBalancer::LoadBalancer(int numRequests, int numServers):
    current_time(0), num_servers(numServers), requestQueue(queue<Request>::container_type(numRequests)), serverList() {
    // Create Servers
    char let = 'A';
    for (int i = 0; i < num_servers; i++) {
        WebServer server(string(1, let));
        serverList.push_back(server);
        let++;
    }
}

void LoadBalancer::giveServerJob(WebServer& server) {
    if (!requestQueue.empty()) {
        server.executeJob(requestQueue.front(), current_time);
        requestQueue.pop();
    }
}

void LoadBalancer::checkServers() {
    for (int i = 0; i < num_servers; i++) {
        // if Server is not busy print log and assign new job
        if (!serverList.at(i).isServerBusy(current_time)) {
            cout << serverList.at(i).getJobLog(current_time) << endl;
            giveServerJob(serverList.at(i));
        }
        current_time++;
    }
}

void LoadBalancer::runLoadBalancer(int runTime) {
    // Assign initial jobs
    for (int i = 0; i < num_servers; i++) {
        giveServerJob(serverList.at(i));
    }

    while (current_time < runTime) {
        // Check servers and assign new jobs as needed
        checkServers();
    }

    // Print out how many jobs left in queue
    cout << "Jobs left in queue: " << requestQueue.size() << endl;
}