#include <nds.h>		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C

//librerías desarrolladas por nosotros para el proyecto

#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"

void RA_Teclado() {

	tecla = TeclaPulsada();

	if (ESTADO == JUEGO) { //direccion de capy
		
		if(tecla==DERECHA && xdir!=-1) {
			xdir = 1;
			ydir = 0;
		} else if(tecla==IZQUIERDA && xdir!=1) {
			xdir = -1;
			ydir = 0;
		} else if(tecla==ARRIBA && ydir!=-1) {
			xdir = 0;
			ydir = 1;
		} else if(tecla==ABAJO && ydir!=1) {
			xdir = 0;
			ydir = -1;
	}	}

	if (ESTADO == MENU) { //botones menu
		
		if(tecla==ARRIBA && tmenu==1) {
			tmenu = 0;
			cambiar_pantalla(1);
		} if(tecla==ABAJO && tmenu==0) {
			tmenu = 1;
			cambiar_pantalla(2);
	}	}

	if (ESTADO == OPCIONES) { //botones opciones
		
		if(tecla==ARRIBA && tmenu==1) {
			tmenu = 0;
			if(opc1==0 && opc2==0) cambiar_pantalla(3);
			else if(opc1==0 && opc2==1) cambiar_pantalla(4);
			else if(opc1==1 && opc2==0) cambiar_pantalla(5);
			else if(opc1==1 && opc2==1) cambiar_pantalla(6);
		}
		
		if(tecla==ABAJO && tmenu==0) {
			tmenu = 1;
			if(opc1==0 && opc2==0) cambiar_pantalla(7);
			else if(opc1==0 && opc2==1) cambiar_pantalla(8);
			else if(opc1==1 && opc2==0) cambiar_pantalla(9);
			else if(opc1==1 && opc2==1) cambiar_pantalla(10);
		}
		
		if((tecla==DERECHA || tecla==IZQUIERDA) && tmenu==0) {
			if(opc1==1){
				opc1 = 0;
				if(opc2==0) cambiar_pantalla(3);
				else if(opc2==1) cambiar_pantalla(4);
			} else if(opc1==0) {
				opc1 = 1;
				if(opc2==0) cambiar_pantalla(5);
				else if(opc2==1) cambiar_pantalla(6);
		}	}
		
		if((tecla==DERECHA || tecla==IZQUIERDA) && tmenu==1) {
			if(opc2==1) {
				opc2 = 0;
				if(opc1==0) cambiar_pantalla(7);
				else if(opc1==1) cambiar_pantalla(9);
			} else if(opc2==0) {
				opc2 = 1;
				if(opc1==0) cambiar_pantalla(8);
				else if(opc1==1) cambiar_pantalla(10);
	}	}	}

	if (ESTADO == PAUSA) { //botones pausa
		
		if(tecla==ARRIBA && tmenu==1) {
			tmenu = 0;
			cambiar_pantalla(33);
		} else if(tecla==ABAJO && tmenu==0) {
			tmenu = 1;
			cambiar_pantalla(34);
}	}	}

