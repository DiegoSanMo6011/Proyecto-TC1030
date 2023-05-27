# Proyecto-TC1030

Proyecto de la materia TC1030 Programación Orientada a Objetos. Trata sobre una Agenda para registrar pendientes y permite buscarlos por nivel de urgencia, fecha y tipo de pendiente, genera una estructura de clases para poder manejar los tipos de pendientes. Cada tipo de pendiente tendrá su propia forma de calcular su nivel de importancia.

## Funcionalidad

El programa permite unicamente las altas de nuevos pendientes de tipo:
  
 - Escolares
 - Domesticas
 - Sociales
 
Las funciones que tendra el programa son: 

  - Mostrar los pendientes totales
  - Mostrar unicamente los pendientes del tipo elegido por el usuario.
  - Mostrar unicamente los pendientes de un dia en especifico, tambien elegido por el usuario.
  - Mostrar los 10 pendientes mas urgentes organizados por nivel de importancia, nivel que sera calculado por el mismo porgrama.
  
Consta de un menu con las opciones antes mencionadas.



## Consideraciones 

Por el momento el codigo mustra la creacion de un objeto de cada tipo.

La funcion nivel_urgencia() es solo un prototipo muy simplificado de lo que se planea sea.

El programa solo permite pendientes de tipo Escolares, Sociales y Domesticas, el usuario no puede crear otro tipo de pendientes.

Se planea que cada pendiente tendrá un día como atributo, en este dia solo se permitirá ingresar un número que esté en el rango de días que tiene el mes en el que se trabaja, es decir, en el mes de mayo solo se pueden ingresar numeros enteros entre el 1 y el 31. 



El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con: "g++ Domesticas.h Escolares.h Sociales.h Pendientes.h main.cpp"

correr en linux: "/a.out"

correr en windows: "a.exe"




