//
// Created by alex on 18/03/15.
//

#ifndef _VH2015_VMALLOCMETADATA_H_
#define _VH2015_VMALLOCMETADATA_H_


class vMallocMetaData {
public:
    vMallocMetaData();
    vMallocMetaData(int size,string type, vRef* id, vRef* offset);
    ~vMallocMetaData();
    void setId(int id);
    vRef* getId();
    void setOffset(vRef* offset);
    vRef* getOffset();
    void setType(vType type);
    vType getType();
    void setSize(int datSize);
    int getSize();
    void setFlag(bool flag);
    bool getUseFlag();
    int getCounter();
    void increaseCounter();
    void decreaseCounter();

private:
    vRef* idRef;
    vRef* offset;
    string type;
    int dataSize;
    bool useFlag;
    int counter;

};


#endif //_VH2015_VMALLOCMETADATA_H_
