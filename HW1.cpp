#include "cola.h"
#include "cola.cpp"
#include <iostream>
#include <stack>
using namespace std;

class Nodo{
public:
    int dato;
    Nodo* left;
    Nodo* right;

    //Constructor
    Nodo(int dato){
        this->dato=dato;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
private:
    Nodo* raiz;
    Nodo* insertarNodoAux(Nodo* nodo,int dato);

    // Funciones auxiliares para imprimir los nodos en diferentes órdenes
    void imprimirEnOrdenAux(Nodo* nodo);
    void imprimirPreOrdenAux(Nodo* nodo);
    void imprimirPostOrdenAux(Nodo* nodo);

public:
    BST();
    ~BST();

    void insertarNodo(int dato);

    // Funciones para imprimir los nodos en diferentes órdenes
    void imprimirEnOrden();
    void imprimirPreOrden();
    void imprimirPostOrden();
    void destruirArbol(Nodo*);

    //Funciones nuevas
    void imprimirEnAnchura();
    void imprimirEnProfundidad();

};

BST::BST(): raiz(nullptr) {}

//Insertar un nodo en el árbol
void BST::insertarNodo(int dato){
    raiz = insertarNodoAux(raiz,dato);
}

Nodo* BST::insertarNodoAux(Nodo* nodo,int dato){
    if (nodo == nullptr)
        return new Nodo(dato);
    if (dato <nodo->dato)
        nodo->left = insertarNodoAux(nodo->left,dato);
    else if (dato > nodo->dato)
        nodo->right = insertarNodoAux(nodo->right,dato);
    return nodo;
}

// Función para imprimir los nodos en orden
void BST::imprimirEnOrden(){
    imprimirEnOrdenAux(raiz);
    cout<<endl;
}

// Función auxiliar para imprimir los nodos en orden
void BST::imprimirEnOrdenAux(Nodo* nodo){
    if (nodo==nullptr){
        return;
    }

    imprimirEnOrdenAux(nodo->left);
    cout<<nodo->dato<<" ";
    imprimirEnOrdenAux(nodo->right);
}

// Función para imprimir los nodos en preorden
void BST::imprimirPreOrden(){
    imprimirPreOrdenAux(raiz);
    cout<<endl;
}

// Función auxiliar para imprimir los nodos en preorden
void BST::imprimirPreOrdenAux(Nodo* nodo){
    if (nodo == nullptr){
        return;
    }

    cout<< nodo->dato << " ";
    imprimirPreOrdenAux(nodo->left);
    imprimirPreOrdenAux(nodo->right);
}

// Función para imprimir los nodos en postorden
void BST::imprimirPostOrden() {
    imprimirPostOrdenAux(raiz);
    cout << endl;
}

// Función auxiliar para imprimir los nodos en postorden
void BST::imprimirPostOrdenAux(Nodo* nodo) {
    if (nodo == nullptr) {
      return;
    }
  
    imprimirPostOrdenAux(nodo->left);
    imprimirPostOrdenAux(nodo->right);
    cout << nodo->dato << " ";
}

BST::~BST() {
    destruirArbol(raiz);
}

// Función auxiliar para destruir el árbol utilizando un recorrido PostOrden
void BST::destruirArbol(Nodo* nodo) {
    if (nodo == nullptr) {
      return;
    }
  
    // Recorrer el subárbol izquierdo
    destruirArbol(nodo->left);
  
    // Recorrer el subárbol derecho
    destruirArbol(nodo->right);
  
    // Eliminar el nodo actual
    delete nodo;
}

void BST::imprimirEnAnchura(){
    if (raiz==nullptr){
        return;
    }

    Cola<Nodo*> q;
    q.push(raiz);

    while (!q.empty()){
        Nodo* nodo=q.front();
        q.pop();

        cout<<nodo->dato<<" ";

        if(nodo->left!=nullptr)
            q.push(nodo->left);
        
        if(nodo->right!=nullptr)
            q.push(nodo->right);
    } 
    cout<<endl; 
}

void BST::imprimirEnProfundidad(){
    if(raiz==nullptr) return;
    stack<Nodo*> nodeStack;
    nodeStack.push(raiz);

    while (!nodeStack.empty())
    {
        Nodo* current=nodeStack.top();
        nodeStack.pop();
        cout<<current->dato<<" ";

        // Primero se inserta el hijo derecho y luego el izquierdo para que el izquierdo sea procesado primero
        if (current->right){
            nodeStack.push(current->right);
        }
        if (current->left)
        {
            nodeStack.push(current->left);
        } 
    }
    cout<<endl;
}

int main(){
    BST arbol;

    arbol.insertarNodo(12);
    arbol.insertarNodo(8);
    arbol.insertarNodo(20);
    arbol.insertarNodo(5);
    arbol.insertarNodo(1);
    arbol.insertarNodo(15);
    arbol.insertarNodo(25);
    arbol.insertarNodo(7);
    arbol.insertarNodo(11);
    arbol.insertarNodo(9);
    arbol.insertarNodo(13);
    arbol.insertarNodo(22);
    arbol.insertarNodo(18);
    arbol.insertarNodo(26);

    arbol.imprimirPreOrden();
    arbol.imprimirEnOrden();
    arbol.imprimirPostOrden();
    arbol.imprimirEnAnchura();
    arbol.imprimirEnProfundidad();
    
}
