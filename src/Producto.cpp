#include "../include/Producto.h"

Producto::Producto(){

    nombre="";
    codigoBarra="";
    categoria="";
    fechaCaducidad="";
    marca="";
    precio=0;
    cantidadDisponible=0;

}

Producto::Producto(string nombre,
                   string codigoBarra,
                   string categoria,
                   string fechaCaducidad,
                   string marca,
                   double precio,
                   int cantidadDisponible){

    this->nombre=nombre;
    this->codigoBarra=codigoBarra;
    this->categoria=categoria;
    this->fechaCaducidad=fechaCaducidad;
    this->marca=marca;
    this->precio=precio;
    this->cantidadDisponible=cantidadDisponible;

}

string Producto::getNombre(){
    return nombre;
}

string Producto::getCodigoBarra(){
    return codigoBarra;
}

string Producto::getCategoria(){
    return categoria;
}

string Producto::getFechaCaducidad(){
    return fechaCaducidad;
}

string Producto::getMarca(){
    return marca;
}

double Producto::getPrecio(){
    return precio;
}

int Producto::getCantidadDisponible(){
    return cantidadDisponible;
}

void Producto::mostrar(){

    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Codigo: "<<codigoBarra<<endl;
    cout<<"Categoria: "<<categoria<<endl;
    cout<<"Caducidad: "<<fechaCaducidad<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Precio: "<<precio<<endl;
    cout<<"Cantidad disponible : "<<cantidadDisponible<<endl;
    cout<<"----------------------"<<endl;

}