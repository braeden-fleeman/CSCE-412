#ifndef REQUEST
#define REQUEST

#include<string>
using namespace std;

class Request {
private:
    string ip_in;
    string ip_out;
    int requestTime; // in clock cycles
public:
    Request();
    int getRequestTime();
    string getIP(string ipType);
    void makeBadRequest();
};

#endif
