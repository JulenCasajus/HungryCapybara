#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C
#include <stdlib.h>		//librería estandar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

//librerías desarrolladas por nosotros para el proyecto

#include "sprites.h"
#include "definiciones.h"

u16* gfxcapy;
u16* gfxcapy2;
u16* gfxsupercapy;
u16* gfxsupercapy2;
u16* gfxsroca;
u16* gfxsmanzana;
u16* gfxsmanzanadorada;

/* Reservar memoria para cada sprite que se quiera mostrar en pantalla */
void memoriaReserva() {
	/* Por cada sprite que se quiera incluir en la pantalla principal hay que hacer algo equivalente a lo que sigue */
	gfxcapy = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxcapy2 = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxsupercapy = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxsupercapy2 = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxsroca = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxsmanzana = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxsmanzanadorada = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
}

/* A cada uno de los 256 valores que puede tomar un pixel en la PALETA PRINCIPAL
   se le puede asignar un color. El valor 0 es transparente. Los valores sin definir son negros. 
   MODIFICAR SEGÚN LOS COLORES QUE QUERAIS UTILIZAR EN VUESTROS SPRITES */
void EstablecerPaletaPrincipal() {

	SPRITE_PALETTE[1] = RGB15(31,0,0); // rojo
	SPRITE_PALETTE[2] = RGB15(31,31,0); // amarillo
	SPRITE_PALETTE[3] = RGB15(31,31,31); // blanco
	SPRITE_PALETTE[6] = RGB15(0,0,0); //negro
	SPRITE_PALETTE[9] = RGB15(16,16,16);
	SPRITE_PALETTE[10] = RGB15(25,25,25);
	SPRITE_PALETTE[11] = RGB15(8,8,8);
	SPRITE_PALETTE[12] = RGB15(31,19,0);
	SPRITE_PALETTE[13] = RGB15(19,0,4);
	SPRITE_PALETTE[14] = RGB15(25,0,5);
	SPRITE_PALETTE[21] = RGB15(0,12,0);
	SPRITE_PALETTE[25] = RGB15(11,5,3);
	SPRITE_PALETTE[26] = RGB15(17,11,6);
	SPRITE_PALETTE[27] = RGB15(27,21,12);
	SPRITE_PALETTE[28] = RGB15(31,24,13);
	SPRITE_PALETTE[29] = RGB15(22,17,9);
}

/* definición de un sprite de 16x16 píxeles para dibujar un capy */
/* Por la forma que tienen de trabajar los bancos de memoria, la imagen del sprite se divide en bloques de 8x8 píxeles. Los primeros 64 (8x8) píxeles que indicamos
aparecerán en el cuadrante superior izquierdo de la imagen del sprite, los siguientes 64 en el cuadrante superior derecho, los siguientes en el cuadrante inferior izquierdo y los
últimos en el cuadrante inferior derecho */

u8 capy[256] = {
	
	0,0,0,0,0,26,25,25,
	0,0,0,0,26,26,25,25,
	0,0,0,0,26,27,29,29,
	0,0,25,25,26,27,27,29,
	0,0,25,25,27,10,6,27,
	0,0,26,26,27,10,10,27,
	0,0,26,26,25,29,29,27,
	0,0,26,26,25,27,27,27,
 
	25,25,26,0,0,0,0,0,
	25,25,26,26,0,0,0,0,
	29,29,27,26,0,0,0,0,
	29,27,27,26,25,25,0,0,
	27,6,10,27,25,25,0,0,
	27,10,10,27,26,26,0,0,
	27,29,29,25,26,26,0,0,
	27,27,27,25,26,26,0,0,

	0,0,0,26,27,27,27,27,
	0,0,0,26,27,27,27,27,
	0,0,25,26,27,27,27,27,
	0,0,26,27,27,27,27,27,
	0,0,26,29,27,27,27,27,
	0,0,0,26,29,29,27,27,
	0,0,0,0,26,26,26,27,
	0,0,0,0,0,0,0,26,

	27,27,27,27,26,0,0,0,
	27,27,27,27,26,0,0,0,
	27,27,27,27,26,25,0,0,
	27,27,27,27,27,26,0,0,
	27,27,27,27,28,26,0,0,
	27,28,28,28,26,0,0,0,
	28,26,26,26,0,0,0,0,
	26,0,0,0,0,0,0,0,
};

