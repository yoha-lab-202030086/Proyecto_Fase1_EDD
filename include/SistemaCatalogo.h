#ifndef SISTEMACATALOGO_H
#define SISTEMACATALOGO_H

#include <string>

#include "Lista.h"
#include "AVL.h"
#include "ArbolB.h"
#include "ArbolBPlus.h"

using namespace std;

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
       void mostrarListaOrdenada();
       void buscarPorCodigo(string codigo);
       void listarPorNombre();
       void eliminarProducto(string nombre);
       
       void mostrarAVL();
       void buscarProducto(string nombre);
       
       void compararRendimiento();

       void mostrarPorCategoria();
       void buscarPorCategoria(string categoria);
       void eliminarProductoBPlus(string nombre);

       void mostrarArbolB();
       void buscarPorRangoFecha(string inicio, string fin);
       void eliminarProductoPorFecha(string fecha);

       void cargarDesdeCSV(string archivo);
}; 

#endif



