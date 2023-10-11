#ifndef SUBMENUJUGADORES_H_INCLUDED
#define SUBMENUJUGADORES_H_INCLUDED

#include "clsJugador.h"
#include "ArchivoJugador.h"
#include "subMenuJugadores.h"

void submenuJugadores();
void agregarRegistroJugador();
void listarJugadores();
void listarJugadorXDNI();
void modificarFechaInscripcion();
bool eliminarRegistroJugador();

void subMenuJugadores(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU JUGADORES "<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1) AGREGAR JUGADOR"<<endl;
        cout<<"2) LISTAR JUGADOR POR DNI" <<endl;
        cout<<"3) LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<endl;
        cout<<"5) ELIMINAR REGISTRO DE JUGADOR"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:agregarRegistroJugador();
                break;
            case 2:listarJugadorXDNI();
                break;
            case 3:listarJugadores();
                break;
            case 4: modificarFechaInscripcion();
                break;
            case 5: eliminarRegistroJugador();
                break;
            case 0:return;
                break;
            default:cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        cout<<endl;
        system("pause");
    }
}


void agregarRegistroJugador(){
    Jugador reg;
    ArchivoJugador archi("Jugadores.dat");
    int DNI;
    cout<<"INGRESE EL DNI:";
    cin>>DNI;
    int pos=archi.buscarRegistro(DNI);
    if(pos==-1){
        reg.Cargar(DNI);
        bool agregar=archi.agregarRegistro(reg);
        if(agregar==true){
            cout << "REGISTRO AGREGADO.";
        }
        else{
            cout<<"NO SE PUDO AGREGAR EL REGISTRO."<<endl;
        }
    }
    else{
        cout<<"YA EXISTE UN REGISTRO CON ESE DNI" <<endl;
    }
}


void listarJugadorXDNI(){
    int DNI;
    cout<<"INGRESE EL DNI DEL JUGADOR QUE DESEA BUSCAR: ";
    cin>>DNI;

    ArchivoJugador archi("Jugadores.dat");
    int pos = archi.buscarRegistro(DNI);

    if(pos==-1){
        cout << "NO SE ENCONTRO UN JUGADOR CON ESE DNI." << endl;
    }
    else{
        Jugador reg = archi.leerRegistro(pos);
        reg.Mostrar();
    }
}


void listarJugadores(){
    ArchivoJugador archi("Jugadores.dat");
    archi.listarRegistros();
}


void modificarFechaInscripcion(){
    int DNI;
    cout<<"INGRESE EL DNI DEL JUGADOR CUYA FECHA DE INSCRPCION DESEA MODIFICAR :";
    cin>>DNI;
    ArchivoJugador archi("Jugadores.dat");
    int pos=archi.buscarRegistro(DNI);
    if(pos==-1){
        cout << "NO SE ENCONTRO UN JUGADOR CON ESE DNI."<<endl;
    }
    else{
        Jugador reg = archi.leerRegistro(pos);
        Fecha nuevaFecha;
        cout<<"INGRESE LA NUEVA FECHA DE INSCRIPCION: ";
        nuevaFecha.Cargar();
        reg.setfechaInscripcion(nuevaFecha);
        if(archi.modificarRegistro(pos, reg)){
            cout<<"FECHA DE INSCRIPCION MODIFICADA EXITOSAMENTE."<<endl;
        }
        else{
            cout<<"ERROR AL MODIFICAR LA FECHA DE INSCRIPCION."<<endl;
        }
    }
}


bool eliminarRegistroJugador(){
    ArchivoJugador archi("Jugadores.dat");
    int dni;
    int pos;
    cout<<"INGRESE EL DNI A BORRAR: ";
    cin>>dni;

    pos=archi.buscarRegistro(dni); //buscarRegistro(int ) devuelve la pos del registro en el archivo.

    if(pos==-1){
        cout<<"NO EXISTE EL REGISTRO CON ESE CODIGO"<<endl;
        return false;
    }
    else{
        if(pos==-2){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
    }
    Jugador reg=archi.leerRegistro(pos);
        reg.Mostrar();
        reg.setEstado(false);
        bool quePaso=archi.modificarRegistro(pos,reg);
        if(quePaso==true){
            cout<<"REGISTRO BORRADO"<<endl;
        }
        else{
            cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
        }
    cout<<endl;
    return true;
}


#endif // SUBMENUJUGADORES_H_INCLUDED
