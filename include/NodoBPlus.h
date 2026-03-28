#ifndef NODOBPLUS_H
#define NODOBPLUS_H

#include "Producto.h"
#include <string>

using namespace std;

class NodoBPlus {

    private:
       string categoria; 
       Producto* producto;
       NodoBPlus* siguiente; 

    public:
       NodoBPlus(string categoria, Producto* producto);

       string getCategoria();
       Producto* getProducto();
       NodoBPlus* getSiguiente();

       void setSiguiente(NodoBPlus* sig);
};
#endif