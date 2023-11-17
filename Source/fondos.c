#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación. */

#include "fondos.h"
#include "graficos.h"
#include "definiciones.h"

#include "FondoAngry.h"
#include "FondoMenu.h"
#include "FondoMenu2.h"
#include "FondoOpciones000.h"
#include "FondoOpciones001.h"
#include "FondoOpciones010.h"
#include "FondoOpciones011.h"
#include "FondoOpciones100.h"
#include "FondoOpciones101.h"
#include "FondoOpciones110.h"
#include "FondoOpciones111.h"
#include "FondoVerde.h"
#include "FondoVerde1.h"
#include "FondoVerde2.h"
#include "FondoVerde3.h"
#include "FondoVerdeM.h"
#include "FondoAmarillo.h"
#include "FondoAmarillo1.h"
#include "FondoAmarillo2.h"
#include "FondoAmarillo3.h"
#include "FondoAmarilloM.h"
#include "FondoMorado.h"
#include "FondoMorado1.h"
#include "FondoMorado2.h"
#include "FondoMorado3.h"
#include "FondoMorado4.h"
#include "FondoMorado5.h"
#include "FondoMoradoM.h"
#include "FondoRojo.h"
#include "FondoRojo1.h"
#include "FondoRojo2.h"
#include "FondoRojo3.h"
#include "FondoRojoM.h"
#include "FondoPausa.h"
#include "FondoPausa2.h"
#include "FondoFin.h"
#include "FondoCreditos.h"
#include "FondoCapy.h"
#include "FondoCapyM.h"

// Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria.
static const int DMA_CHANNEL = 3;

