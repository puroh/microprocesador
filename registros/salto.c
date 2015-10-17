#include <stdint.h>
#include <stdio.h>
#include "flags.h"
#include "alu.h"
#include <stdbool.h>
#include <curses.h>

bool banderas[4];
uint32_t LR;

void B(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto en una direccion especifica 
{
   *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion 
}
void BEQ(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera Z 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if(banderas[Z]==1) //Condicion de salto para BEQ 
	{
       *pc+= 2*valor; //Redirecciona el contador Pc según la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BNE(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera Z 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if(banderas[Z]==0) //Condicion de salto para BNE 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc según la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion
    }
}
void BCS(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera C 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if(banderas[C]==1) //Condicion de salto para BCS 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BCC(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera C 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if(banderas[C]==0) //Condicion de salto para BCC 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instruccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion
    }
}
void BMI(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera N 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado
    if(banderas[N]==1) //Condicion de salto para BMI 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BPL(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera N 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if(banderas[N]==0) //Condicion de salto para BPL 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion
    }
}
void BVS(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera V 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado
    if(banderas[V]==1) //Condicion de salto para BVS 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BVC(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera V 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado
    if(banderas[V]==0) //Condicion de salto para BVC 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BHI(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera C y Z 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if((banderas[C]==1)&&(banderas[Z]==0)) //Condicion de salto para BHI 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion
    }
}
void BLS(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera C o Z 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if((banderas[C]==0)&&(banderas[Z]==1)) //Condicion de salto para BLS 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BGE(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta que la bandera N == V 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if(banderas[N]==banderas[V]) //Condicion de salto para BGE 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BLT(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta que la bandera N != V 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if(banderas[N]!=banderas[V]) //Condicion de salto para BLT 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion
    }
    else //En caso contrario realiza la siguiente operacion
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BGT(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera Z y N == V 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if(banderas[Z]==0) //Condicion de salto para BGT 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BLE(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto teniendo en cuenta la bandera Z y N != V 
{
    obtenerBandera(banderas); //Obtiene el valor de la bandera para posteriormente ser evaluado 
    if((banderas[Z]==0)&&(banderas[N]==banderas[V])) //Condicion de salto para BLE 
	{
        *pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion 
    }
    else //En caso contrario realiza la siguiente operacion 
	{
        *pc+=2; //Redirecciona el contador Pc segun la instrucccion 
    }
}
void BAL(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza siempre un salto el cual no tiene condición para realizarlo
{
    pc+= 2*valor; //Redirecciona el contador Pc segun la instrucccion
}
void BL(uint32_t *pc,uint32_t valor) //Funcion que no retorna pero realiza un salto hasta la instruccion en LR 
{
    LR=*pc+2; //LR toma el valor de la instruccion que tenga PC sumandole 2 posiciones
    *pc+=valor*2; //Redirecciona el contador Pc segun la instrucccion 
    mvprintw(6,40,"LR:%d",LR); //Imprime en pantalla el valor de LR haciendo uso de la libreria curses 
}
void BX(uint32_t *pc) //Funcion que no retorna pero realiza un salto a una direccion especifica por un registro 
{
	*pc=LR; //El contador Pc toma el valor de la instrucción donde se encuentre LR
}
