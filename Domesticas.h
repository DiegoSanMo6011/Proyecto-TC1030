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
    // declaro atributos de instancia privados
    private:
        int importancia;
        string estado;
    // declaracion de los constructores y los metodos del objeto
    public:
        // cosntructor default
        Domesticas();
        //constructor
        Domesticas(string,string,int,int,string);
        //metodos
        string get_tipo();
        string get_estado();
        int get_dia();
        void set_estado(string nuevo_estado);        
        int nivel_urgencia ();
        string to_string ();
};

//constructor default 
Domesticas::Domesticas () {
    nombre = ""; 
    tipo = ""; 
    dia = 0;
}
//cosntructor
Domesticas::Domesticas (string nom, string tip, int day, int impor, string estatus): Pendientes(nom,tip,day){
    importancia = impor;
    estado = estatus;
}

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
 * getter dia
 *
 * @param
 * @return string tipo
*/
int Domesticas::get_dia(){
    return dia;
}
/**
 * getter tipo
 *
 * @param
 * @return string tipo
*/
string Domesticas::get_tipo(){
    return tipo;
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