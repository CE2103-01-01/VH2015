//
// Created by roberto on 19/04/15.
//

#ifndef VH2015_TREE_H
#define VH2015_TREE_H

#include "Leaf.h"
#include <cstdlib>

const int treeSize=25;

template <class T> class Tree{
    int* len;
    int* floors;
    Leaf* root;
    void split(Leaf*);
    int max(int);
public:
    Tree();
    ~Tree();
    T* searchElement(int);
    void insertElement(T,int);
    void deleteElement(T);
    Leaf* getRoot();
};

template <class T> Tree::Tree(){
    root = (Leaf*)(malloc(sizeof(Leaf)));
    new(root) Leaf(0,treeSize);
    len = (int*)(malloc(sizeof(int)));
    *len = 0;
    floors = (int*)(malloc(sizeof(int)));
    *floors= 1;
}

template <class T> Tree::~Tree(){
    free(len);
    free(root);
    free(floors);
}

template <class T> int Tree::max(int floor){
    int res = treeSize-1;
    for(int i = 1; i<floor; i++){
        res += i*i*(treeSize-1);
    }
    return res;
}

template <class T> void Tree::split(Leaf* toSplit){
    if(!(toSplit->isTerminal())){
        void* sons = toSplit->getSons();
        for(int i=0; i<treeSize; i++){
            split((Leaf*)(sons+i*sizeof(Leaf)));
        };
    }else{
        toSplit->split(treeSize);
    };
    (*floors)++;
}

template <class T> T* Tree::searchElement(int index){
    index--;
    void* path = malloc((*floors)*sizeof(int));
    for(int i=*floors; i>0;i--){
        *((int*)path+i) = index%treeSize;
        index-=max(i-1);
    }
    void* tmp = (void*)root;
    for(int i=0; i<*floors-1; i++){
        tmp = ((Leaf*)tmp)->getSons() + *((int*)(path+i*sizeof(Leaf)));
    }
    tmp = ((Leaf*)(tmp))->getContainers() + *((int*)(path+(*floors)*sizeof(Container)));
    free(path);
    return (T*)(((Container*)(tmp))->getData());
}

template <class T> void Tree::insertElement(T* param, int index){
    if((*len)+1 < max(*floors)){
        index--;
        void* path = malloc((*floors)*sizeof(int));
        for(int i=*floors; i>0;i--){
            *((int*)path+i) = index%treeSize;
            index-=max(i-1);
        }
        void* tmp = (void*)root;
        for(int i=0; i<*floors-1; i++){
            tmp = ((Leaf*)tmp)->getSons() + *((int*)(path+i*sizeof(Leaf)));
        }
        tmp = ((Leaf*)(tmp))->getContainers() + *((int*)(path+(*floors)*sizeof(Container)));
        ((Container*)(tmp))->setData((void*)(param));
        free(path);
        (*len)++;
    }else{
        split(root);
        insertElement(param,index);
    }
}

template <class T> void Tree::deleteElement(int index){
    index--;
    void* path = malloc((*floors)*sizeof(int));
    for(int i=*floors; i>0;i--){
        *((int*)path+i) = index%treeSize;
        index-=max(i-1);
    }
    void* tmp = (void*)root;
    for(int i=0; i<*floors-1; i++){
        tmp = ((Leaf*)tmp)->getSons() + *((int*)(path+i*sizeof(Leaf)));
    }
    tmp = ((Leaf*)(tmp))->getContainers() + *((int*)(path+(*floors)*sizeof(Container)));
    free(((Container*)(tmp))->getData());
    ((Container*)(tmp))->setData(0);
    free(path);
}

template <class T> Leaf* Tree::getRoot(){
    return root;
}

#endif //VH2015_TREE_H