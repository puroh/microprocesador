#include <stdint.h>
#include <stdio.h>
#include "flags.h"
#include "alu.h"
#include <curses.h>






void flag(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn,bool *banderas,uint8_t *compar) /* Función que no retorna, pero determina el valor de las banderas en la dirección Rd */
{
	if(*Rd>((1<<31))) /* Comparacion lógica con Rd para detrminar si hay bandera negativa */
	{
		banderas[N]=1;
	}
	else /* Se ejecuta esta instruccioón en caso de no ser verdadera la condición lógica matemática*/
	{
		banderas[N]=0; /* Vale cero en casoi de no cumplir con la primera condición */
	}
	if(!*Rd) /* Se establece que si es diferente se determina la bandera de ceros */
	{
		banderas[Z]=1; /* Para cuando cumple con la condición*/
	}
	else /* Se ejecuta esta instruccioón en caso de no ser verdadera la condición lógica matemática*/
	{
    banderas[Z]=0; /* En caso de no cumplir con la condición */
	}
    if(*compar==0) /* Compara la variable igual a cero, para saber si se ha modificado todas las banderas */
	{
		if(((*Rm>=(1<<31))^(*Rn<0))&&((*Rn>=(1<<31))^(*Rm<0))) /* Condición lógica matemática que determina si hay bandera Carry */
		{
			banderas[C]=1; /* Si cumple con la condición */
		}
        else /* Se ejecuta esta instruccioón en caso de no ser verdadera la condición lógica matemática*/
		{
            banderas[C]=0; /* En el caso de no cumplir con la condición */
		}
    }
    if(*compar==0) /* Compara la variable igual a cero, para saber si se ha modificado todas las banderas */
	{
		if((((*Rm&(1<<31))==(1<<31)&&(*Rn&(1<<31))==(1<<31))&&(((*Rd&(1<<31))==0)))||(((*Rm&(1<<31))==(0)&&(*Rn&(1<<31))==(0))&&(((*Rd&(1<<31))==(1<<31))))) /* Condición lógica matemática que determina si hay bandera Sobreflujo */
		{
			banderas[V]=1; /* Si cumple con la condición */
		}
        else /* Se ejecuta esta instruccioón en caso de no ser verdadera la condición lógica matemática*/
		{
            banderas[V]=0; /* En el caso de no cumplir con la condición */
		}
    }

/***********************/
/* Muestra las banderas*/

	attrset(COLOR_PAIR(2 )); /* Permite cambiar el color a los textos */
	mvprintw(7,40,"N:%d Z:%d C:%d V:%d\n",banderas[N],banderas[Z],banderas[C],banderas[V]); /* Imprime el valor de las banderas en una interfaz, mediante el uso de la libreria curses */
	refresh(); /* Código sirve para ser uso de printw */
/***********************/
}





