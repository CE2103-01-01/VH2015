#include <iostream>
#include <Test/Headers/TestApplication.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include "vHeap/Headers/vRef.h"
#include "src/vTypes/Headers/vChar.h"
#include "src/vTypes/Headers/vInt.h"
#include "src/vTypes/Headers/vLong.h"
#include "src/vTypes/Headers/vFloat.h"
#include "src/vTypes/Headers/vSimpleList.h"
#include "../libs/rapidjson/rapidjson.h"
#include "../libs/rapidjson/document.h"
#include "../libs/rapidjson/stringbuffer.h"
#include "../libs/rapidjson/writer.h"
#include "../libs/pugixml.hpp"

//TODO: implementar vArray
//TODO: cambiar vString de heap a vHeap
//TODO: cambiar vSimpleList de heap a vHeap
//TODO: implementar vDoubleList
//TODO: implementar vDebuger
//TODO: aplicación de prueba
//TODO: vHeap como servidor
//TODO: visores de uso y dump de memoria

using namespace std;
using namespace pugi;

template<class T> int vPlacement(vRef<T> vR, T toPlace);

void pruebaVHeap() {
    vRef<int> r1 = vRef<int>(vMalloc(sizeof(int)));
}

void pruebaVString() {
    vString* str = static_cast<vString*>(malloc(sizeof(vString)));
    new(str) vString("Hola");
    !(*str);

    --(*str);
    !(*str);

    std::cout<<(*str)[0]<<std::endl;

    (*str) += "aa";
    !(*str);
}

void pruebaLista() {
    std::cout << "Resultado Esperado: 2,3,4,5,6" << std::endl;
    vList<int> *lista = new vList<int>();
    lista->append(5);
    lista->append(2);
    lista->add(4);
    lista->add(3);
    lista->add(6);
    lista->swap(0, 5);
    vListIterator<int> *i = lista->getIterator();
    while(i->exists())
    {
        std::cout<<*i->next()<<std::endl;
    }

    std::cout<<"Resultado Esperado: 2,3,4,5,6"<<std::endl;
}

void pruebaChar(){
    vChar a = vChar(65);
    vRef<vChar> b = &a;
    std::cout<<"A(65): "<<!**b<<std::endl;

    vChar c = vChar(67);
    vRef<vChar> d = &c;
    std::cout<<"C(67): "<<!**d<<std::endl;

    vChar e = vChar(70);
    vRef<vChar> f = &e;
    std::cout<<"F(70): "<<!**f<<std::endl;
};

void pruebaFloat(){
    vFloat a = vFloat(3.5);
    vRef<vFloat> b = &a;
    std::cout<<"vFloat 3.5: "<<!**b<<std::endl;

    vFloat c = vFloat(5.66);
    vRef<vFloat> d = &c;
    std::cout<<"vFloat 5.66: "<<!**d<<std::endl;

    vFloat e = vFloat(0.2111);
    vRef<vFloat> f = &e;
    std::cout<<"vFloat 0.2111: "<<!**f<<std::endl;
};

void pruebaInt(){
    vInt a = vInt(10);
    vRef<vInt> b = &a;
    std::cout<<"vInt 10: "<<!**b<<std::endl;

    vInt c = vInt(1);
    vRef<vInt> d = &c;
    std::cout<<"vInt 1: "<<!**d<<std::endl;

    vInt e = vInt(500);
    vRef<vInt> f = &e;
    std::cout<<"vInt 500: "<<!**f<<std::endl;
};

void pruebaLong(){
    vLong a = vLong(1000000);
    vRef<vLong> b = &a;
    std::cout<<"vLong 1000000: "<<!**b<<std::endl;

    vLong c = vLong(100000000000);
    vRef<vLong> d = &c;
    std::cout<<"vLong 100000000000: "<<!**d<<std::endl;

    vLong e = vLong(1000000000);
    vRef<vLong> f = &e;
    std::cout<<"vLong 1000000000: "<<!**f<<std::endl;
};

void pruebaDumpTxt(){
    Dump dump;
    dump.saveDumpFile();

}

void pruebaListaSimple(){
    unsigned int id = vMalloc(sizeof(vSimpleList<vChar>));
    vRef<vSimpleList<vChar>> lista;
    lista =  vRef<vSimpleList<vChar>>(id);
    vSimpleList<vChar> l = vSimpleList<vChar>();
    vChar bs = vChar(61);
    std::cout<<"aaa"<<std::endl;
};

void pruebaPager(){
    vPager* vP = static_cast<vPager*>(malloc(sizeof(vPager)));
    new(vP) vPager();

    void* d = malloc(sizeof(int));
    *static_cast<int*>(d) = 8;

    string path = vP->pageDown(d,1,sizeof(d));

    void* dPaged = malloc(sizeof(int));
    vP->pageUp(path, sizeof(int), dPaged);

    cout<<"Ruta: "<<path<<endl;
    cout<<"Dato en RAM: "<<*static_cast<int*>(d)<<endl;
    cout<<"Dato leido del HD: "<<*static_cast<int*>(dPaged)<<endl;
};
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
    rapidjson::Document document;
    document.SetObject();
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    xml_document doc;
    doc.load_file("vHeap.xml");
    int size = doc.child("VH2015").child("vHeap").attribute("size").as_int();
    float over = doc.child("VH2015").child("vHeap").attribute("overweight").as_float();


    document.AddMember("TotalSize",(int)(size+size*over)*1024*1024,allocator);
    document.AddMember("UseSize",*vHeap::getInstance()->vSize,allocator);
    rapidjson::StringBuffer buffer;

    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    //Send some messages to the client
    // message = "Greetings! I am your connection handler\n";
    //write(sock , message , strlen(message));

    //message = "Now type something and i shall repeat what you type \n";
    //write(sock , message , strlen(message));

    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        //end of string marker
        client_message[read_size] = '\0';
        printf("Got %d bytes: %s\n", read_size, client_message);

        //Send the message back to client
        char json[1024];
        strcpy(json, buffer.GetString());
        write(sock , json , strlen(json));

        //clear the message buffer
        memset(client_message, 0, 2000);
        usleep(5000);
    }

    if(read_size == 0)
    {
        puts("Client disconnected");
        //fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    return 0;
};
void startSocket(){
    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 9500 );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");

    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);


    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    pthread_t thread_id;

    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");

        if( pthread_create( &thread_id , NULL ,  connection_handler , (void*) &client_sock) < 0)
        {
            perror("could not create thread");

        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( thread_id , NULL);
        puts("Handler assigned");
    }

    if (client_sock < 0)
    {
        perror("accept failed");

    }
};
int createDirectory(string path)
{

    return mkdir(path.c_str(), 0777);
}
int main() {
    string path = getenv("HOME");
    path.append("/.vh2015/");
    createDirectory(path);
    /*
    ///Redirects cout to output.txt
    ofstream out(path + "output.txt");
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf());
    */

    pruebaChar();
    pruebaInt();
    pruebaFloat();
    pruebaLong();


    //std::cout.rdbuf(coutbuf); //restore old buffer
    return 0;
};