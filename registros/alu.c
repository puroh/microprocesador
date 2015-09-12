#include <stdint.h>
#include <stdbool.h>

bool banderas[3];
void obtenerBandera(bool *bands)
{
    bands=banderas;
}

void ADD(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{
    *Rd=*Rm+*Rn;
     flag(Rd,Rm,Rn,banderas);
}
void SUB(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{
    *Rd=*Rm+((~*Rn)+1);
    flag(Rd,Rm,Rn,banderas);

}
void AND(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{

    *Rd=*Rm&*Rn;
    flag(Rd,Rm,Rn,banderas);

}
void ORR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{

    *Rd=*Rm|*Rn;
    flag(Rd,Rm,Rn,banderas);

}
void EOR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn)
{

    *Rd=*Rm^*Rn;
    flag(Rd,Rm,Rn,banderas);

}
void MOV(uint32_t *Rm,uint32_t *Rn)
{

    *Rm=*Rn;

}
void CMP(uint32_t *Rm,uint32_t *Rn)
{
    uint32_t R;
    R=*Rm+((~*Rn)+1);
    flag(&R,Rm,Rn,banderas);
}


