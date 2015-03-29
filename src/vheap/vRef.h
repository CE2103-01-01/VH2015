//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VREF_H_
#define _VH2015_VREF_H_

class vRef {
    int referenceID;
    public:
        vRef(int ID);
        void changeID(int);
        virtual ~vRef();
        int operator *();
};

vRef::vRef(int id){
    referenceID=id;
};

vRef::~vRef(){};

void vRef::changeID(int id) {
    referenceID = id;
};

int vRef::operator*() {
    return referenceID;
}
#endif //_VH2015_VREF_H_
