#include "streaming.h"
#include "base64.h"

streaming::streaming()
{

}

void streaming::setFile(std::string file)
{
   namesong = file;
}

std::string streaming::streamin(int current)
{
 std::filebuf *pduf;
 char marca[64];
 std::cout<<"inicio de abrir archivo"<<std::endl;
 mp3In.open(namesong, std::ios::in| std::ios::binary);
 if(mp3In.is_open()){
     std::cout<<"vsd"<<std::endl;
     pduf = mp3In.rdbuf();
     size = pduf->pubseekoff(0, std::ios::end,std::ios::in);
     std::cout<<size<<std::endl;
     if(current < size){
         mp3In.seekg(size-current, std::ios::cur);
         mp3In.read(marca,30);
         std::cout<<"no pos guau"<<marca<<std::endl;
        mp3In.close();
        const std::string s= "abec";
        std::string str(marca);
        str = marca;
        std::string enconde = base64_encode(reinterpret_cast<const unsigned char*>(str.c_str()),s.length());


        std::cout<<"encode"<<enconde<<std::endl;
        return enconde;
     }else{
         std::cout<<"excede el tamano del archivo"<<std::endl;
         mp3In.close();
         //size = pduf->pubseekoff(-128, std::ios::end,std::ios::in);
     }
 }else{
     std::cout<<"Fichero inexistente"<<std::endl;
 }

}

char *streaming::returnSong()
{

}
