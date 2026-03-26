#include "../include/NodoB.h"

NodoB::NodoB(int grado, bool hoja) {
    gradoMinimo = grado;
    esHoja = hoja;

    // Máximo de claves = 2*t - 1
    productos = new Producto*[2 * grado - 1];

    // Máximo de hijos = 2*t
    hijos = new NodoB*[2 * grado];

    cantidadClaves = 0;

    // Inicializar hijos en nullptr
    for(int i = 0; i < 2 * grado; i++) {
        hijos[i] = nullptr;
    }
}