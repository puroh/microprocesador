#include <stdint.h>
#include "ram.h"
#include <curses.h>
uint8_t bitcount(uint8_t *R){

	uint8_t i,contador=0;
	for(i=0;i<16;i++){
	if((1 & R[i])!=0)
       contador++;
                    }
    return contador;
}
void PUSH(uint32_t *registros,uint32_t *memory,uint8_t *res){
    uint8_t address;
    uint8_t i=0;
    (registros[12])--;
    address=registros[12]-(4*bitcount(res));
    for(i=0;i<15;i++){
		if( (1  & res[i])!= 0 ){

            memory[MEMORIA-((address/4)+2)]=registros[i];


			address=address+4;
			}
		}
	registros[12]-=(4*bitcount(res));
	}

void POP(uint32_t *registros,uint32_t *memory,uint8_t *res){
    uint8_t address;
    uint8_t i=0;

    address=registros[12];
    for(i=0;i<7;i++){
		if( (1 & res[i])!= 0 ){

           registros[i]=memory[MEMORIA-((address/4)+2)];


			address=address+4;
			}
		}
	registros[12]+=(4*bitcount(res));
}





void mostrar_memoria(uint32_t *memoria , int tama){
    int i,j,h,k,l;
        h=0;
		l=0;
		k=DIRMAXMEM;
	    for(i=0;i<tama/8;i++)
        {
		for(j=0;j<tama/8;j++){
		h+=15;
		mvprintw(14+i,8+h,"%.2X : %.8X",k,memoria[l]);
		l=l+1;
		k=k-4;
        refresh();

        }
		//tama = 64
		h=0;
		}

}
void inimemoria(uint32_t *memoria,int tama){
    int i;
    for(i=0;i<(tama*4);i++)
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
