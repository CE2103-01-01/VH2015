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
    vArray<int> arr = vArray<int>(5);
    for(int i = 0; i<5; i++){
        *(arr[i]) = i;
    };
    for(int i = 0; i<5; i++){
        std::cout<<"arr["<< i <<"]= "<< *(arr[i]) <<std::endl;
    };
};

void pruebaSimpleList(){
    vSimpleList<int> a = vSimpleList<int>();
    vRef<vSimpleList<int>> r = vMalloc(sizeof(a));
    vPlacement(r,a);
    (**r)+0;
    std::cout<< "vSimpleList[0] = 0 : " << (**r)[0] <<std::endl;
    (**r)+1;
    std::cout<< "vSimpleList[1] = 1 : " << (**r)[1] <<std::endl;
    (**r)+2;
    std::cout<< "vSimpleList[2] = 2 : " << (**r)[2] <<std::endl;
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
    vBinaryTree<vString> myBinary = vBinaryTree<vString>();
    myBinary.insert(vString("a"));
    myBinary.insert(vString(""));

};

void begin(){
    pruebaPager();
    pruebaLong();
    pruebaInt();
    pruebaChar();
    pruebaFloat();
    pruebaArray();
    pruebaSimpleList();
    pruebaDoubleList();
    pruebaString();
    //pruebaTree();
    std::cout<<"FIN DE LAS PRUEBAS"<<std::endl;
};