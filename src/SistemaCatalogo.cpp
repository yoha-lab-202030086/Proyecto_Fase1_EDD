#include "../include/SistemaCatalogo.h"
#include <iostream>

using namespace std; 

SistemaCatalogo::SistemaCatalogo() {
}

void SistemaCatalogo::agregarProducto(Producto* producto) {
    listaProductos.insertar(producto); 
}

void SistemaCatalogo::mostrarProductos() {
    listaProductos.mostrar();
}

void SistemaCatalogo::buscarProducto(string nombre) {
    Producto* encontrado = 
    listaProductos.buscarPorNombre(nombre);

    if(encontrado != nullptr) {

        cout<<"Producto encontrado:  \n"; 
        encontrado->mostrar(); 
    }else{
        cout<<"Producto no encontrado:  \n";
      }
}
