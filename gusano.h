/*
**
**		Nombre del fichero: 	gusano.h
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye las constantes, estructuras 
**								y cabeceras relacionadas con el gusano
**
*/

#ifndef GUSANO_H
#define GUSANO_H

#include "coord.h"
#include "lib/teclas_tictac.h"

#define MAX_COORDS 64
#define INI_LONG 4

typedef struct{
  unsigned int lon;
  tcoord coord[MAX_COORDS];
  char dir;
} tgusano;

void init_gusano(tgusano *gusano, int nfil, int ncol); /*Inicializa el gusano que pasa por referencia a partir del numero de filas y columnas del tablero*/
void mover_gusano(char tecla, tgusano *gusano); /*actualiza la lista de coordenadas del gusano en función de la tecla apretada*/
void mover_cuerpo(tgusano *gusano); /*Mueve todas las coordenadas menos la cabeza*/
void actualizar_direccion(tgusano *gusano, int tecla);/*cambia, si es necesario, la dirección del gusanito*/
void mover_cabeza(tgusano *gusano); /*Mueve la cabeza segun la dirección del gusanito*/
void crecer(tgusano *gusano); /*Aumenta el tamaño del gusano en 1*/

#endif