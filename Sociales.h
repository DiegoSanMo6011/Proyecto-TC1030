/*
 * Proyecto TC1030
 * Diego Gerardo Sanchez Moreno
 * A01276011
 * 
 */

/*
 * Clase Sociales que hereda de Pedientes
 */

#ifndef SOCIALES_H
#define SOCIALES_H

#include "Pendientes.h"

#include <string>
#include <sstream>

using namespace std;

class Sociales: public Pendientes{
    // declaro atributos privados de instancia
        private:
        string hora;
        bool importante;
    // declaracion de los constructores y los metodos del objeto
    public:
        // cosntructor default
        Sociales();
        //constructor
        Sociales(string nom, string tip, int day, string hor, bool impor);
        //metodos
        string get_hora();
        string get_tipo();
        int get_dia();
        void set_hora(string nueva_hora);
        int nivel_urgencia ();
        string to_string ();
};
//constructor default
Sociales::Sociales () {
    nombre = ""; 
    tipo = ""; 
    dia = 0;
}
//cosntructor
Sociales::Sociales (string nom, string tip, int day, string hor, bool impor): Pendientes(nom,tip,day){
    hora = hor;
    importante = impor;
}
/**
 * getter hora
 *
 * @param
 * @return string hora
*/
string Sociales::get_hora(){
    return hora;
}

/**
 * getter tipo
 *
 * @param
 * @return string tipo
*/
string Sociales::get_tipo(){
    return tipo;
}

/**
 * getter dia
 *
 * @param
 * @return string tipo
*/
int Sociales::get_dia(){
    return dia;
}

/**
 * setter hora
 *
 * @param string nueva_hora
 * @return 
*/
void Sociales::set_hora(string nueva_hora){
    hora = nueva_hora;
}

/**
 * Calcula el nivel de urgencia del pendiente
 * 
 *
 * @param 
 * @return string con los datos de pendientes Escolares
*/
int Sociales::nivel_urgencia(){
    int urgencia = 0;
    if (importante == false){
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
string Sociales::to_string(){

    stringstream aux;
    aux << "\nNombre: " << nombre << "\nTipo: " << tipo << "\nDia: " << dia 
    << "\nHora: " << hora << "\nUrgencia: " << nivel_urgencia() << "\n" ;
    return aux.str();
}

#endif //SOCIALES_H