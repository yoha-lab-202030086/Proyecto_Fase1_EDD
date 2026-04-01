#include "../include/NodoBPlus.h"

NodoBPlus::NodoBPlus(int grado, bool hoja) {
    this->grado = grado;
    this->esHoja = hoja;

    claves = new string[grado];
    hijos = new NodoBPlus*[grado + 1];
    productos = new Producto*[grado];

    for (int i = 0; i < grado + 1; i++) hijos[i] = nullptr;
    for (int i = 0; i < grado; i++) productos[i] = nullptr;

    siguiente = nullptr;
    cantidadClaves = 0;
}

bool NodoBPlus::getEsHoja() { return esHoja; }
int NodoBPlus::getCantidadClaves() { return cantidadClaves; }
string* NodoBPlus::getClaves() { return claves; }
NodoBPlus** NodoBPlus::getHijos() { return hijos; }
Producto** NodoBPlus::getProductos() { return productos; }
NodoBPlus* NodoBPlus::getSiguiente() { return siguiente; }
int NodoBPlus::getGrado() { return grado; }

void NodoBPlus::setCantidadClaves(int c) { cantidadClaves = c; }
void NodoBPlus::setSiguiente(NodoBPlus* sig) { siguiente = sig; }