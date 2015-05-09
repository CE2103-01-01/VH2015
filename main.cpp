#include <Test/Headers/Ship.h>
#include <Test/Headers/TestApplication.h>
#include "Socket/Socket.h"
#include "Test/Headers/proof.h"
#include "vHeap/Headers/vCleaner.h"

int main() {
    //Se inicializa vHeap
    //Se reserva memoria para los pthreads
    void* socketThread =  malloc(sizeof(pthread_t));
    void* defragmenterThread =  malloc(sizeof(pthread_t));
    void* dumpThread =  malloc(sizeof(pthread_t));
    //Se crea el desfragmentador
    void* defragmenterObject = malloc(sizeof(vDefragmenter));
    new(static_cast<vDefragmenter*>(defragmenterObject))
            vDefragmenter(vHeap::getInstance()->getInitPos(),vHeap::getInstance()->getFinalPos());
    //Se crea el dump
    void* dumpObject = malloc(sizeof(Dump));
    new(static_cast<Dump*>(dumpObject)) Dump();
    //Se inicializan los pthreads
    pthread_create(static_cast<pthread_t*>(socketThread),0,&startSocket,0);
    pthread_create(static_cast<pthread_t*>(defragmenterThread),0,vDefragmentThread,defragmenterObject);
    pthread_create(static_cast<pthread_t*>(dumpThread),0,dump,dumpObject);

    //Se ejecuta la prueba
    createVDoubleList();
    begin();
    play();

    //Se libera el espacio utilizado
    free(socketThread);
    free(defragmenterThread);
    free(dumpThread);
    free(dumpObject);
    free(defragmenterObject);
    //Limpia folder de paginas

    vCleaner::clean(Constants::PAGES_PATH);
    vCleaner::clean(Constants::DUMPS_PATH);

    return 0;
}