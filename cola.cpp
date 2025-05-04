#include "cola.h"

template<typename T>
Cola<T>::Cola(): size_cola(0), nodo_front(NULL), nodo_back(NULL){}


template<typename T>
bool Cola<T>::empty(){
    return size_cola == 0;
}


template<typename T>
int Cola<T>::size(){
    return size_cola;
}


template<typename T>
T Cola<T>::front(){
    return nodo_front->valor;
}


template<typename T>
T Cola<T>::back(){
    return nodo_back->valor;
}


template<typename T>
void Cola<T>::push(T e){
    Node<T>* nuevo = new Node<T>(e, NULL);
    if(empty()){
        nodo_front = nuevo;
    }else{
        nodo_back->next = nuevo;
    }
    nodo_back = nuevo;
    size_cola++;
}


template<typename T>
void Cola<T>::pop(){
    if(!empty()){
        Node<T>* tmp = nodo_front;
        nodo_front = nodo_front->next;
        delete tmp;
        size_cola--;
        if(empty()){
            nodo_back = NULL;
        }
    }
}

