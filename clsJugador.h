#ifndef CLSJUGADOR_H_INCLUDED
#define CLSJUGADOR_H_INCLUDED

#include "fecha.h"

class Jugador{
 private:
    int DNI;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int nroClaustro;
    int nroDeporte;
    int nroEquipo;
    Fecha fechaInscripcion;
    float matricula;
    bool estado;
 public:
  Jugador(int _DNI=0, const char* _nombre="NADA", const char* _apellido="NADA",
            const char* _email="NADA", const char* _telefono="NADA",
            int _claustro=0, int _deporte=0, int _nroEquipo=0,
            Fecha _fechaInscripcion=Fecha(), float _matricula=0){

        DNI=_DNI;
        strcpy(nombre,_nombre);
        strcpy(apellido,_apellido);
        strcpy(email,_email);
        strcpy(telefono,_telefono);
        nroClaustro=_claustro;
        nroDeporte=_deporte;
        nroEquipo=_nroEquipo;
        fechaInscripcion=_fechaInscripcion;
        matricula=_matricula;
        estado=true;
    }

    //sets().
    void setDNI(int d){DNI=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido,a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    bool setClaustro(int c){
        if(c>=1 && c<=4) return true;
        else return false;
    }
    bool setDeporte(int d){
        if(d>=1 && d<=10) return true;
        else return false;
    }
    void setEquipo(int e){nroEquipo=e;}
    void setfechaInscripcion(Fecha f){fechaInscripcion=f;}
    void setMatricula(float m){matricula=m;}
    void setEstado(bool e){estado=e;}

    //gets().
    int getDNI(){return DNI;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    const char *getTelefono(){return telefono;}
    int getClaustro(){return nroClaustro;}
    int getDeporte(){return nroDeporte;}
    int getEquipo(){return nroEquipo;}
    Fecha getfechaInscripcion(){return fechaInscripcion;}
    float getMatricula(){return estado;}
    bool getEstado(){return estado;}

    void Cargar(int _DNI=0){
        if(_DNI == 0){
        cout<<"INGRESE EL DNI: ";
        cin>>DNI;
        }
        else{
            DNI=_DNI;
        }
        cout<<"INGRESE EL NOMBRE: ";
        cin>>nombre;
        cout<<"INGRESE EL APELLIDO: ";
        cin>>apellido;
        cout<<"INGRESE EL EMAIL: ";
        cin>>email;
        cout<<"INGRESE EL TELEFONO: ";
        cin>>telefono;
        cout<<"INGRESE EL NRO DE CLAUSTRO(OPCION DEL 1 AL 4): ";
        cin>>nroClaustro;
        while(setClaustro(nroClaustro)==false){
            cout<<" INGRESE CORRECTAMENTE EL NRO DE CLAUSTRO."<<endl;
            cout<<"NRO DE CLAUSTRO (OPCION DEL 1 AL 4): ";
            cin>>nroClaustro;
        }

        cout<<"INGRESE EL NRO DE DEPORTE (OPCION DE 1 AL 10): ";
        cin>>nroDeporte;
        while(setDeporte(nroDeporte)==false){
            cout<<" INGRESE CORRECTAMENTE EL NRO DE CLAUSTRO."<<endl;
            cout<<"NRO DE DEPORTE (OCPCION DEL 1 AL 10: ";
            cin>>nroDeporte;
        }
        ArchivoDeporte archi("Deportes.dat");
        bool validar=true;
        while(validar==true){
            if(archi.buscarRegistroBool(nroDeporte)){
                setDeporte(nroDeporte);
                validar=false;
            }
            else{
                cout<<"NUMERO DE ID INVALIDO"<<endl;
                cout<<" INGRESE NUEVAMENTE EL NRO DE DEPORTE: ";
                cin>>nroDeporte;
            }
        }

        cout<<"INGRESE EL NRO DE EQUIPO: ";
        cin>>nroEquipo;
        cout<<"INGRESE LA FECHA DE INSCRIPCION: "<<endl;
        fechaInscripcion.Cargar();
        cout<<"INGRESE EL NRO DE MATRICULA: ";
        cin>>matricula;
        estado = true;
    }

    void Mostrar(){
        if(estado==true){
            cout<<"DOCUMENTO: ";
            cout<<DNI<<endl;
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            cout<<"APELLIDO: ";
            cout<<apellido<<endl;
            cout<<"EMAIL: ";
            cout<<email<<endl;
            cout<<"TELEFONO: ";
            cout<<telefono<<endl;
            cout<<"NRO DE CLAUSTRO: ";
            cout<<nroClaustro<<endl;
            cout<<"NRO DE DEPORTE: ";
            cout<<nroDeporte<<"\t"<<endl;
            ArchivoDeporte archi("Deportes.dat");
            if(archi.buscarRegistroBool(nroDeporte)==false){
                cout<<" EL DEPORTE FUE DADO DE BAJA"<<endl;
            }
            cout<<"NRO DE EQUIPO ";
            cout<<nroEquipo<<endl;
            cout<<"FECHA DE INSCRIPCION ";
            fechaInscripcion.Mostrar();
            cout<<"MATRICULA: ";
            cout<<matricula;
            cout<<endl;
        }
    }
};


#endif // CLSJUGADOR_H_INCLUDED
