#include "../include/tablaHash.h"
#include <iostream>

using namespace std; 

TablaHash::TablaHash() {
    for (int i=0; i<TAM; i++) {
        tabla[i] = nullptr;
    }    
}

int TablaHash::funcionHash(string codigo) {
    int suma = 0;
    for(char c : codigo) {
        suma += c; 
    }
  return suma % TAM;
}

bool TablaHash::insertar(Producto* producto) {
    int indice = funcionHash(producto->getCodigoBarra());
    if(tabla[indice] == nullptr) {
        tabla[indice] = producto;
       
        return true;
    }
       return false;   
}

Producto* TablaHash::buscar(string codigo) {
    int indice = funcionHash(codigo);
    if(tabla[indice] != nullptr && tabla[indice]->getCodigoBarra() == codigo) {

        return tabla[indice];
}

    return nullptr;
}
