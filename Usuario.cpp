#include "Usuario.h"

Usuario::Usuario(std::string nombre){
  this->nombre = nombre;
}

void Usuario::verLista(Nodo *inventario){
  Nodo* aux = inventario;
  bool dep = false;
  bool tec = false;
  if(aux == NULL){
    std::cout<<"No hay articulos en el inventario.";
  }
  else{
  while(aux){
    if(aux->articulo.tipo == 'D'){
      if(!dep){
        std::cout<<"--Tipos de Articulo Deportivos--"<<std::endl;
        dep = true;
      }
        std::cout<<"Nombre: "<<aux->articulo.nombre<<std::endl;
        std::cout<<"Id: "<<aux->articulo.id<<std::endl;
        std::cout<<"Precio: "<<aux->articulo.precio<<std::endl;
        std::cout<<"Cantidad: "<<aux->articulo.cantidad<<std::endl;
        std::cout<<std::endl;
    }
    else if (aux->articulo.tipo == 'T'){
      if(!tec){
        std::cout<<"--Tipos de Articulo Tecnologico--"<<std::endl;
        tec = true;
      }
        std::cout<<"Nombre: "<<aux->articulo.nombre<<std::endl;
        std::cout<<"Id: "<<aux->articulo.id<<std::endl;
        std::cout<<"Precio: "<<aux->articulo.precio<<std::endl;
        std::cout<<"Cantidad: "<<aux->articulo.cantidad<<std::endl;
        std::cout<<std::endl;
    }
    else if (aux->articulo.tipo == 'E'){
      if(!tec){
        std::cout<<"--Tipos de Articulo Extranjero--"<<std::endl;
        tec = true;
      }
        std::cout<<"Nombre: "<<aux->articulo.nombre<<std::endl;
        std::cout<<"Id: "<<aux->articulo.id<<std::endl;
        std::cout<<"Precio: "<<aux->articulo.precio<<std::endl;
        std::cout<<"Cantidad: "<<aux->articulo.cantidad<<std::endl;
        std::cout<<std::endl;
    }
    aux = aux->siguiente;
  }
}
}