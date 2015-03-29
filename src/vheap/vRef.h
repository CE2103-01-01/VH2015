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

#endif //_VH2015_VREF_H_
