#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include "../libs/rapidjson/rapidjson.h"
#include "../libs/rapidjson/document.h"
#include "../libs/rapidjson/stringbuffer.h"
#include "../libs/rapidjson/writer.h"
#include "../libs/pugixml.hpp"
#include "proof.h"
#include "Tree/Tree.h"
#include "Test/Headers/Ship.h"
#include "Constants.h"

using namespace std;
using namespace pugi;
using namespace rapidjson;

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
    Document document;
    const char* json = "{\"TotalSize\":\"0\",\"UseSize\":0}";
    document.Parse<0>(json);
    rapidjson::Value& s = document["TotalSize"];
    s.SetInt(vHeap::getInstance()->getSize());



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
      //  printf("Got %d bytes: %s\n", read_size, client_message);

        //Send the message back to client

        /*
        document.AddMember("TotalSize",(int)(size+size*over)*1024*1024,allocator);
        document.AddMember("UseSize",vHeap::getInstance()->getUse(),allocator);
        rapidjson::StringBuffer buffer;

        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);

         */
        rapidjson::Value& j = document["UseSize"];
        j.SetInt(vHeap::getInstance()->getUse());
        rapidjson::StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        document.Accept(writer);
        char json2[1024];
        strcpy(json2, buffer.GetString());
        write(sock , json2 , strlen(json2));
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
void* startSocket(void*){
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
    //puts("bind done");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection

    c = sizeof(struct sockaddr_in);
    pthread_t thread_id;

    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        //puts("Connection accepted");

        if( pthread_create( &thread_id , NULL ,  connection_handler , (void*) &client_sock) < 0)
        {
          //  perror("could not create thread");

        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( thread_id , NULL);
       // puts("Handler assigned");
    }

    if (client_sock < 0)
    {
        perror("accept failed");

    }
};

int main() {
    pthread_t thread;
    pthread_create(&thread,NULL,&startSocket,NULL);

   // begin();
    play();
    return 0;
};