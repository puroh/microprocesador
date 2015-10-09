#include <stdint.h>
#include "ram.h"
#include <curses.h>
uint8_t bitcount(uint8_t *R) //Determina cuantos 1 hay en los datos que contienen los registros
{
	uint8_t i,contador=0; //Declaracion e inicializacion de variables para el ciclo que determinara la cantidad de 1 que contiene cada registro
	for(i=0;i<16;i++) //Ciclo for que permite determina cuantos unos hay en cada registro
	{
		if((1 & R[i])!=0) //Condicion que permite establecer que si el valor en el registro es diferente de cero es porque es uno y el contador se incrementa
		{
			contador++; //Incremento del contador
		}
    }
    return contador; //Retorna el valor del contador, el cual determino la cantidad de unos que hay en los registros
}
void PUSH(uint32_t *registros,uint32_t *memory,uint8_t *res) //Funcion PUSH que permite ir almacenando los datos
{
    uint8_t address; //Declaracion de variables
    uint8_t i=0;
    (registros[12])--;
    address=registros[12]-(4*bitcount(res));
    for(i=0;i<15;i++)
	{
		if( (1  & res[i])!= 0 )
		{
            memory[MEMORIA-((address/4)+2)]=registros[i];
			address=address+4;
		}
	}
	registros[12]-=(4*bitcount(res));
}
void POP(uint32_t *registros,uint32_t *memory,uint8_t *res) //Funcion POP que permite organizar los datos
{
    uint8_t address;
    uint8_t i=0;
    address=registros[12];
    for(i=0;i<7;i++)
	{
		if( (1 & res[i])!= 0 )
		{
			registros[i]=memory[MEMORIA-((address/4)+2)];
			address=address+4;
		}
	}
	registros[12]+=(4*bitcount(res));
}
void mostrar_memoria(uint32_t *memoria , int tama) //Funcion que muestra el pantalla los valores guardados en menoria 
{
    int i,j,h,k,l;

        h=0;
		l=0;
		k=DIRMAXMEM;
	    for(i=0;i<tama/8;i++)
        {
			for(j=0;j<tama/8;j++)
			{
				h+=1;
				mvprintw(14+i,5+h,"%.2X : %.2X %.2X %.2X %.2X",k,(uint8_t)(memoria[l]>>24),(uint8_t)(memoria[l]>>16),(uint8_t)(memoria[l]>>8),(uint8_t)(memoria[l]));//Visualiza los valores guardados en memoria haciendo uso de la libreria curses
				l=l+1;
				k=k-4;
        		refresh();

        }
		//tama = 64
		h=0;
	}
}

void inimemoria(uint32_t *memoria,int tama) //Funcion que inicializa la memoria
{
    int i; //Declaracion de variable para el ciclo for
    for(i=0;i<(tama*4);i++) //Comienza desde el valor maximo y va disminuyendo
    {
        memoria[i]= -1; 
    }
}


/*
void inicia_ram(void)
{
	
    uint32_t registros[15]={10,11,12,13,14,15,250,251,0,0,0,0,1,0,0};
	registro[12] es SP
    uint32_t memoria[MEMORIA];

    registros[12]= DIRMAXMEM+1;
	inimemoria(memoria,MEMORIA);
	
    mvprintw(11,20,"\t\tmemoria inicializada");
	refresh();
    mostrar_memoria(memoria,MEMORIA);

    PUSH(registros,memoria,"R2,R3,R4,R5");

    mostrar_memoria(memoria,MEMORIA);

    POP(registros,memoria,"R0,R1,R2,R3");

    mostrar_memoria(memoria,MEMORIA);

    mvprintw(23,20,"Valor de registros %.8X %.8X  %.8X  %.8X",registros[0],registros[1],registros[2],registros[3]);

    mvprintw(25,20,"valor de SP %.8X ",registros[12]);
	refresh();

fila 11
columna 20
Disp();
}*/
