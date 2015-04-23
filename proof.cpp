//
// Created by roberto on 17/04/15.
//

#include "proof.h"

void pruebaChar(){
    vChar a = vChar(65);
    std::cout<<"vChar A: "<< !a <<std::endl;
    a+=1;
    std::cout<<"vChar B: "<< !a <<std::endl;
};

void pruebaFloat(){
    vFloat a = vFloat(3.5);
    std::cout<<"vFloat 3.5: "<< !a <<std::endl;
    a+=1;
    std::cout<<"vFloat 4.5: "<< !a <<std::endl;
};

void pruebaInt(){
    vInt a = vInt(3);
    std::cout<<"vInt 3: "<< !a <<std::endl;
    a+=1;
    std::cout<<"vInt 4: "<< !a <<std::endl;
};

void pruebaLong(){
    vLong a = vLong(3000000);
    std::cout<<"vLong 3000000: "<< !a <<std::endl;
    a+=100;
    std::cout<<"vLong 3000100: "<< !a <<std::endl;
};

void pruebaPager(){
    vPager pager;

    void* dataHeap = malloc(sizeof(long));
    *static_cast<long*>(dataHeap) = 80000000000000;

    pager.pageDown(dataHeap,1,sizeof(long));

    void* dataPaged = malloc(sizeof(long));
    pager.pageUp(dataPaged,1,sizeof(long));

    std::cout<<"Dato en RAM: "<<*static_cast<long*>(dataHeap)<<std::endl;
    std::cout<<"Dato leido del HD: "<<*static_cast<long*>(dataPaged)<<std::endl;
};

void pruebaArray(){
    vArray<int> arr1 = vArray<int>(1500);
    for(int i = 0; i<1500; i+=1) *(arr1[i]) = i;
    vArray<int> arr2 = vArray<int>(1500);
    for(int i = 0; i<1500; i+=1) *(arr2[i]) = i;
    vArray<int> arr3 = vArray<int>(1500);
    for(int i = 0; i<1500; i+=1) *(arr3[i]) = i;

    for(int i = 0; i<1500; i+=1){
        std::cout<<"arr1["<< i <<"]= "<< *(arr1[i]) <<std::endl;
        std::cout<<"arr2["<< i <<"]= "<< *(arr2[i]) <<std::endl;
        std::cout<<"arr3["<< i <<"]= "<< *(arr3[i]) <<std::endl;
    }
};

void pruebaSimpleList(){
    vSimpleList<int> a = vSimpleList<int>();
    vRef<vSimpleList<int>> r = vMalloc(sizeof(a));
    vPlacement(r,a);
    for(int i=0; i<10; i++){
        (**r)+i;
    }
};

void pruebaDoubleList(){
    vDoubleList<int> hola = vDoubleList<int>();
    vRef<vDoubleList<int>> r = vMalloc(sizeof(hola));
    vPlacement(r,hola);
};

void pruebaString(){
    vString a = vString("hola ");
    a+="a ";
    a+="todos";
    std::cout<<"impresion vString: "<<!a<<std::endl;
    --a;
    std::cout<<"impresion vString borrado: "<<!a<<std::endl;
};

void pruebaTree(){
    Tree<int>* tr = static_cast<Tree<int>*>(malloc(sizeof(Tree<int>)));
    new(tr) Tree<int>();
    for(int i=0; i<10000; i++){
        tr->insertElement(i,i);
    }
    std::cout<< "longitud del arbol: "<< tr->lenght() <<std::endl;
    free(tr);
};

void begin(){
    pruebaTree();
    pruebaSimpleList();
    pruebaDoubleList();
    pruebaString();
    pruebaLong();
    pruebaInt();
    pruebaChar();
    pruebaFloat();
    pruebaArray();

    std::cout<<"FIN DE LAS PRUEBAS"<<std::endl;
};