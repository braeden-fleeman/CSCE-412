#include <iostream>
#include <fstream>
#include "loadBalancer.h"

LoadBalancer::LoadBalancer(int numRequests, int numServers):
    current_time(0), num_servers(numServers), requestQueue(queue<Request>::container_type(numRequests)), serverList() {
    // Create Servers
    for (int i = 0; i < num_servers; i++) {
        string name = "Server:" + to_string(i);
        WebServer server(name);
        serverList.push_back(server);
    }
}

void LoadBalancer::giveServerJob(WebServer& server) {
    Request badReq;
    badReq.makeBadRequest();
    if (!requestQueue.empty()) {
        server.executeJob(requestQueue.front(), current_time);
        requestQueue.pop();
    } else {
        server.executeJob(badReq, -1);
    }
}

void LoadBalancer::checkServers(ofstream& outputWriter) {
    for (int i = 0; i < num_servers; i++) {
        // if Server is not busy print log and assign new job
        if (!serverList.at(i).isServerBusy(current_time) && !serverList.at(i).isBadReq()) {
            outputWriter << serverList.at(i).getJobLog(current_time) << endl;
            giveServerJob(serverList.at(i));
        } else if (serverList.at(i).isBadReq()) {
            giveServerJob(serverList.at(i));
        }

        current_time++;
    }
}

void LoadBalancer::runLoadBalancer(int runTime) {
    // Create file
    ofstream output("LoadBalancerLogs.txt");
    output << "Braeden Fleeman" << endl << "CSCE 412\n\n";
    // Output initial queue size
    output << "Initial Queue Size: " << requestQueue.size() << endl;
    output << "Odds of Adding New Requests: 1/35 every ten cycle" << endl;
    output << "Number of New Tasks Possibly Added: 1 to 2 * number of servers" << endl;

    // List range for task times
    output << "Task Time Range: 1 to 1000 clock cycles\n" << endl;

    // Assign initial jobs
    output << "Start of Load Balancer Log:" << endl;
    for (int i = 0; i < num_servers; i++) {
        giveServerJob(serverList.at(i));
    }

    while (current_time < runTime) {
        // Check servers and assign new jobs as needed
        checkServers(output);

        // Randomly add new jobs. Occurs with a 1/35 chance
        if (rand() % 35 == 0) {
            // Add new jobs (Max # of new jobs = 2 * # of numServer)
            int newRequests = (rand() % (2 * num_servers)) + 1;
            for (int i = 0; i < newRequests; i++) {
                Request req;
                requestQueue.push(req);
                current_time++;
            }
        }

        // See if queue is empty
        if (requestQueue.empty()) {
            // see if all servers done
            int doneServers = 0;
            for (int i = 0; i < num_servers; i++) {
                // if Server is not busy print log and assign new job
                if (!serverList.at(i).isServerBusy(current_time) && !serverList.at(i).isBadReq()) {
                    output << serverList.at(i).getJobLog(current_time) << endl;
                }
                if (serverList.at(i).isBadReq()) {
                    doneServers++;
                }
                current_time++;
            }

            // exit load balancer if both are true
            if (doneServers == 10) {
                output << "All jobs finished at " << current_time << endl;
                break;
            }
        }

    }

    // Print out how many jobs left in queue
    output << "\nJobs left in queue: " << requestQueue.size() << endl;

    // close file
    output.close();
}