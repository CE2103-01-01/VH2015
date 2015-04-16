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

vList<char>* vString::operator !(){
    return word;
};

bool vString::operator==(std::string string) {
    if (string.length() != word->len()) return false;
    else {
        for (unsigned int i = 0; i < string.length(); i++) {
            if (string[i] != *word->get(i)) return false;
        }
        return true;
    }
};

bool vString::operator==(vString str) {
    if ((!str)->len() != word->len()){
        return false;
    }else {
        vListIterator<char>* iter1 = word->getIterator();
        vListIterator<char>* iter2 = (!str)->getIterator();
        while(iter1->exists()){
                if(iter1->next() != iter2->next()){
                    return false;
	        };
        };
        return true;
    }
};

int vString::operator +=(vString str){
    vListIterator<char>* iter = (!str)->getIterator();
    while(iter->exists()){
        word->append(*static_cast<char*>(iter->next()));
    };
    return 0;
};

int vString::operator =(vString str){
	if(word!=0){
	    vListIterator<char>* iter = (!str)->getIterator();
	    word->deleteAll();
	    while(iter->exists()){
	        word->append(*static_cast<char*>(iter->next()));
    	    };
            return 0;
	}else{    
            word = static_cast<vList<char> *>(malloc(sizeof(vList<char>)));
            new(word) vList<char>();
	    vListIterator<char>* iter = (!str)->getIterator();
            while(iter->exists()){
	        word->append(*static_cast<char*>(iter->next()));
    	    };
            return 0;
	};
};

int vString::operator =(std::string str){
	if(word!=0){
	    word->deleteAll();
        for(int index=0; index<str.length(); index++){
            word->append(static_cast<char>(str[index]));
        }
	}else{    
        word = static_cast<vList<char> *>(malloc(sizeof(vList<char>)));
        new(word) vList<char>();
        for(int i=0; i<str.length(); i++){
            word->append(static_cast<char>(str[i]));
        }
        return 0;
	};
};

bool vString::operator>=(vString str) {
        vListIterator<char>* iter1 = word->getIterator();
        vListIterator<char>* iter2 = (!str)->getIterator();
        while(iter1->exists() && iter2->exists()){
            if(iter1->next() >=  iter2->next()){
                return true;
            };
        };
    if (iter1->exists()) return true;
    return false;

}

unsigned int vString::len() {
    return word->len();
}
