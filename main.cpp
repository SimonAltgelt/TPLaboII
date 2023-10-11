#include<iostream>
#include <cstring>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;

#include "ArchivoDeportes.h"
#include "ArchivoJugador.h"
#include "clsDeportes.h"
#include "clsJugador.h"
#include "fecha.h"
#include "funcionesGlobales.h"
#include "reportes.h"
#include "subMenuConfiguracion.h"
#include "subMenuDeportes.h"
#include "subMenuJugadores.h"

int main(){
    int opc;
    while(true){
    system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) MENU JUGADORES "<<endl;
        cout<<"2) MENU DEPORTES"<<endl;
        cout<<"3) REPORTES"<<endl;
        cout<<"4) CONFIGURACION"<<endl;
        cout<<"--------------"<<endl;
        cout<<"0) SALIR  "<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");

        switch(opc){
            case 1: subMenuJugadores();
            break;
            case 2: subMenuDeportes();
            break;
            case 3: //reportes();
            break;
            case 4: subMenuConfiguracion();
            break;
            case 0: return 0;
            break;

            default: cout<<"OPCION INCORRECTA. INGRESAR OPCION NUEVAMENTE ";
            break;
        }
    cout<<endl;
    system("pause");
    }
 return 0;
}
