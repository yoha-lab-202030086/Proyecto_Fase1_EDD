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

void ArbolBPlus::eliminar(string nombre) {

    NodoBPlus* actual = cabeza;
    NodoBPlus* anterior = nullptr;

    while(actual != nullptr) {

        if(actual->getProducto()->getNombre() == nombre) {

            if(anterior == nullptr) {
                cabeza = actual->getSiguiente();
            } else {
                    anterior->setSiguiente(actual->getSiguiente());
                }
                 delete actual;

                    cout<<"(B+) eliminado correctamente\n";

                    cout<<"(B+) si fuera un B+ real -> se evaluaria redistribucion o fusion\n";

                    return;
        }
                anterior = actual;
                actual = actual->getSiguiente();
    }
                 cout<<"No encontrado\n";
}
                