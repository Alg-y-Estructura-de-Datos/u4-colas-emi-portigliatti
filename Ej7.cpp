/*
Imagina una oficina con varias impresoras compartidas por varios empleados. Cada vez que un
empleado envía un documento para imprimir, este se coloca en una cola de impresión. Las
impresoras trabajan de manera que el primer documento enviado es el primero en ser impreso.
Si una impresora está ocupada, el documento queda en espera en la cola hasta que la impresora
esté disponible.
Implementar un sistema de gestión de colas de impresión en el que se:
 Agreguen documentos a la cola de impresión.
 Se impriman documentos en el orden en que fueron enviados.
 Se pueda mostrar el estado de la cola de impresión y los documentos pendientes.
*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

struct Documento{
    string nombre;
    int pag;

    Documento(const string& nombre="", int pag=0):nombre(nombre),pag(pag){}
    void mostrar()const{
        cout<<"Documento: "<<nombre<<", Paginas: "<<pag<<endl;
    }
};

void mostrarCola(Cola<Documento>& cola){
    Cola<Documento> aux;
    cout<<"El estado actual de la cola de impresion: "<<endl;
    while(!cola.esVacia()){
        Documento doc=cola.desencolar();
        doc.mostrar();
        aux.encolar(doc);
    }

    while(!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }
}

void agregarDocumento(Cola<Documento>& cola){
    string nombre;
    int pag;
    cout<<"Ingrese el nombre del documento: "<<endl;
    cin.ignore();
    getline(cin,nombre);
    cout<<"Ingrese el numero de paginas: "<<endl;
    cin>>pag;

    Documento nuevoDocumento(nombre,pag);
    cola.encolar(nuevoDocumento);
    cout<<"Documento agregado a la cola de impresion con exito."<<endl;
}

void imprimirDocumento(Cola<Documento>& cola){
    if(!cola.esVacia()){
        cout<<"No hay documentos en la cola de impresion."<<endl;
        return;
    }

    Documento documentoImpreso=cola.desencolar();
    cout<<"Imprimiendo: ";
    documentoImpreso.mostrar();
}

void menu(){
    cout<<"Menu de opciones"<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"1. Mostrar cola de impresion."<<endl;
    cout<<"2. Agregar nuevo documento a la cola."<<endl;
    cout<<"3. Imprimir el siguiente documento."<<endl;
    cout<<"4. Salir del programa."<<endl;
    cout<<"----------------------------------------------"<<endl;
}

int main(){
    Cola<Documento> colaimpresion;
    int opc;

    do
    {
        cout<<"Ingrese una opcion: "<<endl;
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            mostrarCola(colaimpresion);
            break;
        case 2:
            agregarDocumento(colaimpresion);
            break;
        case 3:
            imprimirDocumento(colaimpresion);
            break;
        case 4:
            cout<<"Saliendo del programa..."<<endl;
            break;
        default:
            cout<<"Opcion invalida. Vuelva a elegir una opcion."<<endl;
            break;
        }
    } while (opc!=4);
    

}