#include <stdint.h>
#include "alu.h"
<<<<<<< HEAD
#include <stdint.h>
#include <stdbool.h>
#include "flags.h"

void flag(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn,bool *banderas){

if(*Rd>((1<<31)-1))
    banderas[N]=1;
else
    banderas[N]=0;

if(!*Rd)
    banderas[Z]=1;
else
    banderas[Z]=0;

if(((*Rm>=(1<<31)-1)^(*Rn<0))&&((*Rn>=(1<<31)-1)^(*Rm<0)))
    banderas[C]=1;
else
    banderas[C]=0;

if((((*Rm&(1<<31))==(1<<31)&&(*Rn&(1<<31))==(1<<31))&&((*Rd&(1<<31))==0))&&(((*Rm&(1<<31))==0&&(*Rn&(1<<31))==0&&((*Rd&(1<<31))==(1<<31)))))
    banderas[V]=1;

else
    banderas[V]=0;

  printf("N:%d Z:%d C:%d V:%d\n",banderas[N],banderas[Z],banderas[C],banderas[V]);
=======
void flag(uint32_t *Rm) /*Se crea una serie de condiciones para determinar las banderas de cualquier función*/
{
	uint32_t x;
	x=1;
	bool flags[3];
	if(((*Rm<<32)>>32)&1==1) /*Evalua para determinar el valor de la bandera N*/
	{
		flags[N]=1;
	}
	else
	{
		flags[N]=0;
	}
	if(!*Rm) /*Evalua para determinar el valor de la bandera Z*/
	{
		flags[Z]=1;
	}
	else
	{
		flags[Z]=0;
	}
	if(*Rm>(x<<32)) /*Evalua para determinar el valor de la bandera C*/
	{
		flags[C]=1;
	}
	else
	{
		flags[C]=0;
	}
	move(6,15);
	printf("signo %d zero %d acarreo %d\n",flags[N],flags[Z],flags[C]); /*Imprime en pantalla el valor de las banderas según las condiciones establecidas anteriormente.*/
>>>>>>> master
}
