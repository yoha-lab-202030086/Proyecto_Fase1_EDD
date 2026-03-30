#include "../include/SistemaCatalogo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib>

using namespace std::chrono; 

SistemaCatalogo::SistemaCatalogo() : arbolB(3){
}

void SistemaCatalogo::agregarProducto(Producto* producto, bool mostrarMensaje) {

    if(!arbol.insertarSeguro(producto)) {
        if(mostrarMensaje)
        cout<<"Producto ya existe\n";
        return;
    }

    listaProductos.insertar(producto); 
    listaOrdenada.insertarOrdenado(producto);
    arbolB.insertar(producto);
    arbolBPlus.insertar(producto);

    if(mostrarMensaje)
     cout<<"Producto agregado correctamente\n";

}

// Mostrar
void SistemaCatalogo::mostrarProductos() {
    listaProductos.mostrar();
}

void SistemaCatalogo::mostrarListaOrdenada() {
    cout<<"\n=== LISTA ORDENADA POR NOMBRE ===\n";
    listaOrdenada.mostrar();
}

// Buscar por codigo (LISTA)
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

void SistemaCatalogo::mostrarAVL() {
   cout<<"\n=== PRODUCTOS ORDENADOS POR NOMBRE ===\n";
    arbol.mostrarInOrden();
    arbol.generarDot("avl.dot");
    system("dot -Tpng avl.dot -o avl.png");
}

// Buscar por nombre (AVL)
void SistemaCatalogo::buscarProducto(string nombre) {
    Producto* encontrado = arbol.buscar(nombre);

    if(encontrado != nullptr) {
        cout<<"Producto encontrado:\n"; 
        encontrado->mostrar(); 
    } else {
        cout<<"Producto no encontrado\n";
    }
}

