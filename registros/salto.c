#include <stdint.h>
#include <stdio.h>
#include "flags.h"
#include "alu.h"
#include <stdbool.h>
#include <curses.h>


bool banderas[4];
uint32_t LR;

    obtenerBandera(banderas);


void B(uint32_t *pc,uint32_t valor)
{
   *pc+= 2*valor;
}
/* CORREGIR
void B(uint32_t *pc,uint32_t valor)
{
    *pc+=valor<<1;
}
*/


void BEQ(uint32_t *pc,uint32_t valor)
{
    if(banderas[Z]==1){
       *pc+= 2*valor;
    }
    else{
        *pc+=2;
    }


}
void BNE(uint32_t *pc,uint32_t valor)
{
    if(banderas[Z]==0){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
    }

}
void BCS(uint32_t *pc,uint32_t valor)
{
    if(banderas[C]==1){
        *pc+= 2*valor;
    }else{
        *pc+=2;
		bool banderas[3];
		obtenerBandera(banderas);
		}
}

void BCC(uint32_t *pc,uint32_t valor)
{

    if(banderas[C]==0){
        *pc+= 2*valor;
    }else{
        *pc+=2;    
    	}
}
void BMI(uint32_t *pc,uint32_t valor)
{
    if(banderas[N]==1){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;

    }
}
void BPL(uint32_t *pc,uint32_t valor)
{
    if(banderas[N]==0){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
    }
}
void BVS(uint32_t *pc,uint32_t valor)
{

    if(banderas[V]==1){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
    }
}
void BVC(uint32_t *pc,uint32_t valor)
{

    if(banderas[V]==0){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
    }
}
void BHI(uint32_t *pc,uint32_t valor)
{
    if((banderas[C]==1)&&(banderas[Z]==0)){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
    }
}
void BLS(uint32_t *pc,uint32_t valor)
{

    if((banderas[C]==0)&&(banderas[Z]==1)){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
    }
}
void BGE(uint32_t *pc,uint32_t valor)
{

    if(banderas[N]==banderas[V]){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;

    }
}
void BLT(uint32_t *pc,uint32_t valor)
{

    if(banderas[N]!=banderas[V]){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
    }
}
void BGT(uint32_t *pc,uint32_t valor)
{
    if(banderas[Z]==0){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;

    }
}
void BLE(uint32_t *pc,uint32_t valor)
{
    if((banderas[Z]==0)&&(banderas[N]==banderas[V])){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;

    }
}
void BAL(uint32_t *pc,uint32_t valor)
{
        *pc+= 2*valor;
}
void BL(uint32_t *pc,uint32_t valor)
{
     LR=*pc+2;
     *pc+=valor*2;
     printw("\nLR:%d\n",LR);
}
void BX(uint32_t *pc)
{
   *pc=LR;
}

