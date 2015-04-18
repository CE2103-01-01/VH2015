//
// Created by roberto on 29/03/15.
//

#include "vTypes/Headers/vString.h"

vString::vString(std::string str){
    word = vSimpleList<char>();
    for(int i=0; i<str.length(); i++){
        word + static_cast<char>(str[i]);
    };
};

vString::~vString() {

};

void vString::operator +=(std::string str){
    for(int i=0; i<str.length(); i++){
        word + static_cast<char>(str[i]);
    };
};

void vString::operator +=(vString str){
    for(vInt i=0; i<str.len(); i+=1){
        word + !str[i];
    };
};

void vString::operator +=(vChar chr){
    word + !chr;
};

vChar vString::operator [](vInt index){
    return vChar(word[index]);
};

void vString::operator --(){

};

void vString::operator !(){
    for(vInt i=0; i<word.len(); i+=1){
        std::cout<<word[i];
    }
    std::cout<<std::endl;
};

bool vString::operator==(std::string str) {
    if (word.len() != str.length()){
        return false;
    }else{
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != !word[i]){
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
        for (vInt i = 0; i < str.len(); i+=1) {
            if (str[i] != word[i]){
                return false;
            }
        }
        return true;
    }
};

void vString::operator =(vString str){
    for (vInt i = 0; i < str.len(); i+=1) {
        word + !str[i];
    }
};

void vString::operator =(std::string str){
    for (vInt i = 0; i < str.length(); i+=1) {
        word + static_cast<char>(str[!i]);
    }
};

vInt vString::len() {
    return word.len();
};