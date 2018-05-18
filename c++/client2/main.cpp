
#include "client.h"

int main( )
{

    client hdue;
    hdue.setPort(8088);
    json dataServer;
    dataServer["type"] = "double";
    dataServer["label"] = "A";
    dataServer["value"] = 8.3;
    dataServer["size"] = 8;
    cout<<dataServer.dump()<<endl;

    hdue.Execute(dataServer.dump());
}