u8 capy2[256] = {

	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,25,25,26,26,26,
	0,0,0,25,25,26,26,26,
	0,26,26,26,27,27,25,25,
	26,26,27,27,10,10,29,27,
	25,25,29,27,6,10,29,27,
	25,25,29,29,27,27,27,27,

	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,25,26,26,0,0,0,
	26,26,26,27,29,26,0,0,
	27,27,27,27,27,29,26,0,
	27,27,27,27,27,29,26,0,
	27,27,27,27,27,27,26,0,
	27,27,27,27,27,27,27,26,

	25,25,29,29,27,27,27,27,
	25,25,29,27,6,10,29,27,
	26,26,27,27,10,10,29,27,
	0,26,26,26,27,27,25,25,
	0,0,0,25,25,26,26,26,
	0,0,0,25,25,26,26,26,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,

	27,27,27,27,27,27,27,26,
	27,27,27,27,27,27,27,26,
	27,27,27,27,27,27,26,0,
	27,27,27,27,27,29,26,0,
	27,27,27,27,27,29,26,0,
	26,26,26,27,29,26,0,0,
	0,0,25,26,26,0,0,0,
	0,0,0,0,0,0,0,0,
};

u8 supercapy[256] = {
	
	0,0,0,1,12,12,12,12,
	0,0,1,12,26,26,25,25,
	0,1,12,2,26,27,29,29,
	1,12,25,25,26,27,27,29,
	12,2,25,25,27,10,6,27,
	12,2,26,26,27,10,10,27,
	12,2,26,26,25,29,29,27,
	12,2,26,26,25,27,27,27,
 
	12,12,12,12,1,0,0,0,
	25,25,26,26,12,1,0,0,
	29,29,27,26,2,12,1,0,
	29,27,27,26,25,25,12,1,
	27,6,10,27,25,25,2,12,
	27,10,10,27,26,26,2,12,
	27,29,29,25,26,26,2,12,
	27,27,27,25,26,26,2,12,

	12,2,2,26,27,27,27,27,
	12,2,2,26,27,27,27,27,
	12,2,25,26,27,27,27,27,
	12,2,26,27,27,27,27,27,
	1,12,26,29,27,27,27,27,
	0,1,12,26,29,29,27,27,
	0,0,1,12,26,26,26,27,
	0,0,0,1,12,12,12,12,

	27,27,27,27,26,2,2,12,
	27,27,27,27,26,2,2,12,
	27,27,27,27,26,25,2,12,
	27,27,27,27,27,26,2,12,
	27,27,27,27,28,26,12,1,
	27,28,28,28,26,12,1,0,
	28,26,26,26,12,1,0,0,
	12,12,12,12,1,0,0,0,
};

u8 supercapy2[256] = {

	0,0,0,1,12,12,12,12,
	0,0,1,12,2,2,2,2,
	0,1,12,25,25,26,26,26,
	1,12,2,25,25,26,26,26,
	12,26,26,26,27,27,25,25,
	12,26,27,27,10,10,29,27,
	12,25,29,27,6,10,29,27,
	12,25,29,29,27,27,27,27,
 
	12,12,12,12,1,0,0,0,
	2,2,2,2,12,1,0,0,
	2,2,25,26,26,12,1,0,
	26,26,26,27,29,26,12,1,
	27,27,27,27,27,29,26,12,
	27,27,27,27,27,29,26,12,
	27,27,27,27,27,27,26,12,
	27,27,27,27,27,27,27,12,

	12,25,29,29,27,27,27,27,
	12,25,29,27,6,10,29,27,
	12,26,27,27,10,10,29,27,
	12,26,26,26,27,27,25,25,
	1,12,2,25,25,26,26,26,
	0,1,12,25,25,26,26,26,
	0,0,1,12,2,2,2,2,
	0,0,0,1,12,12,12,12,

	27,27,27,27,27,27,28,12,
	27,27,27,27,27,28,26,12,
	27,27,27,27,27,28,26,12,
	27,27,27,27,27,28,26,12,
	26,26,26,27,28,26,12,1,
	2,2,25,26,26,12,1,0,
	2,2,2,2,12,1,0,0,
	12,12,12,12,1,0,0,0,
};

