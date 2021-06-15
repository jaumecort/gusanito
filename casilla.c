/*
**
**		Nombre del fichero: 	casilla.c
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye el codigo de las funciones asociadas a la casilla
**
*/

#include <stdio.h>
#include "casilla.h"

void init_casilla(tcasilla *casilla, char valor, char color){
	casilla->valor = valor;
	casilla->color = color;
}
void print_casilla(tcasilla casilla){
	printf_color(casilla.color);
	printf("%c", casilla.valor);
}