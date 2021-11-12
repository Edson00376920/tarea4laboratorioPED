#include "doble.hpp"
 
 ListaDoble saga;
    
    bool continuar = true;
    Datos p;
   Datos pref;

int menu(){
    int opcion = 0;
    cout << "Ingresar datos." << endl;
    p = solicitarDatos();
                saga.insertBack(p);
                cout << "Usuario regristado." << endl;
    cout << "1) Mostrar datos ingresados" << endl;
    cout <<"2) Salir"<<endl; 
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    
    do{
        switch(menu()){      
        
            case 1: 
                saga.traversalForwardDirection();
                break;
    
            case 2: 
                continuar = false;
                break;
            default: 
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
