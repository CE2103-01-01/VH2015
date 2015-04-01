#include <iostream>
#include <Test/Headers/TestApplication.h>
#include "vHeap/Headers/vHeap.h"
#include "src/vTypes/Headers/vChar.h"

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
    std::cout << "Resultado Esperado: 2,3,4,5,6" << std::endl;
    vList<int> *lista = new vList<int>();
    lista->append(5);
    lista->append(6);
    lista->add(4);
    lista->add(2);
    lista->add(3);
    lista->swap(0, 1);
    vListIterator<int> *i = lista->getIterator();
    while(i->exists())
    {
        std::cout<<*i->next()<<std::endl;
    }

    std::cout<<"Resultado Esperado: 2,3,4,5,6"<<std::endl;
}

void pruebaChar(){
    vChar chr = vChar(63);
    std::cout<<"Valor del vChar chr: "<< !chr <<std::endl;
};
void pruebaDumpTxt(){
    Dump dump;
    dump.saveDumpFile();

}

int main() {
    pruebaLista();
    //pruebaVHeap();
    //start(vString("vList"));

    return 0;
};