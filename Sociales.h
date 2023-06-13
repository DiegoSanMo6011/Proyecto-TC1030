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