//
// Created by roberto on 29/03/15.
//

#include "vTypes/Headers/vString.h"

vString::vString(std::string str){
    word = vSimpleList<char>();
    for(int i=0; i<str.length(); i++){
        (word) + static_cast<char>(str[i]);
    };
};

vString::~vString() {

};

void vString::operator +=(std::string str){
    for(int i=0; i<str.length(); i++){
        (word) + (static_cast<char>(str[i]));
    };
};

void vString::operator +=(vString str){
    for(int i=0; i < !str.len(); i++){
        (word) + !(str[i]);
    };
};

void vString::operator +=(vChar chr){
    (word) + !chr;
};

void vString::operator +=(char chr){
    (word) + chr;
};

char vString::operator [](int index){
    return (word)[index];
};

void vString::operator --(){
    --word;
};

std::string vString::operator !(){
    std::string ret = "";
    if(word.len() > 0){
        for(int i=0; i < word.len(); i++){
            std::stringstream tmp;
            tmp << (word)[i];
            ret.append(tmp.str());
        };
    };
    return ret;
};

bool vString::operator==(std::string str) {
    if ((word).len() != str.length()){
        return false;
    }else{
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != !(word)[i]){
                return false;
            }
        }
        return true;
    }
};

bool vString::operator==(vString str) {
    if (word.len() != str.len()){
        return false;
    }else{
        for (int i = 0; i < !str.len(); i+=1) {
            if (str[i] != (word)[i]){
                return false;
            }
        }
        return true;
    }
};

void vString::operator =(vString str){
    for (int i = 0; i < !str.len(); i+=1) {
        (word) + str[i];
    }
};

void vString::operator =(std::string str){
    for (int i = 0; i < str.length(); i+=1) {
        (word) + static_cast<char>(str[i]);
    }
};

//longitud
int vString::len() {
    return word.len();
};

bool vString::operator>=(std::string str) {
    for (int i = 0; i < word.len() && i < str.length(); i+=1) {
        if (word[i]<str[i]) return false;
    }
    return true;
}

bool vString::operator>=(vString str) {
    for (int i = 0; i < word.len() && i < str.len(); i+=1) {
        if (word[i]<str[i]) return false;
    }
    return true;
}
