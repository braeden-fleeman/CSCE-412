#include "webServer.h"

WebServer::WebServer(string name): currentJob(), jobExecutionTime(0), jobStartTime(0), serverName(name) {}

void WebServer::executeJob(Request req, int current_time) {
    jobExecutionTime = req.getRequestTime();
    jobStartTime = current_time;
    currentJob = req;
}

string WebServer::getJobLog(int current_time) {
    string log = "At " + to_string(current_time) + " " + serverName + " Processed request from ";
    log += currentJob.getIP("IN") + " to " + currentJob.getIP("OUT");
    return log;
}

bool WebServer::isServerBusy(int current_time) {
    // See if job is still "executing"
    return jobExecutionTime + jobStartTime > current_time;
}