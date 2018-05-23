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


        //tcp.Send("prueba bebe");
        usleep(2000);
        if( str != "" ){

            cout<<"message difeten"<<endl;
           // WriteDats *es = new
            WriteDats *lr = new WriteDats();
            int descision = lr->read(str);
            switch (descision) {
            case 0:
               cout<<"Buscar cancion.. aqui agregar busqueda"<<endl;
                //aqui se debe buscar la cancion y devolver la metadata de la cancion
                break;
            case 1:
                cout<<"Agregar cancion"<<endl;
                //aqui se debe agregar la cancion, crear la estructura y el json
                tcp.Send("agregada");
                break;
            case 2:
                cout<<"Eliminar cancion"<<endl;
                //aqui debe buscar y eliminar
                tcp.Send("eliminada");
                break;
            case 3:
                cout<<"Actualizar"<<endl;
                //aqui debe mdoficicar el json y enviar la nueva metadata
                tcp.Send("Archivo Modificado");
                break;
            case 4:
                cout<<"Reproducir"<<endl;
                //se envia el nombre de la cancion y se debe empezar a enviar los chunks
                tcp.Send("streaming pronto");
                break;
            case 10:
                cout<<"Usuario nuevo"<<endl;
                //Aqui se debe hacer todas las verificaciones del caso y crear el hash para la contrsena
                tcp.Send("Usuario creado");
                break;
            case 11:
                cout<<"Log In"<<endl;
                //verificar todo
                tcp.Send("Login success");
                break;
            case 12:
                //aqui eliminar de la lista de usuarios
                cout<<"Eliminar usuario"<<endl;
                tcp.Send("Usuario eliminado");
                break;
            default:

                break;
            }
            tcp.Send("buenas");
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



