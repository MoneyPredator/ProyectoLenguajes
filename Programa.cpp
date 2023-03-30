#include <iostream>
#include <cstdlib>
#include "Programa.h"

void Programa::Bienvenida(){
    std::cout<<"--Bienvenido a EAFIT-Zone--"<<std::endl;
    std::cout<<"--¿Quien eres?:\nIngresa 1 para identificarte como coordinador.--\nIngresa 2 para identificarte como Cliente--"<<std::endl;
    std::cin>>Usuario;
    bool exit = false;
    do{
        switch(Usuario){
            case 1:{
                std::string nombre;
                char op;
                std::cout<<"Ingrese su nombre:";
                std::cin>>nombre;
                menuCoordinador(nombre);
              std::cout<<"Seguro que desea salir? (s/n):"; std::cin>>op;
              if(op == 's'){
                exit = true;
              }
              break;
            }
            case 2:{
                std::string nombre;
                char op;
                std::cout<<"Ingrese su nombre:";
                std::cin>>nombre;
                menuCliente(nombre);
              std::cout<<"Seguro que desea salir? (s/n):"; std::cin>>op;
              if(op == 's'){
                exit = true;
              }
              break;
            }
            default:
              std::cout<<"Opción No valida, canson"<<std::endl;
          break;
        }
    }while(!exit);
}

void Programa::menuCoordinador(std::string nombre){
    Coordinador c(nombre);
    int opcion;
    bool emergencia = false;
    do{
    std::cout<<"--Menu de opciones de "<<nombre<< "--\n1.Agregar Articulo \n2.Modificar Articulo \n3.Eliminar Articulo\n4.ver inventario \n5.Salir\nIngresas: "; std::cin>>opcion;
        switch(opcion){
            case 1:{
              bool exit = false;
              int tetha;
              do{
                cout>>
                inventario = c.addArticulo(inventario);
                std::cout<<"Desea añadir otro articulo? \n1.Para si.\n2.Para no.\nIngresas: "; std::cin>>tetha;
              }while(tetha != 2);
                std::cout<<"\nSaliendo...";
              break;
            }
            case 2:{
                int id;
                std::cout << "Ingresa el Id del articulo que deseas modificar: ";
                std::cin >> id;
                c.modArticulo(inventario, id);
                int opcion;
                std::cout<<"Desea regresar al menu de opciones?\n1.Si\n2.No";
                std::cin>>opcion;
                if(opcion == 1){
                    menuCoordinador(nombre);
                }
              else if(opcion == 2){
                std::cout<<"\nSaliendo...";
                emergencia = true;
              }
              break;
            }
            case 3:{
                int id;
                std::cout << "Ingresa el Id del articulo que deseas eliminar: ";
                std::cin >> id;
                c.delArticulo(inventario, id);
                int opcion;
                std::cout<<"Desea regresar al menu de opciones?\n1.Si\n2.No";
                std::cin>>opcion;
                if(opcion == 1){
                    menuCoordinador(nombre);
                }
              else if(opcion == 2){
                std::cout<<"\nSaliendo";
                emergencia = true;
              }
              break;
            }
            case 4:{
               c.verLista(inventario);
              int opcion;
              std::cout<<"Deseas regresar al menu de opciones?\n1.Si\n2.No\nIngresas: "; std::cin>>opcion;
              if(opcion == 1){
                menuCoordinador(nombre);
              }
              else if(opcion == 2){
                std::cout<<"\nSaliendo...";
                emergencia = true;
              }
              break;
            }
            case 5:{
              std::cout<<"\nSaliendo...";
              emergencia = true;
              break;
            }
            default:
              std::cout<<"Opción No valida, canson"<<std::endl;
          break;
        }
   }while(!emergencia);
      }

void Programa::menuCliente(std::string nombre){
    Cliente a(nombre);
    int opcion;
    std::cout<<"--Menu de opciones--\n1.Agregar articulo al carrito \n2.Pagar\n3.ver carritoCompras \n4.Salir"<<std::endl;
    std::cin>>opcion;
        while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4){
        switch(Usuario){
            case 1:{
                a.comprar(inventario);
                int opcion;
                std::cout<<"Desea regresar al menu de opciones?\n1.Si\n2.No";
                std::cin>>opcion;
                if(opcion == 1){
                    menuCliente(nombre);
                }
            }
            case 2:{
                a.pagar(inventario);
            }
            case 3:{
                a.verLista(inventario);
            }
            case 4:{
                Bienvenida();
            }
            default:
              std::cout<<"Opción No valida, canson"<<std::endl;
        }
        std::cout << "Favor ingrese un valor valido: ";
        std::cin >> Usuario;
    }
}

void Programa::cerrar(int salida){
  if(salida < 1 || salida > 3){
  std::cout<<"Vuelva pronto!"<<std::endl;
  exit(0);
}
}