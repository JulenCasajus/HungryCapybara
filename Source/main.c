#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C
#include <stdlib.h>		//librería estandar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

//librerías desarrolladas por nosotros para el proyecto

#include "graficos.h"		
#include "definiciones.h"
#include "sprites.h"
#include "juego.h"


int main(void) {

	inicializarGraficosSprites();

	HabilitarInterrupciones();

	ConfigurarTeclado(0x40F0); //en binario: 0100 0000 1111 0000. ints activadas para bit 4, 5, 6 y 7 (IZQUIERDA, DERECHA, ARRIBA, ABAJO)

	ConfigurarTemporizador(56798,0x00C1); //en binario: 0000 0000 1100 0001. activados bit 1, 6 y 7 (64Hz, Overflow, Time On)

	EstablecerVectorInt(); //activar IRQ --> Tiempo y Teclado (IZQUIERDA, DERECHA, ARRIBA y ABAJO por interrupcion)

	juego(); // llamada al juego

	DeshabilitarInterrupciones();

	return(0);
}