u8 sroca[256] = {

	0,0,0,0,0,0,0,0,
	0,0,0,0,0,6,6,6,
	0,0,0,0,6,10,10,10,
	0,0,0,6,9,10,10,10,
	0,0,0,6,9,9,10,10,
	0,0,0,6,11,9,9,10,
	0,0,6,11,11,11,9,9,
	0,6,11,11,11,11,11,11,

	0,0,0,0,0,0,0,0,
	6,0,0,0,0,0,0,0,
	10,6,6,0,0,0,0,0,
	10,0,9,6,0,0,0,0,
	10,10,9,6,0,0,0,0,
	10,10,10,9,6,0,0,0,
	9,10,10,9,9,6,0,0,
	9,10,10,10,9,9,6,0,

	6,11,11,11,11,11,11,9,
	6,11,11,11,9,9,11,9,
	6,11,11,11,9,9,9,9,
	6,11,11,11,11,9,9,9,
	6,11,11,11,11,11,9,9,
	0,6,11,11,11,11,11,11,
	0,6,11,11,11,11,11,11,
	0,0,6,6,6,6,6,6,

	9,10,10,10,10,9,6,0,
	9,10,10,10,10,9,11,6,
	9,9,9,9,9,9,11,6,
	9,9,9,9,9,11,11,6,
	11,9,11,9,11,11,11,6,
	9,11,9,11,11,11,6,0,
	11,11,11,11,11,11,6,0,
	6,6,6,6,6,6,0,0,
};

u8 smanzana[256] = {
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,6,
	0,0,0,0,6,6,6,6,
	0,0,0,6,1,1,1,6,
	0,0,6,1,1,1,1,1,
	0,6,1,1,3,3,3,1,
	0,6,1,3,3,3,3,1,

	6,6,6,0,0,0,0,0,
	6,14,6,0,0,0,0,0,
	14,14,6,6,0,0,0,0,
	14,6,21,21,6,0,0,0,
	14,6,21,21,21,6,0,0,
	6,1,6,21,21,21,6,0,
	1,1,1,6,21,21,21,6,
	1,1,1,13,6,6,6,6,

	0,6,1,3,3,3,1,1,
	0,6,1,3,3,1,1,1,
	0,6,1,1,1,1,1,1,
	0,6,13,1,1,1,1,1,
	0,6,13,13,1,1,1,1,
	0,0,6,13,13,13,13,13,
	0,0,6,13,13,13,13,6,
	0,0,0,6,6,6,6,0,

	1,1,1,1,13,13,6,0,
	1,1,1,1,13,13,6,0,
	1,1,1,1,13,13,6,0,
	1,1,1,13,13,13,6,0,
	1,1,13,13,13,13,6,0,
	13,13,13,13,13,6,0,0,
	6,13,13,13,13,6,0,0,
	0,6,6,6,6,0,0,0,
};

u8 smanzanadorada[256] = {
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,6,
	0,0,0,0,6,6,6,6,
	0,0,0,6,2,2,2,6,
	0,0,6,2,2,2,2,2,
	0,6,2,2,3,3,3,2,
	0,6,2,3,3,3,3,2,

	6,6,6,0,0,0,0,0,
	6,14,6,0,0,0,0,0,
	14,14,6,6,0,0,0,0,
	14,6,21,21,6,0,0,0,
	14,6,21,21,21,6,0,0,
	6,2,6,21,21,21,6,0,
	2,2,2,6,21,21,21,6,
	2,2,2,12,6,6,6,6,

	0,6,2,3,3,3,2,2,
	0,6,2,3,3,2,2,2,
	0,6,2,2,2,2,2,2,
	0,6,12,2,2,2,2,2,
	0,6,12,12,2,2,2,2,
	0,0,6,12,12,12,12,12,
	0,0,6,12,12,12,12,6,
	0,0,0,6,6,6,6,0,

	2,2,2,2,12,12,6,0,
	2,2,2,2,12,12,6,0,
	2,2,2,2,12,12,6,0,
	2,2,2,12,12,12,6,0,
	2,2,12,12,12,12,6,0,
	12,12,12,12,12,6,0,0,
	6,12,12,12,12,6,0,0,
	0,6,6,6,6,0,0,0,
};

