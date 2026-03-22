#include "../include/SistemaCatalogo.h"
#include <iostream>

using namespace std;

int main(){

    SistemaCatalogo sistema;

    int opcion;

    do{

        cout<<"\n===== CATALOGO DE SUPERMERCADO =====\n";
        cout<<"1. Agregar producto\n";
        cout<<"2. Mostrar productos\n";
        cout<<"3. Buscar producto por nombre\n";
        cout<<"4. Buscar producto por codigo de barra\n";
        cout<<"5. Cargar archivo CSV\n";
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

        else if(opcion == 2){

            sistema.mostrarProductos();

        }

        else if(opcion == 3){

            string nombre;

            cout<<"Ingrese nombre del producto: ";
            cin>>nombre;

            sistema.buscarProducto(nombre);

        }

        else if(opcion == 4) {
            string codigo;
            cout<<"Ingrese codigo de barra: ";
            cin>>codigo;

            sistema.buscarPorCodigo(codigo);

        }
    else if(opcion == 5){
    sistema.cargarDesdeCSV("data/productos.csv");
        }
 } while(opcion != 0);

    return 0;

}