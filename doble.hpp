#include <iostream>
#include <string>
using namespace std;


struct Datos{
    string nombre;
    string perfil; 
    int id;
};

Datos solicitarDatos(void){
    Datos p;
    cout << "Nombre de usuario: ";
    getline(cin, p.nombre);
    cout << "ID del usuario: ";
    cin >> p.id; cin.ignore();
     cout << "Perfil de usuario ";
    getline(cin, p.perfil);
    return p;
}

void mostrarDatos(Datos p){
    cout << "Datos: " << p.nombre;
    cout << " (" << p.id << ")." << endl;
    cout << p.perfil<<endl;
}

typedef Datos T;
const T noValido = {"","",0};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble();
    
        void insertBack(T);
        void traversalForwardDirection(void);
        bool empty(void);
       
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}


void ListaDoble::insertBack(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
    
}

void ListaDoble::traversalForwardDirection(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarDatos(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

bool ListaDoble::empty(void){
    return pInicio == NULL;
}
