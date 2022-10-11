#include "webServer.h"

/**
 * Constructor for the webserver
 * @param name the name for the server
*/
WebServer::WebServer(string name): currentJob(), jobExecutionTime(0), jobStartTime(0), serverName(name) {}

/**
 * "Executes" the request by storing the request, job start time, and the request processing time
 * @param req The request being passed to the server
 * @param current_time The time at which the job was given to the server
*/
void WebServer::executeJob(Request req, int current_time) {
    // Store job info for "execution"
    jobExecutionTime = req.getRequestTime();
    jobStartTime = current_time;
    currentJob = req;
}

/**
 * Returns a log with the current_time and the IP addresses of the request
 * @param current_time is the time at which the log is created
*/
string WebServer::getJobLog(int current_time) {
    string log = "At " + to_string(current_time) + " " + serverName + " Processed request from ";
    log += currentJob.getIP("IN") + " to " + currentJob.getIP("OUT");
    return log;
}

/**
 * Checks to see if the request the server was given is a bad request
*/
bool WebServer::isBadReq() {
    return jobExecutionTime == -1;
}

/**
 * Checks to see if the server is still "processing" a request
 * @param current_time current time to see if enough time has passed for processing to be done
*/
bool WebServer::isServerBusy(int current_time) {
    // See if job is still "executing"
    return jobExecutionTime + jobStartTime > current_time;
}