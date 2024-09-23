/*
Crear una función que reciba una cola por referencia y un número. Dicha función debe: Eliminar
todas las ocurrencias de dicho número, menos la primera. Si dicho número no se repite, deja la
cola como esta. Si dicho número no está en la cola, debe anunciar un mensaje de error. Imprimir
la cola al final para verificar si hubo o no modificaciones.
*/


#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void eliminarOcurrencias(Cola<int>& cola, int numero) {
    Cola<int> aux;
    bool encontrado = false;
    int cont = 0;

    while (!cola.esVacia()) {
        int elemento = cola.desencolar();
        if (elemento == numero) {
            if (!encontrado) {
                encontrado = true;
                aux.encolar(elemento);
            } else {
                cont++;
            }
        } else {
            aux.encolar(elemento);
        }
    }

    if (!encontrado) {
        cout << "Error: el número " << numero << " no está en la cola." << endl;
    } else {
        cout << "Se eliminaron " << cont << " ocurrencias del numero " << numero << "." << endl;
    }

    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }

    cout << "Cola resultante: ";
    while (!cola.esVacia()) {
        int elemento = cola.desencolar();
        cout << elemento << " ";
        aux.encolar(elemento);
    }
    cout << endl;

    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
}

int main() {
    Cola<int> cola;
    int numero;

    cout << "Ingrese los datos de la cola (ingrese '-1' para terminar): " << endl;
    int n;
    while (cin >> n && n != -1) {
        cola.encolar(n);
    }

    cout << "Ingrese el numero a eliminar: " << endl;
    cin >> numero;

    eliminarOcurrencias(cola, numero);
}   