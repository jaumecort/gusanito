/*
**
**		Nombre del fichero: 	barra.h
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye las constantes, estructuras y cabeceras 
**								relacionadas con la barra
**
*/

#ifndef BARRA_H
#define BARRA_H

#include "lib/colores.h"

#define MAX_NAME 14
#define COMER 0
#define CHOQUE 1
#define NORMAL 2

typedef struct {
	char name[MAX_NAME];
	int namelon;
	int puntos;
	int vidas;
	int segundos;
} tbarra;

void init_barra(tbarra *barra); /*Inicializa la barra con los puntos a 0 y las vidas a 1*/
void print_barra(tbarra barra, int ps); /*Imprime la barra con el nombre previamente introducido y con las variables ya inicializadas*/
void act_barra(tbarra *barra, int estado); /*Comprueba el estado del gusano y aumenta puntos en el caso de que coma una fruta o resta vida en el caso que choque*/
void suma_puntos(tbarra *barra); /*Aumenta 1 puntos cuando el gusano come una fruta*/
void get_time(int segundos, int *min, float *seg); /*Devuelve en el formato correcto los segundos totales por las variables min y seg*/

#endif