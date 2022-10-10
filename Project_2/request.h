#include<string>
using std::string;

class Request {
private:
    string ip_in;
    string ip_out;
    int requestTime; // in clock cycles
public:
    Request();
    int getRequestTime();
    string getIP(string ipType);
};
