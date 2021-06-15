/*
**
**		Nombre del fichero: 	juego.c
**		Autores:				Victor Montiel, Abel Coll y Jaume Cortés
**		Fecha: 					21/11/2020
**
**		Descripción:			Incluye el codigo de las funciones asociadas al juego
**
*/

#include <stdio.h>
#include "juego.h"

int inicializar_juego(tjuego *juego){
	pantalla_inicial(juego);
	inicializar_azar();
	init_tictac();		

	if (ajustar_tablero(&juego->tablero)==-1){
		return -1;
	}
 
	juego->tictacs = 0;

	init_tablero(&juego->tablero);
	paredes_tablero(&juego->tablero);

	init_barra(&juego->barra);

	init_gusano(&juego->gusano, juego->tablero.nfil, juego->tablero.ncol);
	juego->fruta = generate_random_coord(juego->tablero.nfil, juego->tablero.ncol);

	print_gusano(juego);
	print_fruta(juego);
	return 0;
}
void ejecutar_juego(tjuego *juego){
	int teclado = lee_tecla_o_tictac(juego->microsegundos);

	juego->tecla=NOTHING;
	while(teclado!=TIC_TAC){
		if(teclado!=NOTHING){
			juego->tecla=teclado;
		}
		teclado = lee_tecla_o_tictac(juego->microsegundos);
	}

	juego->tictacs++;
	juego->barra.segundos = juego->tictacs / juego->ps;

	traducir_tecla(&juego->tecla);
	mover_gusano(juego->tecla, &juego->gusano);
	print_gusano(juego);

	if (estado(*juego) == COMER){
		crecer(&juego->gusano);
		suma_puntos(&juego->barra);
		juego->fruta = generate_random_coord(juego->tablero.nfil, juego->tablero.ncol);
		print_fruta(juego);
	}

	act_barra(&juego->barra, estado(*juego));	
}
int estado(tjuego juego){
	int estado = NORMAL;
	int i;

	//COMER
	for(i=0; i<juego.gusano.lon; i++){
		if ((juego.gusano.coord[i].xcol == juego.fruta.xcol) && 
			(juego.gusano.coord[i].yfil == juego.fruta.yfil)){
			estado = COMER;
		}
	}
	//CHOQUE
	if (juego.tablero.casilla[juego.gusano.coord[0].yfil][juego.gusano.coord[0].xcol].valor == CASILLA_VALOR_PARED){
		estado = CHOQUE;
	} 
	//CHOQUE CON GUSANO	
	for(i=1; i<juego.gusano.lon; i++){
		if((juego.gusano.coord[0].yfil == juego.gusano.coord[i].yfil) && (juego.gusano.coord[0].xcol == juego.gusano.coord[i].xcol)){
			estado = CHOQUE;
		}
	}
	return estado;
}
void mostrar_juego(tjuego juego){
	borrar_pantalla();
	print_barra(juego.barra, juego.ps);
	printf("\n");
	print_tablero(juego.tablero);
}
void print_gusano(tjuego *juego){
	int i;
	//Cuerpo
	for(i=1; i<juego->gusano.lon; i++){
		init_casilla(&juego->tablero.casilla[juego->gusano.coord[i].yfil][juego->gusano.coord[i].xcol], CASILLA_VALOR_GUSANO, CASILLA_COLOR_GUSANO);
	}
	init_casilla(&juego->tablero.casilla[juego->gusano.coord[juego->gusano.lon].yfil][juego->gusano.coord[juego->gusano.lon].xcol], CASILLA_VALOR_VACIA, CASILLA_COLOR_VACIA);
	//Cabeza
	if(estado(*juego)==CHOQUE){
		init_casilla(&juego->tablero.casilla[juego->gusano.coord[1].yfil][juego->gusano.coord[1].xcol], CASILLA_VALOR_CHOQUE, CASILLA_COLOR_CHOQUE);
		init_casilla(&juego->tablero.casilla[juego->gusano.coord[juego->gusano.lon].yfil][juego->gusano.coord[juego->gusano.lon].xcol], CASILLA_VALOR_GUSANO, CASILLA_COLOR_GUSANO);
	} else {
		init_casilla(&juego->tablero.casilla[juego->gusano.coord[0].yfil][juego->gusano.coord[0].xcol], CASILLA_VALOR_GUSANO, CASILLA_COLOR_GUSANO);
	}
}
void print_fruta(tjuego *juego){
	init_casilla(&juego->tablero.casilla[juego->fruta.yfil][juego->fruta.xcol], CASILLA_VALOR_FRUTA, CASILLA_COLOR_FRUTA);
}
void pantalla_inicial(tjuego *juego){
	int i=-1;

	borrar_pantalla();

  	printf ("FO - Bienvenido al Proyecto Gusanito!\n\nAutores del proyecto: Abel Coll / Jaume Cortés / Víctor Montiel\nProfesora del proyecto: Beatriz Otero\n\nEl jugador puede controlar el movimiento del gusanito y el juego con las teclas:\n\t- Flecha arriba (o tecla 'a')\n\t- Flecha abajo (o tecla 'z')\n\t- Flecha izquierda (o tecla 'o')\n\t- Flecha derecha (o tecla 'p')\n\t- Tecla 'q' (para cancelar)\n\n");

 	printf("Introduzca el nombre del jugador: ");
	while(i<MAX_NAME && juego->barra.name[i] != '\n'){
		i++;
		scanf("%c", &juego->barra.name[i]);
	}
	juego->barra.namelon = i; 

	printf ("Introduzca velocidad (3.00 p/s por defecto): ");
	scanf ("%d",&juego->ps);
	if(juego->ps <= 0){
		juego->ps = 3;
	}
	juego->microsegundos = SEGUNDO/juego->ps;
}
void finalizar_juego(tjuego juego){
  	int i, min;
	float seg;
	
	borrar_pantalla();
	mostrar_juego(juego);

	printf_color(BOLD_RED);
	printf ("\n\tEL JUEGO HA ACABADO CON LOS SIGUIENTES DATOS:\n");
	printf_reset_color();

  	printf ("\n- Nombre del jugador:\t\t");
  	for (i = 0; i < juego.barra.namelon; i++){
   		printf ("%c", juego.barra.name[i]);
  	}
	printf ("\n- Puntos obtenidos:\t\t%d", juego.barra.puntos);
	get_time(juego.barra.segundos, &min, &seg);
	printf ("\n- Tiempo de juego:\t\t%02d:%02.f", min, seg);
	printf ("\n- Tamaño del tablero:\t\t%d filas x %d columnas", juego.tablero.nfil, juego.tablero.ncol);
	printf ("\n- Longitud del gusano:\t\t%d", juego.gusano.lon);
	printf ("\n- Velocidad del gusano:\t\t%d pasos/seg\n", juego.ps);
}
int es_fin_juego(tjuego *juego){
	if(juego->tecla == CANCEL || estado(*juego) == CHOQUE){
		return 1;
	}  else{
		return 0;
	}
}
void traducir_tecla(char *tecla){
	if(*tecla == UP2) *tecla = UP1;
	if(*tecla == DOWN2) *tecla = DOWN1;
	if(*tecla == LEFT2) *tecla = LEFT1;
	if(*tecla == RIGHT2) *tecla = RIGHT1;
}