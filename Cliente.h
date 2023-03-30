#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include "Usuario.h"
#include "Nodo.h"

using namespace std;

class Cliente : public Usuario{
    public:
        Cliente(std::string nombre);
        float impuesto = 0;
        Nodo* carritoCompras = NULL;

        void comprar(Nodo*);
        Nodo* devolver(Nodo*);
        void pagar(Nodo*);
        void control(Nodo*,int);
};

#endif