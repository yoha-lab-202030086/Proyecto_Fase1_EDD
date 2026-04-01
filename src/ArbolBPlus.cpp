#include "../include/ArbolBPlus.h"
#include <iostream>

using namespace std;

ArbolBPlus::ArbolBPlus(int grado) {
    this->grado = grado;
    raiz = new NodoBPlus(grado, true);
}

void ArbolBPlus::insertar(Producto* producto) {
    NodoBPlus* hoja = buscarHoja(raiz, producto->getCategoria());

    insertarEnHoja(hoja, producto);

    if (hoja->getCantidadClaves() == grado) {
        dividirHoja(hoja);
    }
}

NodoBPlus* ArbolBPlus::buscarHoja(NodoBPlus* nodo, string clave) {
    if (nodo->getEsHoja()) return nodo;

    int i = 0;
    while (i < nodo->getCantidadClaves() && clave >= nodo->getClaves()[i]) {
        i++;
    }

    return buscarHoja(nodo->getHijos()[i], clave);
}

void ArbolBPlus::insertarEnHoja(NodoBPlus* hoja, Producto* producto) {
    int i = hoja->getCantidadClaves() - 1;

    while (i >= 0 && producto->getCategoria() < hoja->getClaves()[i]) {
        hoja->getClaves()[i + 1] = hoja->getClaves()[i];
        hoja->getProductos()[i + 1] = hoja->getProductos()[i];
        i--;
    }

    hoja->getClaves()[i + 1] = producto->getCategoria();
    hoja->getProductos()[i + 1] = producto;

    hoja->setCantidadClaves(hoja->getCantidadClaves() + 1);
}

void ArbolBPlus::dividirHoja(NodoBPlus* hoja) {
    int mitad = grado / 2;

    NodoBPlus* nuevaHoja = new NodoBPlus(grado, true);

    for (int i = mitad; i < grado; i++) {
        nuevaHoja->getClaves()[i - mitad] = hoja->getClaves()[i];
        nuevaHoja->getProductos()[i - mitad] = hoja->getProductos()[i];
    }

    nuevaHoja->setCantidadClaves(grado - mitad);
    hoja->setCantidadClaves(mitad);

    nuevaHoja->setSiguiente(hoja->getSiguiente());
    hoja->setSiguiente(nuevaHoja);

    string claveSube = nuevaHoja->getClaves()[0];

    insertarEnPadre(hoja, claveSube, nuevaHoja);
}

void ArbolBPlus::insertarEnPadre(NodoBPlus* izquierda, string clave, NodoBPlus* derecha) {
    if (raiz == izquierda) {
        NodoBPlus* nuevaRaiz = new NodoBPlus(grado, false);

        nuevaRaiz->getClaves()[0] = clave;
        nuevaRaiz->getHijos()[0] = izquierda;
        nuevaRaiz->getHijos()[1] = derecha;

        nuevaRaiz->setCantidadClaves(1);

        raiz = nuevaRaiz;
        return;
    }

    NodoBPlus* padre = buscarPadre(raiz, izquierda);

    int i = padre->getCantidadClaves() - 1;

    while (i >= 0 && clave < padre->getClaves()[i]) {
        padre->getClaves()[i + 1] = padre->getClaves()[i];
        padre->getHijos()[i + 2] = padre->getHijos()[i + 1];
        i--;
    }

    padre->getClaves()[i + 1] = clave;
    padre->getHijos()[i + 2] = derecha;

    padre->setCantidadClaves(padre->getCantidadClaves() + 1);

    if (padre->getCantidadClaves() == grado) {
        dividirInterno(padre);
    }
}

NodoBPlus* ArbolBPlus::buscarPadre(NodoBPlus* actual, NodoBPlus* hijo) {
    if (actual->getEsHoja()) return nullptr;

    for (int i = 0; i <= actual->getCantidadClaves(); i++) {
        if (actual->getHijos()[i] == hijo) {
            return actual;
        }

        NodoBPlus* encontrado = buscarPadre(actual->getHijos()[i], hijo);
        if (encontrado != nullptr) return encontrado;
    }

    return nullptr;
}

void ArbolBPlus::dividirInterno(NodoBPlus* nodo) {
    int mitad = grado / 2;

    NodoBPlus* nuevo = new NodoBPlus(grado, false);

    for (int i = mitad + 1; i < grado; i++) {
        nuevo->getClaves()[i - (mitad + 1)] = nodo->getClaves()[i];
    }

    for (int i = mitad + 1; i <= grado; i++) {
        nuevo->getHijos()[i - (mitad + 1)] = nodo->getHijos()[i];
    }

    nuevo->setCantidadClaves(grado - mitad - 1);

    string claveSube = nodo->getClaves()[mitad];
    nodo->setCantidadClaves(mitad);

    insertarEnPadre(nodo, claveSube, nuevo);
}

void ArbolBPlus::mostrar() {
    mostrarRec(raiz);
}

void ArbolBPlus::mostrarRec(NodoBPlus* nodo) {
    if (nodo == nullptr) return;

    if (nodo->getEsHoja()) {
        for (int i = 0; i < nodo->getCantidadClaves(); i++) {
            nodo->getProductos()[i]->mostrar();
        }
    } else {
        for (int i = 0; i <= nodo->getCantidadClaves(); i++) {
            mostrarRec(nodo->getHijos()[i]);
        }
    }
}

void ArbolBPlus::buscarPorCategoria(string categoria) {
    buscarRec(raiz, categoria);
}

void ArbolBPlus::buscarRec(NodoBPlus* nodo, string categoria) {
    if (nodo == nullptr) return;

    if (nodo->getEsHoja()) {
        for (int i = 0; i < nodo->getCantidadClaves(); i++) {
            if (nodo->getClaves()[i] == categoria) {
                nodo->getProductos()[i]->mostrar();
            }
        }
    } else {
        for (int i = 0; i <= nodo->getCantidadClaves(); i++) {
            buscarRec(nodo->getHijos()[i], categoria);
        }
    }
}

void ArbolBPlus::eliminar(string clave) {
    cout << "Eliminacion no implementada aun\n";
}

void ArbolBPlus::generarDot(string archivo) {
    ofstream file(archivo);

    file << "digraph G {\n";
    file << "node [shape=record, style=filled, fillcolor=lightblue];\n";

    generarDotRec(file, raiz);

    file << "}\n";
    file.close();
}

void ArbolBPlus::generarDotRec(ofstream &file, NodoBPlus* nodo) {
    if (nodo == nullptr) return;

    file << "\"Nodo" << nodo << "\" [label=\"";

    if (nodo->getEsHoja()) {
      
        for (int i = 0; i < nodo->getCantidadClaves(); i++) {
            file << nodo->getClaves()[i] << "\\n" //
                 << nodo->getProductos()[i]->getNombre();

            if (i != nodo->getCantidadClaves() - 1) file << " | ";
        }
    } else {
 
        for (int i = 0; i < nodo->getCantidadClaves(); i++) {
            file << nodo->getClaves()[i];

            if (i != nodo->getCantidadClaves() - 1) file << " | ";
        }
    }

    file << "\"];\n";

    if (!nodo->getEsHoja()) {
        for (int i = 0; i <= nodo->getCantidadClaves(); i++) {
            if (nodo->getHijos()[i] != nullptr) {
                file << "\"Nodo" << nodo << "\" -> \"Nodo"
                     << nodo->getHijos()[i] << "\";\n";

                generarDotRec(file, nodo->getHijos()[i]);
            }
        }
    }
}

                