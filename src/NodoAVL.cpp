#include "../include/NodoAVL.h"

NodoAVL::NodoAVL(Producto* p) {
     producto = p; 
     izquierda = nullptr;
     derecha = nullptr; 
     altura = 1;
}

Producto* NodoAVL::getProducto() { 
    return producto;
}

NodoAVL* NodoAVL::getDerecha() { //
    return derecha; 
}

NodoAVL* NodoAVL::getIzquierda() { 
    return izquierda;
}

void NodoAVL::setDerecha(NodoAVL* n) {
    derecha = n;
}

void NodoAVL::setIzquierda(NodoAVL* n) {
    izquierda = n;
}

int NodoAVL::getAltura() {
    return altura;
}

void NodoAVL::setAltura(int a) {
    altura = a;
}