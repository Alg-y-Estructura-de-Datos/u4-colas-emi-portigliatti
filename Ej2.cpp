/*
Implementar una función que suprima de la cola todos los elementos mayores que un número
“n” dado como límite. Al final se debe imprimir la cola depurada sin perder el orden que había
desde la cola original.
*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void suprimir(Cola<int>& cola, int limite){
    Cola<int>aux;

    while(!cola.esVacia()){
        int dato=cola.desencolar();
        if(dato<=limite){
            aux.encolar(dato);
        }
    }

    while(!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }
}

int main() {

    Cola<int>cola;
    int limite;

    cout<<"Ingrese los datos de la cola(ingrese '-1' para terminar): "<<endl;
    int n;
    while(cin>>n && n!=-1){
        cola.encolar(n);
    }

    cout<<"Ingrese el numero limite: "<<endl;
    cin>>limite;
    
    suprimir(cola,limite);

    cout<<"Cola luego de la operacion: "<<endl;
    while (!cola.esVacia())
    {
        cout<<cola.desencolar()<<" ";   
    }
    cout<<endl;

}
