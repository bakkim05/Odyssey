#include <iostream>
#include <string>
#include <fstream>
#include "tcpserver.cpp"
#include <QCoreApplication>
#include <QInputDialog>
#include <writedats.h>
#include <streaming.h>
#include <sstream>
#include <string.h>
#include <base64.h>
#include <maker.h>
#include <iterador.h>

using namespace std;
using namespace rapidxml;
TCPServer tcp;
int PORT;
int SIZE;

void *loop (void *m) {
    pthread_detach(pthread_self());
    cout<<"buscando loop"<<endl;
    while (true){
        srand (time (NULL));
        char ch = 'a' + rand () % 26;
        char const* p2 = "Bertha";
        string s(1,ch);
        string str = tcp.getMessage();
        cout<<"mesage"<<str<<endl;
        //base64 *nose = new base64();
       // nose->encode(p2, 11);


        //tcp.Send("prueba bebe");

        if( str != "" ){

            cout<<"message difeten"<<endl;
            // WriteDats *es = new
            Maker *usuario = new Maker();
            Iterador *iterado = new Iterador();
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
            {
                cout<<"Reproducir"<<endl;
                //se envia el nombre de la cancion y se debe empezar a enviar los chunks
                streaming *stream = new streaming();
                string song = lr->getSong(str);
                //aqui debo colocar en setFile el nombre de la cancion, que se debe almacenar con exactamente el mismo nombre.
                stream->setFile("charlie-puth-how-long.mp3");
                string encode =stream->streamin(30);
                string loadXml = lr->writeStreaming(song,encode);
                tcp.Send(loadXml);
                tcp.clean();
                break;
            }
            case 10:
            {
                cout<<"Usuario nuevo"<<endl;
                //Aqui se debe hacer todas las verificaciones del caso y crear el hash para la contrsena
                string username = lr->getUser(str);
                char* userchar = new char[username.length()+1];
                strcpy(userchar,username.c_str());
                if(usuario->searchUser(userchar)){
                   cout<<"Hay alguien con ese nombre"<<endl;
                }else{
                    iterado->fullJsonUser(str,usuario);
                    cout<<"no hay nadie"<<endl;
                }
                tcp.Send("Usuario creado");
                tcp.clean();
                break;
            }
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



