#ifndef WEBSERVER
#define WEBSERVER

#include <queue>
#include "request.h"
using namespace std;

class WebServer {
private:
    Request currentJob;
    int jobExecutionTime;
    int jobStartTime;
    string serverName;

public:
    WebServer(string name);
    void executeJob(Request request, int curent_time);
    string getJobLog(int current_time);
    bool isServerBusy(int current_time);
    bool isBadReq();

};

#endif