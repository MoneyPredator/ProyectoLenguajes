#include <iostream>
#include "Cliente.h"

Cliente::Cliente(std:: string _nombre):Usuario(_nombre){
  this->nombre = _nombre;
}

void Cliente:: comprar(Nodo *inventario){
  bool exit = false;
  while(!exit){
        verLista(inventario);
        std::cout<<"Ingrese el ID del articulo que desea comprar: ";
        int id; 
        std::cin>>id;
//sl articulo seleccionado
        Nodo* sl = inventario;
        Nodo* anterior = NULL;
        while(sl && sl->articulo->id != id){
          anterior = sl;
          sl = sl->siguiente;
        }
    if(!sl){
      std::cout<<"El articulo no esta disponible."<<std::endl;
    }
    else{
      std::cout<<"Cuantas unidades desea llevar: ";
      int cantidad; 
      std::cin>>cantidad;
      
      if(cantidad < sl->articulo->cantidad){
        sl->articulo->cantidad -= cantidad;
        //agregar articulo al carrito compras
        if(sl->articulo->tipo == 'D'){
        ArticuloDep* nuevo = new ArticuloDep(sl->articulo->nombre,sl->articulo->id,sl->articulo->precio,sl->articulo->tipo, cantidad);
        }
        else if(sl->articulo->tipo == 'T'){
          ArticuloTec* nuevo = new ArticuloTec(sl->articulo->nombre,sl->articulo->id,sl->articulo->precio,sl->articulo->tipo, cantidad);
        }
        else{
          ArticuloTec* nuevo = new ArticuloTec(sl->articulo->nombre,sl->articulo->id,sl->articulo->precio,sl->articulo->tipo, cantidad, sl->articulo->impuesto);
        }
        
        if(carritoCompras == NULL){
          Nodo* nuevo = new Nodo(nuevo);
        }
        else{
          Nodo* aux = carritoCompras;
          while(aux->siguiente){
            aux = aux->siguiente;
          }
          aux->siguiente = new Nodo(nuevo);
          }
        std::cout<<"Articulo agregado al carrito."<<std::endl;
          Nodo* nuevoN = new Nodo(nuevo);
      }

      else if(cantidad == sl->articulo->cantidad){
        
        //agregar articulo al carrito compras
        Articulo nuevo(sl->articulo->nombre,sl->articulo->id,sl->articulo->precio,sl->articulo->tipo, cantidad);
        if(carritoCompras == NULL){
          carritoCompras = new Nodo(nuevo);
        }
        else{
          Nodo* aux = carritoCompras;
          while(aux->siguiente){
            aux = aux->siguiente;
          }
          aux->siguiente = new Nodo(nuevo);
          }
        std::cout<<"Articulo agregado al carrito."<<std::endl;
          Nodo* nuevoN = new Nodo(nuevo);
        control(inventario, id);
        if(anterior == NULL){
            inventario = sl->siguiente;
        }
        else{
          anterior->siguiente = sl->siguiente;
        }
        delete sl;
      }
                
      else{
        std::cout<<"La cantidad pedida supera la existente."<<std::endl;
        continue;
      }
    }
    
    std::cout<<"Desea continuar comprando? \n 1. Para Si. \n2. Para No.\nIngresas: "; int continuar; std::cin>>continuar;
    if(continuar == 2){
      exit = true;
    }
    else if(continuar != 1){
      std::cout<<"Opcion no valida. Ingrese 1 o 2."<<std::endl;
    }
  }
}

void Cliente:: pagar(Nodo* inventario){
    float total = 0;
  if(carritoCompras == NULL){
    std::cout<<"No hay productos en el carrito."<<std::endl;
    return;
  }
    Nodo* aux = carritoCompras;
    std::cout<<"Detalles de su compra:"<<std::endl;
  while(aux){
    if(aux->articulo->id == aux->siguiente->articulo->id){
      std::cout<<"Tienes un descuento del 10%";
      total -= ((total/100)*10);
    }
    if(aux->articulo->tipo == 'E'){
        std::cout<<"--Estos son los articulos con impuesto y su subtotal:--";
        float subtotal = aux->articulo->cantidad * aux->articulo->precio;
        std::cout<<aux->articulo->nombre<<"---x"<<aux->articulo->cantidad<<"---$"<<aux->articulo->precio<<"Impuesto:"<<aux->articulo->impuesto<<" Subtotal: "<<subtotal<<std::endl;
        std::cout<<std::endl;
        total += subtotal;
        aux = aux->siguiente;
    }
    float subtotal = aux->articulo->cantidad * aux->articulo->precio;
    std::cout<<aux->articulo->nombre<<"---x"<<aux->articulo->cantidad<<"---$"<<aux->articulo->precio<<" Subtotal: "<<subtotal<<std::endl;
    std::cout<<std::endl;
    total += subtotal;
    aux = aux->siguiente;
  }
    std::cout<<"El total a pagar es:";
    std::cout<<total<<std::endl;
    std::cout<<"Desea pagar?\n1.Si \n2.No"<<std::endl;
    int pago;
    std::cin>>pago;
    if(pago == 1){
        std::cout<<"Pago exitoso,Feliz dia"<<std::endl;
        carritoCompras = NULL;
    }
    else if(pago == 2){
        inventario = devolver(inventario);
        std::cout<<"Compra cancelada"<<std::endl;
        verLista(carritoCompras);
    }
    total = 0;
}

Nodo* Cliente::devolver(Nodo* inventario){
  Nodo* aux = inventario;
  while(aux !=NULL){
    Nodo* caraux = carritoCompras;
    bool encontrar = false;
    while(caraux != NULL && !encontrar){
      if(caraux->articulo->id == aux->articulo->id){
        aux->articulo->cantidad += caraux->articulo->cantidad;
        encontrar = true;
      }
      caraux = caraux->siguiente;
    }
    if(!encontrar && caraux == NULL){
      if(aux->articulo->tipo == 'D'){
      ArticuloDep* nuevo = new ArticuloDep(aux->articulo->nombre,aux->articulo->id,aux->articulo->precio,aux->articulo->tipo,aux->articulo->cantidad);
      }
      else if(aux->articulo->tipo == 'T'){
      ArticuloTec* nuevo = new ArticuloTec(aux->articulo->nombre,aux->articulo->id,aux->articulo->precio,aux->articulo->tipo,aux->articulo->cantidad);
      }
      else if(aux->articulo->tipo == 'E'){
      ArticuloExt* nuevo = new ArticuloExt(aux->articulo->nombre,aux->articulo->id,aux->articulo->precio,aux->articulo->tipo,aux->articulo->cantidad, aux->articulo->impuesto);
      }
      Nodo* nuevoNodo = new Nodo(nuevo);
      nuevoNodo->siguiente = carritoCompras;
      carritoCompras = nuevoNodo;
    }
    aux = aux->siguiente;
  }
  return inventario;
}

void Cliente ::control(Nodo *inventario,int id) {
  Nodo *actual = inventario;
  Nodo *aux = NULL;
  while (actual) {
    if (actual->articulo->id == id) {
      if (aux) {
        aux->siguiente = actual->siguiente;
      } else {
        inventario = actual->siguiente;
      }
      delete actual;
      std::cout << "El articulo fue eliminado correctamente" << std::endl;
    }
    aux = actual;
    actual = actual->siguiente;
  }
  std::cout << "Articulo no encontrado/No existe" << std::endl;
}

