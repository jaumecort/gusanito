/*
**
**		Nombre del fichero: 	coord.c
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye el codigo de las funciones asociadas
**								al tipo de dato coord
**
*/

#include <stdio.h>
#include "coord.h"

tcoord generate_random_coord(int filas, int columnas){
	tcoord coord;

    coord.xcol = numero_al_azar(columnas-2)+1;
    coord.yfil = numero_al_azar(filas-2)+1;
	return coord;
}