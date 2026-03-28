#include "../include/NodoBPlus.h"

NodoBPlus::NodoBPlus(string categoria, Producto* producto){
  this->categoria = categoria; 
  this->producto = producto; 
  this->siguiente = nullptr;
}

string NodoBPlus::getCategoria() {
    return categoria; 
}

Producto* NodoBPlus::getProducto() {
    return producto;
}

NodoBPlus* NodoBPlus::getSiguiente() {
    return siguiente;
}

void NodoBPlus::setSiguiente(NodoBPlus* sig) {
    siguiente = sig; 
}


