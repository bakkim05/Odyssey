#include <iostream>
#include <string>
#include <fstream>
#include "tcpserver.cpp"
#include <QCoreApplication>
#include <QInputDialog>
#include <orderram.h>
#include <json.hpp>
using json = nlohmann::json;
using namespace std;
TCPServer tcp;
int PORT;
int SIZE;

json Var;
void *Memorymap;

int Current_oofset = 0;
void *Currentposition;
void *Two;
bool first = true;
json convert (json info){
    string label = info["label"];
    info.erase("label");
    json nuevo;
    nuevo[label] = info;
    return nuevo;
}

int typeget (string info){

    if (info.find("Get this: ")>info.length()){
        return 0;
    }else if (info.find("Size")<=info.length()){
        return 2;
    }
    else {
        return 1;
    }
}
void set_on_memory (json info){

}
void *TYPES(json info);
string getDirection(void *direction);
int setOffset (string type){

    if (type == "int" || type == "float"){

        if (!first){
            Current_oofset+=4;
            first = true;
            return 0;
        } else {

            Current_oofset+=4;

            return Current_oofset-4;
        }
    }  else if (type == "long" || type == "double"){
        if (!first){
            Current_oofset+=8;
            first = true;
            return 0;
        } else {
            Current_oofset+=8;
            return Current_oofset-8;
        }
    }else if (type == "char"){
        if (!first){
            Current_oofset+=1;
            first = true;
            return 0;
        } else {
            Current_oofset+=1;
            return Current_oofset-1;
        }
    }
}
int validate (json info){
    if (info["value"].is_string()){
     if (Var.find (info["value"]) != Var.end ()) return 2;
     else if (info["type"] != "char") return 1;
    }
    else return 0;
}
void *loop (void *m) {

    pthread_detach(pthread_self());

    while (true){
        srand (time (NULL));
        char ch = 'a' + rand () % 26;

        string s(1,ch);
        string str = tcp.getMessage();
        if( str != "" )
        {

            if (typeget(str) == 1){

                string variable = str.substr(10, str.length());
                json toSend;

                toSend["type"] = Var[variable]["type"];
                if (toSend["type"] == "int"){
                    int* prueba = (int*)(Memorymap +(int)Var[variable]["offset"]);
                    toSend["value"] = *prueba;
                } else if (toSend["type"] == "long"){

                    long* prueba = (long*)(Memorymap +(int)Var[variable]["offset"]);
                    toSend["value"] = *prueba;
                }else if (toSend["type"] == "double"){

                    double* prueba = (double*)(Memorymap +(int)Var[variable]["offset"]);
                    toSend["value"] = *prueba;
                } else if (toSend["type"] == "float"){

                    float* prueba = (float*)(Memorymap +(int)Var[variable]["offset"]);
                    toSend["value"] = *prueba;
                }else if (toSend["type"] == "char"){
                    if (validate(Var[variable]) == 2) {
                        char* prueba = (char*)(Memorymap +(int)Var[variable]["offset"]);
                        string f =  Var[variable]["value"];
                        toSend["value"] = Var[f]["value"];
                    } else {
                        char* prueba = (char*)(Memorymap +(int)Var[variable]["offset"]);
                        toSend["value"] = Var[variable]["value"];
                    }
                }
                tcp.Send(toSend.dump());
                tcp.clean();
            } else if (str == "Reset"){
                delete Memorymap;
                Current_oofset = 0;
                first = 0;
                Memorymap = (void*) malloc (SIZE);
                Currentposition = Memorymap;
                Var.clear();
                tcp.clean();
            }
            else {
                auto j3 = json::parse (str);
                string b = j3["label"];
                if (Var.find (j3["label"]) != Var.end () && j3["value"] == Var[b]["value"]){

                    cout << "Exist" << endl;
                    tcp.Send(Var.dump());
                    tcp.clean();

                } else if (Var.find (j3["label"]) != Var.end () && j3["value"] != Var[b]["value"]){
                    TYPES(j3);
                    tcp.Send(Var.dump());
                    tcp.clean();
                }
                else {
                cout << "New Variable: " << str << endl;
                // Analizar str a json osea convertir un str a json
                void* actual = TYPES(j3);
                setOffset(j3["type"]);
                if (Current_oofset >= SIZE){
                    tcp.Send ("Error full memory");
                    tcp.clean();
                } else {
                    j3["direction"] = getDirection(actual);
                    j3["countr"] =1;
                    j3["offset"] = Current_oofset;
                    j3 = convert(j3);

                    Var.merge_patch(j3);

                    tcp.Send(Var.dump());
                    tcp.clean();
                }
                }
            }
        }
        usleep(1000);
}
        tcp.detach();
        }
