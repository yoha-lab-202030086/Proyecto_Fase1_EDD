#ifndef LISTA_H
#define LISTA_H

#include "../include/Nodo.h"

Nodo::Nodo(Producto* p) {
    producto = p; 
    siguiente = nullptr; 
}

Producto* Nodo::getProducto() {
    return producto;
}

Nodo* Nodo:: getSiguiente() {
    return siguiente; 
}

void Nodo:: setSiguiente(Nodo* sig) {
    siguiente = sig; 
}

#endif