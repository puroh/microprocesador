#include <stdint.h>
#include <stdio.h>
#include "flags.h"
#include "alu.h"
#include <curses.h>

uint32_t H=2147483648UL;

void flag(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn,bool *banderas,uint8_t *compar)// Función que no retorna, pero determina el valor de las banderas en la dirección Rd 
{
	if(*Rd>=((1<<31)))
	{
        banderas[N]=1; //Vale 1 la bandera negativa si cumple con la condición 
	}
    else // Se ejecuta esta instruccioón en caso de no ser verdadera la condición lógica matematica
	{
        banderas[N]=0; // Vale cero la bandera negativa en caso de no cumplir con la primera condición 
	}
    if(!*Rd) // Se establece que si es diferente se determina la bandera de ceros 
	{
        banderas[Z]=1; // Para cuando cumple con la condición la bandera de ceros es 1
	}
    else // Se ejecuta esta instruccioón en caso de no ser verdadera la condición lógica matemática
	{
		banderas[Z]=0; // En caso de no cumplir con la condición la bandera de ceros sera 0
	}
    if(*compar==0) // Compara la variable igual a cero, para saber si se ha modificado todas las banderas 
	{   
        if(( (*Rm>=H)&&(*Rn<H)&&(*Rd<H)) || ((*Rn>=H)&&(*Rm<H)&&(*Rd<H)) || ((*Rm>=H)&&(*Rn>=H)) ) // Condición lógica matemática que determina si hay bandera Carry
		{
			banderas[C]=1; // Si cumple con la condición es carry es 1 
		}
        else // Se ejecuta esta instruccioón en caso de no ser verdadera la condición lógica matemática
		{
            banderas[C]=0; // En el caso de no cumplir con la condición el carry es 0
		}
    }
    if(*compar==0) // Compara la variable igual a cero, para saber si se ha modificado todas las banderas 
	{
        if((*Rm&(H))==(*Rn&H)) // Si los bits mas significativo de Rm y Rn son iguales
        {
            if((*Rm&H)!=(*Rd&H))	// Si los bits mas significativos de Rd y Rn son diferentes
            {
                banderas[V]=1; // Si cumple con la condición la bandera de sobreflujo es 1
            }
        }
        else // Se ejecuta esta instruccioón en caso de no ser verdadera la condición lógica matemática
		{
            banderas[V]=0; // En el caso de no cumplir con la condición la bandera de sobreflujo sera 0
		}
	}

// Muestra las banderas

	attrset(COLOR_PAIR(2 )); // Permite cambiar el color a los textos 
	mvprintw(7,40,"N:%d Z:%d C:%d V:%d",banderas[N],banderas[Z],banderas[C],banderas[V]); // Imprime el valor de las banderas en una interfaz, mediante el uso de la libreria curses 
	refresh(); // Código que sirve para ser uso de printw 
}






