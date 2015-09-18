#include <stdint.h>
<<<<<<< HEAD
#include <stdio.h>
=======
>>>>>>> master
#include "flags.h"
#include "alu.h"
#include <stdbool.h>

<<<<<<< HEAD
bool banderas[4];
uint32_t LR;

    obtenerBandera(banderas);


void B(uint32_t *pc,uint32_t valor)
{
   *pc+= 2*valor;
}
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
    }
    else{
        *pc+=2;
=======
bool banderas[3];
obtenerBandera(banderas);

void B(uint32_t *pc,uint32_t valor)
{
    *pc+=valor<<1;
}
void BEQ(uint32_t *pc,uint32_t valor)
{
	if(banderas[Z]==1)
	{
		pc+=valor<<1;
	}
}
void BNE(uint32_t *pc,uint32_t valor)
{
    if(banderas[Z]==0)
	{
    }
}
void BCS(uint32_t *pc,uint32_t valor)
{
    if(banderas[C]==1)
	{
>>>>>>> master
    }
}
void BCC(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if(banderas[C]==0){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if(banderas[C]==0)
	{
>>>>>>> master
    }
}
void BMI(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if(banderas[N]==1){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if(banderas[N]==1)
	{
>>>>>>> master
    }
}
void BPL(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if(banderas[N]==0){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if(banderas[N]==0)
	{
>>>>>>> master
    }
}
void BVS(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if(banderas[V]==1){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if(banderas[V]==1)
	{
>>>>>>> master
    }
}
void BVC(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if(banderas[V]==0){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if(banderas[V]==0)
	{
>>>>>>> master
    }
}
void BHI(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if((banderas[C]==1)&&(banderas[Z]==0)){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if((banderas[C]==1)&&(banderas[Z]==0))
	{
>>>>>>> master
    }
}
void BLS(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if((banderas[C]==0)&&(banderas[Z]==1)){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if((banderas[C]==0)&&(banderas[Z]==1))
	{
>>>>>>> master
    }
}
void BGE(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if(banderas[N]==banderas[V]){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if(banderas[N]==banderas[V])
	{
>>>>>>> master
    }
}
void BLT(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if(banderas[N]!=banderas[V]){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if(banderas[N]!=banderas[V])
	{
>>>>>>> master
    }
}
void BGT(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if(banderas[Z]==0){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if(banderas[Z]==0)
	{
>>>>>>> master
    }
}
void BLE(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
    if((banderas[Z]==0)&&(banderas[N]==banderas[V])){
        *pc+= 2*valor;
    }
    else{
        *pc+=2;
=======
    if((banderas[Z]==0)&&(banderas[N]==banderas[V]))
	{
>>>>>>> master
    }
}
void BAL(uint32_t *pc,uint32_t valor)
{
<<<<<<< HEAD
        *pc+= 2*valor;
}
void BL(uint32_t *pc,uint32_t valor)
{
     LR=*pc+2;
     *pc+=valor*2;
     printf("\nLR:%d\n",LR);
}
void BX(uint32_t *pc)
{
   *pc=LR;
=======

>>>>>>> master
}

