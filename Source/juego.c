#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estándar de C
#include <stdlib.h>		//librería estándar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

//librerías desarrolladas por nosotros para el proyecto

#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"

//definiciones de variables

int ESTADO;
int contador_manzana, numroca; //manzanas comidas y numero de rocas
int i, xdir, ydir; //direcciones de movimiento
int xpos, ypos, applex, appley, gapplex, gappley; //posiciones capibara, manzana y manzana dorada
int rocax, rocay, vrocax[100], vrocay[100]; //posiciones rocas
int tecla, tmenu; //tecla pulsada y botones menu
int opc1, opc2; //facil/dificil, poder on/off
int wait, secs; //tipo y segundos de espera
int tiempo, tiempog; //tiempo juego y tiempo manzana dorada
int puntuacion; //+100 por manzana, +250 por manzana dorada y baja con el tiempo
bool apple, gapple, dgapple, roca; //hay manzana o manzana dorada en pantalla?; dibujar manzana dorada o roca?
bool rojo, poder, poderON; //fondo rojo? tiene el poder? poder activado?
bool GameOver, easteregg, pulsado = false; //juego finalizado? easteregg? pantalla pulsada?

bool coincide_roca(int applex,int appley) { //comprueba si la posicion dada coincide con una roca
	i = 0;
	bool coincide = false;
	while(i<numroca && !coincide) {
		coincide = (applex==vrocax[i] && appley==vrocay[i]);
		i++;
	}
	return coincide;
}

