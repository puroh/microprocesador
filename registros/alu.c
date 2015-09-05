#include <stdint.h>

void ADD(uint32_t *Rm,uint32_t *Rn)
{
    *Rm=*Rm+*Rn;
    flag(Rm);
}
void SUB(uint32_t *Rm,uint32_t *Rn)
{
    *Rm=*Rm+((~*Rn)+1);

}
void AND(uint32_t *Rm,uint32_t *Rn)
{

    *Rm=*Rm&*Rn;

}
void ORR(uint32_t *Rm,uint32_t *Rn)
{

    *Rm=*Rm|*Rn;

}
void EOR(uint32_t *Rm,uint32_t *Rn)
{

    *Rm=*Rm^*Rn;

}
void MOV(uint32_t *Rm,uint32_t *Rn)
{

    Rn=Rm;

}

