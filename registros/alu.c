#include <stdint.h>
#include <stdbool.h>

bool banderas[3];
void obtenerBandera(bool *bands)
{
    bands=banderas;
}
void ADD(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) /* Definen las direcciones que contiene los valores a operar y la dirección en donde se almacenara dicho resultado en este caso una suma */
{
    *Rd=*Rm+*Rn; /* Suma entre las direcciones que contiene  el valor de los registros a operar */
	flag(Rd,Rm,Rn,banderas);
}
void SUB(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) /* Definen las direcciones que contiene los valores a operar y la dirección en donde se almacenara dicho resultado en este caso una resta */
{
    *Rd=*Rm+((~*Rn)+1); 
    flag(Rd,Rm,Rn,banderas);
}
void AND(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) /* Definen las direcciones que contiene los valores a operar y la dirección en donde se almacenara dicho resultado en este caso una multiplicación */
{
    *Rd=*Rm&*Rn; /* Multiplicación entre las direcciones que contiene  el valor de los registros a operar */
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
void MOV(uint32_t *Rm,uint32_t *Rn) /* Defienen las diracciones que contiene la dirección del valor a mover como también la dirección a donde se desea almacenar */
{
    *Rm=*Rn; /* Igualación de las direcciones para copiar el valor de Rn en la dirección de Rm */
}
void CMP(uint32_t *Rm,uint32_t *Rn)
{
    uint32_t R;
    R=*Rm+((~*Rn)+1);
    flag(&R,Rm,Rn,banderas);
}


