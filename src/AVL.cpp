#include "../include/AVL.h"

// Constructor
AVL::AVL(){
    raiz = nullptr;
}

// Altura
int AVL::altura(NodoAVL* n){
    if(n == nullptr) return 0;
    return n->getAltura();
}

// Máximo
int AVL::max(int a, int b){
    return (a > b) ? a : b;
}

// Factor de balance
int AVL::getBalance(NodoAVL* n){
    if(n == nullptr) return 0;
    return altura(n->getIzquierda()) - altura(n->getDerecha());
}

// Rotación derecha
NodoAVL* AVL::rotarDerecha(NodoAVL* nodoDesbalanceado){

    NodoAVL* nuevaRaiz = nodoDesbalanceado->getIzquierda();
    NodoAVL* subArbol = nuevaRaiz->getDerecha();

    nuevaRaiz->setDerecha(nodoDesbalanceado);
    nodoDesbalanceado->setIzquierda(subArbol);

    nodoDesbalanceado->setAltura(max(altura(nodoDesbalanceado->getIzquierda()), altura(nodoDesbalanceado->getDerecha())) + 1);
    nuevaRaiz->setAltura(max(altura(nuevaRaiz->getIzquierda()), altura(nuevaRaiz->getDerecha())) + 1);

    return nuevaRaiz;
}

// Rotación izquierda
NodoAVL* AVL::rotarIzquierda(NodoAVL* nodoDesbalanceado){

    NodoAVL* nuevaRaiz = nodoDesbalanceado->getDerecha();
    NodoAVL* subArbol = nuevaRaiz->getIzquierda();

    nuevaRaiz->setIzquierda(nodoDesbalanceado);
    nodoDesbalanceado->setDerecha(subArbol);

    nodoDesbalanceado->setAltura(max(altura(nodoDesbalanceado->getIzquierda()), altura(nodoDesbalanceado->getDerecha())) + 1);
    nuevaRaiz->setAltura(max(altura(nuevaRaiz->getIzquierda()), altura(nuevaRaiz->getDerecha())) + 1);

    return nuevaRaiz;
}

// Insertar
NodoAVL* AVL::insertar(NodoAVL* nodo, Producto* producto){

    if(nodo == nullptr){
        return new NodoAVL(producto);
    }

    if(producto->getNombre() < nodo->getProducto()->getNombre()){
        nodo->setIzquierda(insertar(nodo->getIzquierda(), producto));
    }
    else if(producto->getNombre() > nodo->getProducto()->getNombre())
    {
        nodo->setDerecha(insertar(nodo->getDerecha(), producto));
    } else {
        return nodo;
    }

    // Actualizar altura
    nodo->setAltura(1 + max(altura(nodo->getIzquierda()), altura(nodo->getDerecha())));

    // Balance
    int balance = getBalance(nodo);

    // Caso 1: Izquierda-Izquierda
    if(balance > 1 && producto->getNombre() < nodo->getIzquierda()->getProducto()->getNombre()){
        return rotarDerecha(nodo);
    }

    // Caso 2: Derecha-Derecha
    if(balance < -1 && producto->getNombre() > nodo->getDerecha()->getProducto()->getNombre()){
        return rotarIzquierda(nodo);
    }

    // Caso 3: Izquierda-Derecha
    if(balance > 1 && producto->getNombre() > nodo->getIzquierda()->getProducto()->getNombre()){
        nodo->setIzquierda(rotarIzquierda(nodo->getIzquierda()));
        return rotarDerecha(nodo);
    }

    // Caso 4: Derecha-Izquierda
    if(balance < -1 && producto->getNombre() < nodo->getDerecha()->getProducto()->getNombre()){
        nodo->setDerecha(rotarDerecha(nodo->getDerecha()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}

// Insertar público
void AVL::insertar(Producto* producto){
    insertarSeguro(producto);
}

bool AVL::insertarSeguro(Producto* producto){
    if(buscar(producto->getNombre()) != nullptr){
        return false;
}

    raiz = insertar(raiz, producto);
    return true;
}

// Buscar
Producto* AVL::buscar(NodoAVL* nodo, std::string nombre){

    if(nodo == nullptr) return nullptr;

    if(nodo->getProducto()->getNombre() == nombre){
        return nodo->getProducto();
    }

    if(nombre < nodo->getProducto()->getNombre()){
        return buscar(nodo->getIzquierda(), nombre);
    }

    return buscar(nodo->getDerecha(), nombre);
}

Producto* AVL::buscar(std::string nombre){
    return buscar(raiz, nombre);
}

void AVL::inOrden(NodoAVL* nodo) {
    if(nodo != nullptr) {
        inOrden(nodo->getIzquierda());
        nodo->getProducto()->mostrar();
        inOrden(nodo->getDerecha());
    }
}

void AVL::mostrarInOrden() {
    inOrden(raiz);
 }   

 NodoAVL* AVL::eliminar(NodoAVL* nodo, std::string nombre){

    if(nodo == nullptr) return nodo;

    if(nombre < nodo->getProducto()->getNombre()){
        nodo->setIzquierda(eliminar(nodo->getIzquierda(), nombre));
    }
    else if(nombre > nodo->getProducto()->getNombre()){
        nodo->setDerecha(eliminar(nodo->getDerecha(), nombre));
    }
    else{

        // Nodo encontrado
        if(nodo->getIzquierda() == nullptr || nodo->getDerecha() == nullptr){

            NodoAVL* temp = nodo->getIzquierda() ? nodo->getIzquierda() : nodo->getDerecha();

            if(temp == nullptr){
                temp = nodo;
                nodo = nullptr;
            } else {
                *nodo = *temp;
            }

            delete temp;
        }
        else{
            NodoAVL* temp = nodo->getDerecha();

            while(temp->getIzquierda() != nullptr){
                temp = temp->getIzquierda();
            }

            nodo->setProducto(temp->getProducto());

            nodo->setDerecha(eliminar(nodo->getDerecha(), temp->getProducto()->getNombre()));
        }
    }

    if(nodo == nullptr) return nodo;

    nodo->setAltura(1 + max(altura(nodo->getIzquierda()), altura(nodo->getDerecha())));

    int balance = getBalance(nodo);

    // Balanceos
    if(balance > 1 && getBalance(nodo->getIzquierda()) >= 0)
        return rotarDerecha(nodo);

    if(balance > 1 && getBalance(nodo->getIzquierda()) < 0){
        nodo->setIzquierda(rotarIzquierda(nodo->getIzquierda()));
        return rotarDerecha(nodo);
    }

    if(balance < -1 && getBalance(nodo->getDerecha()) <= 0)
        return rotarIzquierda(nodo);

    if(balance < -1 && getBalance(nodo->getDerecha()) > 0){
        nodo->setDerecha(rotarDerecha(nodo->getDerecha()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void AVL::eliminar(std::string nombre){
    raiz = eliminar(raiz, nombre);
}
 