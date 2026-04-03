EXEC = catalogo

CXX = g++

CXXFLAGS = -std=c++11

SRC = src/main.cpp \
      src/Producto.cpp \
      src/Lista.cpp \
      src/Nodo.cpp \
      src/SistemaCatalogo.cpp \
      src/NodoAVL.cpp \
      src/AVL.cpp \
      src/NodoB.cpp \
      src/ArbolB.cpp \
      src/NodoBPlus.cpp \
      src/ArbolBPlus.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)