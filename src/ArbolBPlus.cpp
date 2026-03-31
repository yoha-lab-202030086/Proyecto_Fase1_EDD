#include "../include/ArbolBPlus.h"
#include <iostream>
#include <fstream>

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

void ArbolBPlus::mostrar() {

    NodoBPlus* actual = cabeza;

    while(actual != nullptr) {

        actual->getProducto()->mostrar();

        actual = actual->getSiguiente();
    }
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

                    return;
        }
                anterior = actual;
                actual = actual->getSiguiente();
    }
                 cout<<"No encontrado\n";
}

void ArbolBPlus::generarDot(string archivo) {

    ofstream file(archivo);

    file << "digraph BPlus {\n";
    file << "rankdir=LR;\n";
    file << "node [shape=record];\n";

    NodoBPlus* actual = cabeza;

    string categoriaActual = "";

    while(actual != nullptr) {

        string nombre = actual->getProducto()->getNombre();
        string categoria = actual->getProducto()->getCategoria();

        // Mostrar categoria solo cuando cambia
        if(categoria != categoriaActual){
            file << "\"" << categoria << "\" [shape=box, style=filled, color=lightblue];\n";
            categoriaActual = categoria;
        }

        file << "\"" << nombre << "\" [label=\"" << nombre << "\"];\n";

        // conectar categoria -> producto
        file << "\"" << categoria << "\" -> \"" << nombre << "\";\n";

        // conectar productos
        if(actual->getSiguiente() != nullptr){
            string siguiente = actual->getSiguiente()->getProducto()->getNombre();
            file << "\"" << nombre << "\" -> \"" << siguiente << "\" [style=dashed];\n";
        }

        actual = actual->getSiguiente();
    }

    file << "}\n";
    file.close();
}

                