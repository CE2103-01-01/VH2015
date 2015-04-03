#include <iostream>
#include <Test/Headers/TestApplication.h>
#include "vHeap/Headers/vRef.h"
#include "src/vTypes/Headers/vChar.h"
#include "src/vTypes/Headers/vSimpleList.h"
#include "../libs/vheaplib.h"
#include "../libs/vheaplib.h"
#include "../libs/vheaplibpp.h"

using namespace std;

void pruebaVHeap() {
    vRef<int> r1 = vMalloc<int>(sizeof(int), "int");
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
    lista->append(2);
    lista->add(4);
    lista->add(3);
    lista->add(6);
    lista->swap(0, 5);
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

void pruebaListaSimple(){
    vRef<vSimpleList<vChar>> lista = vMalloc<vSimpleList<vChar>>(sizeof(vSimpleList<vChar>), "vSimpleList");
    vSimpleList<vChar> l = vSimpleList<vChar>();
    vPlacement<vSimpleList<vChar>>(lista, l);

};

int main() {
    int i = 0;
    cout << i++ << endl;
    pruebaListaSimple();
    //pruebaLista();
    //pruebaVHeap();
    //start(vString("vList"));

    return 0;
};