void cambiar_pantalla(int i) {

    if(i==0) {
        consoleClear();
        iprintf("\x1b[10;5HPULSA START O TOCA LA");
        iprintf("\x1b[14;5HPANTALLA PARA EMPEZAR");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoAngryBitmap, (uint16 *)BG_BMP_RAM(0), FondoAngryBitmapLen);  
    } else if(i==1) {
        consoleClear();
        iprintf("\x1b[2;9HINSTRUCCIONES:");
        iprintf("\x1b[6;2HUSA LAS FLECHAS PARA MOVERTE");
        iprintf("\x1b[8;3HY PULSA A PARA ACTIVAR PODER");
        iprintf("\x1b[10;3HAL COMER UNA MANZANA DORADA");
        iprintf("\x1b[14;10HOBJETIVO:");
        iprintf("\x1b[18;3HCOME TANTAS MANZANAS COMO");
        iprintf("\x1b[20;1HPUEDAS SIN CHOCARTE CON ROCAS");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoMenuBitmap, (uint16 *)BG_BMP_RAM(0), FondoMenuBitmapLen);  
    } else if(i==2) dmaCopyHalfWords(DMA_CHANNEL, FondoMenu2Bitmap, (uint16 *)BG_BMP_RAM(0), FondoMenu2BitmapLen);  
      else if(i==3) {
        consoleClear();
        iprintf("\x1b[4;10HMODO:  FACIL");
        iprintf("\x1b[8;4HLAS MANZANAS NO APARECEN");
        iprintf("\x1b[10;9HEN LOS BORDES");
        iprintf("\x1b[14;5HLA VELOCIDAD ES LENTA");
        iprintf("\x1b[18;5HEL PODER ESTA ACTIVADO");
        iprintf("\x1b[22;2HPULSA B PARA VOLVER AL MENU");
        dmaCopyHalfWords(DMA_CHANNEL, FondoOpciones000Bitmap, (uint16 *)BG_BMP_RAM(0), FondoOpciones000BitmapLen);
    } else if(i==4) {
        consoleClear();
        iprintf("\x1b[4;10HMODO:  NORMAL");
        iprintf("\x1b[8;4HLAS MANZANAS NO APARECEN");
        iprintf("\x1b[10;9HEN LOS BORDES");
        iprintf("\x1b[14;5HLA VELOCIDAD ES LENTA");
        iprintf("\x1b[18;3HEL PODER ESTA DESACTIVADO");
        iprintf("\x1b[22;2HPULSA B PARA VOLVER AL MENU");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoOpciones001Bitmap, (uint16 *)BG_BMP_RAM(0), FondoOpciones001BitmapLen);
    } else if(i==5) {
        consoleClear();
        iprintf("\x1b[4;10HMODO:  DIFICIL");
        iprintf("\x1b[8;4HLAS MANZANAS APARECEN EN");
        iprintf("\x1b[10;8HTODA LA PANTALLA");
        iprintf("\x1b[14;5HLA VELOCIDAD ES RAPIDA");
        iprintf("\x1b[18;5HEL PODER ESTA ACTIVADO");
        iprintf("\x1b[22;2HPULSA B PARA VOLVER AL MENU");
        dmaCopyHalfWords(DMA_CHANNEL, FondoOpciones010Bitmap, (uint16 *)BG_BMP_RAM(0), FondoOpciones010BitmapLen);
    } else if(i==6) {
        consoleClear();
        iprintf("\x1b[4;10HMODO:  EXTREMO");
        iprintf("\x1b[8;4HLAS MANZANAS APARECEN EN");
        iprintf("\x1b[10;8HTODA LA PANTALLA");
        iprintf("\x1b[14;5HLA VELOCIDAD ES RAPIDA");
        iprintf("\x1b[18;3HEL PODER ESTA DESACTIVADO");
        iprintf("\x1b[22;2HPULSA B PARA VOLVER AL MENU");
        dmaCopyHalfWords(DMA_CHANNEL, FondoOpciones011Bitmap, (uint16 *)BG_BMP_RAM(0), FondoOpciones011BitmapLen);
    } else if(i==7) {
        consoleClear();
        iprintf("\x1b[4;10HMODO:  FACIL");
        iprintf("\x1b[8;4HLAS MANZANAS NO APARECEN");
        iprintf("\x1b[10;9HEN LOS BORDES");
        iprintf("\x1b[14;5HLA VELOCIDAD ES LENTA");
        iprintf("\x1b[18;5HEL PODER ESTA ACTIVADO");
        iprintf("\x1b[22;2HPULSA B PARA VOLVER AL MENU");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoOpciones100Bitmap, (uint16 *)BG_BMP_RAM(0), FondoOpciones100BitmapLen);
    } else if(i==8) {
        consoleClear();
        iprintf("\x1b[4;10HMODO:  NORMAL");
        iprintf("\x1b[8;4HLAS MANZANAS NO APARECEN");
        iprintf("\x1b[10;9HEN LOS BORDES");
        iprintf("\x1b[14;5HLA VELOCIDAD ES LENTA");
        iprintf("\x1b[18;3HEL PODER ESTA DESACTIVADO");
        iprintf("\x1b[22;2HPULSA B PARA VOLVER AL MENU");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoOpciones101Bitmap, (uint16 *)BG_BMP_RAM(0), FondoOpciones101BitmapLen);
    } else if(i==9) {
        consoleClear();
        iprintf("\x1b[4;10HMODO:  DIFICIL");
        iprintf("\x1b[8;4HLAS MANZANAS APARECEN EN");
        iprintf("\x1b[10;8HTODA LA PANTALLA");
        iprintf("\x1b[14;5HLA VELOCIDAD ES RAPIDA");
        iprintf("\x1b[18;5HEL PODER ESTA ACTIVADO");
        iprintf("\x1b[22;2HPULSA B PARA VOLVER AL MENU");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoOpciones110Bitmap, (uint16 *)BG_BMP_RAM(0), FondoOpciones110BitmapLen);
    } else if(i==10) {
        consoleClear();
        iprintf("\x1b[4;10HMODO:  EXTREMO");
        iprintf("\x1b[8;4HLAS MANZANAS APARECEN EN");
        iprintf("\x1b[10;8HTODA LA PANTALLA");
        iprintf("\x1b[14;5HLA VELOCIDAD ES RAPIDA");
        iprintf("\x1b[18;3HEL PODER ESTA DESACTIVADO");
        iprintf("\x1b[22;2HPULSA B PARA VOLVER AL MENU");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoOpciones111Bitmap, (uint16 *)BG_BMP_RAM(0), FondoOpciones111BitmapLen);
    } else if(i==11) dmaCopyHalfWords(DMA_CHANNEL, FondoVerdeBitmap, (uint16 *)BG_BMP_RAM(0), FondoVerdeBitmapLen);
      else if(i==12) dmaCopyHalfWords(DMA_CHANNEL, FondoVerde1Bitmap, (uint16 *)BG_BMP_RAM(0), FondoVerde1BitmapLen);
      else if(i==13) dmaCopyHalfWords(DMA_CHANNEL, FondoVerde2Bitmap, (uint16 *)BG_BMP_RAM(0), FondoVerde2BitmapLen);
      else if(i==14) dmaCopyHalfWords(DMA_CHANNEL, FondoVerde3Bitmap, (uint16 *)BG_BMP_RAM(0), FondoVerde3BitmapLen);
      else if(i==15) dmaCopyHalfWords(DMA_CHANNEL, FondoVerdeMBitmap, (uint16 *)BG_BMP_RAM(0), FondoVerdeMBitmapLen);
      else if(i==16) dmaCopyHalfWords(DMA_CHANNEL, FondoAmarilloBitmap, (uint16 *)BG_BMP_RAM(0), FondoAmarilloBitmapLen);
      else if(i==17) dmaCopyHalfWords(DMA_CHANNEL, FondoAmarillo1Bitmap, (uint16 *)BG_BMP_RAM(0), FondoAmarillo1BitmapLen);
      else if(i==18) dmaCopyHalfWords(DMA_CHANNEL, FondoAmarillo2Bitmap, (uint16 *)BG_BMP_RAM(0), FondoAmarillo2BitmapLen);
      else if(i==19) dmaCopyHalfWords(DMA_CHANNEL, FondoAmarillo3Bitmap, (uint16 *)BG_BMP_RAM(0), FondoAmarillo3BitmapLen);
      else if(i==20) dmaCopyHalfWords(DMA_CHANNEL, FondoAmarilloMBitmap, (uint16 *)BG_BMP_RAM(0), FondoAmarilloMBitmapLen);
      else if(i==21) dmaCopyHalfWords(DMA_CHANNEL, FondoMoradoBitmap, (uint16 *)BG_BMP_RAM(0), FondoMoradoBitmapLen);
      else if(i==22) dmaCopyHalfWords(DMA_CHANNEL, FondoMorado1Bitmap, (uint16 *)BG_BMP_RAM(0), FondoMorado1BitmapLen);
      else if(i==23) dmaCopyHalfWords(DMA_CHANNEL, FondoMorado2Bitmap, (uint16 *)BG_BMP_RAM(0), FondoMorado2BitmapLen);
      else if(i==24) dmaCopyHalfWords(DMA_CHANNEL, FondoMorado3Bitmap, (uint16 *)BG_BMP_RAM(0), FondoMorado3BitmapLen);
      else if(i==25) dmaCopyHalfWords(DMA_CHANNEL, FondoMorado4Bitmap, (uint16 *)BG_BMP_RAM(0), FondoMorado4BitmapLen);
      else if(i==26) dmaCopyHalfWords(DMA_CHANNEL, FondoMorado5Bitmap, (uint16 *)BG_BMP_RAM(0), FondoMorado5BitmapLen);
      else if(i==27) dmaCopyHalfWords(DMA_CHANNEL, FondoMoradoMBitmap, (uint16 *)BG_BMP_RAM(0), FondoMoradoMBitmapLen);
      else if(i==28) dmaCopyHalfWords(DMA_CHANNEL, FondoRojoBitmap, (uint16 *)BG_BMP_RAM(0), FondoRojoBitmapLen);
      else if(i==29) dmaCopyHalfWords(DMA_CHANNEL, FondoRojo1Bitmap, (uint16 *)BG_BMP_RAM(0), FondoRojo1BitmapLen);
      else if(i==30) dmaCopyHalfWords(DMA_CHANNEL, FondoRojo2Bitmap, (uint16 *)BG_BMP_RAM(0), FondoRojo2BitmapLen);
      else if(i==31) dmaCopyHalfWords(DMA_CHANNEL, FondoRojo3Bitmap, (uint16 *)BG_BMP_RAM(0), FondoRojo3BitmapLen);
      else if(i==32) dmaCopyHalfWords(DMA_CHANNEL, FondoRojoMBitmap, (uint16 *)BG_BMP_RAM(0), FondoRojoMBitmapLen);
      else if(i==33) {
        consoleClear();
        if(easteregg) iprintf("\x1b[4;7HCAPYBARA SUPREMACY");
        else iprintf("\x1b[4;8HPUNTUACION = %d", puntuacion);
        iprintf("\x1b[8;6HMANZANAS COMIDAS = %d", contador_manzana);
        if(poder) {
            iprintf("\x1b[12;8HPODER = OBTENIDO");
        } else iprintf("\x1b[12;7HPODER = NO OBTENIDO");
        iprintf("\x1b[18;4HPULSA A PARA SELECCIONAR");
        iprintf("\x1b[22;2HPULSA B  PARA VOLVER AL MENU");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoPausaBitmap, (uint16 *)BG_BMP_RAM(0), FondoPausaBitmapLen);
    } else if(i==34) dmaCopyHalfWords(DMA_CHANNEL, FondoPausa2Bitmap, (uint16 *)BG_BMP_RAM(0), FondoPausa2BitmapLen);
      else if(i==35) {
        consoleClear();
        if(easteregg) iprintf("\x1b[4;7HCAPYBARA SUPREMACY");
        else iprintf("\x1b[4;8HPUNTUACION = %d", puntuacion);
        iprintf("\x1b[8;1HPULSA A PARA VOLVER AL INICIO");
        iprintf("\x1b[12;1HPULSA SELECT PARA VER CREDITOS");
        iprintf("\x1b[16;1HPULSA B PARA TERMINAR EL JUEGO");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoFinBitmap, (uint16 *)BG_BMP_RAM(0), FondoFinBitmapLen);
    } else if(i==36) {
        consoleClear();
        iprintf("\x1b[10;1HPULSA A PARA VOLVER AL INICIO");
        iprintf("\x1b[14;1HPULSA B PARA TERMINAR EL JUEGO");
	    dmaCopyHalfWords(DMA_CHANNEL, FondoCreditosBitmap, (uint16 *)BG_BMP_RAM(0), FondoCreditosBitmapLen);
    } else if(i==37) dmaCopyHalfWords(DMA_CHANNEL, FondoCapyBitmap, (uint16 *)BG_BMP_RAM(0), FondoCapyBitmapLen);
      else if(i==38) dmaCopyHalfWords(DMA_CHANNEL, FondoCapyMBitmap, (uint16 *)BG_BMP_RAM(0), FondoCapyMBitmapLen);
}

