#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "Producto.h"
#include <string>

class TablaHash {

    private: 
       static const int TAM = 1000;
       Producto* tabla[TAM]; 
       int funcionHash(string codigo); //

    public:
        TablaHash();
        bool insertar(Producto* producto);
        Producto* buscar(string codigo);
}; 

#endif