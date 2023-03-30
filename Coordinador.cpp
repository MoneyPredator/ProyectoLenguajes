#include "Coordinador.h"
#include <iostream>

// Ez
Coordinador::Coordinador(std::string _nombre) : Usuario(_nombre) {
  this->nombre = _nombre;
}

Nodo *Coordinador::addArticulo(Nodo *inventario ) {
  std::string nombre;
  int id;
  float precio;
  int cantidad;
  bool salida = true;
  int otro;
  char tipo;
  while (salida) {
    std::cout << "Ingrese el nombre: ";
    std::cin >> nombre;
    std::cout << "Ingrese el id: ";
    std::cin >> id;
    //std::cout << "antes  ";
    //id = comprobarid(inventario, id);
    //std::cout << "paso  ";
    std::cout << "Ingrese el precio: ";
    std::cin >> precio;
    std::cout << "Ingrese la cantidad: ";
    std::cin >> cantidad;
    cantidad = comprobarcan(cantidad);
    std::cout << "De que tipo desea que sea su articulo?\nIngrese 1 para "
                 "deportivo\nIngrese 2 para tecnologico\nIngrese 3 para extranjero\nTipo: ";
    int opcional;
    std::cin >> opcional;
    //while (opcional == 1 || opcional == 2 || opcional == 3) {
      switch (opcional) {
      case 1: {
        tipo = 'D';
        ArticuloDep *nuevo = new ArticuloDep(nombre, id, precio, tipo, cantidad);
        Nodo *punto = new Nodo(nuevo);
        
        if (inventario == NULL) {
          return punto;
        }
        Nodo *aux = inventario;
        while (aux->siguiente) {
          aux = aux->siguiente;
        }
        aux->siguiente = punto;
        return inventario;
      }

      case 2: {
        tipo = 'T';
        ArticuloTec *nuevo =  new ArticuloTec(nombre, id, precio, tipo, cantidad);
        Nodo *punto = new Nodo(nuevo);
        if (!inventario) {
          return punto;
        }
        Nodo *aux = inventario;
        while (aux->siguiente) {
          aux = aux->siguiente;
        }
        aux->siguiente = punto;
        return inventario;
      }
      case 3: {
        int impuesto;
        std::cout<<"De cuanto sera el impuesto?: "; std::cin>>impuesto;
        tipo = 'E';
        ArticuloExt *nuevo = new ArticuloExt(nombre, id, precio, tipo, cantidad, impuesto);
        Nodo *punto = new Nodo(nuevo);
        if (!inventario) {
          return punto;
        }
        Nodo *aux = inventario;
        while (aux->siguiente) {
          aux = aux->siguiente;
        }
        aux->siguiente = punto;
        return inventario;
      }
      default:
        std::cout << "Opcion NO valida,canson" << std::endl;
      }
      std::cout << "Favor ingrese un valor valido: ";
      std::cin >> opcional;
  }
}

/*int Coordinador::comprobarid(Nodo *inventario, int id) {
  int x = id;
  Nodo *aux = inventario;
  if(aux == NULL){
    return x;
  }
  while (aux) {
    if (aux->articulo.id == x){
      std::cout<<"Id existente, ingrese otro: "; std::cin>>x;
        return comprobarid(inventario,x);
    }
    aux = aux->siguiente;
  }
  return x;
}*/

int Coordinador::comprobarcan(int cantidad) {
  int x = cantidad;
    if(x <= 0){
      std::cout<<"Esta cantidad no es posible, ingrese otra: "; std::cin>>x;
        return comprobarcan(x);
  }
  return x;
}

Nodo *Coordinador::modArticulo(Nodo *inventario, int id) {
  while (inventario) {
    if (inventario->articulo->id == id) {
      int opcion;
      std::cout << "Que desea modificar de este articulo?" << std::endl;
      std::cout << "1. Nombre" << std::endl;
      std::cout << "2. Id" << std::endl;
      std::cout << "3. Precio" << std::endl;
      std::cout << "4. Cantidad" << std::endl;
      std::cin >> opcion;

      switch (opcion) {
      case 1:
        std::cout << "Ingrese el nuevo nombre: ";
        std::cin >> inventario->articulo->nombre;
        std::cout << "Nombre cambiado correctamente." << std::endl;
        return inventario;
        break;
      case 2:
        std::cout << "Ingrese una nueva Id: ";
        std::cin >> inventario->articulo->id;
        /*inventario->articulo->id = comprobarid(inventario, inventario->articulo->id);*/
        std::cout << "Id cambiada correctamente." << std::endl;
        return inventario;
        break;
      case 3:
        std::cout << "Ingrese el nuevo Precio: ";
        std::cin >> inventario->articulo->precio;
        std::cout << "Precio cambiado correctamente." << std::endl;
        return inventario;
        break;
      case 4:
        std::cout << "Ingrese la nueva cantidad: ";
        std::cin >> inventario->articulo->cantidad;
        inventario->articulo->cantidad = comprobarcan(inventario->articulo->cantidad);
        std::cout << "Cantidad cambiada correctamente." << std::endl;
        return inventario;
        break;

      default:
        std::cout << "Opcion no valida" << std::endl;
        return inventario;
      }
    }
    inventario = inventario->siguiente;
  }
  std::cout << "El articulo no se encuentra en la lista o el Id no es correcta."
            << std::endl;
  return inventario;
}

Nodo *Coordinador::delArticulo(Nodo *inventario, int id) {
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
      return inventario;
    }
    aux = actual;
    actual = actual->siguiente;
  }
  std::cout << "Articulo no encontrado/No existe" << std::endl;
  return inventario;
}