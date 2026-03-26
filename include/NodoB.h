#ifndef NODOB_H
#define NODOB_H

#include "Producto.h"

class NodoB {

public:
    Producto** productos;     // Arreglo de productos (claves)
    NodoB** hijos;            // Arreglo de hijos

    int cantidadClaves;       // Cuántos productos hay en el nodo
    bool esHoja;              // Indica si es hoja

    int gradoMinimo;          // Grado del árbol (t)

    // Constructor
    NodoB(int grado, bool hoja);
};

#endif