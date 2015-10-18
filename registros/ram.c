#include <stdint.h>
#include "ram.h"
#include <curses.h>
#include "flags.h"
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
    uint8_t address;
    uint8_t i=0;
    if(registros[13]>=255){
    (registros[13])--;}
    address=registros[13]-(4*bitcount(res));


    for(i=0;i<16;i++){
        if(1&(res[8]|res[9]|res[10]|res[11]|res[12]|res[15])){
        registros[13]+=(4*bitcount(res));
        break;
        }
		if( (1  & res[i])!= 0 ){

            memory[MEMORIA-((address/4)+2)]=registros[i];

			address=address+4;
			}
		}
	registros[13]-=(4*bitcount(res));
}
void POP(uint32_t *registros,uint32_t *memory,uint8_t *res) //Funcion POP que permite organizar los datos
{
     uint8_t address;
    uint8_t i=0;

    address=registros[13];
    for(i=0;i<16;i++){
        if(1&(res[8]|res[9]|res[10]|res[11]|res[12]|res[14])){
        registros[13]-=(4*bitcount(res));
        break;
        }
		if( (1 & res[i])!= 0 ){
           registros[i]=memory[MEMORIA-((address/4)+2)];


			address=address+4;
			}
		}
	registros[13]+=(4*bitcount(res));
}
void mostrar_memoria(uint32_t *memoria , int tama) //Funcion que muestra el pantalla los valores guardados en menoria 
{
    int i,j,h,k,l;

	h=2;
	l=0;
	k=DIRMAXMEM;
	for (i=0 ; i<tama/8;i++)//filas
		{
		for (j=0; j<tama/8;j++)//columnas
			{
			move(i+7,j+h);//posiciona el cursor
			attron(COLOR_PAIR(1));
			printw("%.2x",k);
			attron(COLOR_PAIR(2));
			printw(" : %.2X %.2X %.2X %.2X",(uint8_t)(memoria[l]>>24),(uint8_t)(memoria[l]>>16),(uint8_t)(memoria[l]>>8),(uint8_t)(memoria[l]));//Visualiza los valores guardados en memoria haciendo uso de la libreria curses
			k=k-4;
			l=l+1;
			h=h+18;			
			}
		h=2;
		}	


}

void inimemoria(uint32_t *memoria,int tama) //Funcion que inicializa la memoria
{
    int i; //Declaracion de variable para el ciclo for
    for(i=0;i<(tama);i++) //Comienza desde el valor maximo y va disminuyendo
    {
        memoria[i]= -1; 
    }
}


void PUSHINTERRUPT(uint32_t *registros,uint32_t *memory,uint8_t *res)
{
    uint8_t address;
    bool bande[4];
    uint32_t bd;

    obtenerBandera(bande);
    bd=((bande[C])<<3)+((bande[Z])<<2)+((bande[N])<<1)+bande[V];

    uint8_t i=0;
    if(registros[13]>255){
    (registros[13])--;}

    address=registros[13]-(4*bitcount(res)+4);

    for(i=0;i<16;i++){
		if( (1  & res[i])!= 0 ){
        memory[MEMORIA-((address/4)+2)]=registros[i];
			address=address+4;
			}
		}
		memory[MEMORIA-((address/4)+2)]=bd;
	registros[13]-=(4*bitcount(res))+4;
	}

void POPINTERRUPT(uint32_t *registros,uint32_t *memory,uint8_t *res)
{
    uint8_t address;
    uint8_t i=0;

    bool f[4];
    uint32_t bd;

    address=registros[13];
    for(i=0;i<16;i++){
		if( (1 & res[i])!= 0 ){
           registros[i]=memory[MEMORIA-((address/4)+2)];


			address=address+4;
			}
		}
		bd = memory[MEMORIA-((address/4)+2)];
		f[C]=(1&bd>>3);
		f[Z]=(1&bd>>2);
		f[N]=(1&bd>>1);
		f[V]=(1&bd);
		SalvarBanderas(f);

	registros[13]+=(4*(bitcount(res)+1));
}

/*

fila 11
columna 20

*/
