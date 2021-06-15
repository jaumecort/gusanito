/*
**
**		Nombre del fichero: 	casilla.h
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye las constantes, estructuras y cabeceras 
**								relacionadas con la casilla
**
*/

#ifndef CASILLA_H
#define	CASILLA_H

#include "lib/colores.h"

#define CASILLA_VALOR_VACIA     ' '
#define CASILLA_VALOR_PARED     '#'
#define CASILLA_VALOR_GUSANO    '@'
#define CASILLA_VALOR_FRUTA     '$'
#define CASILLA_VALOR_CHOQUE    'X'
#define CASILLA_COLOR_VACIA     WHITE
#define CASILLA_COLOR_PARED     WHITE
#define CASILLA_COLOR_GUSANO    BOLD_GREEN
#define CASILLA_COLOR_FRUTA     BOLD_RED
#define CASILLA_COLOR_CHOQUE    BOLD_YELLOW
#define CASILLA_COLOR_TEXTO     BOLD_GREEN

typedef struct{
	char valor;
	int color;
} tcasilla;

void init_casilla(tcasilla *casilla, char valor, char color); /*Establece a la casilla el tipo, valor y color iniciales*/
void print_casilla(tcasilla casilla); /*Imprime una casilla*/

#endif