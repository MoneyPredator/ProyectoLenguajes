#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <iostream>
#include "Coordinador.h"
#include "Cliente.h"

class Programa{
  public:
    int Usuario;
    Nodo* inventario;
    void Bienvenida();
    void menuCliente(std::string);
    void menuCoordinador(std::string);
    void cerrar(int);
};

#endif