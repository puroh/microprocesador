#include <stdint.h>
#include "alu.h"
#include <stdint.h>
#include <stdbool.h>
#include "flags.h"
#include <curses.h>

void flag(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn,bool *banderas) /* Define las direcciones de las variables que deteremina el valor de la banderas (C,Z y N) */
{
int p=0;
	if(*Rd>((1<<31)-1)) 
	{
		banderas[N]=1;
	}
	else
	{
		banderas[N]=0;
	}
	if(!*Rd)
	{
		banderas[Z]=1;
	}
	else
	{
		banderas[Z]=0;
	}
	if(((*Rm>=(1<<31)-1)^(*Rn<0))&&((*Rn>=(1<<31)-1)^(*Rm<0)))
	{
		banderas[C]=1;
	}
	else
	{
		banderas[C]=0;
	}
	if((((*Rm&(1<<31))==(1<<31)&&(*Rn&(1<<31))==(1<<31))&&((*Rd&(1<<31))==0))&&(((*Rm&(1<<31))==0&&(*Rn&(1<<31))==0&&((*Rd&(1<<31))==(1<<31)))))
	{
		banderas[V]=1;
	}
	else
	{
		banderas[V]=0;
	}
	attrset(COLOR_PAIR(2 ));
	printw("p:%d N:%d Z:%d C:%d V:%d\n",p,banderas[N],banderas[Z],banderas[C],banderas[V]);
	refresh();
/*
if (p==0){/*add*
	attrset(COLOR_PAIR(2 ));
  	mvprintw(3,41,"p:%d N:%d Z:%d C:%d V:%d\n",p,banderas[N],banderas[Z],banderas[C],banderas[V]);
	refresh();
	}
if(p==1){/*SUB*
	attrset(COLOR_PAIR(2 ));
  	mvprintw(8,41,"aaN:%d Z:%d C:%d V:%d\n",banderas[N],banderas[Z],banderas[C],banderas[V]);
	refresh();
	}
if(p==2){/*AND*
	attrset(COLOR_PAIR(2 ));
  	mvprintw(18,41,"N:%d Z:%d C:%d V:%d\n",banderas[N],banderas[Z],banderas[C],banderas[V]);
	refresh();
	}
if(p==3){/*ORR*
  	mvprintw(21,41,"N:%d Z:%d C:%d V:%d\n",banderas[N],banderas[Z],banderas[C],banderas[V]);
	refresh();
	}
if(p==4){/*EOR*
  	mvprintw(27,81,"N:%d Z:%d C:%d V:%d\n",banderas[N],banderas[Z],banderas[C],banderas[V]);
	refresh();
	}
if(p==5){/*MOV*
	mvprintw(3,81,"N:%d Z:%d C:%d V:%d\n",banderas[N],banderas[Z],banderas[C],banderas[V]);
	refresh();
	}
if(p==6){/*MOV*
	mvprintw(14,81,"N:%d Z:%d C:%d V:%d\n",banderas[N],banderas[Z],banderas[C],banderas[V]);
	refresh();
	}
p++;
if(p>6){
	p=0;
}*/
}
