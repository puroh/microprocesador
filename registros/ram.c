#include <stdint.h>
#include "ram.h"
#include <curses.h>
#include "flags.h"
uint32_t bitcount(uint32_t *R) //Determina cuantos 1 hay en los datos que contienen los registros
{
	uint32_t i,contador=0; //Declaracion e inicializacion de variables para el ciclo que determinara la cantidad de 1 que contiene cada registro
	for(i=0;i<16;i++) //Ciclo for que permite determina cuantos unos hay en cada registro
	{
		if((1 & R[i])!=0) //Condicion que permite establecer que si el valor en el registro es diferente de cero es porque es uno y el contador se incrementa
		{
			contador++; //Incremento del contador
		}
    }
    return contador; //Retorna el valor del contador, el cual determino la cantidad de unos que hay en los registros
}
void PUSH(uint32_t *registros,uint32_t *memory,uint32_t *res) //Funcion PUSH que permite ir almacenando los datos
{
    uint32_t address; //Declaracion de variables
    uint32_t i=0; // Declaracion de variable para el ciclo for
    if(registros[13]>=255) //Condicion maxima de registros
	{
		(registros[13])--; //Disminucion en los registros para ir almacenando
	}
    address=registros[13]-(4*bitcount(res));// Address guarda la posicion en la que se van a guardar los datods en ram r
    for(i=0;i<16;i++) // Condicion en donde comenzara a guardar los datos 
	{
        if(1&(res[8]|res[9]|res[10]|res[11]|res[12]|res[15])) 
		{
			registros[13]+=(4*bitcount(res)); // Sube el Sp 4 posicion debido a que el almacenamiento se realizqa de forma descendente
			break;
        }
		if( (1  & res[i])!= 0 )
		{
            memory[MEMORIA-((address/4)+2)]=registros[i]; // Posicion en donde almacenara la memoria el dato del registro[i]
			address=address+4; // Modifica la memoria maxima disponible y cuadra el sp
		}
	}
	registros[13]-=(4*bitcount(res)); // Baja el Sp 4 posicion debido a que el almacenamiento se realizqa de forma descendente
}
void POP(uint32_t *registros,uint32_t *memory,uint32_t *res) //Funcion POP que permite organizar los datos
{
    uint32_t address; // Declaracion de variable la cual sera el Sp
    uint32_t i=0; // Declaracion de variable para el ciclo for
    address=registros[13]; //declara el registro 13 como sp
    for(i=0;i<16;i++) // Ciclos de los espacios de memoria en donde se esta guardando la informacion
	{
        if(1&(res[8]|res[9]|res[10]|res[11]|res[12]|res[14]))
		{
			registros[13]-=(4*bitcount(res)); // Baja 4 posiciones el Sp esto es para sobre escribir en los pasiciones ya almacenadas con el fin de organizar los datos en memoria
			break;
        }
		if( (1 & res[i])!= 0 )
		{
			registros[i]=memory[MEMORIA-((address/4)+2)]; // Posicion en donde almacenara la memoria el dato del registro[i]
			address=address+4; // Modifica la memoria maxima disponible y cuadra el sp
		}
	}
	registros[13]+=(4*bitcount(res)); // Sube 4 posiciones el Sp esto es para sobre escribir en los pasiciones ya almacenadas con el fin de organizar los datos en memoria
}
void mostrar_memoria(uint32_t *memoria , int tama) //Funcion que muestra el pantalla los valores guardados en menoria 
{
    int i,j,h,k,l; // Declaracion de algunas variables para la muestra de los registros en memoria
	h=2; // Declara valor inicial a variable h
	l=0; // Declara valor inicial a variable l
	k=DIRMAXMEM; // Variable que inicialmente contiene la direcccion maxima de memoria (funciona como Sp)
	for (i=0 ; i<tama/8;i++) // Hace referencia a las filas de la pantalla
	{
		for (j=0; j<tama/8;j++) // Hace referencia a las colomnas de la pantalla
		{
			move(i+7,j+h); //posiciona el cursor
			attron(COLOR_PAIR(1));
			printw("%.2x",k); //imprime
			attron(COLOR_PAIR(2));
			printw(" : %.2X %.2X %.2X %.2X",(uint32_t)(memoria[l]>>24),(uint32_t)(memoria[l]>>16),(uint32_t)(memoria[l]>>8),(uint32_t)(memoria[l]));//Visualiza los valores guardados en memoria haciendo uso de la libreria curses
			k=k-4; // Va en orden ascendente para mostrar el contenido de la ram ya que baja cada 4 veces cuando se guarda 
			l=l+1; // Variable que va ir dando la posicion de la memoeria en la que se va a guardar
			h=h+18;	// Incremento que se usa para la visualizacion espaciada en la panatalla al mostrar el banco de registros		
		}
		h=2;
	}	
}
void inimemoria(uint32_t *memoria,int tama) //Funcion que inicializa la memoria
{
    int i; //Declaracion de variable para el ciclo for
    for(i=0;i<(tama);i++) //Comienza desde el valor maximo y va disminuyendo
    {
        memoria[i]= -1; // A cada posicion de memoria se llena con -1
    }
}
void PUSHINTERRUPT(uint32_t *registros,uint32_t *memory,uint32_t *res) //Funcion PUSH dentro de la interrupcion
{
    uint32_t address; //declara direccion
    bool bande[4]; //uso de banderas
    uint32_t bd; //declaracion de variables sin signo de 32 bits
    obtenerBandera(bande); //obtiene el valor de las banderas C,N,V y Z
    bd=((bande[C])<<3)+((bande[Z])<<2)+((bande[N])<<1)+bande[V];
    uint32_t i=0; //declaracion de variables sin signo de 32 bits para ser usada dentro del for
    if(registros[13]>255)
	{
		(registros[13])--; //decremento en los registros
	}
    address=registros[13]-(4*bitcount(res)+4);
    for(i=0;i<16;i++) // Condicion en donde comenzara a guardar los datos 
	{
		if( (1  & res[i])!= 0 )
		{
			memory[MEMORIA-((address/4)+2)]=registros[i]; // Posicion en donde almacenara la memoria el dato del registro[i]
			address=address+4; // Modifica la memoria maxima disponible y cuadra el sp
		}
	}
	memory[MEMORIA-((address/4)+2)]=bd; //Igualacion en la memoria al valor en bd
	registros[13]-=(4*bitcount(res))+4; //posicionamiento del sp
}
void POPINTERRUPT(uint32_t *registros,uint32_t *memory,uint32_t *res) //Funcion POP dentro de la interrupcion
{
    uint32_t address; //declara direccion
    uint32_t i=0; //declaracion de variables sin signo de 32 bits para ser usado en el for
    bool f[4]; //uso de banderas
    uint32_t bd; //declaracion de variables sin signo de 32 bits
    address=registros[13]; //declara el registro 13 como sp
    for(i=0;i<16;i++) // Ciclos de los espacios de memoria en donde se esta guardando la informacion
	{
		if( (1 & res[i])!= 0 )
		{
			registros[i]=memory[MEMORIA-((address/4)+2)]; // Posicion en donde almacenara la memoria el dato del registro[i]
			address=address+4; // Modifica la memoria maxima disponible y cuadra el sp
		}
	}
	bd = memory[MEMORIA-((address/4)+2)]; //bd valdra lo que hay en dicha posicion de memoria
	f[C]=(1&bd>>3); //la bandera de carry sera igual a dicho desplazamiento multiplicado por 1
	f[Z]=(1&bd>>2); //la bandera de ceros sera igual a dicho desplazamiento multiplicado por 1
	f[N]=(1&bd>>1); //la bandera de negativo sera igual a dicho desplazamiento multiplicado por 1
	f[V]=(1&bd); //la bandera de sobreflujo sera igual al bd multiplicado por 1
	SalvarBanderas(f); //guarda los cambios de las banderas para posteriormente ser usados
	registros[13]+=(4*(bitcount(res)+1)); //posicionamiento del sp
}
void LDR(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory) // Funcion que extrae 4 valores de la pila dependiendo de la suma de las direcciones 
{
    uint32_t direccion=Rn+Rm; //operacion que realiza para determinar el posicionamiento donde extraera el valor en memoria
    *Rt=(uint32_t)(memory[MEMORIA-((direccion/4)+2)]<<24)+(uint32_t)(memory[MEMORIA-((direccion/4)+2)]<<16)+(uint32_t)(memory[MEMORIA-((direccion/4)+2)]<<8)+memory[MEMORIA-((direccion/4)+2)]; //donde se ubicara en memoria para obtener el valor
}
void LDRB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory) // Funcion que extrae un valor de la pila dependiendo de la suma de la direccion con otra direccion de registro
{
    uint32_t direccion=Rn+Rm; //operacion que realiza para determinar el posicionamiento donde extraera el valor en memoria
    *Rt=memory[MEMORIA-((direccion/4)+2)]; //donde se ubicara en memoria para obtener el valor
}
void LDRH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory) // Funcion que extrae dos valores de la pila dependiendo de la suma de la direccion con un valor inmediato adicionalmente se realiza extension de ceros
{
    uint32_t direccion=Rn+Rm; //operacion que realiza para determinar el posicionamiento donde extraera el valor en memoria
    *Rt=(uint32_t)(memory[MEMORIA-((direccion/4)+2)]<<8)+(uint32_t)memory[MEMORIA-((direccion/4)+2)]; //donde se ubicara en memoria para obtener el valor
}
void STR(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory) // Funcion que almacena 4 valores en la pila 
{
    uint32_t direccion = Rn + Rm; //operacion que realiza para determinar el posicionamiento donde almacenara el valor en memoria
    memory[MEMORIA-((direccion/4)+2)]= *Rt; //donde se ubicara en memoria para almacenar el valor
}
void STRB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory) // Funcion que almacena un valore en la pila ya sea los primeros 8 bit o los 8 bit ultimos
{
    uint32_t direccion=Rn+Rm; //operacion que realiza para determinar el posicionamiento donde almacenara el valor en memoria
    memory[MEMORIA-((direccion/4)+2)]=*Rt; //donde se ubicara en memoria para almacenar el valor
}
void STRH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory) // Funcion que almacena dos valores en la pila ya sea los 16 primeros 16bit o los ultimos 16 bits 
{
    uint32_t direccion=0;
    memory[MEMORIA-((direccion/4)+2)]=*Rt; //donde se ubicara en memoria para almacenar el valor
}

/*

fila 11
columna 20

*/
