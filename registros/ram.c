#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>

#define MEMORIA 64
#define DIRMAXMEM 255



//WINDOW *newwin(35,35,0,0);
//WINDOW *win;
void inicia_ram(void)
{
	
    uint32_t registros[15]={10,11,12,13,14,15,250,251,0,0,0,0,1,0,0};/*registro[12] es SP*/
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

/*fila 11
columna 20*/
Disp();
}

int bitcount(int *R){

	int i,contador=0;
	for(i=0;i<9;i++){
	if(((1<<i)& *R)!=0)
       contador++;
                    }
    return contador;
}
void PUSH(uint32_t *registros,uint32_t *memory,uint8_t *res){/*memory memoria SRAM y res es un arreglo de caracteres que contiene*/
                                                                /*los caracteres que se quieren guardar en memoria*/
    int R=0,address;
    int n;
    uint8_t i=0;
    while(res[i]!='\0'){
       /* if( (res[i]=='R') && (res[i+1]>'7' | res[i+1]<'12') ){
          mvprintw("\nuno o mas registros no son permitidos\n");
          break;
          }*/
        if(res[i]=='R'){
            n=(int)((res[i+1])-48); /*Para pasar de caracter a numero (codigo ASCII)*/
            R+=(1<<(n));

        }
      i++;
    }
    (registros[12])--;
    address=registros[12]-(4*bitcount(&R));
    for(i=0;i<15;i++){
		if ( ( (1<<i) & R)!= 0 ){

            memory[MEMORIA-((address/4)+2)]=registros[i];


			address=address+4;
			}
		}
	registros[12]-=(4*bitcount(&R));
	}
void POP(uint32_t *registros,uint32_t *memory,uint8_t *res){
    int R=0,address;
    int n;
    uint8_t i=0;
    while(res[i]!='\0'){
       /* if( (res[i]=='R') && (res[i+1]>'7' | res[i+1]<'12') ){
          mvprintw("\nuno o mas registros no son permitidos\n");
          break;
          }*/
        if(res[i]=='R'){
            n=(int)((res[i+1])-48); /*Para pasar de caracter a numero (codigo ASCII)*/
            R+=(1<<(n));

        }
      i++;
    }
    address=registros[12];
    for(i=0;i<7;i++){
		if ( ( (1<<i) & R)!= 0 ){

           registros[i]=memory[MEMORIA-((address/4)+2)];


			address=address+4;
			}
		}
	registros[12]+=(4*bitcount(&R));
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
















