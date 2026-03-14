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

void Lista::mostrar() {

    Nodo* temp = cabeza; 

    while(temp != nullptr) {

        temp->getProducto()->mostrar(); 
        temp = temp->getSiguiente(); 
    }
}

        
