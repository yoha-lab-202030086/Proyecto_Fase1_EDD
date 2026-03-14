#include "../include/Lista.h"
#include "../include/Producto.h"

int main() {

    Lista lista;

    Producto* p1 = new
    Producto("Arroz","111","Granos","2026-05-10","Gallo",5.50,100);
    Producto* p2 = new
    Producto("Leche","222","Lacteos","2026-04-01","DosPinos",8.25,50);

    lista.insertar(p1); 
    lista.insertar(p2);

    lista.mostrar();

    return 0;
}