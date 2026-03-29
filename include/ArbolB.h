#ifndef ARBOLB_H
#define ARBOLB_H

#include <string>
#include "NodoB.h"
#include "Producto.h"

using namespace std;

class ArbolB {
private:
    NodoB* raiz;
    int grado;
    int gradoMinimo;

    // Insercion
    void insertarNoLleno(NodoB* nodo, Producto* producto);
    void dividirHijo(NodoB* padre, int i, NodoB* hijo);

    // Busqueda
    void buscarPorRango(NodoB* nodo, string inicio, string fin, int &contador);

    // Eliminacion
    void eliminarRec(NodoB* nodo, string fecha);
    void eliminarDeHoja(NodoB* nodo, int i);
    void eliminarDeInterno(NodoB* nodo, int i);

    Producto* obtenerPredecesor(NodoB* nodo);
    Producto* obtenerSucesor(NodoB* nodo);

    void llenar(NodoB* nodo, int i);
    void fusionar(NodoB* nodo, int i);

    void prestarDeAnterior(NodoB* nodo, int i);
    void prestarDeSiguiente(NodoB* nodo, int i);

public:
    // Constructor
    ArbolB(int grado);

    // Operaciones principales 
    void insertar(Producto* producto);
    void mostrar();
    void mostrarRec(NodoB* nodo);
    void eliminar(string fecha);
    void buscarPorRango(string inicio, string fin);
};

#endif