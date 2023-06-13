/*
 * Proyecto TC1030
 * Diego Gerardo Sanchez Moreno
 * A01276011
 * 
 */

/*
 * Clase Pendientes contiene los datos genericos de todos los tipos de pendientes,
 * tiene tres clases hijas que son los tipos de pendientes:
 * Escolares, Domesticas y Sociales
 *
 */

#ifndef PENDIENTES_H
#define PENDIENTES_H

#include <string>
#include <sstream>

using namespace std;

// definicion de la clase pendientes que es abstracta
class Pendientes{
    //declaro atributos
    protected:
        string nombre;
        string tipo;
        int dia;
    //declaracion del constructores y los metodos del objeto
    public:
        //constructor default
        Pendientes();
        //contructor 
        Pendientes(string nom, string tip, int day);
        //metodos
        virtual string to_string() = 0;
        virtual int nivel_urgencia() = 0;
        string get_tipo();
        int get_dia();
};
//cosntructor default
Pendientes::Pendientes () {
    nombre = ""; 
    tipo = ""; 
    dia = 0;
}
//contructor
Pendientes::Pendientes (string nom, string tip, int day){
    nombre=nom;
    tipo=tip;
    dia=day;

}

/**
 * getter tipo
 *
 * @param
 * @return string tipo
*/
string Pendientes::get_tipo(){
    return tipo;
}

/**
 * getter dia
 *
 * @param
 * @return string tipo
*/
int Pendientes::get_dia(){
    return dia;
}
#endif //PENDIENTES_H