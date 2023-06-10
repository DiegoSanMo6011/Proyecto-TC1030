
/*
 * Proyecto TC1030
 * Diego Gerardo Sanchez Moreno
 * A01276011
 * 
 */

/**
 * En este main se demustra la creacion de objetos de cada tipo y lo que hace cada uno
 */
//bibliotecas
#include <iostream>
#include <string>

#include "Domesticas.h"
#include "Escolares.h"
#include "Sociales.h"
#include "Agenda.h"

using namespace std;

//funcion que imprime el menu
void menu(){
    cout<<"\nMenu: \n"<<endl;
    cout<<"1. Crea pendientes escolares.\n";
    cout<<"2. Crea pendientes domesticos.\n";
    cout<<"3. Crea pendientes sociales.\n";
    cout<<"4. Muestra pendientes.\n";
    cout<<"5. Muestra pendientes por tipo.\n";
    cout<<"6. Muestra pendientes por dia.\n";
    cout<<"7. Muestra 10 pendientes mas urgentes.\n";
    cout<<"8. Salir\n"<<endl;
}

//funcion para escoger el estado del pendiente
string estado_pend(){
    int opcion = 0;
    int ban = 1;
    string estado = "";
    while (ban == 1){
        cout << "\n Selecciona el estado del pendiente";
        cout << "\n (1) Sin empezar \n (2) Con avances \n (3) Terminado \n";
        cin >> opcion;
        if (opcion == 1){
            estado = "Sin empezar";
            ban = 0;
            return estado;
        }
        else if (opcion == 2){
            estado = "Con avances";
            ban = 0;
            return estado;
        }
        else if (opcion == 3){
            estado = "Terminado";
            ban = 0;
            return estado;
        }
        else{
            cout << "este no es un valor aceptado";
            ban = 1;
        }
    }
    return estado;
}

//funcion para escoger el tipo del pendiente
string tipo_pend(){
    int opcion = 0;
    int ban = 1;
    string tipo = "";
    while (ban == 1){
        cout << "\n Selecciona el tipo de pendientes a bsucar";
        cout << "\n (1) Escolares \n (2) Domesticas \n (3) Sociales \n";
        cin >> opcion;
        if (opcion == 1){
            tipo = "Escolar";
            ban = 0;
            return tipo;
        }
        else if (opcion == 2){
            tipo = "Domestico";
            ban = 0;
            return tipo;
        }
        else if (opcion == 3){
            tipo = "Social";
            ban = 0;
            return tipo;
        }
        else{
            cout << "este no es un valor aceptado";
            ban = 1;
        }
    }
    return tipo;
}

//funcion importante
bool importante(){
    int opcion = 0;
    bool importante = false;
    int ban = 1;
    while (ban == 1){
        cout << "\n Selecciona si el pendiente es importante o no";
        cout << "\n (1) Si \n (2) No \n";
        cin >> opcion;
        if (opcion == 1){
            importante = true;
            ban = 0;
            return importante;
        }
        else if (opcion == 2){
            importante = false;
            ban = 0;
            return importante;
        }
        else{
            cout << "este no es un valor aceptado";
            ban = 1;
        }
    }
    return importante;
}

int main (){

    int opcion = 0;
    //variables temporales
    char temp_nombre[100]="";
    char temp_materia[100]="";
    string  temp_tipo, temp_hora, temp_estado;
    int temp_dia, temp_importancia;
    bool temp_importante;

    //creacion de un objeto de cada clase 
    Agenda agenda;
    agenda.crea_ejemplos();
    agenda.muestra_pend();

 //Ciclo para que siga corriendo el codigo hasta que el ususario elija salir.
    while(opcion < 8 && opcion > -1){
       //imprimir menu
        menu();
        cin >> opcion;
        //switch que realiza metodo dependiendo de opcion
        switch(opcion){
            // caso 1 crea pendientes escolar
            case 1:
                cout << "Dime el nombre " << endl;
                cin.ignore();
                cin.getline(temp_nombre,100);
                temp_tipo = "Escolar";
                cout << "Dime el dia " << endl;
                cin >> temp_dia;
                cout << "Dime la materia " << endl;
                cin.ignore();
                cin.getline(temp_materia,100);
                cout << "Dime la hora de entrega en formato 00:00 "<<endl;
                cin >> temp_hora;
                temp_estado = estado_pend();

                agenda.agrega_escolares(temp_nombre,temp_tipo,temp_dia,temp_materia,temp_hora,temp_estado);

                break;
            // caso 2 crea pendientex domesticas
            case 2:
                cout << "Dime el nombre " << endl;
                cin.ignore();
                cin.getline(temp_nombre,100);
                temp_tipo = "Domestico";
                cout << "Dime el dia" << endl;
                cin >> temp_dia;
                cout << "Dime el nivel de importancia en una escala de 0 a 5" << endl; 
                cin >> temp_importancia;
                temp_estado = estado_pend();

                agenda.agrega_domesticas(temp_nombre,temp_tipo,temp_dia,temp_importancia,temp_estado);
                
                break;
            // caso 3 crea y muestra el pendiente social
            case 3:
                cout << "Dime el nombre " << endl;
                cin.ignore();
                cin.getline(temp_nombre,100);
                temp_tipo = "Social";
                cout << "Dime el dia" << endl;
                cin >> temp_dia;
                cout << "Dime la hora del evento en formato 00:00"<<endl;
                cin >> temp_hora;
                temp_importante = importante();

                agenda.agrega_sociales(temp_nombre, temp_tipo, temp_dia, temp_hora, temp_importante);
                
                break;
            // caso 4 muestra pendientes
            case 4:
                agenda.muestra_pend();
                break;
            // caso 5 muestra pendientes por tipo
            case 5:
                temp_tipo = tipo_pend();
                agenda.muestra_pend(temp_tipo);
                break;
            // caso 6 muestra pendientes por dia
            case 6:
                cout << ("Ingresa el dia del que quieres saber los pendientes");
                cin >> temp_dia;
                agenda.muestra_pend(temp_dia);
                break;
            case 7:
                agenda.muestra_pend_urge();
                break;
        }
    }
return 0;
}