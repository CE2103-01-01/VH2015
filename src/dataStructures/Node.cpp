//
// Created by alex on 19/03/15.
//

template<typename T>
Node<T>::Node(){
    data=NULL;
    nextNode=NULL;
}
template <typename T>
Node<T>::Node(T data_) {
    data=data_;
    nextNode=NULL;
}
template<typename T>
void Node<T>::delete_all()
{
    if (nextNode)
        nextNode->delete_all();
    delete this;
}
template<typename T>
Node<T>::~Node() {

}

