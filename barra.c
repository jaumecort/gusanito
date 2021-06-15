/*
**
**		Nombre del fichero: 	barra.c
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye el codigo de las funciones asociadas a la barra
**
*/

#include <stdio.h>
#include "barra.h"
#include "lib/colores.h"

void init_barra(tbarra *barra){
	barra->puntos = 0;
	barra->vidas = 1;
	barra->segundos = 0;
}
void print_barra(tbarra barra, int ps){
	int i, min;
	float seg;

	printf_color(BOLD_GREEN);

	printf("Nombre: ");
	for(i=0; i<barra.namelon; i++){
		printf("%c", barra.name[i]);
	}
  
	printf("\tPuntos: %d\tVidas: %d", barra.puntos, barra.vidas);

	get_time(barra.segundos, &min, &seg);
	printf("\t Tiempo: %02d:%02.f", min, seg);

	printf_reset_color();
}
void act_barra(tbarra *barra, int estado){
	if (estado == CHOQUE) barra->vidas--;
 	if (estado == COMER) suma_puntos(barra);
} 
void suma_puntos(tbarra *barra){
	barra->puntos = barra->puntos +1;
}
void get_time(int segundos, int *min, float *seg){
	*min = segundos/60;
	*seg = segundos - 60 * *min;
}