#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

void subMenuConfiguracion();

void subMenuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
        cout<<"3) RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
        cout<<"4) RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
        cout<<"5) ESTABLECER DATOS DE INICIO      "<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: //completar
                break;
            case 2: //completar
                break;
            case 3: //completar
                break;
            case 4: //completar
                break;
            case 5: //completar
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


#endif // SUBMENUCONFIGURACION_H_INCLUDED
