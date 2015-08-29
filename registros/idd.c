#include <stdint.h>
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
}
