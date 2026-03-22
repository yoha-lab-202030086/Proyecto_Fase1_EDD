#ifndef AVL_H
#define AVL_H

#include "NodoAVL.h"
#include "Producto.h"

class AVL {

    private:
        NodoAVL* raiz;

        int altura(NodoAVL* n);
        int max(int a, int b);
        int getBalance(NodoAVL* n);

        NodoAVL* rotarDerecha(NodoAVL* nodoDesbalanceado);
        NodoAVL* rotarIzquierda(NodoAVL* nodoDesbalanceado);

        NodoAVL* insertar(NodoAVL* nodo, Producto* producto);
        Producto* buscar(NodoAVL* nodo, std::string nombre);
        
    public:
        AVL();

        void insertar(Producto* producto);
        Producto* buscar(std::string nombre);
    };
 #endif