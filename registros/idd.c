#include <stdint.h>
<<<<<<< HEAD
uint32_t LSLS(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	Rd=Rm<<Rn;
	return Rd;
}
uint32_t LSRS(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	Rd=Rm>>Rn;
	return Rd;
}
uint32_t ROR(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	Rd=Rm<<(32-Rn);
	Rm=Rm>>Rn;
	Rd=Rm|Rd;
    return Rd;
}
uint32_t BIC(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	Rd &= ~Rm;
	return Rd;
}
uint32_t MVN(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	Rd=~Rm;
	return Rd;
}uint32_t RSBS(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	Rd=0-Rn;
	return Rd;
}
void NOP()
{
=======
void LSLS(uint32_t *Rm,uint32_t *Rn){
  *Rm=*Rm<<*Rn;
}
void LSRS(uint32_t *Rm,uint32_t *Rn){
  *Rm=*Rm>>*Rn;
}
void ROR(uint32_t *Rm,uint32_t *Rn){
   *Rm=*Rm>>32;
   *Rn=*Rn<<32;
   *Rm=*Rm||*Rn;
}
void ASRS(uint32_t *Rm,uint32_t *Rn){
   *Rn=~0<<(32-*Rn);
   *Rm=(*Rm>>1)|*Rn;
>>>>>>> 617f899605fcc84aef36460062dea83e6bd8de51
}
uint32_t REV(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
 
}

