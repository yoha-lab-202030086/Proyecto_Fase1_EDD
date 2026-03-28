#ifndef ARBOLBPLUS_H
#define ARBOLBPLUS_H

#include "NodoBPlus.h"

class ArbolBPlus {

    private:
       NodoBPlus* cabeza;

    public:
       ArbolBPlus();

       void insertar(Producto* producto);
       void buscarPorCategoria(string categoria);
};
 #endif