#include <iostream>
#include "src/vheap/vHeap.h"
#include "src/vTypes/vString.h"
#include "src/vTypes/vSimpleList.h"
#include "src/vTypes/vSimpleList.cpp"
#include "src/vTypes/vChar.h"

using namespace std;

void pruebaVHeap() {
    vHeap *vH = vHeap::getInstance();
    vRef r1 = vH->vMalloc(4, "t1");
    vRef r2 = vH->vMalloc(2, "t2");
    vRef r3 = vH->vMalloc(8, "t3");
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

    std::cout<<"Hola"<<std::endl;
    vList<std::string>* lista = new vList<std::string>();
    lista->append("hoola");
    lista->append("as");
    lista->add("s");
    //lista->add(3);
    //lista->add(2);
    vListIterator<std::string>* i = lista->getIterator();
    while(i->exists())
    {
        std::cout<<*i->next()<<std::endl;
    }

    std::cout<<"Resultado Esperado: 2,3,4,5,6"<<std::endl;
}

void pruebaChar(){
    vChar chr = vChar(60);
};

int main() {
    /**
    pruebaVString();
    vSimpleList<std::string> lista;
    lista.add_end("a");
    lista.add_end("l");
    lista.add_end("e");
    lista.add_end("x");
    lista.print();
    */
    
    pruebaChar();
    return 0;
};