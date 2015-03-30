#include <iostream>
#include "src/vheap/vHeap.h"
using namespace std;

int main(){
    int a = static_cast<int>(1.0);
    std::cout<<"Hola"<<std::endl;
    List<std::string>* lista = new List<std::string>();
    lista->append("hoola");
    lista->append("as");
    lista->add("s");
    //lista->add(3);
    //lista->add(2);
    ListIterator<std::string>* i = lista->getIterator();
    while(i->exists())
    {
        std::cout<<*i->next()<<std::endl;
    }
    std::cout<<"Resultado Esperado: 2,3,4,5,6"<<std::endl;
    vHeap* vH = vHeap::getInstance();
    vRef r1 = vH->vMalloc(4,"t1");
    vRef r2 = vH->vMalloc(2,"t2");
    vRef r3 = vH->vMalloc(8,"t3");
    
    return 0;
};
