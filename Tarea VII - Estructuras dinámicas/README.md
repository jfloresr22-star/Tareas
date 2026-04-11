## Descripción
El programa permite la clasificación automatica de los datos por medio
de diferentes estructuras dinámicas, segun el tipo de numero ingresado.
Números pares	 	= 	Cola
Números impares	 	=	Pila
Números negativos 	=	Lista enlazada

## Funcionamiento 

El usuario debe ingresar números desde el menu y dependiendo del valor
del dato ingresado se clasifica automaticamente de la siguiente forma:

1. Si es par se guarda en una cola
2. Si es impar se guarda en una pila
3. Si es negativo se guarda en una lista idependientemente que se par o impar

Ademas la lista de números negativos se ordena antes de mostrarse.


## Opciones del programa

1. Ingresar número
2. Mostrar pila
3. Mostrar cola
4. Mostrar lista
5. Eliminar de pila
6. Eliminar de cola
7. Salir

La primera opción del programa nos permite ingresar un dato por ejemplo:
2, 5, -3, 8, 7
Al selecionar la segunda opción nos despliega:
Pila 7 -> 5
Al selecionar la tercera opción nos despliega:
Cola 2 -> 8
La cuarta opcion nos despliega:
-3

## Ejecutar el programa
g++ Estructuras_dinamicas.cpp -o Estructuras_dinamicas
Estructuras_dinamicas.exe

## Autor
Josue David Flores Roldan