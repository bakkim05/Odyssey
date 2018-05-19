#include "client.h"

client::client()
{

}

void client::setPort (int port){

    ready = false;
    PORT = port;

}
void client::Execute(string Data)
{

    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send(Data);
    cout<<"siguiendo la linea basica"<<endl;
    string rec = tcp.receive();
   // auto j3 = json::parse (rec);
    //cout << j3 << endl;
    //return j3;

}
string client:: Get (string label){

    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send("Get this: "+label);

    string rec = tcp.receive();

    return rec;
}

void client:: Reset (){

    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send("Reset");
}

