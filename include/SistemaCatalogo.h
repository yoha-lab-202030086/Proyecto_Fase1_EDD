#ifndef SISTEMACATALOGO_H
#define SISTEMACATALOGO_H

#include <string>

#include "Lista.h"
#include "AVL.h"
#include "ArbolB.h"
#include "ArbolBPlus.h"

class SistemaCatalogo {

    private: 
       Lista listaProductos; 
       Lista listaOrdenada;
       AVL arbol;
       ArbolB arbolB;
       ArbolBPlus arbolBPlus;

    public: 
       SistemaCatalogo();
       void agregarProducto(Producto* producto, bool mostrarMensaje = true);
       void mostrarProductos();
       void buscarProducto(string nombre);
       void buscarPorCodigo(string codigo);
       void listarPorNombre();
       void mostrarListaOrdenada();
       void eliminarProducto(string nombre);
       void buscarPorRangoFecha(string inicio, string fin);
       void compararRendimiento();
       void buscarPorCategoria(string categoria);
       void cargarDesdeCSV(string archivo);
}; 

#endif



