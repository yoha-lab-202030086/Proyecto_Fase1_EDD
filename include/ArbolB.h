#ifndef ARBOLB_H
#define ARBOLB_H

#include "NodoB.h"
#include <string>

class ArbolB {

private:
    NodoB* raiz;
    int gradoMinimo;

    void insertarNoLleno(NodoB* nodo, Producto* producto);
    void dividirHijo(NodoB* nodoPadre, int indice, NodoB* hijoLleno);
    void buscarPorRango(NodoB* nodo, std::string inicio, std::string fin, int &contador);
    

public:
    ArbolB(int grado);

    void insertar(Producto* producto);
    void buscarPorRango(std::string inicio, std::string fin);
    void eliminar(std::string nombre);
};

#endif