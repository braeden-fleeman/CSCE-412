#ifndef WEBSERVER
#define WEBSERVER

#include <queue>
#include "request.h"
using namespace std;

/**
 * "Processes" Request Objects.
 * The WebServer class mimics processing Request objects.
 * Stores the request data and returns a log saying processed
 * after enough time has passed.
*/
class WebServer {
private:
    Request currentJob; /**< The current job the server is working on*/
    int jobExecutionTime; /**< How long the server should take to process the request*/
    int jobStartTime; /**< What time the server was given the job at*/
    string serverName; /**< The name of the server for logging purposes*/

public:
    WebServer(string name);
    void executeJob(Request request, int curent_time);
    string getJobLog(int current_time);
    bool isServerBusy(int current_time);
    bool isBadReq();

};

#endif