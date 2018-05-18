#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <signal.h>
#include "tcpclient.h"
#include <typeinfo>
#include "json.hpp"
#include <string>

using namespace std;
using json = nlohmann::json;

class client
{
public:
    client();
    void sig_exit(int s);
    void setPort (int port);
    json Execute(string Data);
    json Get (string label);
    void Reset ();

private:
    TCPClient tcp;
    int PORT = 9000;
    bool ready = false;
};

#endif // CLIENT_H
