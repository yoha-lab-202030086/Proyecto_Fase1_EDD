#include "../include/ArbolBPlus.h"
#include <iostream>

using namespace std;

// Constructor
ArbolBPlus::ArbolBPlus(){
    cabeza = nullptr;
}

// Insertar ordenado por categoria
void ArbolBPlus::insertar(Producto* producto){

    NodoBPlus* nuevo = new NodoBPlus(producto->getCategoria(), producto);

    // Caso: lista vacía o insertar al inicio
    if(cabeza == nullptr || producto->getCategoria() < cabeza->getCategoria()){
        nuevo->setSiguiente(cabeza);
        cabeza = nuevo;
        return;
    }

    NodoBPlus* actual = cabeza;

    while(actual->getSiguiente() != nullptr &&
          actual->getSiguiente()->getCategoria() < producto->getCategoria()){
        actual = actual->getSiguiente();
    }

    nuevo->setSiguiente(actual->getSiguiente());
    actual->setSiguiente(nuevo);
}

// Buscar
void ArbolBPlus::buscarPorCategoria(string categoria){

    NodoBPlus* actual = cabeza;
    bool encontrado = false;

    cout << "\n=== PRODUCTOS DE LA CATEGORIA ===\n";

    while(actual != nullptr){

        if(actual->getCategoria() == categoria){
            actual->getProducto()->mostrar();
            encontrado = true;
        }

        actual = actual->getSiguiente();
    }

    if(!encontrado){
        cout << "No hay productos en esta categoria\n";
    }
}