#ifndef NODOBPLUS_H
#define NODOBPLUS_H

#include <string>
#include "Producto.h"

using namespace std;

class NodoBPlus {

private:
    bool esHoja;

    string* claves;
    NodoBPlus** hijos;
    Producto** productos;

    NodoBPlus* siguiente;

    int cantidadClaves;
    int grado;

public:
    NodoBPlus(int grado, bool hoja);

    bool getEsHoja();
    int getCantidadClaves();
    string* getClaves();
    NodoBPlus** getHijos();
    Producto** getProductos();
    NodoBPlus* getSiguiente();
    int getGrado();

    void setCantidadClaves(int c);
    void setSiguiente(NodoBPlus* sig);
};

#endif