void juego() {

	ESTADO = INICIO;

	cambiar_pantalla(0);

	opc1 = 0;
	opc2 = 0;

	while(ESTADO!=FIN) {

		if(ESTADO==INICIO) {
			
			if((TeclaDetectada()==1 && TeclaPulsada()==START) || TactilDetectado()==1) { //START o tocar la pantalla
				if(!pulsado) {
					pulsado = true;
					tmenu = 0;
					cambiar_pantalla(1);
					ESTADO = MENU;
			}	} else pulsado = false;
		}

		if(ESTADO==MENU) {
			
			if(TactilDetectado()==1) { //pulsar botones con pantalla tactil
				if(!pulsado) {
					pulsado = true;
					if (70 < PANT_DAT.px && PANT_DAT.px < 185  && 59 < PANT_DAT.py && PANT_DAT.py < 95) {
						if(tmenu==1) {
							tmenu = 0;
							cambiar_pantalla(1);
						} else if(tmenu==0) { //iniciar juego despues de 3 segundos
							iniciar_juego();
							wait = 0;
							secs = 0;
							ESTADO = WAIT;
					}	} else if(70 < PANT_DAT.px && PANT_DAT.px < 185 && 113 < PANT_DAT.py && PANT_DAT.py < 147) {
						if(tmenu==0) {
							tmenu = 1;
							cambiar_pantalla(2);
						} else if(tmenu==1) { //entrar al menu con las opciones guardadas
							tmenu = 0;
							if(opc1==0 && opc2==0) {
								cambiar_pantalla(3);
							} else if(opc1==0 && opc2==1) {
								cambiar_pantalla(4);
							} else if(opc1==1 && opc2==0) {
								cambiar_pantalla(5);
							} else if(opc1==1 && opc2==1) {
								cambiar_pantalla(6);
							}
							ESTADO = OPCIONES;
			}	}	}	} else pulsado = false;

			if(TeclaDetectada()==1) { //pulsar botones con teclas
				tecla = TeclaPulsada();
				if(tecla==A && tmenu==0) { //iniciar juego despues de 3 segundos
					iniciar_juego();
					wait = 0;
					secs = 0;
					ESTADO = WAIT;
				} else if(tecla==A && tmenu==1) { //entrar al menu con las opciones guardadas
					tmenu = 0;
					if(opc1==0 && opc2==0) {
						cambiar_pantalla(3);
					} else if(opc1==0 && opc2==1) {
						cambiar_pantalla(4);
					} else if(opc1==1 && opc2==0) {
						cambiar_pantalla(5);
					} else if(opc1==1 && opc2==1) {
						cambiar_pantalla(6);
					}
					ESTADO = OPCIONES;
		}	}	}

		if(ESTADO==OPCIONES) {
			
			if(TactilDetectado()==1) {
				if(!pulsado) {
					pulsado = true;
					if(40 < PANT_DAT.px && PANT_DAT.px < 214 && 59 < PANT_DAT.py && PANT_DAT.py < 97) {
						if(tmenu==1) {
							tmenu = 0;
							if(opc1==0 && opc2==0) cambiar_pantalla(3);
							else if(opc1==0 && opc2==1) cambiar_pantalla(4);
							else if(opc1==1 && opc2==0) cambiar_pantalla(5);
							else if(opc1==1 && opc2==1) cambiar_pantalla(6);
						} else if(tmenu==0) {
							if(opc1==1){
								opc1 = 0;
								if(opc2==0) cambiar_pantalla(3);
								else if(opc2==1) cambiar_pantalla(4);
							} else if(opc1==0) {
								opc1 = 1;
								if(opc2==0) cambiar_pantalla(5);
								else if(opc2==1) cambiar_pantalla(6);
					}	}	}

					if(40 < PANT_DAT.px && PANT_DAT.px < 214 && 113 < PANT_DAT.py && PANT_DAT.py < 147) {
						if(tmenu==0) {
							tmenu = 1;
							if(opc1==0 && opc2==0) cambiar_pantalla(7);
							else if(opc1==0 && opc2==1) cambiar_pantalla(8);
							else if(opc1==1 && opc2==0) cambiar_pantalla(9);
							else if(opc1==1 && opc2==1) cambiar_pantalla(10);
						} else if(tmenu==1) {
							if(opc2==1) {
								opc2 = 0;
								if(opc1==0) cambiar_pantalla(7);
								else if(opc1==1) cambiar_pantalla(9);
							} else if(opc2==0) {
								opc2 = 1;
								if(opc1==0) cambiar_pantalla(8);
								else if(opc1==1) cambiar_pantalla(10);
			}	}	}	}	} else pulsado = false;

			if(TeclaDetectada()==1) {
				tecla = TeclaPulsada();
				if(tecla==B) { //volver al menu
					tmenu = 0;
					cambiar_pantalla(1);
					ESTADO = MENU;
		}	}	}

		if(ESTADO==JUEGO) {

			if(GameOver) { //si GameOver, esperar 2 segundos y mostrar resultado
				wait = 1;
				secs = 0;
				ESTADO = WAIT;
			} else {

				if(rojo && opc1==1 && opc2==1 && xpos>238 && !easteregg) { //easteregg
					easteregg = true;
					poderON = false;
					consoleClear();
					iprintf("\x1b[14;10HOK I PULL UP");
					cambiar_pantalla(37);
					borrar_sprites();
					xpos = 1;
					xdir = 1; ydir = 0;
					numroca = 0;
					MostrarManzana(1, applex, appley);
					MostrarCapy10(0, xpos, ypos);

				} else if(xpos<1 || xpos>238 || ypos<1 || ypos>174 || (numroca>0 && puntuacion==0)) GameOver = true;
				//GameOver si choca con bordes o la puntuacion llega a 0

				for(i=0; i<numroca; i++) { //GameOver si choca con roca sin poder
					if(xpos<vrocax[i]+14 && xpos+14>vrocax[i] && ypos<vrocay[i]+14 && ypos+14>vrocay[i] && !poderON) GameOver = true;
				}

				if(roca) { //aparecer roca al comer manzana //&&numroca<50

					rocax = (rand() % (16)) * 16; //numero aleatorio en direccion x; (256) entre 16 bits de sprite
					rocay = (rand() % (12)) * 16; //numero aleatorio en direccion y; (192) entre 16 bits de sprite

        			if(rocax<xpos-32 || rocax>xpos+48 || rocay<ypos-32 || rocay>ypos+48) {
        				MostrarRoca(numroca + 3, rocax, rocay);
						vrocax[numroca] = rocax; //guardar posiciones de las rocas añadidas
						vrocay[numroca] = rocay;
						numroca++;
						roca = false;
     		  	}	}

				if(!apple) { //aparecer manzana si no hay
					
					if(opc1==0) { //modo facil
						applex = (rand() % (14) + 1) * 16; //numero aleatorio en direccion x quitando bordes; (256-32) entre 16 bits de sprite
						appley = (rand() % (10) + 1) * 16; //numero aleatorio en direccion y quitando bordes; (192-32) entre 16 bits de sprite
					} else if(opc1==1) { //modo dificil
						applex = (rand() % (16)) * 16; //numero aleatorio en direccion x; (256) entre 16 bits de sprite
						appley = (rand() % (12)) * 16; //numero aleatorio en direccion y; (192) entre 16 bits de sprite
					}

					if((applex<xpos-32 || applex>xpos+48 || appley<ypos-32 || appley>ypos+48) && !coincide_roca(applex, appley)) {
						MostrarManzana(1, applex, appley);
						apple = true;
				}	}

				if(xpos<applex+16 && xpos+16>applex && ypos<appley+16 && ypos+16>appley && apple) { //come manzana
					contador_manzana++;
					puntuacion = puntuacion + 100;
					BorrarManzana(1, applex, appley);
					apple = false;
					roca = true;
				}

				if(dgapple) { //aparecer manzana dorada si ha pasado el tiempog

					gapplex = ((rand() % (14)) + 1) * 16; //numero aleatorio en direccion x quitando bordes; (256-32) entre 16 bits de sprite
					gappley = ((rand() % (10)) + 1) * 16; //numero aleatorio en direccion y quitando bordes; (192) entre 16 bits de sprit


					if(!coincide_roca(gapplex, gappley) && (gapplex!=applex || gappley!=appley) &&
						gapplex<xpos-32 || gapplex>xpos+48 || gappley<ypos-32 || gappley>ypos+48){
						MostrarManzanaDorada(2, gapplex, gappley);
						gapple = true;
						dgapple = false;
				}	}

				if(xpos<gapplex+16 && xpos+16>gapplex && ypos<gappley+16 && ypos+16>gappley && gapple) { //come manzana dorada
					contador_manzana++;
					puntuacion = puntuacion + 250;
					BorrarManzanaDorada(2, gapplex, gappley);
					cambiar_pantalla(16);
					poder = true; //guarda el poder
					gapple = false;
				}

				if(contador_manzana==25 && !rojo) {
					rojo = true;
					if(!poder && !poderON) cambiar_pantalla(28);
				}

				if(TeclaDetectada()==1) {
					tecla = TeclaPulsada();
					if(tecla==SELECT) { //pausa
						borrar_sprites();
						tmenu = 0;
						cambiar_pantalla(33);
						ESTADO = PAUSA;
					} else if(tecla==A && poder) { //activa poder
						cambiar_pantalla(26);
						tiempog = 0;
						poder = false;
						poderON = true;
		}	}	}	}

		if(ESTADO==PAUSA) {

			if(TactilDetectado()==1) { //pulsar botones con pantalla tactil
				if(!pulsado) {
					pulsado = true;
					if (70 < PANT_DAT.px && PANT_DAT.px < 185  && 59 < PANT_DAT.py && PANT_DAT.py < 95) {
						if(tmenu==1) {
							tmenu = 0;
							cambiar_pantalla(33);
						} else if(tmenu==0) { //iniciar juego despues de 3 segundos
							mostrar_sprites();
							wait = 0;
							secs = 0;
							ESTADO = WAIT;
					}	} else if(70 < PANT_DAT.px && PANT_DAT.px < 185 && 113 < PANT_DAT.py && PANT_DAT.py < 147) {
						if(tmenu==0) {
							tmenu = 1;
							cambiar_pantalla(34);
						} else if(tmenu==1) { //entrar al menu con las opciones guardadas
							cambiar_pantalla(35);
							ESTADO = GOVER;
			}	}	}	} else pulsado = false;

			if(TeclaDetectada()==1) {
				tecla = TeclaPulsada();
				if(tecla==B || (tecla==A && tmenu==0)) { //reanudar partida
					mostrar_sprites();
					wait = 0;
					secs = 0;
					ESTADO = WAIT;
				} if(tecla==A && tmenu==1) { //salir de la partida
					cambiar_pantalla(35);
					ESTADO = GOVER;
		}	}	}

		if(ESTADO==GOVER) {

			if(TactilDetectado()==1) { //volver al menu al tocar la pantalla
				pulsado = true;
				cambiar_pantalla(0);
				ESTADO = INICIO;
			}

			if(TeclaDetectada()==1) {
				tecla = TeclaPulsada();
				if(tecla==A) { //volver al menu
					cambiar_pantalla(0);
					ESTADO = INICIO;
				} else if(tecla==SELECT) cambiar_pantalla(36); //creditos
				else if(tecla==B) { //terminar programa
					consoleClear();
					ESTADO = FIN;
}	}	}	}	}

void iniciar_juego() {
	tiempo = 0; tiempog = 0;
	contador_manzana = 0;
	puntuacion = 0;
	numroca = 0;
	apple = false;
	gapple = false;
	dgapple = false;
	roca = false;
	rojo = false;
	poder = false;
	poderON = false;
	GameOver = false;
	easteregg = false;
	xdir = 0; ydir = 1;
	xpos = 119; ypos = 140;
	wait = 0; secs = 0;
	ESTADO = WAIT;
}

void borrar_sprites() {
	BorrarCapy(0, xpos, ypos);
	BorrarManzana(1, applex, appley);
	if(gapple) BorrarManzanaDorada(2, gapplex, gappley);
	for(i=0; i<numroca; i++) {
		BorrarRoca(i + 3, vrocax[i], vrocay[i]);
}	}

void mostrar_sprites() { 
	MostrarManzana(1, applex, appley);
	if(gapple) MostrarManzanaDorada(2, gapplex, gappley);
	for(i=0; i<numroca; i++) {
		MostrarRoca(i + 3, vrocax[i], vrocay[i]);
}	}