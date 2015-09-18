#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>
#include <ncurses.h>
#include "screen.h"
#include "alu.h"
#include "flags.h"


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

WINDOW *win; /** manejaremos una única ventana de pantalla completa **/


void IniVideo(){/*Para los colores */
	win=initscr();/* Inicia modo curses */
	clear();
	refresh();
	noecho();/* No imprimir los caracteres leidos */
	cbreak();
	curs_set(0);	/* Cursor Invisible */
	keypad(stdscr, TRUE);/* Obtener F1, F2, etc */
 	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);
	if(has_colors()) {
	         start_color();/* Permite manejar colores */
	         init_pair(1, COLOR_RED, COLOR_GREEN);
	         init_pair(2, COLOR_WHITE, COLOR_GREEN);
	         init_pair(3, COLOR_GREEN, COLOR_BLACK);
	         init_pair(4, COLOR_WHITE, COLOR_RED);
	         init_pair(5, COLOR_BLUE, COLOR_GREEN);
        }
        bkgd(COLOR_PAIR(5));
}


Exit(){
        attroff(COLOR_PAIR(1));
        clear();
        refresh();
        endwin();
        exit(1);
}



int main(void)
{
	IniVideo();  
	Disp();     
	getch();
    Exit();    
}

void Disp(){
	uint32_t registers[12];
	showRegisters(registers, 12);

/************************************
orden
ADD
SUB
AND
ORR
EOR
MOV
CMP


/************************************/
	attrset(COLOR_PAIR(1 ));
    mvprintw(2,40,"ADD\n");
	attrset(COLOR_PAIR(5 ));
	registers[2]=12;
	registers[1]=2;
	ADD(&registers[0],&registers[1],&registers[2]);
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/
/***************************************/


}
