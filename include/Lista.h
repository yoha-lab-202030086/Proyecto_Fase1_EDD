#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {

    private: 
       Nodo* cabeza;


    public: 
       Lista(); 
       void insertar(Producto* producto); 
       void insertarOrdenado(Producto* producto);
       void mostrar(); 
       Producto* buscarPorNombre(string nombre); 
       Producto* buscarPorCodigo(string codigo);
};

#endif
