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
    int max();
public:
    Tree();
    ~Tree();
    T* searchElement(int);
    void insertElement(T);
    void deleteElement(T);
    Leaf* getRoot();
};

template <class T> Tree::Tree(){
    root = (Leaf*)(malloc(sizeof(Leaf)));
    new(root) Leaf(0,treeSize);
    len = (int*)(malloc(sizeof(int)));
    *len = 0;
    floors = (int*)(malloc(sizeof(int)));
    *floors= 0;
};

template <class T> Tree::~Tree(){
    free(len);
    free(root);
    free(floors);
};

template <class T> int Tree::max(){
    int res = treeSize-1;
    for(int i = 1; i<*floors; i++){
        res += i*i*(treeSize-1);
    }
    return res;
};

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
};

template <class T> T* Tree::searchElement(int index){

};

template <class T> void Tree::insertElement(T* param){
    if(*len < max()){

    }else{
        split(root);
    }
};

template <class T> void Tree::deleteElement(int index){
    searchElement(index);
};

template <class T> Leaf* Tree::getRoot(){
    return root;
};

#endif //VH2015_TREE_H