#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

bool esFechaValida(int dia, int mes, int anio);

class Fecha{
private:
    int dia, mes, anio;
public:

    void Cargar();
    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }
    ///sets()
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    ///gets()
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

};
void Fecha::Cargar() {
    bool entra;
    /// Pide el día
    entra=true;
    while (entra){
        cout<<endl<<"INGRESE EL DIA: ";
        cin>>dia;
        if (dia<=31 && dia>=1){
            entra=false;
        }
        else{
            cout<<"------------------------------------------------"<<endl;
            cout<<"EL DÍA INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
        }
    }
    /// Pide el mes
    entra=true;
    while (entra==true){
        cout<<"INGRESE EL MES: ";
        cin>>mes;
        if (mes>=1 && mes<=12){
            entra=false;
        }else{
            cout<<"------------------------------------------------"<<endl;
            cout<<"EL MES INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
        }
    }
    /// Pide el año
    entra=true;
    while(entra){
        cout<<"INGRESE EL AÑO: ";
        cin>>anio;
        if(anio>=1000){
            entra=false;
        }else{
            cout<<"------------------------------------------------"<<endl;
            cout<<"EL AÑO INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
        }
    }
    /// Verifica si la fecha es válida
    if(!esFechaValida(dia, mes, anio)) {
        cout<<"LA FECHA INGRESADA NO ES VALIDA. INTENTE NUEVAMENTE."<<endl;
        cout<<endl;
        Cargar(); /// Se llama a la función de nuevo para que el usuario ingrese una fecha válida
    }
}

bool esFechaValida(int dia, int mes, int anio) {
    /// Obtiene la fecha actual
    time_t now = time(0);
    tm *f = localtime(&now);
    /// Verifica si la fecha es anterior o igual a la fecha actual
    if (anio > f->tm_year + 1900 || (anio==f->tm_year + 1900 && mes > f->tm_mon + 1) || (anio == f->tm_year + 1900 && mes == f->tm_mon + 1 && dia > f->tm_mday)) {
        cout<<"------------------------------"<<endl;
        cout<<"LA FECHA DEBE SER ANTERIOR O IGUAL A LA FECHA ACTUAL." << endl;
        cout<<"FECHA ACTUAL:" << f->tm_mday << "/" << f->tm_mon + 1 << "/" << f->tm_year + 1900<<endl;
        return false;
    }
    return true;
}


#endif // FECHA_H_INCLUDED
