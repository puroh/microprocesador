#include <stdint.h>
#include <stdio.h>
#include "flags.h"
#include "alu.h"
#include <curses.h>

void flag(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn,bool *banderas,uint8_t *compar){
if(*Rd>((1<<31)))
    banderas[N]=1;
else
    banderas[N]=0;

if(!*Rd)
    banderas[Z]=1;
else
    banderas[Z]=0;
    if(*compar==0){
         if((((*Rm<<31))==(1<<31)&&((*Rn&(1<<31))==(1<<31)))&&(((*Rd&(1<<31))==0))||(((*Rn<<31))==(1<<31)&&((*Rm&(1<<31))==(1<<31)))&&(((*Rd&(1<<31))==0))||(((*Rn&(1<<31))==(1<<31))&&((*Rm&(1<<31))==(1<<31))&&(((*Rd&(1<<31))==(1<<31)))))
            banderas[C]=1;
        else
            banderas[C]=0;
    }
    if(*compar==0){
        if((((*Rm&(1<<31))==(1<<31)&&(*Rn&(1<<31))==(1<<31))&&(((*Rd&(1<<31))==0)))||(((*Rm&(1<<31))==(0)&&(*Rn&(1<<31))==(0))&&(((*Rd&(1<<31))==(1<<31))))){

            banderas[V]=1;}

        else
            banderas[V]=0;
    }
	attrset(COLOR_PAIR(2 ));
	mvprintw(3,40,"N:%d Z:%d C:%d V:%d\n",banderas[N],banderas[Z],banderas[C],banderas[V]);
	refresh();
}
