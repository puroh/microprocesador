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
    uint8_t i=0; // Declaracion de variable para el ciclo for
    (registros[12])--; //
    address=registros[12]-(4*bitcount(res)); // Address guarda la posicion en la que se van a guardar los datods en ram r
    for(i=0;i<15;i++) // Condicion en donde comenzara a guardar los datos 
	{
		if( (1  & res[i])!= 0 ) 
		{
            memory[MEMORIA-((address/4)+2)]=registros[i]; // Posicion en donde almacenara la memoria el dato del registro[i]
			address=address+4; // Modifica la memoria maxima disponible y cuadra el sp
		}
	}
	registros[12]-=(4*bitcount(res)); // Baja el Sp 4 posicion debido a que el almacenamiento se realizqa de forma descendente
}
void POP(uint32_t *registros,uint32_t *memory,uint8_t *res) //Funcion POP que permite organizar los datos
{
    uint8_t address; // Declaracion de variable la cual sera el Sp
    uint8_t i=0; // Declaracion de variable para el ciclo for
    address=registros[12]; //declara el registro 12 como sp
    for(i=0;i<7;i++) // Ciclos de los espacios de memoria en donde se esta guardando la informacion
	{
		if( (1 & res[i])!= 0 )
		{
			registros[i]=memory[MEMORIA-((address/4)+2)]; // Posicion en donde almacenara la memoria el dato del registro[i]
			address=address+4; // // Modifica la memoria maxima disponible y cuadra el sp
		}
	}
	registros[12]+=(4*bitcount(res)); // Sube 4 posiciones el Sp esto es para sobre escribir en los pasiciones ya almacenadas con el fin de organizar los datos en memoria
}
void mostrar_memoria(uint32_t *memoria , int tama) //Funcion que muestra en pantalla los valores guardados en menoria 
{
    int i,j,h,k,l; // Declaracion de algunas variables para la muestra de los registros en memoria
    h=0; // Declara valor inicial a variable h
	l=0; // Declara valor inicial a variable l
	k=DIRMAXMEM; // Variable que inicialmente contiene la direcccion maxima de memoria (funciona como Sp)
	for(i=0;i<tama/8;i++) // Hace referencia a las filas de la pantalla
    {
		for(j=0;j<tama/8;j++) // Hace referencia a las colomnas de la pantalla
		{
			h+=15;  // Incremento que se usa para la visualizacion espaciada en la panatalla al mostrar el banco de registros
			mvprintw(14+i,8+h,"%.2X : %.8X",k,memoria[l]); //Visualiza los valores guardados en memoria haciendo uso de la libreria curses
			l=l+1; // Variable que va ir dando la posicion de la memoeria en la que se va a guardar
			k=k-4; // Va en orden ascendente para mostrar el contenido de la ram ya que baja cada 4 veces cuando se guarda 
			refresh(); 
        }
		//tama = 64
		h=0; // Variable que hace referencia a un espacio para que no halla translapamiento
	}
}
void inimemoria(uint32_t *memoria,int tama) //Funcion que inicializa la memoria
{
    int i; //Declaracion de variable para el ciclo for
    for(i=0;i<(tama*4);i++) //Comienza desde el valor maximo y va disminuyendo
    {
        memoria[i]= -1; // A cada posicion de memoria se llena con -1
    }
}