/* Carga en memoria cada uno de los sprites que hemos dibujado */

void GuardarSpritesMemoria() { 

	int i;
	
	//sprite de 16*16
	for(i = 0; i < 16 * 16 / 2; i++) {	
		gfxcapy[i] = capy[i*2] | (capy[(i*2)+1]<<8);				
	} for(i = 0; i < 16 * 16 / 2; i++) {	
		gfxcapy2[i] = capy2[i*2] | (capy2[(i*2)+1]<<8);				
	} for(i = 0; i < 16 * 16 / 2; i++) {	
		gfxsupercapy[i] = supercapy[i*2] | (supercapy[(i*2)+1]<<8);				
	} for(i = 0; i < 16 * 16 / 2; i++) {	
		gfxsupercapy2[i] = supercapy2[i*2] | (supercapy2[(i*2)+1]<<8);				
	} for(i = 0; i < 16 * 16 / 2; i++) {	
		gfxsroca[i] = sroca[i*2] | (sroca[(i*2)+1]<<8);				
	} for(i = 0; i < 16 * 16 / 2; i++) {	
		gfxsmanzana[i] = smanzana[i*2] | (smanzana[(i*2)+1]<<8);				
	} for(i = 0; i < 16 * 16 / 2; i++) {	
		gfxsmanzanadorada[i] = smanzanadorada[i*2] | (smanzanadorada[(i*2)+1]<<8);				
}	}


void BorrarCapy(int indice, int x, int y) {

	oamSet(&oamMain,					//main graphics engine context
			indice,           			//oam index (0 to 127)  
			x, y,   					//x and y pixel location of the sprite
			0,                    		//priority, lower renders last (on top)
			0,					  		//this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_16x16,     
			SpriteColorFormat_256Color, 
			gfxcapy,//+16*16/2,         //pointer to the loaded graphics
			-1,                  		//sprite rotation data  
			false,               		//double the size when rotating?
			true,						//hide the sprite?
			false, false, 				//vflip, hflip
			false						//apply mosaic
			); 

	oamUpdate(&oamMain);
}

void MostrarCapy00(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxcapy, -1, false, false, false, true, false); 

	oamUpdate(&oamMain);
}

void MostrarCapy01(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxcapy, -1, false, false, true, false, false); 

	oamUpdate(&oamMain);
}

void MostrarCapy10(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxcapy2, -1, false, false, true, false, false); 

	oamUpdate(&oamMain);
}

void MostrarCapy11(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxcapy2, -1, false, false, false, true, false); 

	oamUpdate(&oamMain);
}

void MostrarSuperCapy00(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsupercapy, -1, false, false, false, true, false); 

	oamUpdate(&oamMain);
}

void MostrarSuperCapy01(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsupercapy, -1, false, false, true, false, false); 

	oamUpdate(&oamMain);
}

void MostrarSuperCapy10(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsupercapy2, -1, false, false, true, false, false); 

	oamUpdate(&oamMain);
}

void MostrarSuperCapy11(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsupercapy2, -1, false, false, false, true, false); 

	oamUpdate(&oamMain);
}

void BorrarSuperCapy(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsupercapy, -1, false, false, false, true, false); 

	oamUpdate(&oamMain);
}

void MostrarManzana(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsmanzana, -1, false, false, false, false, false); 

	oamUpdate(&oamMain);
}

void BorrarManzana(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsmanzana, -1, false, true, false, false, false); 

	oamUpdate(&oamMain);
}

void MostrarManzanaDorada(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsmanzanadorada, -1, false, false, false, false, false); 

	oamUpdate(&oamMain);
}

void BorrarManzanaDorada(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsmanzanadorada, -1, false, true, false, false, false); 

	oamUpdate(&oamMain);
}

void MostrarRoca(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsroca, -1, false, false, false, false, false); 

	oamUpdate(&oamMain);
}

void BorrarRoca(int indice, int x, int y) {

	oamSet(&oamMain, indice, x, y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, gfxsroca, -1, false, true, false, false, false); 

	oamUpdate(&oamMain);
}