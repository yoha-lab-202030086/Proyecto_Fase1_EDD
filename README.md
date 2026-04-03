# Sistema de Catálogo de Supermercado

## Compilación
Asegúrse de tener instalado:
- g++
- make (opcional)
- Graphviz (para generación de imágenes)

Compilar manualmente:
g++ src/*.cpp

## Ejecución
catalogo.exe

## Requisitos
- Sistema operativo Linux / Windows (con MinGW)
- Graphviz instalado (para visualizar árboles)

## Funcionalidades
- Agregar productos
- Mostrar productos
- Buscar por nombre y código
- Eliminar productos
- Ordenamiento por nombre
- Búsqueda por categoría (Árbol B+)
- Búsqueda por rango de fechas (Árbol B)
- Visualización de estructuras (AVL, B, B+)
- Comparación de rendimiento entre estructuras

## Archivos importantes
- src/: implementación
- include/: encabezados
- avl.dot / btree.dot / bplus.dot: archivos generados
- .png: visualización de árboles

## Notas
Para generar imágenes:
dot -Tpng archivo.dot -o salida.png