void SistemaCatalogo::compararRendimiento() {

    Nodo* actual = listaProductos.getCabeza();

    if(actual == nullptr){
        cout << "No hay productos para medir\n";
        return;
    }

    // Obtener primero
    string primero = actual->getProducto()->getNombre();

    // Obtener último
    while(actual->getSiguiente() != nullptr){
        actual = actual->getSiguiente();
    }
    string ultimo = actual->getProducto()->getNombre();

    string noExiste = "XXXX_NO_EXISTE";

    int N = 1000;
    int M = 50;

    long long totalLista = 0;
    long long totalListaOrdenada = 0;
    long long totalAVL = 0;

    // Busqueda
    for(int j = 0; j < M; j++){
        for(int i = 0; i < N; i++){

            string nombre;

            if(i % 3 == 0) nombre = primero;
            else if(i % 3 == 1) nombre = ultimo;
            else nombre = noExiste;

            // Lista normal
            auto i1 = high_resolution_clock::now();
            listaProductos.buscarPorNombre(nombre);
            auto f1 = high_resolution_clock::now();
            totalLista += duration_cast<microseconds>(f1 - i1).count();

            // Lista ordenada
            auto i2 = high_resolution_clock::now();
            listaOrdenada.buscarPorNombre(nombre);
            auto f2 = high_resolution_clock::now();
            totalListaOrdenada += duration_cast<microseconds>(f2 - i2).count();

            // AVL
            auto i3 = high_resolution_clock::now();
            arbol.buscar(nombre);
            auto f3 = high_resolution_clock::now();
            totalAVL += duration_cast<microseconds>(f3 - i3).count();
        }
    }

    // Insercion
   long long totalInsLista = 0;
   long long totalInsListaOrd = 0;
   long long totalInsAVL = 0;

for(int i = 0; i < 2000; i++){
    Producto* p = new Producto("Test"+to_string(i), to_string(i), "Test", "2027-01-01", "Test", 10, 1);

    auto i1 = high_resolution_clock::now();
    listaProductos.insertar(p);
    auto f1 = high_resolution_clock::now();
    totalInsLista += duration_cast<microseconds>(f1 - i1).count();

    auto i2 = high_resolution_clock::now();
    listaOrdenada.insertarOrdenado(p);
    auto f2 = high_resolution_clock::now();
    totalInsListaOrd += duration_cast<microseconds>(f2 - i2).count();

    auto i3 = high_resolution_clock::now();
    arbol.insertar(p);
    auto f3 = high_resolution_clock::now();
    totalInsAVL += duration_cast<microseconds>(f3 - i3).count();
}

long long insLista = totalInsLista / 500;
long long insListaOrd = totalInsListaOrd / 500;
long long insAVL = totalInsAVL / 500;

    // Eliminacion
    long long totalDelLista = 0;
    long long totalDelListaOrd = 0;
    long long totalDelAVL = 0;

for(int i = 0; i < 2000; i++){

    string nombre = "Test" + to_string(i);

    auto i1 = high_resolution_clock::now();
    listaProductos.eliminarPorNombre(nombre);
    auto f1 = high_resolution_clock::now();
    totalDelLista += duration_cast<microseconds>(f1 - i1).count();

    auto i2 = high_resolution_clock::now();
    listaOrdenada.eliminarPorNombre(nombre);
    auto f2 = high_resolution_clock::now();
    totalDelListaOrd += duration_cast<microseconds>(f2 - i2).count();

    auto i3 = high_resolution_clock::now();
    arbol.eliminar(nombre);
    auto f3 = high_resolution_clock::now();
    totalDelAVL += duration_cast<microseconds>(f3 - i3).count();
}

long long delLista = totalDelLista / 500;
long long delListaOrd = totalDelListaOrd / 500;
long long delAVL = totalDelAVL / 500;

    // Promedios
    long long promLista = totalLista / (N * M);
    long long promListaOrd = totalListaOrdenada / (N * M);
    long long promAVL = totalAVL / (N * M);

    // Resultados
    cout << "\n=== BUSQUEDA (PROMEDIO) ===\n";
    cout << "Lista: " << promLista << " us\n";
    cout << "Lista Ordenada: " << promListaOrd << " us\n";
    cout << "AVL: " << promAVL << " us\n";

    cout << "\n=== INSERCION ===\n";
    cout << "Lista: " << insLista << " us\n";
    cout << "Lista Ordenada: " << insListaOrd << " us\n";
    cout << "AVL: " << insAVL << " us\n";

    cout << "\n=== ELIMINACION ===\n";
    cout << "Lista: " << delLista << " us\n";
    cout << "Lista Ordenada: " << delListaOrd << " us\n";
    cout << "AVL: " << delAVL << " us\n";

    cout << "\nCasos evaluados:\n";
    cout << "- Exito\n- Extremos\n- Fallo\n";

    cout << "\nComplejidad teorica:\n";
    cout << "Lista: O(n)\n";
    cout << "AVL: O(log n)\n";
}

void SistemaCatalogo::mostrarPorCategoria() {
     cout<<"\n=== PRODUCTOS ORDENADOS POR CATEGORIA ===\n";
     arbolBPlus.mostrar();
     arbolBPlus.generarDot("bplus.dot");
    system("dot -Tpng bplus.dot -o bplus.png");
}   

void SistemaCatalogo::buscarPorCategoria(string categoria) {
    arbolBPlus.buscarPorCategoria(categoria);
} 

void SistemaCatalogo::eliminarProductoBPlus(string nombre) {
    arbolBPlus.eliminar(nombre);
}

void SistemaCatalogo::mostrarArbolB() {
    arbolB.mostrar();
}

void SistemaCatalogo::buscarPorRangoFecha(string inicio, string fin){
    cout<<"\n=== PRODUCTOS EN RANGO ===\n";
    arbolB.buscarPorRango(inicio, fin);
}

void SistemaCatalogo::eliminarProductoPorFecha(string fecha) {

    arbolB.eliminar(fecha);

     cout<<"Producto eliminado correctamente\n";
}   

// Cargar CSV 
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

        agregarProducto(nuevo, false);

        contador++;
    }

    file.close();

    cout << "Productos cargados: " << contador << endl;
}

