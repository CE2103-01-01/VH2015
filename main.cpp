#include <iostream>
#include <Test/Headers/TestApplication.h>
#include "vHeap/Headers/vRef.h"
#include "src/vTypes/Headers/vChar.h"
#include "src/vHeap/Headers/vPager.h"
#include "../libs/vheaplibpp.h"

using namespace std;

void pruebaVHeap() {
    vRef r1 = vRef(vMalloc(sizeof(int)));
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
    vChar chr;
    chr = (char)63;
    std::cout<<"Valor del vChar chr: "<< !chr <<std::endl;
};
void pruebaDumpTxt(){
    Dump dump;
    dump.saveDumpFile();

}

void pruebaPager(){
    vPager* vP = static_cast<vPager*>(malloc(sizeof(vPager)));
    new(vP) vPager();

    void* d = malloc(sizeof(int));
    *static_cast<int*>(d) = 8;

    string path = vP->pageDown(d,1,sizeof(d));

    void* dPaged = malloc(sizeof(int));
    vP->pageUp(path, sizeof(int), dPaged);

    cout<<"Ruta: "<<path<<endl;
    cout<<"Dato en RAM: "<<*static_cast<int*>(d)<<endl;
    cout<<"Dato leido del HD: "<<*static_cast<int*>(dPaged)<<endl;
};

int main() {
    pruebaPager();
    //pruebaListaSimple();
    //pruebaLista();
    //pruebaVHeap();
    //start(vString("vList"));

    return 0;
};