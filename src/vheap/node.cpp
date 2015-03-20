//
// Created by alex on 19/03/15.
//

#include "node.h"

template<typename T>
node<T>::node(){
    data=NULL;
    nextNode=NULL;
}
template <typename T>
node<T>::node(T data_) {
    data=data_;
    nextNode=NULL;
}
template<typename T>
void node<T>::delete_all()
{
    if (nextNode)
        nextNode->delete_all();
    delete this;
}
template<typename T>
node<T>::~node() {

}