bool exist  (json info) {
    string t = info["label"];

    if (Var[t].is_null())

        return 0;

   else{
        return 1;
    }
}


void* TYPES (json info){

    string tipo = info["type"];

    if (exist(info)){
        string var = info["label"];
        if (validate(Var[var])==1){
            string toa = Var[var]["value"];
            Var[toa]["countr"] = ((int)Var[toa]["countr"])-1;
            Var[var]["value"] = info["value"];
        } else if (validate(Var[var])==2){
            string toa = Var[var]["value"];
            Var[toa]["countr"] = ((int)Var[toa]["countr"])-1;
            Var[var]["value"] = info["value"];
        }
            else {
            Var[var]["value"] = info["value"];
        }
        return Memorymap + (int)Var[var]["offset"];
    }else{

    if (tipo == "int") //Caso para int
    {
        int *entero = (int*)Currentposition;
        if (validate(info)==1) {
            string label = info["value"];
            *entero = (int)Var[label]["value"];
            Var[label]["countr"] =((int)Var[label]["countr"])+1;
        }
        else *entero = (int)info["value"];
        Two = Currentposition;

        Currentposition =(char*) entero+4;


        return Two;
    }
    else if (tipo ==  "char") //Caso para char
    {
        char* arreglo = (char*)&Currentposition;
        if (validate(info) == 2){
            string label = info["value"];
            string st = Var[label]["value"];
            arreglo = (char*)st.c_str();
            Var[label]["countr"] =((int)Var[label]["countr"])+1;
        } else {
            string valor = info ["value"];
            arreglo = (char*)valor.c_str();
        }
        Two = Currentposition;

        Currentposition+=1;

        return Two;
    }
    else if (tipo == "float") //Caso para float
    {
        float* flotante = (float*)Currentposition;
        cout << flotante << endl;
        if (validate(info)==1) {
            string label = info["value"];
            *flotante = (float)Var[label]["value"];
            Var[label]["countr"] =((int)Var[label]["countr"])+1;
        }
        else *flotante = (float)info["value"];
        Two = Currentposition;

        Currentposition = (char*)flotante+4;


        return Two;
    }
    else if( tipo == "double" )//Caso double
    {
        double *doble = (double*)Currentposition;

        if (validate(info)) {
            string label = info["value"];
            *doble = (double)Var[label]["value"];
            Var[label]["countr"] =((int)Var[label]["countr"])+1;
        }
        else *doble = (double)info["value"];
        Two = Currentposition;
        Currentposition = (char*)doble+8;

        return Two;
    }
    else if (tipo == "long") // Caso long
    {
        long *larg = (long*)Currentposition;
        cout << larg << endl;
        if (validate(info)) {
            string label = info["value"];
            *larg = (long)Var[label]["value"];
            Var[label]["countr"] =((int)Var[label]["countr"])+1;
        }
        else *larg = (long)info["value"];
        Two = Currentposition;


        return Two;
    }

    }
}
string getDirection(void *direction) {
    // Obtener dirección de memoria
    ostringstream oss;
    oss << (void const*)(int*)(direction);
    string d = oss.str();

    return d;
}

int main(int argc, char *argv[]) {
        QCoreApplication a(argc, argv);
        while (true){
        cout << "Ingrese el Puerto entre 5500 y 9000" << endl;
        cin >> PORT;
        if (PORT >= 5500 && PORT <= 9000) break;
        }
        cout << "Ingrese el tamaño de la memoria en Bytes " << endl;
        cin >> SIZE;
        cout << "| Puerto: " << PORT << " | " << "Memory: " << SIZE << " Bytes |" << endl;

        // Unico Malloc de la memoria
        Memorymap = (void*) malloc (SIZE);
        Currentposition = Memorymap;


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



