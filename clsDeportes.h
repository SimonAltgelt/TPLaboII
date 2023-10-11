#ifndef CLSDeporte_H_INCLUDED
#define CLSDeporte_H_INCLUDED

int contarRegistros();

class Deporte{
 private:
    int ID;
    char nombre[30];
    int tipo;
    int anio;
    bool estado;
 public:
  Deporte(int _ID=0, const char* _nombre="NADA", int _tipo=0, int _anio=0){
        ID= _ID;
        strcpy(nombre, _nombre);
        tipo=_tipo;
        anio=_anio;
        estado=true;

    }

    //sets().
    void setID(int d){ID=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    bool setTipo(int t){
        if((t>=1) && (t<=21)) return true;
        else return false;
    }
    bool setAnio(int a){
        if((a>=1800) && (a<=2023)) return true;
        else return false;
    }
    void setEstado(bool e){estado=e;}

    //gets().
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    int getTipo(){return tipo;}
    int getAnio(){return anio;}
    bool getEstado(){return estado;}

    void Cargar(){
        int contador=contarRegistros();
        ID=++contador;
        cout<<"ID: "<<ID<<endl;
        cout<<"INGRESE EL NOMBRE: ";
        cin>>nombre;
        cout<<"INGRESE EL TIPO DE DEPORTE (OPCION DEL 1 AL 21): ";
        cin>>tipo;
        while(setTipo(tipo)==false){
                cout<<"  INGRESE CORRECTAMENTE EL TIPO DE DEPORTE."<<endl;
                cout<<" TIPO DE DEPORTE (OPCION DEL 1 AL 21): ";
                cin>>tipo;
            }
        cout<<"INGRESE EL ANIO DE ORIGEN (OPCION 1800 AL ACTUAL): ";
        cin>>anio;
        while(setAnio(anio)==false){
                cout<<"  INGRESE CORRECTAMENTE EL ANIO DE ORIGEN."<<endl;
                cout<<" ANIO DE ORIGEN (OPCION 1800 AL ACTUAL): ";
                cin>>anio;
            }
        estado=true;
    }


    void Mostrar(){
        if(estado==true){
            cout<<"ID: ";
            cout<<ID<<endl;
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            cout<<"TIPO DE DEPORTE (OPCION DEL 1 AL 21): ";
            cout<<tipo<<endl;
            cout<<"ANIO DE ORIGEN(OPCION 1800 AL ACTUAL): ";
            cout<<anio<<endl;
            estado=true;
            cout<<endl;
        }
    }
};


int contarRegistros(){
    FILE *p;
    p=fopen("Deportes.dat","rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,SEEK_END);
    int tam=ftell(p);
    int numRegistros=tam/sizeof(Deporte);

    // Reiniciar el contador basándose en la posición de los registros
    fseek(p,0,SEEK_SET);
    for(int i=0;i<numRegistros;i++) {
        Deporte reg;
        fread(&reg, sizeof(Deporte), 1, p);
        reg.setID(i+1);  // Asignar IDs consecutivos
        fseek(p,i * sizeof(Deporte),SEEK_SET);
        fwrite(&reg,sizeof(Deporte),1,p);
    }
    fclose(p);
return numRegistros;
}



#endif // CLSDeporte_H_INCLUDED
