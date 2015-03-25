#ifndef VHEAP_H
#define VHEAP_H

#include <stdlib.h>
#include "Metadata.h"
#include "vRef.h"
#include "dataStructures.h"

class vHeap
{
    int* overweight;
    void* mainChunk;
    void* actualDir;
    int* actualID;
    Lista<Metadata>* control;
    public:
        vHeap(int, int);
        virtual ~vHeap();
        vRef vMalloc(int,std::string);
        void vFree(vRef);
        void printMetadata();
};



/** Constructor
*
* @param int oW is the overweight
* @param int oW is the size of the main chunk
*/
vHeap::vHeap(int oW, int cS){
    overweight=static_cast<int*>(malloc(sizeof(int)));
    *overweight=oW;
    mainChunk=malloc(cS);
    actualDir=mainChunk;
    actualID=static_cast<int*>(malloc(sizeof(int)));
    *actualID=0;
    control=static_cast<Lista<Metadata>*>(malloc(sizeof(Lista<Metadata>)));
    new(control) Lista<Metadata>();
};

/** Destructor
*
*/
vHeap::~vHeap(){
    free(overweight);
    free(mainChunk);
};

/** vMalloc
*
* @param int s is the size
* @param string t is the type
*/
vRef vHeap::vMalloc(int s, std::string t){
    Metadata n = Metadata(*actualID,s,actualDir);
    actualDir+=s;
    *actualID+=1,
    control->insertarAlFinal(n);
    return vRef(*actualID-1);
};

void vHeap::vFree(vRef){};

void vHeap::printMetadata(){
    if(control->len()>0){
        for(int i=0; i<control->len(); i++){
            (control->datoPosicion(i)).print();
        };
    }else{
        std::cout<<"La lista esta vacia"<<std::endl;
    };
};

#endif // VHEAP_H
