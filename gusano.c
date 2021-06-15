/*
**
**		Nombre del fichero: 	gusano.c
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye el codigo de las funciones asociadas al gusano
**
*/

#include <stdio.h>
#include "gusano.h"

void init_gusano(tgusano *gusano, int nfil, int ncol){
	int i;

	gusano->lon = INI_LONG;
	gusano->dir = 'E';
	for(i=0; i<gusano->lon; i++){
		gusano->coord[i].yfil = nfil/2-1;
		gusano->coord[i].xcol = (ncol/2)-i;
	}
}
void mover_gusano(char tecla, tgusano *gusano){
	mover_cuerpo(gusano);
	actualizar_direccion(gusano, tecla);
	mover_cabeza(gusano);
}
void mover_cabeza(tgusano *gusano){
	switch(gusano->dir){
		case 'S':
			gusano->coord[0].yfil = gusano->coord[1].yfil+1;
			gusano->coord[0].xcol = gusano->coord[1].xcol;
			break;
		case 'N':
			gusano->coord[0].yfil = gusano->coord[1].yfil-1;
			gusano->coord[0].xcol = gusano->coord[1].xcol;
			break;
		case 'E':
			gusano->coord[0].yfil = gusano->coord[1].yfil;
			gusano->coord[0].xcol = gusano->coord[1].xcol+1;
			break;
		case 'W':
			gusano->coord[0].yfil = gusano->coord[1].yfil;
			gusano->coord[0].xcol = gusano->coord[1].xcol-1;
			break;
	}
}
void actualizar_direccion(tgusano *gusano, int tecla){
	if (tecla == UP1 && gusano->dir != 'S') gusano->dir = 'N';
	else if (tecla == DOWN1 && gusano->dir != 'N') gusano->dir = 'S';
	else if (tecla == LEFT1 && gusano->dir != 'E') gusano->dir = 'W';
	else if (tecla == RIGHT1 && gusano->dir != 'W') gusano->dir = 'E';
}
void mover_cuerpo(tgusano *gusano){
	int i;

	for (i=gusano->lon; i>0; i--){
		gusano->coord[i].yfil = gusano->coord[i-1].yfil;
		gusano->coord[i].xcol = gusano->coord[i-1].xcol;
	}
}
void crecer(tgusano *gusano){
	gusano->lon++;
}