/*
Implementar un programa con un menú de opciones para manejar un sistema de citas en un
consultorio médico. Añadiremos funcionalidades adicionales, como mostrar pacientes, agregar
nuevos pacientes y atender a los pacientes en espera. También manejaremos los datos de
pacientes de manera más detallada, como con nombres y números de teléfono.
*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

struct Paciente{
    string nombre;
    string telefono;

    Paciente(){}
    Paciente(const string& nombre, const string& telefono):nombre(nombre),telefono(telefono){}

    void imprimir()const{
        cout<<"Nombre: "<<nombre<<", Telefono: "<<telefono<<endl;
    }

};

void mostrarPaciente(const Paciente& paciente){
    if(paciente.nombre.empty() && paciente.telefono.empty()){
        cout<<"No hay pacientes en espera"<<endl;
        return;
    }
    paciente.imprimir();
}

void mostrarCola(Cola<Paciente>& cola){

    Cola<Paciente> aux;
    while (!cola.esVacia())
    {
        Paciente paciente=cola.desencolar();
        mostrarPaciente(paciente);
        aux.encolar(paciente);

    }

    while(!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }
}

void agregarPaciente(Cola<Paciente>& cola){
    string nombre, telefono;
    cout<<"Ingrese el nombre del paciente: "<<endl;
    cin.ignore();
    getline(cin,nombre);
    cout<<"Ingrese el telefono del paciente: "<<endl;
    getline(cin,telefono);
    Paciente nuevoPaciente(nombre,telefono);
    cola.encolar(nuevoPaciente);
    cout<<"Paciente agregado con exito."<<endl;
}

void atenderPaciente(Cola<Paciente>& cola){
    if(cola.esVacia()){
        cout<<"No hay pacientes en espera"<<endl;
        return;
    }

    Paciente pacienteAtendido=cola.desencolar();
    cout<<"Paciente atendido: "<<endl;
    mostrarPaciente(pacienteAtendido);
}

void menu(){
    cout<<"Menu de opciones"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"1. Mostrar pacientes en espera."<<endl;
    cout<<"2. Agregar nuevo paciente."<<endl;
    cout<<"3. Atender al siguiente paciente."<<endl;
    cout<<"4. Salir."<<endl;
    cout<<"------------------------------------------------"<<endl;
}

int main(){
    Cola<Paciente> colaPacientes;
    int opc;

    do{
        menu();
        cout<<"Ingrese una opcion: "<<endl;
        cin>>opc;

        switch (opc)
        {
        case 1:
            mostrarCola(colaPacientes);
            break;
        case 2:
            agregarPaciente(colaPacientes);
            break;
        case 3:
            atenderPaciente(colaPacientes);
            break;
        case 4:
            cout<<"Saliendo del programa..."<<endl;
            break;
        default:
            cout<<"Opcion no valida. Intenelo de nuevo"<<endl;
            break;
        }
    }while(opc!=4);

}