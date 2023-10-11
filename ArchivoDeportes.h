#ifndef ARCHIVODeporte_H_INCLUDED
#define ARCHIVODeporte_H_INCLUDED

#include "clsDeportes.h"

class ArchivoDeporte{
 private:
    char nombre[30];
 public:
    ArchivoDeporte(const char *nombreArchivo){strcpy(nombre, nombreArchivo);}
    const char *getNombre() {return nombre;}
    bool listarRegistros();
    bool agregarRegistro(Deporte);
    int buscarRegistro(int ID);
    bool buscarRegistroBool(int ID);
    Deporte leerRegistro(int pos);
    bool modificarRegistro(int pos, Deporte reg);
    int contarRegistros();
};


bool ArchivoDeporte::listarRegistros(){
    Deporte reg;
    FILE *p=fopen(nombre,"rb");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    while(fread(&reg, sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
return true;
}


bool ArchivoDeporte::agregarRegistro(Deporte reg){
    FILE *p=fopen(nombre,"ab");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
return escribio;
}

int ArchivoDeporte::buscarRegistro(int ID){
    Deporte reg;
    FILE *p=fopen(nombre,"rb");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int cont=0;
    while(fread(&reg, sizeof reg,1,p)==1){
        if(reg.getID() == (ID)){
            fclose(p);
            return cont ;
        }
         cont++;
    }
    fclose(p);
return -1;
}


bool ArchivoDeporte::buscarRegistroBool(int ID){
    Deporte reg;
    FILE *p=fopen(nombre,"rb");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    while(fread(&reg, sizeof reg,1,p)==1){
        if(reg.getEstado()==true){
            if(reg.getID()==(ID)){
                fclose(p);
                return true;
            }
        }
    }
    fclose(p);
return false;
}


Deporte ArchivoDeporte::leerRegistro(int pos){
    Deporte reg;
    reg.setEstado(false);
    FILE *p=fopen(nombre,"rb"); // aca va el ROOT.
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }

    fseek(p,sizeof(Deporte)*pos,0);
    fread(&reg, sizeof reg, 1,p);
    fclose(p);
    return reg;

    reg.setEstado(false);

return reg;
}


bool ArchivoDeporte::modificarRegistro(int pos, Deporte reg){
    FILE *p=fopen(nombre,"rb+"); // Agrega al modo lo que le falta.
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof(Deporte)*pos,0);
    bool escribio = fwrite(&reg, sizeof reg, 1,p);

    fclose(p);
return escribio;
}

int ArchivoDeporte::contarRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int tam=ftell(p);

    fclose(p);
return tam/sizeof(Deporte);
}

#endif // ARCHIVODeporte_H_INCLUDED
