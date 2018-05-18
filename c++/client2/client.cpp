#include "client.h"

client::client()
{

}

void client::setPort (int port){

    ready = false;
    PORT = port;

}
json client::Execute(string Data)
{

    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send(Data);
    cout<<"siguiendo la linea basica"<<endl;
    string rec = tcp.receive();
    cout<<"fail"<<endl;
    auto j3 = json::parse (rec);
    cout << j3 << endl;
    return j3;

}
json client:: Get (string label){

    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send("Get this: "+label);

    string rec = tcp.receive();

    auto j3 = json::parse (rec);
    return j3;
}

void client:: Reset (){

    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send("Reset");
}

