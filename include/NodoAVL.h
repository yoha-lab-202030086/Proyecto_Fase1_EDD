#ifndef NODOAVL_H
#define NODOAVL_H

#include "Producto.h"
#include <string>

using namespace std; 

class NodoAVL {

    private:
       Producto* producto;
       NodoAVL* izquierda;
       NodoAVL* derecha;
       int altura; 

    public: 
       NodoAVL(Producto* p);

       Producto* getProducto();

       NodoAVL* getIzquierda();
       NodoAVL* getDerecha();

       void setIzquierda(NodoAVL* n);
       void setDerecha(NodoAVL* n);

       int getAltura();
       void setAltura(int a);
}; 

#endif