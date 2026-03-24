#include "../include/SistemaCatalogo.h"
#include <iostream>

using namespace std;

int main(){

    SistemaCatalogo sistema;

    int opcion;

    do{

        cout<<"\n===== CATALOGO DE SUPERMERCADO =====\n";
        cout<<"1. Agregar producto\n";
        cout<<"2. Mostrar productos (lista no ordenada)\n";
        cout<<"3. Mostrar productos (lista ordenada)\n";
        cout<<"4. Buscar producto por codigo de barra (Lista)\n";
        cout<<"5. Eliminar producto (Lista)\n";
        cout<<"6. Mostrar productos ordenados (AVL)\n";
        cout<<"7. Buscar producto por nombre (AVL)\n";
        cout<<"8. Eliminar producto (AVL)\n";
        cout<<"10. Cargar archivo CSV\n";
        cout<<"0. Salir\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        if(opcion == 1){

            string nombre;
            string codigo;
            string categoria;
            string fecha;
            string marca;
            double precio;
            int cantidad;

            cout<<"Nombre: ";
            cin>>nombre;

            cout<<"Codigo de barra: ";
            cin>>codigo;

            cout<<"Categoria: ";
            cin>>categoria;

            cout<<"Fecha caducidad (YYYY-MM-DD): ";
            cin>>fecha;

            cout<<"Marca: ";
            cin>>marca;

            cout<<"Precio: ";
            cin>>precio;

            cout<<"Cantidad disponible: ";
            cin>>cantidad;

            Producto* nuevo = new Producto(nombre,codigo,categoria,fecha,marca,precio,cantidad);

            sistema.agregarProducto(nuevo);

        }

        else if(opcion == 2) {

            sistema.mostrarProductos();

        }

        else if(opcion == 3) {
            sistema.mostrarListaOrdenada();
        }   

        else if(opcion == 4){
            
            string codigo;
            cout<<"Ingrese codigo de barra: ";
            cin>>codigo;

            sistema.buscarPorCodigo(codigo);
        }
        else if(opcion == 5) {
            
            string nombre;
            cout<<"Ingrese nombre del producto a eliminar: ";
            cin>>nombre;

            sistema.eliminarProducto(nombre);
        }
        else if(opcion == 6) {
            sistema.listarPorNombre();
        }
        else if(opcion == 7) {
            string nombre;

            cout<<"Ingrese nombre del producto: ";
            cin>>nombre;

            sistema.buscarProducto(nombre);
        }
        else if(opcion == 8) {
            string nombre;
            cout<<"Ingrese nombre del producto a eliminar: ";
            cin>>nombre;

            sistema.eliminarProducto(nombre);
        }
        else if(opcion == 10) {
            sistema.cargarDesdeCSV("data/productos.csv");
        }

 } while(opcion != 0);

    return 0;

}