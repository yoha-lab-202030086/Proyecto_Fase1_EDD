#ifndef SISTEMACATALOGO_H
#define SISTEMACATALOGO_H

#include "Lista.h"
#include "TablaHash.h"

class SistemaCatalogo {

    private: 
       Lista listaProductos; 
       TablaHash tablaHash;

    public: 
       SistemaCatalogo();
       void agregarProducto(Producto* producto);
       void mostrarProductos();
       void buscarProducto(string nombre);
       void buscarPorCodigo(string codigo);
}; 

#endif



