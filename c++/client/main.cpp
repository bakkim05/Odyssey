
#include "client.h"

int main( )
{
    client hdue;
    hdue.setPort(8088);
    WriteDats *ur = new WriteDats();
    cout<<"sd"<<endl;
    json dataServer;
    dataServer["type"] = "int";
    dataServer["label"] = "Y";
    dataServer["value"] = 8;
    dataServer["size"] = 8;
    cout<<dataServer.dump()<<endl;
    ur->escribir("congoli","calypso", "Ferguson","costarica","1965","cfdgfgdfg","folklore");
    string d = ur->getXml();
    vector<uint64_t>vec(d.begin(),d.end());
    cout<<d <<endl;
    hdue.Execute(d);
    //hdue.Get("B");
    return 0;
}
