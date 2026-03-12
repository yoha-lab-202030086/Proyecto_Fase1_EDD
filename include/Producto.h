#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

using namespace std;

class Producto{

private:

    string nombre;
    string codigoBarra;
    string categoria;
    string fechaCaducidad;
    string marca;

    double precio;
    int cantidadDisponible;

public:

    Producto();

    Producto(string nombre,
             string codigoBarra,
             string categoria,
             string fechaCaducidad,
             string marca,
             double precio,
             int cantidadDisponible);

    string getNombre();
    string getCodigoBarra();
    string getCategoria();
    string getFechaCaducidad();
    string getMarca();
    double getPrecio();
    int getCantidadDisponible();

    void mostrar();

};

#endif