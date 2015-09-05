#include <stdint.h>
#include <stdbool.h>
#include "alu.h"
void flag(uint32_t *Rm){
uint32_t x;
x=1;
bool flags[3];

if(((*Rm<<32)>>32)&1==1)
    flags[N]=1;
else
    flags[N]=0;

if(!*Rm)
    flags[Z]=1;
else
    flags[Z]=0;

if(*Rm>(x<<32))
    flags[C]=1;
else
    flags[C]=0;


move(6,15);
printw("signo %d zero %d acarreo %d\n",flags[N],flags[Z],flags[C]);
}
