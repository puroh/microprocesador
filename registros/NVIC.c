#include <stdint.h>
#include "NVIC.h"

void NVIC_EnableIRQ(uint8_t *Exnumb,uint8_t numb) // Funcion que activa las interrupciones
{
    Exnumb[numb]=1; // Condicion para entrar a las instrucciones de interrupcion
    //printw("Entro a NVIC");
}

void NVIC_DisableIRQ(uint8_t *Exnumb,uint8_t numb) // Funcion que ejecuta la regresion al codigo principal 
{
    Exnumb[numb]=0; // Condicion para regresar al codigo principal
}
/*
Exnumb 16=IRQ0  Primer interrupcion (n+15)=IRQ(n-1);
Exnumb
1     -     Reset -3, the highest 0x00000004 Asynchronous
2   -14     NMI -2 0x00000008 Asynchronous
3   -13     HardFault -1 0x0000000C Synchronous
4-10 -      Reserved - - -
11  -5      SVCall Configurablee 0x0000002C Synchronous
12  -13     - Reserved - - -
14  -2      PendSV Configurablee 0x00000038 Asynchronous
15  -1      SysTickc Configurablee 0x0000003C Asynchronous
15   -      Reserved - - -
16 primer interrupcion*/
