#ifndef ARBOLBPLUS_H
#define ARBOLBPLUS_H

#include "NodoBPlus.h"
#include <string>
#include <fstream>

using namespace std;

class ArbolBPlus {

private:
    NodoBPlus* raiz;
    int grado;

    NodoBPlus* buscarHoja(NodoBPlus* nodo, string clave);

    void insertarEnHoja(NodoBPlus* hoja, Producto* producto);
    void dividirHoja(NodoBPlus* hoja);
    void insertarEnPadre(NodoBPlus* izquierda, string clave, NodoBPlus* derecha);
    NodoBPlus* buscarPadre(NodoBPlus* actual, NodoBPlus* hijo);
    void dividirInterno(NodoBPlus* nodo);

    void buscarRec(NodoBPlus* nodo, string categoria);
    void generarDotRec(ofstream& file, NodoBPlus* nodo);

public:
    ArbolBPlus(int grado);

    void insertar(Producto* producto);
    void mostrar();
    void buscarPorCategoria(string categoria);

    void eliminar(string clave);  

    void generarDot(string archivo);
};

#endif