//
// Created by alex on 20/03/15.
//


vHeap::vHeap(int s, float o){
    overweight=static_cast<float*>(malloc(sizeof(float)));
    *overweight=o;

    actualID=static_cast<int*>(malloc(sizeof(int)));
    *actualID=0;

    mainChunk=malloc(s);
    actualPos=mainChunk;

    memoryTable=static_cast<List<vMallocMetaData>*>(malloc(sizeof(List<vMallocMetaData>)));//TODO-roberto arreglar
    new(memoryTable) List<vMallocMetaData>();

    vDebug=static_cast<bool*>(malloc(sizeof(bool)));
    dumpFrecuency=static_cast<int*>(malloc(sizeof(int)));
};

vHeap::~vHeap(){
    free(overweight);
    free(vDebug);
    free(memoryTable);
    free(mainChunk);
    free(dumpFrecuency);
};



vHeap::vHeap(int s, float o){
    overweight=static_cast<float*>(malloc(sizeof(float)));
    *overweight=o;

    actualID=static_cast<int*>(malloc(sizeof(int)));
    *actualID=0;

    mainChunk=malloc(s);
    actualPos=mainChunk;

    memoryTable=static_cast<List<vMallocMetaData>*>(malloc(sizeof(List<vMallocMetaData>)));//TODO-roberto hay un error aqui
    new(memoryTable) List<vMallocMetaData>();

    vDebug=static_cast<bool*>(malloc(sizeof(bool)));
    dumpFrecuency=static_cast<int*>(malloc(sizeof(int)));

    //singleton=this;
};

vHeap::~vHeap(){
    free(overweight);
    free(vDebug);
    free(memoryTable);
    free(mainChunk);
    free(dumpFrecuency);
};

vRef vHeap::vMalloc(int sz, std::string type){
    vRef r= vRef(*actualID);
    vMallocMetaData m = vMallocMetaData(sz,type,(*actualID)++,actualPos);
    memoryTable->append(m);
    actualPos+=sz;

    return r;
};

void vHeap::printMetadata(){
    ListIterator<vMallocMetaData>* iter;
    memoryTable->getIterator(iter);
    std::cout<<"ANTES DE ENTRAR AL WHILE"<<std::endl;
    while(iter->exists()){
        std::cout<<"DENTRO DEL WHILE"<<std::endl;

        vMallocMetaData* m = iter->next();
        std::cout<<
        "ID: "   << m->getId()   <<
        "Size: " << m->getSize() <<
        "Type: " << m->getType() <<
        std::endl;
    };
};


vHeap* vHeap::getInstance() {
    if(!vHeapSingleton)
        *vHeapSingleton = vHeap(0,0);//TODO-ernesto obtener datos del xml
    return vHeapSingleton;

}
