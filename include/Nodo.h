#ifndef NODO_H
#define NODO_H

#include "Producto.h"

class Nodo {

    private: 
         Producto* producto; 
         Nodo* siguiente; 

    public: 
       Nodo(Producto* p);   
       Producto* getProducto(); 
       Nodo* getSiguiente();
       void setSiguiente(Nodo* sig);
}; 

#endif

