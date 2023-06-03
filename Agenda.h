/*
 *
 * Proyecto "Agenda de pendientes" calse Agenda
 * Diego Gerardo Sanchez Moreno
 * A01276011
 * 01/06/2023
 * version : 1
 * Esta clase define objeto de tipo Agenda que contiene todas las operaciones para 
 * agregar nuevos pendientes,
 */

#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include <iostream>
#include <sstream>

//bibliotecas con los objetos a usar
#include "Pendientes.h"
#include "Domesticas.h"
#include "Sociales.h"
#include "Escolares.h"

using namespace std;

const int MAX = 200; // valor constante para el tamano de los arreglos

//definicion de la clase
class Agenda {
    //Declaro las variables privadas de instancia
    private:
        Pendientes * pend[MAX]; // se define como apuntador para utilizar polimorfismo
        int cont;
    //Declaro constructor por default y metodos publicos
    public:

        Agenda (): cont(0) {}; // constructor default

        void crea_ejemplos();
        void muestra_pend();
        void muestra_pend(string tipo);
        void muestra_pend(int dia);
        void muestra_pend_urge();
        void agrega_escolares(string nom, string tip, int day, string mate, string hora, string estatus);
        void agrega_sociales(string nom, string tip, int day, string hor, bool impor);
        void agrega_domesticas(string nom, string tip, int day, int impor, string estatus);
};

/**
 * crea_ejemplos genera objetos en pend[]
 *
 * genera objetos de tipo Escolares, Domesticas y Sociales y los
 * guarda en la varibale de instancia en pend[] (arreglo de pendientes)
 * para poder hacer pruebas. No usar esta función si se va a usar el programa
 * como agenda, ya que los datos son falsos.
 *
 * @param
 * @return
 */
void Agenda::crea_ejemplos(){
    //la funcion new crea el objeto en tiempo de ejecucion para usar polimorfismo
    pend[cont] = new Sociales("Comida con familia", "Social", 3, "2:30 pm", false);
    cont++;
    pend[cont] = new Sociales("Tarde de Minecraft", "Social", 4, "7:30 pm", true);
    cont++;
    pend[cont] = new Domesticas("Lavar ropa", "Domestica", 6, 9, "Sin empezar");
    cont++;
    pend[cont] = new Domesticas("Comprar bolsas", "Domestica", 3, 7, "Terminado");
    cont++;
    pend[cont] = new Escolares("Avance proyecto 3", "Escolar", 2, "POO", "11:59", "Con avances");
    cont++;
    pend[cont] = new Escolares("Tarea 2", "Escolar", 8, "Estadistica", "11:59", "Sin empezar");
    cont++;

}

/**
 * muestra_pend imprime los pendientes guardados
 *
 * utiliza el arreglo pend[] y el orden de registro, para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método to_string().
 *
 * @param
 * @return
 */
void Agenda::muestra_pend(){
    //ciclo que recorre el arreglo 
    for(int i = 0; i < cont ; i++){
        cout << pend[i] -> to_string();
    }
}

/**
 * muestra_pend imprime los pendientes guardados
 *
 * utiliza el arreglo pend[] y el tipo de pendiente, para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método to_string().
 *
 * @param
 * @return
 */
void Agenda::muestra_pend(string tipo){
    // ciclo que recorre el arreglo
    for (int i = 0; i < cont; i++) {
    if (pend[i] -> get_tipo() == tipo){
            cout << pend[i] -> to_string();
        }
    }
}

/**
 * muestra_pend imprime los pendientes guardados
 *
 * utiliza el arreglo pend[] y el dia del pendiente, para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método to_string().
 *
 * @param
 * @return
 */
void Agenda::muestra_pend(int dia){
    // ciclo que recorre el arreglo
    for (int i = 0; i < cont; i++) {
        if (pend[i] -> get_dia() == dia){
            cout << pend[i] -> to_string();
        }
    }
}

/**
 * muestra_pend_urge imprime los 10 pendientes con mayor nivel de urgenia
 *
 * utiliza el arreglo pend[] y el nivel de urgencia, para recorrer todo el
 * arreglo lee los 10 con mayor nivel de urgencia e imprime cada uno de los objetos con su método to_string().
 *
 * @param
 * @return
 */
void Agenda::muestra_pend_urge(){
    Pendientes *mas_urgentes[10];
    for (int i = 0; i < 5; i++) {
        mas_urgentes[i] = nullptr;
    }

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (pend[i] -> nivel_urgencia() > mas_urgentes[j] -> nivel_urgencia()){
                for (int k = 9; k > j; k--) {
                    mas_urgentes[k] = mas_urgentes[k - 1];
                }
                // Insertar el nuevo mayor en la posición correspondiente
                 mas_urgentes[j] = pend[i];
            }
        }
    }
    //ciclo que recorre el arreglo e imprime sus componentes 
    for(int i=0; i < cont ; i++){
        if (mas_urgentes[i] != nullptr){
        cout << mas_urgentes[i] -> to_string();
        }
    }
}

/**
 * agrega_escolares crea un objeto Escolares y lo agrega a
 * arreglo de pendients
 *
 * crea un objeto Escolares y lo agrega a arreglo de pendients usando como
 * index un contador que incrementa en 1.
 *
 * @param string nom, string tip, int day, string mate, string hora, string estatus
 * @return
 */
void Agenda::agrega_escolares(string nom, string tip, int day, string mate, string hora, string estatus) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  pend[cont] = new Escolares(nom, tip, day, mate, hora, estatus);
  cont++;
}

/**
 * agrega_sociales crea un objeto Sociales y lo agrega a
 * arreglo de pendientes
 *
 * crea un objeto Sociales y lo agrega a arreglo de pendientes usando como
 * index un contador que incrementa en 1.
 *
 * @param string nom, string tip, int day, string hor, bool impor;
 * @return
 */
void Agenda::agrega_sociales(string nom, string tip, int day, string hor, bool impor) {
  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  pend[cont] = new Sociales(nom, tip, day, hor, impor);
  cont++;
}

/**
 * agrega_domesticas crea un objeto Domesticas y lo agrega a
 * arreglo de pendientes
 *
 * crea un objeto Domesticas y lo agrega a arreglo de pendientes usando como
 * index un contador que incrementa en 1.
 *
 * @param string nom, string tip, int day, int impor, string estatus
 * @return
 */
void Agenda::agrega_domesticas(string nom, string tip, int day, int impor, string estatus) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  pend[cont] = new Domesticas(nom, tip, day, impor, estatus);
  cont++;
}

#endif //AGENDA_H