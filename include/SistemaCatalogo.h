#ifndef SISTEMACATALOGO_H
#define SISTEMACATALOGO_H

#include <string>

#include "Lista.h"
#include "AVL.h"

class SistemaCatalogo {

    private: 
       Lista listaProductos; 
       AVL arbol;

    public: 
       SistemaCatalogo();
       void agregarProducto(Producto* producto);
       void mostrarProductos();
       void buscarProducto(string nombre);
       void buscarPorCodigo(string codigo);
       void cargarDesdeCSV(string archivo);
}; 

#endif



