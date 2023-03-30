#ifndef ARTICULO_H
#define ARTICULO_H

#include <iostream>
#include <string>

class Articulo {
public:
    std::string nombre;
    int id;
    float precio;
    char tipo;
    int cantidad;
    virtual ~Articulo() {};
    Articulo() {}
    Articulo(std::string n, int i, float p,char t, int c);
};

class ArticuloDep : public Articulo{
public:
    char tipo = 'D';
    ArticuloDep() {}
    ArticuloDep(std::string nombre, int id, float precio,char tipo, int cantidad);
};

class ArticuloTec : public Articulo{
public:
    char tipo = 'T';
    ArticuloTec() {}
    ArticuloTec(std::string nombre, int id, float precio,char tipo, int cantidad);
};

class ArticuloExt : public Articulo{
public:
    int impuesto;
    char tipo = 'E';
    ArticuloExt() {}
    ArticuloExt(std::string nombre, int id, float precio,char tipo, int cantidad, int impuesto);
};

#endif