/* PANTALLA SUPERIOR NDS (32x24)
..................................
.(0,0)                     (0,31).
.                                .
.                                .
.                                .
.          MODO:  NORMAL         .
.                                .
.                                .
.                                .
.    LAS MANZANAS NO APARECEN    .
.                                .
.          EN LOS BORDES         .
.                                .
.                                .
.                                .
.     LA VELOCIDAD ES LENTA      .
.                                .
.                                .
.                                .
.     EL PODER ESTA ACTIVADO     .
.                                .
.                                .
.                                .
.  PULSA B  PARA VOLVER AL MENU  .
.(23,0)                   (23,31).
..................................
*/

/* PANTALLA SUPERIOR NDS (32x24)
..................................
.(0,0)                     (0,31).
.                                .
.                                .
.                                .
.        PUNTUACION = 1750       .
.                                .
.                                .
.                                .
.      MANZANAS COMIDAS = 18     .
.                                .
.                                .
.                                .
.                                .
.   PULSA A PARA ACTIVAR PODER   .
.                                .
.                                .
.                                .
.                                .
.  PULSA SELECT PARA PONER PAUSA .
.                                .
.                                .
.                                .
.                                .
.(23,0)                   (23,31).
..................................
*/

/* PANTALLA SUPERIOR NDS (32x24)
..................................
.(0,0)                     (0,31).
.                                .
.                                .
.                                .
.        PUNTUACION = 1750       .
.                                .
.                                .
.                                .
.      MANZANAS COMIDAS = 18     .
.                                .
.                                .
.                                .
.       PODER = NO OBTENIDO      .
.                                .
.                                .
.                                .
.                                .
.                                .
.    PULSA A PARA SELECCIONAR    .
.                                .
.                                .
.                                .
.  PULSA B PARA VOLVER AL JUEGO  .
.(23,0)                   (23,31).
..................................
*/