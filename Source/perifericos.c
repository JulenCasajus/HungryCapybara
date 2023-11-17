#include <nds.h>		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C

//librerías desarrolladas por nosotros para el proyecto

#include "definiciones.h"

int TeclaDetectada() { //Devuelve TRUE si detecta que se ha pulsado alguna tecla
	if ((~TECLAS_DAT & 0x03FF)!=0) return 1;
	else return 0;
}

int TeclaPulsada() { //Devuelve el código de la tecla pulsada
	if((~TECLAS_DAT & 0x0001)!=0) return A;
	else if((~TECLAS_DAT & 0x0002)!=0) return B;
	else if((~TECLAS_DAT & 0x0004)!=0) return SELECT;
	else if((~TECLAS_DAT & 0x0008)!=0) return START;
	else if((~TECLAS_DAT & 0x0010)!=0) return DERECHA;
	else if((~TECLAS_DAT & 0x0020)!=0) return IZQUIERDA;
	else if((~TECLAS_DAT & 0x0040)!=0) return ARRIBA;
	else if((~TECLAS_DAT & 0x0080)!=0) return ABAJO;
	else if((~TECLAS_DAT & 0x0100)!=0) return R;
	else if((~TECLAS_DAT & 0x0200)!=0) return L;
	else return -1;
}

int TactilDetectado() { // Devuelve TRUE si la pantalla detecta que ha sido tocada
	touchRead(&PANT_DAT);
	return (PANT_DAT.px != 0 || PANT_DAT.py != 0);
}

void ConfigurarTeclado(int Conf_Tec) {
	TECLAS_CNT |= Conf_Tec;
}

void ConfigurarTemporizador(int Latch, int Conf_Tiempo) {
	TIMER0_DAT = Latch; //Latch = 65.536 - [(1 / (60 ticks/seg)) * (33554432 / 64Hz)
	TIMER0_CNT |= Conf_Tiempo;
}

void HabilitarInterrupciones() {
	HabilitarIntTeclado();
	HabilitarIntTiempo();
}

void HabilitarIntTeclado() {
	IME = 0;
	IE |= 0x00001000;
	IME = 1;
}

void InhibirIntTeclado() {
	IME = 0;
	IE &= 0xFFFFEFFF;
	IME = 1;
}

void HabilitarIntTiempo() {
	IME = 0;
	IE |= 0x00000008;
	IME = 1;
}

void InhibirIntTiempo() {
	IME = 0;
	IE &= 0xFFFFFFF7;
	IME = 1;
}

void PonerEnMarchaTiempo() {
	TIMER0_CNT |= 0x0080;
}

void PararTiempo() {
	TIMER0_CNT &= 0xFF7F;
}
