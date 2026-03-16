#include "../include/tablaHash.h"

TablaHash::TablaHash() {  
}

int TablaHash::funcionHash(string codigo) {
    int num = stoi(codigo);

  return num % TAM;
}

void TablaHash::insertar(Producto* producto) {
    int indice = funcionHash(producto->getCodigoBarra());
    
        tabla[indice].insertar(producto);       
}

Producto* TablaHash::buscar(string codigo) {
    int indice = funcionHash(codigo);

        return tabla[indice].buscarPorCodigo(codigo);
}
