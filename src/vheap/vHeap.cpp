//
// Created by alex on 20/03/15.
//

#include "vHeap.h"
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
    control=static_cast<List<Metadata>*>(malloc(sizeof(List<Metadata>)));
    new(control) List<Metadata>();
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