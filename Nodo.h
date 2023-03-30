#ifndef NODO_H
#define NODO_H

#include <iostream>
#include "Articulo.h"

class Nodo{
  public:  
    Articulo *articulo;
    Nodo* siguiente = NULL;
    Nodo(Articulo* art);
};
#endif