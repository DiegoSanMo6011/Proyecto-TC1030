
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

using namespace std;

//funcion que imprime el menu
void menu(){
    cout<<"\nMenu: \n"<<endl;
    cout<<"1. Crea pendiente escolar.\n";
    cout<<"2. Crea pendiente domestica.\n";
    cout<<"3. Crea pendiente social.\n";
    cout<<"4. Cambia el estado del pendiente escolar.\n";
    cout<<"5. Cambia el estado del pendiente domesetico.\n";
    cout<<"6. Cambia la hora del pendiente social.\n";
    cout<<"7. Salir\n"<<endl;
}

//funcion para escoger el estado del pendiente
string estado_pend(){
    int opcion = 0;
    string estado = "";
    cout << "\n Selecciona el estado del pendiente";
    cout << "\n (1) Sin empezar \n (2) Con avances \n (3) Terminado \n";
    cin >> opcion;
    if (opcion == 1){
        estado = "Sin empezar";
        return estado;
    }
    else if (opcion == 2){
        estado = "Con avances";
        return estado;
    }
    else if (opcion == 3){
        estado = "Terminado";
        return estado;
    }
    else{
        cout << "este no es un valor aceptado";
    }
}

//funcion importante
bool importante(){
    int opcion = 0;
    bool importante = false;
    cout << "\n Selecciona si el pendiente es importante o no";
    cout << "\n (1) Si \n (2) No \n";
    cin >> opcion;
    if (opcion == 1){
        importante = true;
        return importante;
    }
    else if (opcion == 2){
        importante = false;
        return importante;
    }
    else{
        cout << "este no es un valor aceptado";
    }
}

int main (){

    int opcion = 0;
    //variables temporales
    string temp_nombre, temp_tipo, temp_materia, temp_hora, temp_estado;
    int temp_dia, temp_importancia;
    bool temp_importante;
    //creacion de un objeto de cada clase 
    Escolares escolar;
    Domesticas domestica;
    Sociales social;

 //Ciclo para que siga corriendo el codigo hasta que el ususario elija salir.
    while(opcion < 7 && opcion > -1){
       //imprimir menu
        menu();
        cin>>opcion;
        //switch que realiza metodo dependiendo de opcion
        switch(opcion){
            // caso 1 crea y muestra el pendiente escolar
            case 1:
                cout << "Dime el nombre " << endl;
                cin >> temp_nombre;
                temp_tipo = "Escolar";
                cout << "Dime el dia" << endl;
                cin >> temp_dia;
                cout << "Dime la materia";
                cin >> temp_materia;
                cout << "Dime la hora de entrega en formato 00:00"<<endl;
                cin >> temp_hora;
                temp_estado = estado_pend();

                escolar = Escolares(temp_nombre, temp_tipo, temp_dia, temp_materia, temp_hora, temp_estado);
                cout << escolar.to_string() << "\n\n";

                break;
            // caso 2 crea y muestra el pendiente domestico
            case 2:
                cout << "Dime el nombre " << endl;
                cin >> temp_nombre;
                temp_tipo = "Domestico";
                cout << "Dime el dia" << endl;
                cin >> temp_dia;
                cout << "Dime el nivel de importancia en una escala de 0 a 5";
                cin >> temp_importancia;
                temp_estado = estado_pend();

                domestica = Domesticas(temp_nombre, temp_tipo, temp_dia, temp_importancia, temp_estado);
                cout << domestica.to_string() << "\n\n";
                
                break;
            // caso 3 crea y muestra el pendiente social
            case 3:
                cout << "Dime el nombre " << endl;
                cin >> temp_nombre;
                temp_tipo = "social";
                cout << "Dime el dia" << endl;
                cin >> temp_dia;
                cout << "Dime la hora del evento en formato 00:00"<<endl;
                cin >> temp_hora;
                temp_importante = importante();

                social = Sociales(temp_nombre, temp_tipo, temp_dia, temp_hora, temp_importante);
                cout << social.to_string() << "\n\n";
                
                break;
            // caso cuatro cambia estado de un pendiente escolar
            case 4:
                temp_estado = estado_pend();
                escolar.set_estado(temp_estado);
                cout << escolar.to_string() << "\n\n";
            // caso cuatro cambia estado de un pendiente domestico
            case 5:
                temp_estado = estado_pend();
                domestica.set_estado(temp_estado);
                cout << domestica.to_string() << "\n\n";
            // caso cuatro cambia la hora de un pendiente social
            case 6:
                cout << "Ingresa la hora del pendiente en formato 00:00";
                cin >> temp_hora;
                social.set_hora(temp_hora);
                cout << social.to_string() << "\n\n";
        }
    }
return 0;
}