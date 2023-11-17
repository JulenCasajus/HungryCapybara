/*-------------------------------------
definiciones.h
-------------------------------------*/
#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C
#include <stdlib.h>		//librería estandar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos


#define IME		(*(vuint32*)0x04000208) //Interrupt Master Enable -- Habilitar-deshabilitar todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable -- Habilitar-deshabilitar las interrupciones de forma individual
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag -- Registro de solicitud de interrupción

// funciones para el tratamiento general de las interrupciones
#define DeshabilitarInterrupciones() IME=0 //Deshabilitar todas las interrupciones

//registros del teclado
#define TECLAS_DAT	(*(vu16*)0x4000130) //registro de datos del teclado
#define TECLAS_CNT	(*(vu16*)0x4000132) //registro de control del teclado

//registros del temporizador Timer0
#define TIMER0_CNT  (*(vuint16*)0x04000102) //registro de control del temporizador
#define TIMER0_DAT  (*(vuint16*)0x04000100) //registro de datos del temporizador



//Acceso a los registros de la pantalla táctil
touchPosition PANT_DAT;

// Nombres asignados a las teclas para facilitar la comprensión de nuestro código
#define A			0 
#define B			1
#define SELECT		2 
#define START		3
#define DERECHA		4 
#define IZQUIERDA	5
#define ARRIBA		6 
#define ABAJO		7
#define R			8 
#define L			9

//Nombres asignados a los estados
#define INICIO      0
#define MENU        1
#define OPCIONES    2
#define JUEGO       3
#define PAUSA       4
#define WAIT        5
#define GOVER       6
#define FIN         7

//definiciones de variables globales externas
extern int ESTADO;
extern int contador_manzana, numroca; //manzanas comidas y numero de rocas
extern int xdir, ydir; //direcciones de movimiento
extern int xpos, ypos, applex, appley, gapplex, gappley; //posiciones capibara, manzana y manzana dorada
extern int rocax, rocay; //posiciones rocas
extern int tecla, tmenu; //tecla pulsada y botones menu
extern int opc1, opc2; //facil/dificil, poder on/off
extern int wait, secs; //tipo y segundos de espera
extern int tiempo, tiempog; //tiempo juego y tiempo manzana dorada
extern int puntuacion; //+100 por manzana, -50 por poder usado
extern bool apple, gapple, dgapple, roca; //dibujar manzana o roca?
extern bool rojo, poder, poderON; //tiene el poder? poder activado?
extern bool GameOver, easteregg; //juego finalizado?