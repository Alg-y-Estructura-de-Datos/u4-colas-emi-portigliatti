/*
Implementar una función que reciba una cola de números enteros y una pila entera vacía, y
separe los elementos de la cola de tal manera que los elementos pares de la cola permanezcan
en la cola, y los elementos impares formen parte de la pila.
Observaciones:
● Al insertar los elementos en la pila, deberán aparecer en orden inverso a como estaban
en la cola: el elemento de la posición 1 de la cola estará al fondo de la pila, el de la
posición 3 será el segundo desde el fondo, etc.
● Si la cola estuviera vacía mostrar mensaje de error.
*/

#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"
using namespace std;

void separar(Cola<int>& cola, Pila<int>& pila){
    if(cola.esVacia()){
        cout<<"La cola esta vacia"<<endl;
        return;
    }
    Cola<int> aux;
    while(!cola.esVacia()){
        int dato=cola.desencolar();
        if(dato%2==0){
            aux.encolar(dato);
        }else{
            pila.push(dato);
        }
    }

    while(!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }
}

void mostrarCola(Cola<int>& cola){
    Cola<int> aux;

    while(!cola.esVacia()){
        int dato=cola.desencolar();
        cout<<dato<<" ";
        aux.encolar(dato);
    }

    cout<<endl;

    while(!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }

}


int main(){
    Cola<int> cola;
    Pila<int> pila;

    cout<<"Ingrese los numeros de la cola(ingrese -1 para terminar): "<<endl;
    int numero;
    while (cin>>numero && numero!=-1)
    {
        cola.encolar(numero);
    }

    separar(cola,pila);

    cout<<"Cola despues de quitar numeros impares: "<<endl;
    mostrarCola(cola);

    cout<<"Pila con los numeros impares en orden inverso: "<<endl;
    while(!pila.esVacia()){
        cout<<pila.pop()<<" ";
    }

    cout<<endl;
    
}
