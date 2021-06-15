/*
**
**		Nombre del fichero: 	tablero.c
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye el codigo de las funciones asociadas al tablero
**
*/

#include <stdio.h>
#include "tablero.h"

void init_tablero(ttablero *tablero){
	int i, j;

	for(i=0; i<tablero->nfil; i++){
		for(j=0; j<tablero->ncol; j++){
			init_casilla(&tablero->casilla[i][j], CASILLA_VALOR_VACIA, CASILLA_COLOR_VACIA);
		}
	}
}

void paredes_tablero(ttablero *tablero){
	int i;

	for(i=0; i<tablero->ncol; i++){
		init_casilla(&tablero->casilla[0][i], CASILLA_VALOR_PARED, CASILLA_COLOR_PARED);
		init_casilla(&tablero->casilla[tablero->nfil-1][i], CASILLA_VALOR_PARED, CASILLA_COLOR_PARED);
	}
	for(i=0; i<tablero->nfil; i++){
		init_casilla(&tablero->casilla[i][0], CASILLA_VALOR_PARED, CASILLA_COLOR_PARED);
		init_casilla(&tablero->casilla[i][tablero->ncol-1], CASILLA_VALOR_PARED, CASILLA_COLOR_PARED);
	}
}
void print_tablero(ttablero tablero){
	int i, j;

	for(i=0; i<tablero.nfil; i++){
        for(j=0; j<tablero.ncol; j++){
			print_casilla(tablero.casilla[i][j]);
		}
		printf("\n");
	}
	printf_reset_color();
}

int ajustar_tablero(ttablero *tablero){
	int filas_terminal, columnas_terminal;
  
	obtener_tamanyo_terminal(&filas_terminal, &columnas_terminal);

	if(filas_terminal<MAXF-1){
		tablero->nfil = filas_terminal -2;
	} else {
		tablero->nfil = MAXF;
	}
	if(columnas_terminal<MAXC){
		tablero->ncol = columnas_terminal;
	} else {
		tablero->ncol = MAXC;
	}

	if (tablero->nfil < MINF){
    	printf ("*** ERROR: El numero de filas del terminal es %d y debe ser minimo %d\n", tablero->nfil, MINF);
    	return -1;
  	}
	else if (tablero->ncol < MINC){
 	  	printf ("*** ERROR: El numero de columnas es %d y debe ser mínimo %d\n", tablero->ncol, MINC);
		return -1;
  	} 
	else {
		return 0;
	}
}