//
// Created by roberto on 05/05/15.
//

#ifndef VH2015_SOCKET_H
#define VH2015_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include "../libs/rapidjson/rapidjson.h"
#include "../libs/rapidjson/document.h"
#include "../libs/rapidjson/stringbuffer.h"
#include "../libs/rapidjson/writer.h"

void *connection_handler(void*);
void* startSocket(void*);

#endif //VH2015_SOCKET_H
