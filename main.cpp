#include <iostream>
#include "src/vheap/vHeap.h"
#include "vheap/List.h"

int main(){
    List<int>* lista = new List<int>();
    lista->append(5);
    lista->append(6);
    lista->add(4);
    lista->add(3);
    lista->add(2);
    ListIterator<int>* i;
    lista->getIterator(i);
    while(i->exists())
    {
        std::cout<<i->next()<<std::endl;
    }
    std::cout<<"Resultado Esperado: 2,3,4,5,6"<<std::endl;
    vHeap* vH = vHeap::getInstance();
    vRef r1 = vH->vMalloc(4,"t1");
    vRef r2 = vH->vMalloc(2,"t2");
    vRef r3 = vH->vMalloc(8,"t3");
    vH->printMetadata();
    return 0;
};
