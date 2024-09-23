/*
Diseñe un programa que sea capaz de leer dos colas y mediante un mensaje indicar si son
iguales. Nota: los elementos constitutivos de las colas son caracteres
*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

bool iguales(Cola<char>& cola1, Cola<char>& cola2){
    while(!cola1.esVacia()&&!cola2.esVacia()){
        if(cola1.peek()!=cola2.peek()){
            return false;
        }
        cola1.desencolar();
        cola2.desencolar();
    }

    return  cola1.esVacia()&&cola2.esVacia();
}

int main() {

    Cola<char> cola1,cola2;
    char caracter;

    cout<<"Ingrese los datos de la cola 1(ingrese '.' para terminar): "<<endl;
    while (cin>>caracter && caracter != '.')
    {
        cola1.encolar(caracter);
    }

    cout<<"Ingrese los datos de la cola 2(ingrese'.' para terminar): "<<endl;
    while(cin>>caracter && caracter!='.'){
        cola2.encolar(caracter);
    }

    if(iguales(cola1,cola2)){
        cout<<"Las colas son iguales"<<endl;
    }else{
        cout<<"Las colas no son iguales"<<endl;
    }
    
}
