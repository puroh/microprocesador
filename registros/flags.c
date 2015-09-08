#include <stdint.h>
#include <stdbool.h>
#include "alu.h"
void flag(uint32_t *Rm) //Se crea una serie de condiciones para determinar las banderas de cualquier función
{
	uint32_t x;
	x=1;
	bool flags[3];
	if(((*Rm<<32)>>32)&1==1) //Evalua para determinar el valor de la bandera N
	{
		flags[N]=1;
	}
	else
	{
		flags[N]=0;
	}
	if(!*Rm) //Evalua para determinar el valor de la bandera Z
	{
		flags[Z]=1;
	}
	else
	{
		flags[Z]=0;
	}
	if(*Rm>(x<<32)) //Evalua para determinar el valor de la bandera C
	{
		flags[C]=1;
	}
	else
	{
		flags[C]=0;
	}
	move(6,15);
	printf("signo %d zero %d acarreo %d\n",flags[N],flags[Z],flags[C]); //Imprime en pantalla el valor de las banderas según las condiciones establecidas anteriormente.
}
