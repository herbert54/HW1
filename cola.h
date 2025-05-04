#ifndef COLA_H
#define COLA_H
#include <iostream>
using namespace std;

template<class T>
struct Node{
    T valor;
    Node<T>* next;
    Node(T valor, Node<T>* next): valor(valor), next(next){}
};


template<class T>
class Cola{
private:
    int size_cola;       
    Node<T>* nodo_front; 
    Node<T>* nodo_back;  
public:
    Cola();        
    bool empty();  
    int size();    
    T front();     
    T back();      
    void push(T);  
    void pop();    
};

#endif 