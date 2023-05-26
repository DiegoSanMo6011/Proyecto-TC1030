/*
 * Proyecto TC1030
 * Diego Gerardo Sanchez Moreno
 * A01276011
 * 
 */

/*
 * Clase Domesticas que hereda de la clase Pendientes
 */

#ifndef DOMESTICAS_H
#define DOMESTICAS_H

#include "Pendientes.h"

#include <string>
#include <sstream>

using namespace std;

class Domesticas: public Pendientes{
    // declaro atributos
    private:
    int importancia;
    string estado;
    // declaracion de los constructores y los metodos del objeto
    public:
    // cosntructor default
    Domesticas(){
        nombre = ""; tipo = ""; dia = 0;
    }
    //constructor
    Domesticas(string nom, string tip, int day, int impor, string estatus):Pendientes(nom,tip,day){
        importancia = impor; estado = estatus;
    }
    //metodos
    string get_estado();
    void set_estado(string nuevo_estado);
    int nivel_urgencia ();
    string to_string ();
};

/**
 * getter estado
 *
 * @param
 * @return string estado
*/
string Domesticas::get_estado(){
    return estado;
}

/**
 * setter estado
 *
 * @param string nuevo_estado 
 * @return 
*/
void Domesticas::set_estado(string nuevo_estado){
    estado=nuevo_estado;
}

/**
 * Calcula el nivel de urgencia del pendiente
 * 
 *
 * @param 
 * @return string con los datos de pendientes Escolares
*/
int Domesticas::nivel_urgencia(){
    int urgencia = 0;
    if (estado == "Terminado"){
        return urgencia;
    }
    else if (estado == "Con avances"){
        urgencia = importancia + 2;
        return urgencia;
    }
    else {
        urgencia = importancia + 4;
        return urgencia;
    }
}

/**
 * Almacena los valores de las variables de instancia en una cadena de
 * texto.
 *
 * @param
 * @return string con los datos de pendientes Escolares
*/
string Domesticas::to_string(){

    stringstream aux;
    aux << "\nNombre: " << nombre << "\nTipo: " << tipo << "\nDia: " << dia 
    << "\nEstado: " << estado << "\nUrgencia: " << nivel_urgencia() << "\n" ;
    return aux.str();
}

#endif //DOMESTICAS_H