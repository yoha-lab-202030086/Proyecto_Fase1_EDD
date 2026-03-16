#include "../include/SistemaCatalogo.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std; 

SistemaCatalogo::SistemaCatalogo() {
}

void SistemaCatalogo::agregarProducto(Producto* producto) {
    listaProductos.insertar(producto); 
    tablaHash.insertar(producto);
}

void SistemaCatalogo::mostrarProductos() {
    listaProductos.mostrar();
}

void SistemaCatalogo::buscarProducto(string nombre) {
    Producto* encontrado = listaProductos.buscarPorNombre(nombre);

    if(encontrado != nullptr) {

        cout<<"Producto encontrado:  \n"; 
        encontrado->mostrar(); 
    }else{
        cout<<"Producto no encontrado:  \n";
      }
}

void SistemaCatalogo::buscarPorCodigo(string codigo) {
    Producto* encontrado = tablaHash.buscar(codigo);

    if(encontrado != nullptr) {

        cout<<"Producto encontrado:  \n"; 
        encontrado->mostrar(); 
    }else{
        cout<<"Producto no encontrado:  \n";
      }
}

void SistemaCatalogo::cargarDesdeCSV(string archivo) {
    ifstream file(archivo);

    if(!file.is_open()) {

    cout<<"No se pudo abrir el archivo\n";
       return;
}

    string linea;

     getline(file,linea); 

     int contador = 0; 

   while(getline(file,linea)) {
      contador++;

    stringstream ss(linea);

        string nombre;
        string codigo;
        string categoria;
        string fecha;
        string marca;
        string precioStr;
        string cantidadStr;

        getline(ss,nombre,',');
        getline(ss,codigo,',');
        getline(ss,categoria,',');
        getline(ss,fecha,',');
        getline(ss,marca,',');
        getline(ss,precioStr,',');
        getline(ss,cantidadStr,',');

        double precio = stod(precioStr);
        int cantidad = stoi(cantidadStr);

        Producto* nuevo = new Producto(
            nombre,
            codigo,
            categoria,
            fecha,
            marca,
            precio,
            cantidad
        );

        agregarProducto(nuevo);

    }

    file.close();

    cout<<"Productos cargados: \n" << contador << endl;

}