void RA_Tiempo() {

	if(ESTADO==JUEGO) {

		tiempo++;
		tiempog++;
		
		if(tiempog==60 && poderON) cambiar_pantalla(25);
		if(tiempog==120 && poderON) cambiar_pantalla(24);
		if(tiempog==180 && poderON) cambiar_pantalla(23);
		if(tiempog==240 && poderON) cambiar_pantalla(22);
		if(tiempog==300 && poderON) {
			poderON = false; //5 segundos de poder
			if(rojo) cambiar_pantalla(28);
			else cambiar_pantalla(11);
		}

		if(((tiempog==1600 && opc1==0) || (tiempog==800 && opc1==1)) && opc2==0) dgapple = true; //aparece manzana dorada

		if(tiempo % 20 == 0 && !easteregg) {
			consoleClear();
			iprintf("\x1b[4;8HPUNTUACION = %d", puntuacion);
			iprintf("\x1b[8;6HMANZANAS COMIDAS = %d", contador_manzana);
			if(poder) iprintf("\x1b[13;3HPULSA A PARA ACTIVAR PODER");
			iprintf("\x1b[18;2HPULSA SELECT PARA PONER PAUSA");
			if(puntuacion>0) puntuacion--;
		}

		if((tiempo % 2 == 0 && opc1==0) || (tiempo % 1 ==0 && opc1==1)) { //cada cuantos ticks se mueve dependiendo de la dificultad

			if(!poderON){
				if(xdir==1 && xpos<255) {
					xpos++;
					MostrarCapy10(0, xpos, ypos);
				} else if(xdir==-1 && xpos>0) {
					xpos--;
					MostrarCapy11(0, xpos, ypos);
				} else if(ydir==-1 && ypos<192) {
					ypos++;
					MostrarCapy00(0, xpos, ypos);
				} else if(ydir==1 && ypos>0) {
					ypos--;
					MostrarCapy01(0, xpos, ypos);
			}	} else if(poderON){
					if(xdir==1 && xpos<255) {
						xpos++;
						MostrarSuperCapy10(0, xpos, ypos);
					} else if(xdir==-1 && xpos>0) {
						xpos--;
						MostrarSuperCapy11(0, xpos, ypos);
					} else if(ydir==-1 && ypos<192) {
						ypos++;
						MostrarSuperCapy00(0, xpos, ypos);
					} else if(ydir==1 && ypos>0) {
						ypos--;
						MostrarSuperCapy01(0, xpos, ypos);
		}	}	}	}


	if (ESTADO == WAIT) {
		
		secs++;

		if(wait==0 && !easteregg) { //volver a jugar tras 3 segundos

			if(secs==1) {

				consoleClear();
				iprintf("\x1b[4;8HPUNTUACION = %d", puntuacion);
				iprintf("\x1b[8;6HMANZANAS COMIDAS = %d", contador_manzana);
				if(poder) iprintf("\x1b[13;3HPULSA A PARA ACTIVAR PODER");
				iprintf("\x1b[18;2HPULSA SELECT PARA PONER PAUSA");

				if(!poderON) {
					if(poder) cambiar_pantalla(19);
					else if(rojo) cambiar_pantalla(31);
					else cambiar_pantalla(14);

					if(xdir==1) MostrarCapy10(0, xpos, ypos);
					else if(xdir==-1) MostrarCapy11(0, xpos, ypos);
					else if(ydir==-1) MostrarCapy00(0, xpos, ypos);
					else if(ydir==1) MostrarCapy01(0, xpos, ypos);
				} else {
					cambiar_pantalla(24);

					if(xdir==1) MostrarSuperCapy10(0, xpos, ypos);
					else if(xdir==-1) MostrarSuperCapy11(0, xpos, ypos);
					else if(ydir==-1) MostrarSuperCapy00(0, xpos, ypos);
					else if(ydir==1) MostrarSuperCapy01(0, xpos, ypos);
			}	}

			if(secs==60) {
				if(poderON) cambiar_pantalla(23);
				else if(poder) cambiar_pantalla(18);
				else if(rojo) cambiar_pantalla(30);
				else cambiar_pantalla(13);
			}

			if(secs==120) {
				if(poderON) cambiar_pantalla(22);
				else if(poder) cambiar_pantalla(17);
				else if(rojo) cambiar_pantalla(29);
				else cambiar_pantalla(12);
			}

			if(secs==180) {
				if(poderON) cambiar_pantalla(21);
				else if(poder) cambiar_pantalla(16);
				else if(rojo) cambiar_pantalla(28);
				else cambiar_pantalla(11);

				ESTADO = JUEGO;
		}	}

		if(wait==0 && easteregg){
			cambiar_pantalla(37);
			consoleClear();
			iprintf("\x1b[14;10HOK I PULL UP");
			if(secs==60) ESTADO = JUEGO;
		}

		if (wait==1) { //enseñar game over tras 1 segundo
			if(secs==1) {
				if(easteregg) cambiar_pantalla(38);
				else if(poderON) cambiar_pantalla(27);
				else if(poder) cambiar_pantalla(20);
				else if(rojo) cambiar_pantalla(32);
				else cambiar_pantalla(15);
			}

			if(secs==60) {
			cambiar_pantalla(35);
			borrar_sprites();
			ESTADO = GOVER;
}	}	}	}

void EstablecerVectorInt() {
	irqSet(IRQ_TIMER0, RA_Tiempo);
	irqSet(IRQ_KEYS, RA_Teclado);
}