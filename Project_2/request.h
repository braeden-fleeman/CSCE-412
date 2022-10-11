#ifndef REQUEST
#define REQUEST

#include<string>
using namespace std;

/**
*   The Mock Request Object.
*   This class contains the request object that is to be used by the
*   WebServer and LoadBalancer classes
*/
class Request {
private:
    string ip_in; /**< Represents incoming IP Address (Randomized) */
    string ip_out; /**< Represents outgoing IP Address (Randomized) */
    int requestTime; /**< Time request takes to be processed in clock cycles */
    string rand_IP();
public:
    Request();
    int getRequestTime();
    string getIP(string ipType);
    void makeBadRequest();
};

#endif
