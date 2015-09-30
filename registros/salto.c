#include <stdint.h>
#include <stdio.h>
#include "flags.h"
#include "alu.h"
#include <stdbool.h>
#include <curses.h>


bool banderas[4];

void B(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto en una dirección especifica */
{
   *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
}
void BEQ(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera Z */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[Z]==1) /* Condición de salto para BEQ */
	{
       *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BNE(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera Z */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[Z]==0) /* Condición de salto para BNE */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BCS(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera C */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[C]==1) /* Condición de salto para BCS */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BCC(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera C */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[C]==0) /* Condición de salto para BCC */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BMI(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera N */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[N]==1) /* Condición de salto para BMI */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BPL(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera N */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[N]==0) /* Condición de salto para BPL */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BVS(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera V */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[V]==1) /* Condición de salto para BVS */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BVC(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera V */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[V]==0) /* Condición de salto para BVC */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BHI(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera C y Z */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if((banderas[C]==1)&&(banderas[Z]==0)) /* Condición de salto para BHI */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BLS(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera C o Z */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if((banderas[C]==0)&&(banderas[Z]==1)) /* Condición de salto para BLS */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BGE(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta que la bandera N == V */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[N]==banderas[V]) /* Condición de salto para BGE */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BLT(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta que la bandera N != V */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[N]!=banderas[V]) /* Condición de salto para BLT */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BGT(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera Z y N == V */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if(banderas[Z]==0) /* Condición de salto para BGT */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BLE(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza un salto teniendo en cuenta la bandera Z y N != V */
{
    obtenerBandera(banderas); /* Obtiene el valor de la bandera para posteriormente ser evaluado */
    if((banderas[Z]==0)&&(banderas[N]==banderas[V])) /* Condición de salto para BLE */
	{
        *pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
    }
    else /* En caso contrario realiza la siguiente operación */
	{
        *pc+=2; /* Redirecciona el contador Pc según la instruccción */
    }
}
void BAL(uint32_t *pc,uint32_t valor) /* Función que no retorna, pero realiza siempre un salto el cual no tiene condición para realizarlo*/
{
    pc+= 2*valor; /* Redirecciona el contador Pc según la instruccción */
}
void BL(uint32_t *pc,uint32_t valor,uint32_t *LR) /* Función que no retorna, pero realiza un salto hasta la instrucción en LR */
{
    *LR=*pc+2; /* LR toma el valor de la instrucción que tenga PC sumandole 2 posiciones */
    *pc+=valor*2; /* Redirecciona el contador Pc según la instruccción */
    mvprintw(6,40,"LR:%d",LR); /* IMprime en pantalla el valor de LR haciendo uso de la libreria curses */
}
void BX(uint32_t *pc,uint32_t *LR) /* Función que no retorna, pero realiza un salto a una dirección especifica por un registro */
{
   *pc=*LR; /* El contador Pc toma el valor de la instrucción donde se encuentre LR*/
}
