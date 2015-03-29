#include <iostream>
#include "src/vheap/vHeap.h"

int main(){
    vHeap* vH = static_cast<vHeap*>(malloc(sizeof(vHeap)));
    new(vH) vHeap(100,100);
    vRef r1 = vH->vMalloc(4,"t1");
    vRef r2 = vH->vMalloc(2,"t2");
    vRef r3 = vH->vMalloc(8,"t3");
    vH->printMetadata();
    return 0;
};
