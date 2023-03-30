#ifndef COORDINADOR_H
#define COORDINADOR_H

#include <iostream>
#include "Nodo.h"
#include "Usuario.h"

//Diablo
class Coordinador:public Usuario{
public:
  Coordinador(std::string nombre);
  std::string nombre;
  Nodo* part = NULL;
  Nodo* addArticulo(Nodo*);
  //int comprobarid(Nodo*,int);
  int comprobarcan(int);
  Nodo* modArticulo(Nodo*,int);
  Nodo* delArticulo(Nodo*,int);
};

#endif