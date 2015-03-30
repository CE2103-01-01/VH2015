#include <iostream>
#include "src/vheap/vHeap.h"
#include "src/vTypes/vString.h"
using namespace std;

int main(){

    vString* str = static_cast<vString*>(malloc(sizeof(vString)));
    new(str) vString("Hola");
    !(*str);

    --(*str);
    !(*str);

    std::cout<<(*str)[0]<<std::endl;

    std::string s="a";
    (*str)+=s;
    std::cout<<"aa"<<std::endl;
    !(*str);


    /**
    std::cout<<"Hola"<<std::endl;
    vList<std::string>* lista = new vList<std::string>();
    //lista->append("hoola");
    //lista->append("as");
    //lista->add("s");
    //lista->add(3);
    //lista->add(2);
    vListIterator<std::string>* i = lista->getIterator();
    while(i->exists())
    {
<<<<<<< Updated upstream
        std::cout<<*i->next()<<std::endl;
=======
        std::cout <<* i->next() << std::endl;
>>>>>>> Stashed changes
    }
     /**

    std::cout<<"Resultado Esperado: 2,3,4,5,6"<<std::endl;
    vHeap* vH = vHeap::getInstance();
    vRef r1 = vH->vMalloc(4,"t1");
    vRef r2 = vH->vMalloc(2,"t2");
    vRef r3 = vH->vMalloc(8,"t3");
    //vH->printMetadata();
*/
     return 0;
};
