#include <stdint.h>
#include <stdio.h>
#include "flags.h"
#include "alu.h"
#include <curses.h>

uint32_t H=2147483648UL;

void flag(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn,bool *banderas,uint8_t *compar){/* Función que no retorna, pero determina el valor de las banderas en la dirección Rd */
    if(*Rd>=((1<<31)))
        banderas[N]=1;
    else
        banderas[N]=0;

    if(!*Rd)
        banderas[Z]=1;
    else
        banderas[Z]=0;
    if(*compar==0){
            
         if(( (*Rm>=H)&&(*Rn<H)&&(*Rd<H)) || ((*Rn>=H)&&(*Rm<H)&&(*Rd<H)) || ((*Rm>=H)&&(*Rn>=H)) )
            banderas[C]=1;
         else
            banderas[C]=0;
    }

    if(*compar==0){
        if((*Rm&(H))==(*Rn&H)) /*si los bits mas significativo de Rm y Rn son iguales*/
        {
            if((*Rm&H)!=(*Rd&H))	/*y si los bits mas significativos de Rd y Rn son diferentes*/
            {
                banderas[V]=1;
            }
        }
        else
            banderas[V]=0;
    	}

/***********************/
/* Muestra las banderas*/

	attrset(COLOR_PAIR(2 )); /* Permite cambiar el color a los textos */
	mvprintw(7,40,"N:%d Z:%d C:%d V:%d",banderas[N],banderas[Z],banderas[C],banderas[V]); /* Imprime el valor de las banderas en una interfaz, mediante el uso de la libreria curses */
	refresh(); /* Código sirve para ser uso de printw */
/***********************/
}






