#include <stdint.h>
uint32_t ADD(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm+Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648){
        C=1;}
    printf("\nC:%d\n",C);
    if(!Rd){
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;

}
uint32_t SUB(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm-Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648){
        C=1;}
    printf("\nC:%d\n",C);
    if(!Rd){
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;

}
uint32_t AND(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm&Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648){
        C=1;}
    printf("\nC:%d\n",C);
    if(!Rd){
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;

}
uint32_t ORR(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm|Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648){
        C=1;}
    printf("\nC:%d\n",C);
    if(!Rd){
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;

}
uint32_t EOR(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm^Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648){
        C=1;}
    printf("\nC:%d\n",C);
    if(!Rd){
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;

}
uint32_t MOV(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
    uint8_t C=0,Z=0,N=0,V=0;
    Rd=Rm<<Rn;
    if(Rm>=2147483648&&Rn<2147483648&&Rd<2147483648){
        C=1;}
    printf("\nC:%d\n",C);
    if(!Rd){
        Z=1;
    }
    printf("\nZ:%d\n",Z);
    return Rd;
}

