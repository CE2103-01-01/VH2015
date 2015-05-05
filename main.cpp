#include "proof.h"
#include "Socket.h"
#include "Test/Headers/Ship.h"

int main() {
    pthread_t thread;
    pthread_create(&thread,NULL,&startSocket,NULL);

    //begin();
    play();
    return 0;
}