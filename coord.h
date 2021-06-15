/*
**
**		Nombre del fichero: 	coord.h
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye las constantes, estructuras y cabeceras 
**								relacionadas con las coords
**
*/

#ifndef coord_H
#define	coord_H

#include "lib/azar.h" 

typedef struct{
  unsigned yfil, xcol;
} tcoord;

tcoord generate_random_coord(int filas, int columnas); /*Devuelve unas coordenadas aleatorias*/

#endif