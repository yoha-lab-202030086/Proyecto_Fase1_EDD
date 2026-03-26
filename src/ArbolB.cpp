#include "../include/ArbolB.h"
#include <iostream>

using namespace std;

// Constructor
ArbolB::ArbolB(int grado) {
    raiz = nullptr;
    gradoMinimo = grado;
}

// Insertar principal
void ArbolB::insertar(Producto* producto) {

    if (raiz == nullptr) {
        raiz = new NodoB(gradoMinimo, true);
        raiz->productos[0] = producto;
        raiz->cantidadClaves = 1;
        return;
    }

    // Si la raíz está llena
    if (raiz->cantidadClaves == 2 * gradoMinimo - 1) {

        NodoB* nuevaRaiz = new NodoB(gradoMinimo, false);
        nuevaRaiz->hijos[0] = raiz;

        dividirHijo(nuevaRaiz, 0, raiz);

        int indice = 0;
        if (producto->getFechaCaducidad() > nuevaRaiz->productos[0]->getFechaCaducidad()) {
            indice++;
        }

        insertarNoLleno(nuevaRaiz->hijos[indice], producto);

        raiz = nuevaRaiz;
    } else {
        insertarNoLleno(raiz, producto);
    }
}

// Insertar en nodo no lleno
void ArbolB::insertarNoLleno(NodoB* nodo, Producto* producto) {

    int i = nodo->cantidadClaves - 1;

    if (nodo->esHoja) {

        // Mover elementos
        while (i >= 0 && producto->getFechaCaducidad() < nodo->productos[i]->getFechaCaducidad()) {
            nodo->productos[i + 1] = nodo->productos[i];
            i--;
        }

        nodo->productos[i + 1] = producto;
        nodo->cantidadClaves++;

    } else {

        while (i >= 0 && producto->getFechaCaducidad() < nodo->productos[i]->getFechaCaducidad()) {
            i--;
        }

        i++;

        // Si el hijo está lleno
        if (nodo->hijos[i]->cantidadClaves == 2 * gradoMinimo - 1) {

            dividirHijo(nodo, i, nodo->hijos[i]);

            if (producto->getFechaCaducidad() > nodo->productos[i]->getFechaCaducidad()) {
                i++;
            }
        }

        insertarNoLleno(nodo->hijos[i], producto);
    }
}

// Dividir nodo
void ArbolB::dividirHijo(NodoB* nodoPadre, int indice, NodoB* hijoLleno) {

    NodoB* nuevoNodo = new NodoB(gradoMinimo, hijoLleno->esHoja);

    nuevoNodo->cantidadClaves = gradoMinimo - 1;

    // Copiar claves
    for (int j = 0; j < gradoMinimo - 1; j++) {
        nuevoNodo->productos[j] = hijoLleno->productos[j + gradoMinimo];
    }

    // Copiar hijos
    if (!hijoLleno->esHoja) {
        for (int j = 0; j < gradoMinimo; j++) {
            nuevoNodo->hijos[j] = hijoLleno->hijos[j + gradoMinimo];
        }
    }

    hijoLleno->cantidadClaves = gradoMinimo - 1;

    // Mover hijos del padre
    for (int j = nodoPadre->cantidadClaves; j >= indice + 1; j--) {
        nodoPadre->hijos[j + 1] = nodoPadre->hijos[j];
    }

    nodoPadre->hijos[indice + 1] = nuevoNodo;

    // Mover claves del padre
    for (int j = nodoPadre->cantidadClaves - 1; j >= indice; j--) {
        nodoPadre->productos[j + 1] = nodoPadre->productos[j];
    }

    nodoPadre->productos[indice] = hijoLleno->productos[gradoMinimo - 1];

    nodoPadre->cantidadClaves++;
}

// Buscar por rango
void ArbolB::buscarPorRango(std::string inicio, std::string fin) {
   
    int contador = 0;
    
    buscarPorRango(raiz, inicio, fin, contador);

    if(contador == 0) {
    cout<<"No hay productos en este rango\n";
    }
}

void ArbolB::buscarPorRango(NodoB* nodo, std::string inicio, std::string fin, int &contador) {

    if (nodo == nullptr) return;

    int i = 0;

    // Recorrer claves
    while (i < nodo->cantidadClaves) {

        // Ir al hijo izquierdo
        if (!nodo->esHoja) {
            buscarPorRango(nodo->hijos[i], inicio, fin, contador);
        }

        string fecha = nodo->productos[i]->getFechaCaducidad();

        if (fecha >= inicio && fecha <= fin) {
            nodo->productos[i]->mostrar();
            contador++;
        }

        i++;
    }

    // Último hijo
    if (!nodo->esHoja) {
        buscarPorRango(nodo->hijos[i], inicio, fin, contador);
    }
}

void ArbolB::eliminar(string nombre) {
}    