//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VREF_H_
#define _VH2015_VREF_H_


class vRef {
public:
    vRef(vObject object,int* ID);
    void changeID(int* id);
    <vObject>operator*();
    <vRef>operator=();
    <vRef>operator ==();
   // <vRef>operator ++();

    <vRef>operator --();

    virtual ~vRef();
protected:
private:
    int* referenceID;
    vObject object;
};


#endif //_VH2015_VREF_H_