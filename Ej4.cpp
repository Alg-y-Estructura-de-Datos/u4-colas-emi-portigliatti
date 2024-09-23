/*
Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
números en una cola, pedir también un numero entero "n". Luego crear una función que
recibiendo una cola y un número entero “n”, si el "n" se encuentra en una de las posiciones de
la cola. Devuelva la suma de los elementos de la cola hasta llegar a "n" (sin incluir a n). Si el
número "n" no se encuentra en la cola, la función devuelve la suma de todos los elementos de
la cola. Imprimir primero la cola antes de la suma de sus elementos.
*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

int sumarNro(Cola<int>& cola, int n){
    Cola<int> aux;
    int suma=0;
    bool encontrado=false;

    while (!cola.esVacia())
    {
        int valor=cola.desencolar();
        if(valor==n){
            encontrado=true;
            aux.encolar(valor);
            break;
        }else{
            suma+=valor;
            aux.encolar(valor);
        }
    }

    while(!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }

    if(!encontrado){
        int sumaTotal=0;
        while(!cola.esVacia()){
            sumaTotal+=cola.desencolar();
        }
        while(!aux.esVacia()){
            cola.encolar(aux.desencolar());
        }
        return sumaTotal;
    }

    return suma;
    
}

void mostrarCola(Cola<int>& cola){
    Cola<int> aux;

    while(!cola.esVacia()){
        int dato=cola.desencolar();
        cout<<dato<<" ";
        aux.encolar(dato);
    }
    cout<<endl;

    while (!aux.esVacia())
    {
        cola.encolar(aux.desencolar());
    }
    
}

int main(){

    Cola<int> cola;
    int n;

    cout<<"Ingrese los datos de la cola(ingrese '-1' para terminar): "<<endl;
    int dato;

    while(cin>>dato && dato!=-1){
        cola.encolar(dato);
    }

    cout<<"Ingrese el numero limite: "<<endl;
    cin>>n;

    cout<<"Cola original: "<<endl;
    mostrarCola(cola);

    int suma=sumarNro(cola,n);

    cout<<"La suma de los elementos hasta llegar a "<<n<<" es: "<<suma<<endl;

}