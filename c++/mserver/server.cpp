#include <iostream>
#include <string>
#include <fstream>
#include "tcpserver.cpp"
#include <QCoreApplication>
#include <QInputDialog>
#include <writedats.h>
#include "CreateXML.h"
using namespace std;
using namespace rapidxml;
TCPServer tcp;
int PORT;
int SIZE;

void *loop (void *m) {
    pthread_detach(pthread_self());
    cout<<"buscando loop"<<endl;
    ParserXML *d = new ParserXML();
    cout<< d->xmlCancion("havana","pop","camila","camila","1856","dsfsdfds","pop")<<endl;
    while (true){
        srand (time (NULL));
        char ch = 'a' + rand () % 26;
        string s(1,ch);
        string str = tcp.getMessage();
        cout<<"mesage"<<str<<endl;
        vector<char> vec1(str.begin(),str.end());

        if( str != "" ){

            cout<<"message difeten"<<endl;
            WriteDats *lr = new WriteDats();
            lr->read(str);
            //jung aqui tiene que enlazar con la estructura de datos!!!!!!!!!
            tcp.Send(str);
            tcp.clean();
        }
        usleep(100000);

    }

    tcp.detach();
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    while (true){
        cout << "Ingrese el Puerto entre 5500 y 9000" << endl;
        cin >> PORT;
        if (PORT >= 5500 && PORT <= 9000) break;
    }
    cout << "Ingrese el tamaño de la memoria en Bytes " << endl;
    cout<<"bullshit"<<endl;
    cin >> SIZE;
    cout << "| Puerto: " << PORT << " | " << "Memory: " << SIZE << " Bytes |" << endl;


    // Ejecución del Servidor con el loop
    pthread_t msg;
    tcp.setup(PORT);
    cout << "A la espera de un cliente" << endl;
    if( pthread_create(&msg, NULL, loop, (void *)0) == 0)
    {
        tcp.receive();
    }

    return a.exec();
}



