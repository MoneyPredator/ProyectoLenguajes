#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "Nodo.h"
class Usuario{
public:
    Usuario(std::string nombre);
    std::string nombre;
    void verLista(Nodo*);
};

#endif