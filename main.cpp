#include <iostream>
#include <Test/Headers/TestApplication.h>
#include "vHeap/Headers/vRef.h"
#include "src/vTypes/Headers/vChar.h"
#include "src/vTypes/Headers/vInt.h"
#include "src/vTypes/Headers/vLong.h"
#include "src/vTypes/Headers/vFloat.h"
#include "src/vTypes/Headers/vSimpleList.h"

//TODO: implementar vArray
//TODO: cambiar vBinaryTree de heap a vHeap
//TODO: cambiar vString de heap a vHeap
//TODO: cambiar vSimpleList de heap a vHeap
//TODO: implementar vDoubleList
//TODO: implementar vDebuger
//TODO: aplicación de prueba
//TODO: vHeap como servidor
//TODO: visores de uso y dump de memoria

using namespace std;

template<class T> int vPlacement(vRef<T> vR, T toPlace);

void pruebaVHeap() {
    vRef<int> r1 = vRef<int>(vMalloc(sizeof(int)));
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
    vChar a = vChar(65);
    vRef<vChar> b = &a;
    std::cout<<"A(65): "<<!**b<<std::endl;

    vChar c = vChar(67);
    vRef<vChar> d = &c;
    std::cout<<"C(67): "<<!**d<<std::endl;

    vChar e = vChar(70);
    vRef<vChar> f = &e;
    std::cout<<"F(70): "<<!**f<<std::endl;
};

void pruebaFloat(){
    vFloat a = vFloat(3.5);
    vRef<vFloat> b = &a;
    std::cout<<"vFloat 3.5: "<<!**b<<std::endl;

    vFloat c = vFloat(5.66);
    vRef<vFloat> d = &c;
    std::cout<<"vFloat 5.66: "<<!**d<<std::endl;

    vFloat e = vFloat(0.2111);
    vRef<vFloat> f = &e;
    std::cout<<"vFloat 0.2111: "<<!**f<<std::endl;
};

void pruebaInt(){
    vInt a = vInt(10);
    vRef<vInt> b = &a;
    std::cout<<"vInt 10: "<<!**b<<std::endl;

    vInt c = vInt(1);
    vRef<vInt> d = &c;
    std::cout<<"vInt 1: "<<!**d<<std::endl;

    vInt e = vInt(500);
    vRef<vInt> f = &e;
    std::cout<<"vInt 500: "<<!**f<<std::endl;
};

void pruebaLong(){
    vLong a = vLong(1000000);
    vRef<vLong> b = &a;
    std::cout<<"vLong 1000000: "<<!**b<<std::endl;

    vLong c = vLong(100000000000);
    vRef<vLong> d = &c;
    std::cout<<"vLong 100000000000: "<<!**d<<std::endl;

    vLong e = vLong(1000000000);
    vRef<vLong> f = &e;
    std::cout<<"vLong 1000000000: "<<!**f<<std::endl;
};

void pruebaDumpTxt(){
    Dump dump;
    dump.saveDumpFile();

}

void pruebaListaSimple(){
    unsigned int id = vMalloc(sizeof(vSimpleList<vChar>));
    vRef<vSimpleList<vChar>> lista;
    lista =  vRef<vSimpleList<vChar>>(id);
    vSimpleList<vChar> l = vSimpleList<vChar>();
    vChar bs = vChar(61);
    std::cout<<"aaa"<<std::endl;
};

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
    pruebaChar();
    pruebaInt();
    pruebaFloat();
    pruebaLong();

    //pruebaPager();
    //pruebaListaSimple();
    //pruebaLista();
    //pruebaVHeap();
    //start(vString("vList"));
    Dump dump;
    dump.saveDumpFile();
    return 0;
};