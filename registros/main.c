#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>
#include "screen.h"
#include "alu.h"
#include "flags.h"
#include "decoder.h"
#include "ram.h"



#define NORMAL       0
#define BRILLO       1
#define SEMIBRILLO   2
#define INTERMITENTE 5
#define INVERSO      7
#define NEGRO       30
#define ROJO        31
#define VERDE       32
#define MARRON      33
#define AZUL        34
#define ROSA        35
#define CELESTE     36
#define BLANCO      37

#define MAXLINEAS 15
#define MAXCAD 70

WINDOW *win; //manejaremos una unica ventana de pantalla completa 
int Disp(void);
void Inivideo(void);
void Exit(void);

void IniVideo(void)
{
	//Para los colores 
	win=initscr();//Inicia modo curses 
	clear();
	refresh();
	noecho(); //No imprimir los caracteres leidos 
	cbreak();
	curs_set(0);	//Cursor Invisible 
	keypad(stdscr, TRUE);  //Obtener F1, F2, etc
 	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);
	if(has_colors()) 
	{
	    start_color();//Permite manejar colores 
	    init_pair(1, COLOR_RED, COLOR_GREEN);
	    init_pair(2, COLOR_WHITE, COLOR_GREEN);
	    init_pair(3, COLOR_GREEN, COLOR_BLACK);
	    init_pair(4, COLOR_RED, COLOR_WHITE);
	    init_pair(5, COLOR_BLUE, COLOR_GREEN);
		init_pair(6, COLOR_GREEN, COLOR_GREEN);
    }
    bkgd(COLOR_PAIR(5)); //color del fondo
}


void Exit(void)
{        
    clear();
    endwin(); //finaliza la muestra de curses
    exit(1); //cierra el programa
}
int main(void)
{	
	IniVideo();  //funcion para configurar colores y el modo de visualizado
	Disp();     //Funcion en donde se realizan las operaciones
    Exit();  	//Funcion para finalizar el programa
    return 0;  
}

int Disp(void)
{	
	char ch='0';				//declaracion de variable tipo char para realizar acciones con el teclado	
	int i, num_instructions; 	//declaracion de variables
	ins_t read;					
	char** instructions;
	instruction_t instruction;
	uint32_t pcou=0;			//contador de direccion de operacion
	uint32_t memoria=500;		//cantidad maxima de instrucciones
	num_instructions = readFile("prueba_1.txt", &read);
	if(num_instructions==-1)
	return 0;	
	if(read.array==NULL)
	return 0;
	instructions = read.array; //Arreglo con las instrucciones 
	//Ejemplo de uso
	//Llama la función que separa el mnemonico y los operandos
	//Llama la instrucción que decodifica y ejecuta la instrucción
	
	instruction = getInstruction(instructions[1]); //Instrucción en la posición 0
	while(pcou<memoria)
	{
		if(pcou>=num_instructions)
		{
			mvprintw(LINES-3,COLS/2,"Limite de instrucciones alcanzado");
			getch();
			break;
        }    
        instruction = getInstruction(instructions[pcou]);
        decodeInstruction(instruction);
        ch = getch();		//obtiene el valor de la tecla presionada
		if(ch=='u') //valida si la tecla presionada es u
		{ 		
			attrset(COLOR_PAIR(4 ));
			mvprintw(LINES-2,COLS/8-2,"  ");
			attrset(COLOR_PAIR(6 ));
			mvprintw(LINES-2,COLS/2-6,"  ");
			refresh();			
			timeout(1000);					
		}		//instruccion que permite seguir ejecutando el codigo aun si no se esta presionando
        if(ch=='p')		//valida si la tecla presionada es p
		{
            timeout(-1);
			attrset(COLOR_PAIR(4 ));
			mvprintw(LINES-2,COLS/2-6,"    ");
			attrset(COLOR_PAIR(6 ));
			mvprintw(LINES-2,COLS/8-2,"    ");
			refresh();
		}//un valor negativo deshabilita para que el codigo siga corriendo solo
		if(ch=='q')
		{		//valida si la tecla presionada es q
			Exit();				//llama la funcion de salida, la que cierra el programa
		}
		//inicia_ram();

//mvprintw(LINES-3,COLS/8,"Correr = u");
//mvprintw(LINES-2,COLS/2-4,"Parar = p");
//mvprintw(LINES-2,COLS*6/8,"Salir = q");

        obtenerPC(&pcou);
    }
		refresh();				//muestra en pantalla los cambias que se hayan realizado anteriormente
	for(i=0; i<num_instructions;i++)
	{
		free(read.array[i]);
	}
	free(read.array);
	return 0;
}
