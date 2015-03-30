//
// Created by roberto on 29/03/15.
//

#include "vString.h"

vString::vString(std::string str){
    word = static_cast<List<char>*>(malloc(sizeof(List<char>)));
    new(word) List<char>();
    for(int i=0; i<str.length(); i++){
        word->append(static_cast<char>(str[i]));
    };
};

vString::~vString() {
    free(word);
};

int vString::operator +=(std::string str){
    for(int i=0; i<str.length(); i++){
        word->append(static_cast<char>(str[i]));
    };
    return 0;
};

char vString::operator [](int index){
    return word->get(index);
};

int vString::operator --(){
    if(word->len()>0){
        word->deleteNode(word->len()-1);
    };
    return 0;
};

int vString::operator !(){
    ListIterator<char>* iter = word->getIterator();
    while(iter->exists()){
        std::cout<<*(iter->next());
    };
    std::cout<<std::endl;
    return 0;
};