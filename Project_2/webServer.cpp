#include <chrono>
#include "webServer.h"

using std::chrono::high_resolution_clock, std::chrono::duration_cast;

WebServer::WebServer() {}

int WebServer::executeJob(Request req) {
    std::chrono::milliseconds executionTime(req.getRequestTime());
    auto startTime = high_resolution_clock::now();
    while (duration_cast<std::chrono::milliseconds>(high_resolution_clock::now() - startTime) < executionTime);

    return 1;
}