#include <stdint.h>
#include <stdbool.h>
#include "flags.h"

bool banderas[4];
uint8_t comp=0;
void ADD(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{
    *Rd=*Rm+*Rn;
    comp=0;
     flag(Rd,Rm,Rn,banderas,&comp);
}
void SUB(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{
    *Rd=*Rm+((~*Rn)+1);
    comp=0;
     flag(Rd,Rm,Rn,banderas,&comp);
}
void AND(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{

     *Rd=*Rm&*Rn;
     comp=1;
     flag(Rd,Rm,Rn,banderas,&comp);

}
void ORR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{

    *Rd=*Rm|*Rn;
    comp=1;
     flag(Rd,Rm,Rn,banderas,&comp);

}
void EOR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{

    *Rd=*Rm^*Rn;
    comp=1;
    flag(Rd,Rm,Rn,banderas,&comp);

}
void MOV(uint32_t *Rm,uint32_t *Rn)
{

    *Rm=*Rn;
    comp=2;
    flag(Rm,Rm,Rn,banderas,&comp);

}
void CMP(uint32_t *Rm,uint32_t *Rn)
{
    uint32_t R;
    R=*Rm+((~*Rn)+1);
    comp=0;
     flag(&R,Rm,Rn,banderas,&comp);
}
void ADCS(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{
    *Rd=*Rm+*Rn+banderas[C];
    comp=1;
     flag(Rd,Rm,Rn,banderas,&comp);
}
void CMN(uint32_t *Rm,uint32_t *Rn)
{
    uint32_t R;
    R=*Rm+*Rn;
    comp=0;
     flag(&R,Rm,Rn,banderas,&comp);
}
void SBC(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{
    *Rd=*Rm+((~*Rn)+1)+banderas[C];
     comp=0;
     flag(Rd,Rm,Rn,banderas,&comp);
}
void MOVS(uint32_t *Rm,uint32_t Rn)
{

    *Rm=Rn;
    comp=2;
    flag(Rm,Rm,&Rn,banderas,&comp);
}
void SUBS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn)
{
    *Rd=*Rm+((~Rn)+1);
    comp=0;
     flag(Rd,Rm,&Rn,banderas,&comp);
}
void ADDS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn)
{
    *Rd=*Rm+Rn;
    comp=0;
     flag(Rd,Rm,&Rn,banderas,&comp);
}
void LSL(uint32_t *Rm,uint32_t *Rn)
{
  *Rm=*Rm<<*Rn;
  comp=1;
  flag(Rm,Rm,Rn,banderas,&comp);
}
void LSR(uint32_t *Rm,uint32_t *Rn)
{
  *Rm=*Rm>>*Rn;
  comp=1;
  flag(Rm,Rm,Rn,banderas,&comp);
}
void ROR(uint32_t *Rm,uint32_t *Rn)
{
   *Rm=*Rm>>32;
   *Rn=*Rn<<32;
   *Rm=*Rm||*Rn;
   comp=1;
   flag(Rm,Rm,Rn,banderas,&comp);
}
void ASRS(uint32_t *Rm,uint32_t *Rn)
{
   *Rn=~0<<(32-*Rn);
   *Rm=(*Rm>>1)|*Rn;
   comp=1;
   flag(Rm,Rm,Rn,banderas,&comp);

}
void REV(uint32_t *Rm,uint32_t *Rn)
{
    *Rn=*Rm<<24;
    *Rn=*Rn|*Rm>>24;
    *Rm=*Rn|((((*Rm<<8)>>24)<<8)|(((*Rm<<16)>>24)<<16));
}
void REV16(uint32_t *Rm,uint32_t *Rn)
{
    *Rn=((*Rm<<24)>>16)|((*Rm<<16)>>24);
    *Rm=*Rn|(((*Rm>>24)<<16)|((*Rm>>16)<<24));
}
void BIC(uint32_t *Rm,uint32_t *Rn)
{
	*Rm &= ~*Rn;
	 comp=1;
     flag(Rm,Rm,Rn,banderas,&comp);
}
void MVN(uint32_t *Rm,uint32_t *Rn)
{
	*Rm=~*Rn;
	 comp=1;
     flag(Rm,Rm,Rn,banderas,&comp);
}
void RSBS(uint32_t *Rm,uint32_t *Rn)
{
	*Rm=(~*Rn)+1;
}
void NOP(void)
{
}
void TST(uint32_t *Rm,uint32_t *Rn)
{
     uint32_t R;
     R=*Rm&*Rn;
     comp=1;
     flag(&R,Rm,Rn,banderas,&comp);

}
void LSLS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn)
{
  *Rd=*Rm<<Rn;
  comp=1;
  flag(Rd,Rm,&Rn,banderas,&comp);
}
void LSRS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn)
{
  *Rd=*Rm>>Rn;
  comp=1;
  flag(Rm,Rm,&Rn,banderas,&comp);
}


void obtenerBandera(bool *bands)
{
    bands=banderas;
}
