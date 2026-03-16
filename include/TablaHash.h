#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "Lista.h"
#include "Producto.h"
#include <string>

class TablaHash {

    private: 
       static const int TAM = 1000;
       Lista tabla[TAM]; 
       int funcionHash(string codigo); //

    public:
        TablaHash();
        void insertar(Producto* producto);
        Producto* buscar(string codigo);
}; 

#endif