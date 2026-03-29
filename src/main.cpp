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
        cout<<"6. Mostrar productos ordenados por nombre (AVL)\n";
        cout<<"7. Buscar producto por nombre (AVL)\n";
        cout<<"8. Eliminar producto por nombre (AVL)\n";
        cout<<"9. Comparar rendimiento Lista Vs AVL\n";
        cout<<"10. Buscar productos por categoria (arbol B+)\n";
        //cout<<"10. Comparar rendimiento Lista Vs AVL\n";
        cout<<"11. Mostrar productos ordenados por fecha (Arbol B)\n";
        cout<<"12. Buscar productos por rango de fecha (Arbol B)\n";
        cout<<"13. Eliminar productos por fecha (Arbol B)\n";
        cout<<"15. Cargar archivo CSV\n";
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
        else if(opcion == 9) {

            sistema.compararRendimiento();
        }
        else if(opcion == 10) {
            string categoria; 
            cout<<"Ingese categoria: ";
            cin>>categoria;

            sistema.buscarPorCategoria(categoria);
        }
        else if(opcion == 11) {
            sistema.mostrarArbolB();
        }   
        else if(opcion == 12) {
            string inicio, fin;
            cout<<"Fecha inicio (YYYY-MM-DD): ";
            cin>>inicio;
            cout<<"Fecha fin (YYYY-MM-DD): ";
            cin>>fin;

            sistema.buscarPorRangoFecha(inicio, fin);
        }
        else if(opcion == 13) {
            string fecha;
            cout<<"Ingrese la fecha de caducidad (YYYY-MM-DD): ";
            cin>>fecha;
 
            sistema.eliminarProductoPorFecha(fecha);

        }
        else if(opcion == 15) {

            sistema.cargarDesdeCSV("data/productos.csv");
        }

 } while(opcion != 0);

    return 0;

}