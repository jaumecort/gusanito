/*
**
**		Nombre del fichero: 	tablero.h
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye las constantes, estructuras 
**								y cabeceras relacionadas con el tablero
**
*/

#ifndef TABLERO_H
#define	TABLERO_H

#include "casilla.h"
#include "lib/tamanyo_terminal.h"

#define MAXC 300
#define MAXF 100
#define MINC 64
#define MINF 20
#define MAX_COORDS 64

typedef struct{
	tcasilla casilla[MAXF][MAXC];
	int nfil;
	int ncol;
} ttablero;

void init_tablero(ttablero *tablero); /*Inicializa el tablero con todas las casillas vacias */
void paredes_tablero(ttablero *tablero);/*Introduce las paredes en el tablero*/
void print_tablero(ttablero tablero); /*Imprime todas las casillas */
int ajustar_tablero(ttablero *tablero); /*Cambia el tamaño del tablero al de la terminal*/

#endif