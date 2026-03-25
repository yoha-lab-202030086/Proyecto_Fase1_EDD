#include "../include/SistemaCatalogo.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std; 

SistemaCatalogo::SistemaCatalogo() {
}

void SistemaCatalogo::agregarProducto(Producto* producto) {

    if(!arbol.insertarSeguro(producto)) {
        cout<<"Producto ya existe\n";
        return;
    }

    listaProductos.insertar(producto); 
    listaOrdenada.insertarOrdenado(producto);
}

// MOSTRAR
void SistemaCatalogo::mostrarProductos() {
    listaProductos.mostrar();
}

void SistemaCatalogo::mostrarListaOrdenada() {
    cout<<"\n=== LISTA ORDENADA POR NOMBRE ===\n";
    listaOrdenada.mostrar();
}

// BUSCAR POR NOMBRE (USA AVL)
void SistemaCatalogo::buscarProducto(string nombre) {
    Producto* encontrado = arbol.buscar(nombre);

    if(encontrado != nullptr) {
        cout<<"Producto encontrado:\n"; 
        encontrado->mostrar(); 
    } else {
        cout<<"Producto no encontrado\n";
    }
}

// BUSCAR POR CODIGO (USA LISTA)
void SistemaCatalogo::buscarPorCodigo(string codigo) {
    Producto* encontrado = listaProductos.buscarPorCodigo(codigo);

    if(encontrado != nullptr) {
        cout<<"Producto encontrado:\n"; 
        encontrado->mostrar(); 
    } else {
        cout<<"Producto no encontrado\n";
    }
}

void SistemaCatalogo::listarPorNombre() {
    cout<<"\n=== PRODUCTOS ORDENADOS POR NOMBRE ===\n";
    arbol.mostrarInOrden();
} 

void SistemaCatalogo::eliminarProducto(string nombre) {

    if(arbol.buscar(nombre) == nullptr) {
        cout<<"Producto no encontrado\n";
        return;
    }    
    listaProductos.eliminarPorNombre(nombre); //lista no ordenada
    listaOrdenada.eliminarPorNombre(nombre);
    arbol.eliminar(nombre);
    
    cout<<"Producto eliminado correctamente\n";
}  

// CARGAR CSV 
void SistemaCatalogo::cargarDesdeCSV(string archivo) {

    ifstream file(archivo);

    if(!file.is_open()) {
        cout << "No se pudo abrir el archivo\n";
        return;
    }

    string linea;
    getline(file, linea); // encabezado

    int contador = 0;

    while(getline(file, linea)) {

        if(linea.empty()) continue;

        stringstream ss(linea);

        string nombre, codigo, categoria, fecha, marca;
        string precioStr, cantidadStr;

        getline(ss,nombre,',');
        getline(ss,codigo,',');
        getline(ss,categoria,',');
        getline(ss,fecha,',');
        getline(ss,marca,',');
        getline(ss,precioStr,',');
        getline(ss,cantidadStr,',');

        double precio = stod(precioStr);
        int cantidad = stod(cantidadStr);

        Producto* nuevo = new Producto(
            nombre, codigo, categoria, fecha, marca, precio, cantidad
        );

        agregarProducto(nuevo);

        contador++;
    }

    file.close();

    cout << "Productos cargados: " << contador << endl;
}