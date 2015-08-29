#include <stdint.h>
<<<<<<< HEAD:registros/alu.c
uint32_t ADD(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm+Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648)
	{
		C=1;
	}
    printf("\nC:%d\n",C);
    if(!Rd)
	{
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;
=======
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

>>>>>>> 617f899605fcc84aef36460062dea83e6bd8de51:registros/ALU.c
}
void SUB(uint32_t *Rm,uint32_t *Rn)
{
<<<<<<< HEAD:registros/alu.c
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm-Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648)
	{
        C=1;
	}
    printf("\nC:%d\n",C);
    if(!Rd)
	{
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;
=======
     uint8_t C=0,Z=0,N=0,V=0;

    *Rm=*Rm-(~*Rn+1);
    if(*Rm==~*Rn){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);

>>>>>>> 617f899605fcc84aef36460062dea83e6bd8de51:registros/ALU.c
}
void AND(uint32_t *Rm,uint32_t *Rn)
{
<<<<<<< HEAD:registros/alu.c
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm&Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648)
	{
        C=1;
	}
    printf("\nC:%d\n",C);
    if(!Rd)
	{
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;
=======
     uint8_t C=0,Z=0,N=0,V=0;

    *Rm=*Rm&*Rn;
    if(*Rm<2147483648&&(*Rn<2147483648||*Rn>=2147483648)){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);

>>>>>>> 617f899605fcc84aef36460062dea83e6bd8de51:registros/ALU.c
}
void ORR(uint32_t *Rm,uint32_t *Rn)
{
<<<<<<< HEAD:registros/alu.c
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm|Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648)
	{
        C=1;
	}
    printf("\nC:%d\n",C);
    if(!Rd)
	{
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;
=======
     uint8_t C=0,Z=0,N=0,V=0;

    *Rm=*Rm|*Rn;
    if(*Rm<2147483648&&(*Rn<2147483648||*Rn>=2147483648)){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);

>>>>>>> 617f899605fcc84aef36460062dea83e6bd8de51:registros/ALU.c
}
void EOR(uint32_t *Rm,uint32_t *Rn)
{
<<<<<<< HEAD:registros/alu.c
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm^Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648)
	{
        C=1;
	}
    printf("\nC:%d\n",C);
    if(!Rd)
	{
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;
=======
     uint8_t C=0,Z=0,N=0,V=0;

    *Rm=*Rm^*Rn;
    if(*Rm<2147483648&&(*Rn<2147483648||*Rn>=2147483648)){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
        Z=1;
    }
    printf("\nZ:%d\n",Z);

>>>>>>> 617f899605fcc84aef36460062dea83e6bd8de51:registros/ALU.c
}
void MOV(uint32_t *Rm,uint32_t *Rn)
{
    uint8_t C=0,Z=0,N=0,V=0;
<<<<<<< HEAD:registros/alu.c
    Rd=Rm<<Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648)
	{
        C=1;
	}
    printf("\nC:%d\n",C);
    if(!Rd)
	{
=======
    Rn=Rm;//Rm lo manda a Rn
    if(*Rm<2147483648&&(*Rn<2147483648||*Rn>=2147483648)){
        C=1;}
    printf("\nC:%d\n",C);
    if(!*Rm){
>>>>>>> 617f899605fcc84aef36460062dea83e6bd8de51:registros/ALU.c
        Z=1;
    }
    printf("\nZ:%d\n",Z);
}

