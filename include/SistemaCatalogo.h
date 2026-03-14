#ifndef SISTEMACATALOGO_H
#define SISTEMACATALOGO_H

#include "Lista.h"

class SistemaCatalogo {

    private: 
       Lista listaProductos; 

    public: 
       SistemaCatalogo();
       void agregarProducto(Producto* producto);
       void mostrarProductos();
       void buscarProducto(string nombre); 
}; 

#endif



