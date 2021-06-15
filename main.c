/*
**
**		Nombre del fichero: 	main.c
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Programa principal para el juego del gusanito
**
*/

#include "juego.h"

int main()
{
	tjuego j;

	if (inicializar_juego(&j) != 0) /* acaba si el terminal no tiene unas dimensiones minimas */
		return -1;
	do {
		mostrar_juego(j);
		ejecutar_juego(&j);	
	} while (!es_fin_juego(&j));

	finalizar_juego(j);

	return 0;
}