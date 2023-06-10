# Proyecto-TC1030

Proyecto de la materia TC1030 Programación Orientada a Objetos. Trata sobre una Agenda para registrar pendientes y permite buscarlos por nivel de urgencia, fecha y tipo de pendiente, genera una estructura de clases para poder manejar los tipos de pendientes. Cada tipo de pendiente tendrá su propia forma de calcular su nivel de importancia.

## Funcionalidad

El programa permite únicamente las altas de nuevos pendientes de tipo:
  
 - Escolares
 - Domesticas
 - Sociales
 
Las funciones que tendra el programa son: 

  - Mostrar los pendientes totales
  - Mostrar únicamente los pendientes del tipo elegido por el usuario.
  - Mostrar únicamente los pendientes de un día en especifico, también elegido por el usuario.
  - Mostrar los 10 pendientes más urgentes organizados por nivel de importancia, nivel que será calculado por el mismo porgrama.
  
Consta de un menú con las opciones antes mencionadas.



## Consideraciones 


La función nivel_urgencia() es sólo un prototipo muy simplificado de lo que se planea sea.

El programa solo permite pendientes de tipo Escolares, Sociales y Domesticas, el usuario no puede crear otro tipo de pendientes.

Es importante ingresar el tipo de dato de cada atributo que se pide, los tipos de datos están especificados en el uml.

El programa sólo corre en la consola y está hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con: "g++ Domesticas.h Escolares.h Sociales.h Pendientes.h Agenda.h main.cpp"

correr en linux: "/a.out"

correr en windows: "a.exe"

## Correciones

Se corrigieron aquellos errores del código que en entregas anteriores evitaban que el código compilara.

Se corrigió la gramatica del readme.





