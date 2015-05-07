#include "Socket.h"
#include "Test/proof.h"

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
    //pthread_create(static_cast<pthread_t*>(socketThread),0,&startSocket,0);
    pthread_create(static_cast<pthread_t*>(defragmenterThread),0,vDefragmentThread,defragmenterObject);
    pthread_create(static_cast<pthread_t*>(dumpThread),0,dump,dumpObject);

    //Se ejecuta la prueba
    begin();
    //play();

    //Se libera el espacio utilizado
    free(socketThread);
    free(defragmenterThread);
    free(dumpThread);
    free(dumpObject);
    free(defragmenterObject);
    //Limpia folder de paginas

    vPager::clean();

    return 0;
}