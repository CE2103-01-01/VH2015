//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VREF_H_
#define _VH2015_VREF_H_

class vRef {
    public:
    vRef(int ID);
    int referenceID;
    void changeID(int);
    virtual ~vRef();
};

#endif //_VH2015_VREF_H_
