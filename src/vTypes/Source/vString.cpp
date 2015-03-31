//
// Created by roberto on 29/03/15.
//

#include "vTypes/Headers/vString.h"

vString::vString(std::string str){
    word = static_cast<vList<char> *>(malloc(sizeof(vList<char>)));
    new(word) vList<char>();
    for(int i=0; i<str.length(); i++){
        word->append(static_cast<char>(str[i]));
    };
};

vString::~vString() {
    free(word);
};

int vString::operator +=(std::string str){
    for(int i=0; i<str.length(); i++){
        std::cout<<i<<std::endl;
        word->append(static_cast<char>(str[i]));
    };
    return 0;
};


char vString::operator [](int index){
    return *word->get(index);
};

int vString::operator --(){
    if(word->len()>0){
        word->deleteNode(word->len()-1);
    };
    return 0;
};

int vString::operator !(){
    vListIterator<char> *iter = word->getIterator();
    while(iter->exists()){
        std::cout<<*(iter->next());
    };
    std::cout<<std::endl;
    return 0;
};

bool vString::operator==(std::string string) {
    if (string.length() != word->len()) return false;
    else {
        for (unsigned int i = 0; i < string.length(); i++) {
            if (string[i] != *word->get(i)) return false;
        }
        return true;
    }
}
