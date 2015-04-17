//
// Created by roberto on 17/04/15.
//

#include "proof.h"

void pruebaChar(){
    vRef<vChar> a = vMalloc(sizeof(vChar));
    vPlacement(a, vChar(65));
    std::cout<<"vChar A: "<<!(**a)<<std::endl;
    (**a)+=1;
    std::cout<<"vChar B: "<<!(**a)<<std::endl;
};

void pruebaFloat(){
    vRef<vFloat> a = vMalloc(sizeof(vFloat));
    vPlacement(a, vFloat(3.5));
    std::cout<<"vFloat 3.5: "<<!(**a)<<std::endl;
    (**a)+=1;
    std::cout<<"vFloat 4.5: "<<!(**a)<<std::endl;
};

void pruebaInt(){
    vRef<vInt> a = vMalloc(sizeof(vInt));
    vPlacement(a, vInt(3));
    std::cout<<"vInt 3: "<<!(**a)<<std::endl;
    (**a)+=1;
    std::cout<<"vInt 4: "<<!(**a)<<std::endl;
};

void pruebaLong(){
    vRef<vLong> a = vMalloc(sizeof(vLong));
    vPlacement(a, vLong(30000000));
    std::cout<<"vLong 30000000: "<<!(**a)<<std::endl;
    (**a)+=100;
    std::cout<<"vLong 30000100: "<<!(**a)<<std::endl;
};

void pruebaPager(){
    vPager* vP = static_cast<vPager*>(malloc(sizeof(vPager)));
    new(vP) vPager();

    void* d = malloc(sizeof(int));
    *static_cast<int*>(d) = 8;

    std::string path = vP->pageDown(d,1,sizeof(d));

    void* dPaged = malloc(sizeof(int));
    vP->pageUp(path, sizeof(int), dPaged);

    std::cout<<"Ruta: "<<path<<std::endl;
    std::cout<<"Dato en RAM: "<<*static_cast<int*>(d)<<std::endl;
    std::cout<<"Dato leido del HD: "<<*static_cast<int*>(dPaged)<<std::endl;
};

void pruebaArray(){
    vArray<vInt> arr = vArray<vInt>(5);
    for(vInt i = 0; i<5; i+=1){
        *(arr[i]) = i;
    };
    for(vInt i = 0; i<5; i+=1){
        std::cout<<"arr["<< !i <<"]= "<< !*(arr[i]) <<std::endl;
    };


};

void begin(){
    //pruebaPager();
    pruebaLong();
    pruebaInt();
    pruebaChar();
    pruebaFloat();
    pruebaArray();
};