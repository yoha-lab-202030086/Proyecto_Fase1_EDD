#include "../include/ArbolB.h"
#include <iostream>
#include <fstream>

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

void ArbolB::mostrar() {
    cout<<"\n=== ARBOL B (IN-ORDEN) === \n";
    mostrarRec(raiz);
    }

void ArbolB::mostrarRec(NodoB* nodo) {
    if(nodo == nullptr) return;

    int i;

    for(i=0; i < nodo->cantidadClaves; i++) {
        if(!nodo->esHoja) {
            mostrarRec(nodo->hijos[i]);
        }
        nodo->productos[i]->mostrar();
    }
    if(!nodo->esHoja) {
        mostrarRec(nodo->hijos[i]);
     }
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

void ArbolB::eliminar(string fecha) {
    if(!raiz) return;

    eliminarRec(raiz, fecha);

    if(raiz->cantidadClaves == 0){
        NodoB* temp = raiz;

        if(raiz->esHoja)
            raiz = nullptr;
        else
            raiz = raiz->hijos[0];

        delete temp;
    }
}

void ArbolB::eliminarRec(NodoB* nodo, string fecha){

    int i = 0;

    // Buscar
    while(i < nodo->cantidadClaves &&
          fecha > nodo->productos[i]->getFechaCaducidad()){
        i++;
    }

    // CASO: encontrado 
    if(i < nodo->cantidadClaves &&
       nodo->productos[i]->getFechaCaducidad() == fecha){

        if(nodo->esHoja){
            eliminarDeHoja(nodo, i);
        } else {
            eliminarDeInterno(nodo, i);
        }
        return;
    }

    // Si es hoja → no existe
    if(nodo->esHoja){
        cout << "No encontrado\n";
        return;
    }

    // Bajar al hijo correcto
    bool ultimo = (i == nodo->cantidadClaves);

    if(nodo->hijos[i]->cantidadClaves < gradoMinimo){
        llenar(nodo, i);
    }

    if(ultimo && i > nodo->cantidadClaves)
        eliminarRec(nodo->hijos[i-1], fecha);
    else
        eliminarRec(nodo->hijos[i], fecha);
}

void ArbolB::eliminarDeHoja(NodoB* nodo, int i){
    for(int j = i; j < nodo->cantidadClaves - 1; j++){
        nodo->productos[j] = nodo->productos[j+1];
    }
    nodo->cantidadClaves--;
}

void ArbolB::eliminarDeInterno(NodoB* nodo, int i){

    NodoB* hijoIzq = nodo->hijos[i];
    NodoB* hijoDer = nodo->hijos[i+1];

    if(hijoIzq->cantidadClaves >= gradoMinimo){
        Producto* pred = obtenerPredecesor(hijoIzq);
        nodo->productos[i] = pred;
        eliminarRec(hijoIzq, pred->getFechaCaducidad());
    }
    else if(hijoDer->cantidadClaves >= gradoMinimo){
        Producto* succ = obtenerSucesor(hijoDer);
        nodo->productos[i] = succ;
        eliminarRec(hijoDer, succ->getFechaCaducidad());
    }
    else {
        string fechaOriginal = nodo->productos[i]->getFechaCaducidad();
    
        fusionar(nodo, i);
        eliminarRec(hijoIzq, fechaOriginal);
    }
}

Producto* ArbolB::obtenerPredecesor(NodoB* nodo){
    while(!nodo->esHoja)
        nodo = nodo->hijos[nodo->cantidadClaves];

    return nodo->productos[nodo->cantidadClaves - 1];
}

Producto* ArbolB::obtenerSucesor(NodoB* nodo){
    while(!nodo->esHoja)
        nodo = nodo->hijos[0];

    return nodo->productos[0];
}

void ArbolB::llenar(NodoB* nodo, int i){

    if(i != 0 && nodo->hijos[i-1]->cantidadClaves >= gradoMinimo)
        prestarDeAnterior(nodo, i);

    else if(i != nodo->cantidadClaves &&
            nodo->hijos[i+1]->cantidadClaves >= gradoMinimo)
        prestarDeSiguiente(nodo, i);

    else {
        if(i != nodo->cantidadClaves)
            fusionar(nodo, i);
        else
            fusionar(nodo, i-1);
    }
}

void ArbolB::prestarDeAnterior(NodoB* nodo, int i){

    NodoB* hijo = nodo->hijos[i];
    NodoB* hermano = nodo->hijos[i-1];

    // Mover claves del hijo hacia la derecha
    for(int j = hijo->cantidadClaves - 1; j >= 0; j--){
        hijo->productos[j+1] = hijo->productos[j];
    }

    // Si no es hoja, mover hijos
    if(!hijo->esHoja){
        for(int j = hijo->cantidadClaves; j >= 0; j--){
            hijo->hijos[j+1] = hijo->hijos[j];
        }
    }

    // Bajar clave del padre al hijo
    hijo->productos[0] = nodo->productos[i-1];

    // Subir clave del hermano al padre
    nodo->productos[i-1] = hermano->productos[hermano->cantidadClaves - 1];

    // Si hay hijos, mover también el puntero
    if(!hijo->esHoja){
        hijo->hijos[0] = hermano->hijos[hermano->cantidadClaves];
    }

    hijo->cantidadClaves++;
    hermano->cantidadClaves--;
}

void ArbolB::prestarDeSiguiente(NodoB* nodo, int i){

    NodoB* hijo = nodo->hijos[i];
    NodoB* hermano = nodo->hijos[i+1];

    // Bajar clave del padre
    hijo->productos[hijo->cantidadClaves] = nodo->productos[i];

    // Si hay hijos
    if(!hijo->esHoja){
        hijo->hijos[hijo->cantidadClaves + 1] = hermano->hijos[0];
    }

    // Subir clave del hermano
    nodo->productos[i] = hermano->productos[0];

    // Mover claves del hermano
    for(int j = 1; j < hermano->cantidadClaves; j++){
        hermano->productos[j-1] = hermano->productos[j];
    }

    // Mover hijos si existen
    if(!hermano->esHoja){
        for(int j = 1; j <= hermano->cantidadClaves; j++){
            hermano->hijos[j-1] = hermano->hijos[j];
        }
    }

    hijo->cantidadClaves++;
    hermano->cantidadClaves--;
}

void ArbolB::fusionar(NodoB* nodo, int i){

    NodoB* hijo = nodo->hijos[i];
    NodoB* hermano = nodo->hijos[i+1];

    hijo->productos[gradoMinimo - 1] = nodo->productos[i];

    for(int j = 0; j < hermano->cantidadClaves; j++){
        hijo->productos[j + gradoMinimo] = hermano->productos[j];
    }

    if(!hijo->esHoja){
        for(int j = 0; j <= hermano->cantidadClaves; j++){
            hijo->hijos[j + gradoMinimo] = hermano->hijos[j];
        }
    }

    for(int j = i; j < nodo->cantidadClaves - 1; j++){
        nodo->productos[j] = nodo->productos[j+1];
    }

    nodo->cantidadClaves--;

    delete hermano;
}

void ArbolB::generarDot(string archivo) {

    ofstream file(archivo);

    file << "digraph BTree {\n";
    file << "graph [bgcolor=\"lightblue\"];\n"; 
    file << "node [shape=record, style=filled, fillcolor=\"white\"];\n";

    generarDotRec(file, raiz);

    file << "}\n";
    file.close();
}

void ArbolB::generarDotRec(ofstream &file, NodoB* nodo) {

    if (nodo == nullptr) return;

    file << "\"Nodo" << nodo << "\" [label=\"";

    int i;

    for (i = 0; i < nodo->cantidadClaves; i++) {

        file << "<f" << i << "> "
             << nodo->productos[i]->getFechaCaducidad()
             << " | ";
    }

    file << "<f" << i << ">\"";

    file << "];\n";

    // Conexiones
    if (!nodo->esHoja) {
        for (int j = 0; j <= nodo->cantidadClaves; j++) {

            if (nodo->hijos[j] != nullptr) {

                file << "\"Nodo" << nodo << "\":f" << j
                     << " -> \"Nodo" << nodo->hijos[j] << "\";\n";

                generarDotRec(file, nodo->hijos[j]);
            }
        }
    }
}