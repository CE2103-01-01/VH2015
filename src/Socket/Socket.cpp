//
// Created by roberto on 05/05/15.
//

#include "Socket.h"

using namespace std;
using namespace rapidjson;

void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
    Document document;
    const char* json = "{\"TotalSize\":\"0\",\"UseSize\":0}";
    document.Parse<0>(json);

    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        //end of string marker
        client_message[read_size] = '\0';
        rapidjson::Value& j = document["UseSize"];
        j.SetInt(vHeap::getInstance()->getUse());
        rapidjson::Value& s = document["TotalSize"];
        s.SetInt(vHeap::getInstance()->getSize());
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

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection

    c = sizeof(struct sockaddr_in);
    pthread_t thread_id;

    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        pthread_create( &thread_id , NULL ,  connection_handler , (void*) &client_sock);
    }

    if (client_sock < 0)
    {
        perror("accept failed");

    }
}