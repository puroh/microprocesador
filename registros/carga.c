
#include <stdint.h>
#include <stdbool.h>
#include "ram.h"
#include <curses.h>
//carga y almacenamineto
uint32_t  offset_addr;/*variable global */
/*
void LDR(uint32_t imm,uint32_t *registros,uint32_t *memory)//Rn =direciones de los registros
	{		
		
		if ((imm<<2)>5)
			{
			
			//Rt=memU[offset_addr,4];falta reconocer lo de 5 y 8
			memory[MEMORIA-((address/4)+2)]=registros[offset_addr];
			}
		else
			{
			imm=(imm<<2);
			offset_addr=Rn[n]+*imm;
			
			}
	}
//memU va a la direccion de la memoria ram, offset va  al posicion y sacaa cuatro valores 

void LDRB (uint32_t Rt,uint32_t Rn,uint32_t Rm,uint32_t imm,uint32_t *registros,uint32_t *memory)
	{
	imm=imm|31;
	if (Rm==0)
		{		
		offset_addr=Rn+&imm;
		Rt=menU[offset_addr,1];
	}else{
		offset_addr=Rm+Rn;
		Rt=menU[offset_addr,1];		
		}
	}


void LDRH (uint32_t Rt,uint32_t Rn,uint32_t imm,uint32_t *registros,uint32_t *memory)
	{
	if (imm!=0)
		{
		imm=(imm<<1)|31; 
		offset_addr=Rn+&imm;
		Rt=menU[offset_add,2];
	}else{
		imm=imm|31;
		offset_addr=Rn+&imm;
		Rt=menU[offset_add,2]	;	
		}	
	
	}	

void LDRSB (uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *registros,uint32_t *memory)
	{	
	uint32_t c;
	if(*Rm>=(1<<31))
			{	
			c=(~0);		
			offset_addr=Rn+Rm;
			offset_addr=offset_addr&c;
			Rt=menU[offset_add,2];
			}
	else
			{
			c=(~1);
			offset_addr=Rn+Rm;
			offset_addr=offset_addr&c;
			Rt=menU[offset_add,2];
			}
	}

void LDRSH (uint32_t Rt,uint32_t Rn,uint32_t Rm,uint32_t *registros,uint32_t *memory)
	{
	
	
	}

void STR (uint32_t Rt,uint32_t Rn,uint32_t imm, uint32_t Rm,uint32_t Sp,uint32_t *registros,uint32_t *memory);

void STRB (uint32_t Rt,uint32_t Rn,uint32_t imm,uint32_t Rm,uint32_t *registros,uint32_t *memory);

void STRH (uint32_t Rt,uint32_t Rn,uint32_t imm,uint32_t Rm,uint32_t *registros,uint32_t *memory);
*/

