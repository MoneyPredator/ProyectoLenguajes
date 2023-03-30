#include "Articulo.h"
//Constructor
Articulo::Articulo(std::string n, int i, float p,char t, int c) {
    nombre = n;
    id = i;
    precio = p;
    tipo = t;
    cantidad = c;
}
ArticuloDep::ArticuloDep(std::string n,int i, float p,char t,int c):Articulo(n,i,p,t,c){
  this->nombre = n;
  this->id = i;
  this->precio = p;
  this->tipo = t;
  this->cantidad = c;
}
ArticuloTec::ArticuloTec(std::string n,int i, float p,char t,int c):Articulo(n,i,p,t,c){
  this->nombre = n;
  this->id = i;
  this->precio = p;
  this->tipo = t;
  this->cantidad = c;
}
ArticuloExt::ArticuloExt(std::string n,int i, float p,char t,int c,int im):Articulo(n,i,p,t,c){
  this->nombre = n;
  this->id = i;
  this->precio = p;
  this->tipo = t;
  this->cantidad = c;
  this->impuesto = im;
}