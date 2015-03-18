//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VREF_H_
#define _VH2015_VREF_H_


class vRef {
public:
    vRef(vObjetc object,int* ID);
    void changeID(int* id);
    <vRef>operator*();
    <vRef>operator=();
    <vRef>operator ==();
   // <vRef>operator ++();
    <vRef>operator*(vRef reference);
    <vRef>operator --();

    virtual ~vRef();
protected:
private:
    int* referenceID;
    vObject object;
};


#endif //_VH2015_VREF_H_
