#include "../include/lista.h"
#include <iostream>

using namespace std; 

Lista::Lista() {
    cabeza = nullptr; 
}

void Lista::insertar(Producto* producto) {
    Nodo* nuevo = new Nodo(producto);

    if(cabeza == nullptr) {
        cabeza = nuevo; 
    }else{

        Nodo* temp = cabeza; 
    
       while(temp->getSiguiente() != nullptr) {
          temp = temp->getSiguiente(); 
        }

        temp->setSiguiente(nuevo); 
    }
}

void Lista::insertarOrdenado(Producto* producto){

    Nodo* nuevo = new Nodo(producto);

    // Insertar al inicio
    if(cabeza == nullptr || 
       producto->getNombre() < cabeza->getProducto()->getNombre()){

        nuevo->setSiguiente(cabeza);
        cabeza = nuevo;
        return;
    }

    Nodo* actual = cabeza;

    // Buscar posición
    while(actual->getSiguiente() != nullptr &&
          actual->getSiguiente()->getProducto()->getNombre() < producto->getNombre()){

        actual = actual->getSiguiente();
    }

    // Insertar
    nuevo->setSiguiente(actual->getSiguiente());
    actual->setSiguiente(nuevo);
}

void Lista::mostrar() {

    Nodo* temp = cabeza; 

    while(temp != nullptr) {

        temp->getProducto()->mostrar(); 
        temp = temp->getSiguiente(); 
    }
}

Producto* Lista::buscarPorNombre(string nombre) {

    Nodo* temp = cabeza; 

    while(temp != nullptr) {

        if(temp->getProducto()->getNombre() == nombre) {
            return temp->getProducto();
         }
        temp = temp->getSiguiente();
    }
    return nullptr; 
}

Producto* Lista::buscarPorCodigo(string codigo){

    Nodo* temp = cabeza;

    while(temp != nullptr){

        if(temp->getProducto()->getCodigoBarra() == codigo){
            return temp->getProducto();
        }

        temp = temp->getSiguiente();
    }

    return nullptr;
}

void Lista::eliminarPorNombre(string nombre){

    if(cabeza == nullptr) return;

    // Caso 1: eliminar cabeza
    if(cabeza->getProducto()->getNombre() == nombre){
        Nodo* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
        return;
    }

    // Caso 2: buscar en los nodos siguientes 
    Nodo* actual = cabeza;

    while(actual->getSiguiente() != nullptr){

        if(actual->getSiguiente()->getProducto()->getNombre() == nombre){
            Nodo* temp = actual->getSiguiente();
            actual->setSiguiente(temp->getSiguiente());
            delete temp;
            return;
        }

        actual = actual->getSiguiente();
    }
}
        
