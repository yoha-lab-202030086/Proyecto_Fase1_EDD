#ifndef ARBOLBPLUS_H
#define ARBOLBPLUS_H

#include "NodoBPlus.h"

class ArbolBPlus {

    private:
       NodoBPlus* cabeza;

    public:
       ArbolBPlus();

       void insertar(Producto* producto);
       void mostrar();
       void buscarPorCategoria(string categoria);
       void eliminar(string nombre);
       void generarDot(string archivo);
};
 #endif