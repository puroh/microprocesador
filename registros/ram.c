#include <stdint.h>
#include <stdbool.h>
#include "flags.h"

void memA(uint32_t adress,int variable, uint32_t *R, uint32_t )
	{
		/*en el disp mostrar lo que guarda en la ram*/
		/*adress es la direccion en la que guarda*/ 
		/*variable el tamaño en el espacio que se va a guardar, guarda en 4 espacios de la memoria(4 bytes), lo mismo para 2*/
		/* *R los datos que voy a  almacenar en la ram*/
		
		unit32_t mem[16]={15}; /**/
		mem[adress]=*R;   /*igualación que permite ubicar la varible mem en la dirección address, en donde a partir de ahí se guarden los registros*/
	}

void push(uint32_t arre_r[30])  /*mandar arreglo con los primeros 8(0,7) registros y el 15(14), si no error*/
{
	int i, adress,memA;  /*se declaran algunas variables que permitiran el almacenamiento de los rtegistros*/
	uint32_t R[15];    /*contiene los registros a almacenar*/
	obtenerregistros(R);   /*exporta el valor de los registros*/
	adress=sp-4*Bitcount(registers);  /*permite ubicar la variable adress en la posición en donde se comenzara a almacenar los registros, de a 4 bytes por registro*/
	for( i=0;i<15;i++)
	{
		if (registros1[i]==1)   
		{
			memA(adress,4,&R[i]);
			adress=adress+4;			
		}
	sp=sp-4*Bitcount(registers);
	}
}
