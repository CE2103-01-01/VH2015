#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <vTypes/Headers/vBinaryTree.h>
#include "../libs/rapidjson/rapidjson.h"
#include "../libs/rapidjson/document.h"
#include "../libs/rapidjson/stringbuffer.h"
#include "../libs/rapidjson/writer.h"
#include "../libs/pugixml.hpp"
#include "src/vTypes/Headers/vDoubleList.h"
#include "proof.h"

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

void pruebaDumpTxt(){
    Dump dump;
    dump.saveDumpFile();

}

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
    begin();

    //pruebaDumpTxt();

    string path = getenv("HOME");
    path.append("/.vh2015/");
    createDirectory(path);

    /*
    ///Redirects cout to output.txt
    ofstream out(path + "output.txt");
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf());
    */

    vBinaryTree<int> myBinary = vBinaryTree<int>();
    myBinary.insert(2);
    myBinary.insert(4);
    myBinary.insert(1);
    myBinary.insert(5);



    //std::cout.rdbuf(coutbuf); //restore old buffer
    return 0;
};