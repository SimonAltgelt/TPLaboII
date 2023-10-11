#ifndef SUBMENUDEPORTES_H_INCLUDED
#define SUBMENUDEPORTES_H_INCLUDED

#include "clsDeportes.h"
#include "ArchivoDeportes.h"
#include "subMenuDeportes.h"

void subMenuDeportes();
void agregarRegistroDeporte();
void listarDeportesXID();
void listarTodo();
void modificarAnioOrigen();
bool eliminarRegistroDeporte();


void subMenuDeportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU DEPORTES"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1) AGREGAR DEPORTE"<<endl;
        cout<<"2) LISTAR DEPORTE POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR ANIO DE ORIGEN"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroDeporte();
                break;
            case 2: listarDeportesXID();
                break;
            case 3: listarTodo();
                break;
            case 4: modificarAnioOrigen();
                break;
            case 5: eliminarRegistroDeporte();
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

void agregarRegistroDeporte(){
    /*
    FILE *p;
    p=fopen("Deportes.dat","wb");
    fclose(p);
    */
    Deporte reg;
    ArchivoDeporte archi("Deportes.dat");
    reg.Cargar();
    bool agregar=archi.agregarRegistro(reg);
    if(agregar==true){
        cout<<"REGISTRO AGREGADO.";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO."<<endl;
    }
}


void listarDeportesXID(){
    int ID;
    cout<<"INGRESE EL ID DEL DEPORTE QUE DESEA BUSCAR: ";
    cin>>ID;

    ArchivoDeporte archi("Deportes.dat");
    int pos=archi.buscarRegistro(ID);

    if(pos==-1){
        cout << "NO SE ENCONTRO UN DEPORTE CON ESE ID." << endl;
    }
    else{
        Deporte reg=archi.leerRegistro(pos);
        reg.Mostrar();
    }
}


void listarTodo(){
    ArchivoDeporte archi("Deportes.dat");
    archi.listarRegistros();
}


void modificarAnioOrigen(){
    int ID;
    int nuevoAnio;
    cout<<"INGRESE EL ID DEL DEPORTE CUYO ANIO DESEA MODIFICAR :";
    cin>>ID;
    ArchivoDeporte archi("Deportes.dat");
    int pos=archi.buscarRegistro(ID);
    if(pos==-1){
        cout << "NO SE ENCONTRO UN DEPORTE CON ESE ID."<<endl;
    }
    else{
        Deporte reg=archi.leerRegistro(pos);
        cout<<"INGRESE EL NUEVO ANIO DE INSCRIPCION: ";
        cin>>nuevoAnio;
        reg.setAnio(nuevoAnio);
        if(archi.modificarRegistro(pos, reg)){
            cout<<"ANIO MODIFICADO EXITOSAMENTE."<<endl;
        }
        else{
            cout<<"ERROR AL MODIFICAR EL ANIO."<<endl;
        }
    }
}


bool eliminarRegistroDeporte(){
    ArchivoDeporte archi("Deportes.dat");
    int id;
    int pos;
    cout<<"INGRESE EL ID A BORRAR: ";
    cin>>id;

    pos=archi.buscarRegistro(id);

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
    Deporte reg=archi.leerRegistro(pos);
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

#endif // SUBMENUDEPORTES_H_INCLUDED
