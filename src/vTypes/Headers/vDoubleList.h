//
// Created by alex on 17/04/15.
//

#ifndef VH2015_VDOUBLELIST_H
#define VH2015_VDOUBLELIST_H
#include <vHeap/Headers/vRef.h>
#include <vheaplib.h>

template <class T>
class vDoubleNode;

template <class T>
class vDoubleList;


template <class T>
class vDoubleNode{

    vRef<T> data;
    vRef<vDoubleNode<T>> prev;
    vRef<vDoubleNode<T>> next;
public:
    vDoubleNode();
    vDoubleNode(T);
    ~vDoubleNode();
    T getData();
    void setNext(vRef<vDoubleNode<T>>);
    void setPrev(vRef<vDoubleNode<T>>);
    vRef<vDoubleNode<T>> getNext();
    vRef<vDoubleNode<T>> getPrev();
    void operator *=(T);
};


template <class T>
class vDoubleList{
private:
    vRef<vDoubleNode<T>> head;
    vRef<vDoubleNode<T>> tail;
    vRef<int> len;
public:
    vDoubleList();
    T operator [] (int);
    void insertFront(T);
    void insertBack(T);
    vRef<vDoubleNode<T>> getPosition(int);
    void insertPosition(int,T);
    void deleteFront();
    void deleteBack();
    void deletePosition(int);
    int getLen();
    bool isEmpty();

};
template<class T>
T vDoubleList<T>::operator[](int pos) {
    if(pos<**len){
        vRef<vDoubleNode<T>> temp = head;
        for(int i=0;i<pos;i++){
            temp= (**temp).getNext();
        }
        return (**temp).getData();
    }
}
template<class T>
vDoubleList<T>::vDoubleList() {
    head=0;
    tail=0;
    len = vMalloc(sizeof(int));
}
template<class T>
void vDoubleList<T>::deletePosition(int pos) {
    if(pos<**len){
        vRef<vDoubleNode<T>> temp;
        temp = head;
        if(pos==0){
            (**temp).getNext();
            head = (**temp).getNext();
            temp.~vRef();
        }
        else {
            if (pos == **len - 1) {
                vRef<vDoubleNode<T>> tempAux;
                tempAux = tail;
                (**(**tempAux).getPrev()).setNext(0);
                tail = (**tempAux).getPrev();
                tempAux.~vRef();
            }
            else {
                for (int i = 0; i < pos; i++) {
                    temp = (**temp).getNext();
                }
                (**(**temp).getPrev()).setNext((**temp).getNext());
                (**(**temp).getNext()).setPrev((**temp).getPrev());
                temp.~vRef();
            }
        }
        (**len)--;
    }
}
template<class T>
int vDoubleList<T>::getLen() {
    return **len;
}
template<class T>
bool vDoubleList<T>::isEmpty() {
    if(**len!=0){
        return false;
    }
    return true;
}
template <class T>
void vDoubleList<T>::insertFront(T data) {
    if (**len== 0) {

        head = vMalloc(sizeof(vDoubleNode<T>));
        tail = head;
        vPlacement(tail, vDoubleNode<T>(data));
    } else {
        vRef<vDoubleNode<T>> tmp = head;
        head = vMalloc(sizeof(vDoubleNode<T>));
        vPlacement(head,vDoubleNode<T>(data));
        (**tmp).setPrev(head);
        (**head).setNext(tmp);



    }
    (**len)++;
}
template <class T>
void vDoubleList<T>::insertBack(T data) {
    vDoubleNode<T> node = vDoubleNode<T>(data);
    if(**len==0){
        tail = vMalloc(sizeof(vDoubleNode<T>));
        head = tail;
        vPlacement(head, vDoubleNode<T>(data));
    }
    else{
       vRef<vDoubleNode<T>> tmp = tail;
        tail = vMalloc(sizeof(vDoubleNode<T>));
        vPlacement(tail,vDoubleNode<T>(data));
        (**tmp).setNext(tail);
        (**tail).setPrev(tmp);
    }
    (**len)++;
}
template<class T>
void vDoubleList<T>::deleteBack() {
    if (**len==1){
        head.~vRef();
        head = 0;
        tail = 0;
    }
    else{
        if(**len>1){
            vRef<vDoubleNode<T>> temp= tail;
            tail = (**temp).getPrev();
            temp.~vRef();

        }
    }
    (**len)--;

}
template<class T>
void vDoubleList<T>::deleteFront() {
    if (**len==1){
        head.~vRef();
        head = 0;
        tail = 0;
    }
    else{
        if(**len>1){
            vRef<vDoubleNode<T>> temp;
            temp = head;
            head = (**temp).getNext();
            temp.~vRef();

        }
    }
    (**len)--;
}
template<class T>
vRef<vDoubleNode<T>> vDoubleList<T>::getPosition(int pos) {
    if(pos<=**len){
        vRef<vDoubleNode<T>> temp;
        temp=head;
        for(int i=0;i<=pos;i++){
            temp = (**temp).getNext();
        }
        return temp;
    }
}


template <class T>
void vDoubleList<T>::insertPosition(int pos, T data) {
    if(pos<**len){
        vRef<vDoubleNode<T>> temp;
        if(pos<**len){
            temp=head;
            for(int i =1; i<pos;i++){
                temp=(**temp).getNext();
            }
            vRef<vDoubleNode<T>> node;
            if(pos==0){
                node=vMalloc(sizeof(vDoubleNode<T>));
                vPlacement(node,vDoubleNode<T>(data));
                (**node).setNext(head);
                (**head).setPrev(node);
                head=node;
            }
            else {
                node = vMalloc(sizeof(vDoubleNode<T>));

                vPlacement(node, vDoubleNode<T>(data));
                (**node).setPrev(temp);
                (**node).setNext((**temp).getNext());
                (**(**temp).getNext()).setPrev(node);
                (**temp).setNext(node);

            }

        }
        else{
            vRef<vDoubleNode<T>> node;
            node = tail;
            vPlacement(tail,vDoubleNode<T>(data));
            (**tail).setPrev(node);
        }
        (**len)++;

    }
}

template<class T>
vDoubleNode<T>::vDoubleNode() {
    prev=0;
    next=0;
}
template <class T>
vDoubleNode<T>::vDoubleNode(T Data) {
    prev=0;
    next=0;
    data = vMalloc(sizeof(T));
    vPlacement(data,Data);
}
template <class T>
T vDoubleNode<T>::getData() {
    return **data;
}
template <class T>
void vDoubleNode<T>::setNext(vRef<vDoubleNode<T>> node) {
   next=node;
}
template <class T>
void vDoubleNode<T>::setPrev(vRef<vDoubleNode<T>> node) {
    prev=node;
}
template <class T>
vRef<vDoubleNode<T>> vDoubleNode<T>::getNext() {
    return next;
}
template <class T>
vRef<vDoubleNode<T>> vDoubleNode<T>::getPrev() {
    return prev;
}
template <class T>
vDoubleNode<T>::~vDoubleNode() {
}
template <class T>
void vDoubleNode<T>::operator*=(T d) {
    if(!data != 0){
        vPlacement(data,d);
    }else{
        data = vMalloc(sizeof(T));
        vPlacement(data,d);
    }
}








#endif //VH2015_VDOUBLELIST_H
