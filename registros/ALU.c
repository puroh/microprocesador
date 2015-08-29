#include <stdint.h>
void ADD(uint32_t *Rm,uint32_t *Rn){
    uint8_t C=0,Z=0,N=0,V=0;

    *Rm=*Rm+*Rn;
    if((*Rm<2147483648)&&(*Rn<2147483648||*Rn>=2147483648)){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);

}
void SUB(uint32_t *Rm,uint32_t *Rn)
{
     uint8_t C=0,Z=0,N=0,V=0;

    *Rm=*Rm-(~*Rn+1);
    if(*Rm==~*Rn){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);

}
void AND(uint32_t *Rm,uint32_t *Rn)
{
     uint8_t C=0,Z=0,N=0,V=0;

    *Rm=*Rm&*Rn;
    if(*Rm<2147483648&&(*Rn<2147483648||*Rn>=2147483648)){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);

}
void ORR(uint32_t *Rm,uint32_t *Rn)
{
     uint8_t C=0,Z=0,N=0,V=0;

    *Rm=*Rm|*Rn;
    if(*Rm<2147483648&&(*Rn<2147483648||*Rn>=2147483648)){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);

}
void EOR(uint32_t *Rm,uint32_t *Rn)
{
     uint8_t C=0,Z=0,N=0,V=0;

    *Rm=*Rm^*Rn;
    if(*Rm<2147483648&&(*Rn<2147483648||*Rn>=2147483648)){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);

}
void MOV(uint32_t *Rm,uint32_t *Rn)
{
    uint8_t C=0,Z=0,N=0,V=0;
    Rn=Rm;//Rm lo manda a Rn
    if(*Rm<2147483648&&(*Rn<2147483648||*Rn>=2147483648)){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);
}

