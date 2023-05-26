/*
 * Proyecto TC1030
 * Diego Gerardo Sanchez Moreno
 * A01276011
 * 
 */

/*
 * Clase Escolares que hereda de la clase Pendientes
 */

#ifndef ESCOLARES_H
#define ESCOLARES_H

#include "Pendientes.h"

#include <string>
#include <sstream>

using namespace std;

class Escolares: public Pendientes{
    // declaro atributos
    private:
    string materia;
    string hora_entrega;
    string estado;
    // declaracion de los constructores y los metodos del objeto
    public:
    // cosntructor default
    Escolares(){
        nombre = ""; tipo = ""; dia = 0;
    }
    //constructor
    Escolares(string nom, string tip, int day, string mate, string hora, string estatus):Pendientes(nom,tip,day){
        materia = mate; hora_entrega = hora; estado = estatus;
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
string Escolares::get_estado(){
    return estado;
}

/**
 * setter estado
 *
 * @param string nuevo_estado 
 * @return 
*/
void Escolares::set_estado(string nuevo_estado){
    estado=nuevo_estado;
}

/**
 * Calcula el nivel de urgencia del pendiente
 * 
 *
 * @param 
 * @return string con los datos de pendientes Escolares
*/
int Escolares::nivel_urgencia(){
    int urgencia = 0;
    if (estado == "Terminado"){
        return urgencia;
    }
    else if (estado == "Con avances"){
        urgencia = 5;
        return urgencia;
    }
    else {
        urgencia = 10;
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
string Escolares::to_string(){

    stringstream aux;
    aux << "\nNombre: " << nombre << "\nTipo: " << tipo << "\nDia: " << dia 
    << "\nMateria: " << materia << "\nHora de entrega: " << hora_entrega <<
    "\nEstado: " << estado << "\nUrgenica " << nivel_urgencia() << "\n" ;
    return aux.str();
}

#endif //ESCOLARES_H