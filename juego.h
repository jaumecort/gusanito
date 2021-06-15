/*
**
**		Nombre del fichero: 	juego.h
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye las constantes, estructuras 
**								y cabeceras relacionadas con el juego
**
*/

#ifndef JUEGO_H
#define	JUEGO_H

#include "tablero.h"
#include "gusano.h"
#include "barra.h"
#include "casilla.h"
#include "lib/teclas_tictac.h"
#include "lib/azar.h"

#define SEGUNDO 1000000
#define COMER 0
#define CHOQUE 1
#define NORMAL 2

typedef struct{
	tgusano gusano;
	ttablero tablero;
	tcoord fruta;
	tbarra barra;
	char tecla;
	long unsigned int microsegundos, tictacs;
	int ps;
} tjuego;

int inicializar_juego(tjuego *juego); /*Contiene la inicializacion del juego*/
void ejecutar_juego(tjuego *juego); /*Mueve el gusano y mira si ha habido algun choque o comida de fruta*/
void mostrar_juego(tjuego juego); /*Contiene el print de la barra y del tablero*/
void print_gusano(tjuego *juego); /*Cambia las casillas del tablero donde se encuentra el gusanito y elimina la ultima*/
void print_fruta(tjuego *juego); /*Cambia las casillas del tablero donde se encuentra la fruta*/
int estado(tjuego juego); /*Evalua en funcion de la posicion de la cabeza del gusano lo que esta pasando y devuelve una constante */
int es_fin_juego(tjuego *juego); /*Evalua si debe o no terminar el juego*/
void pantalla_inicial(tjuego *juego); /*Pantalla que pregunta por el nombre, y la velocidad*/
void finalizar_juego(tjuego juego); /*Pantalla final*/
void traducir_tecla(char *tecla); /*Traduce las teclas 'a' 'z' 'o' 'p'*/

#endif