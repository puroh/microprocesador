#include <stdint.h>
#include "screen.h"
#include <curses.h>
#include "ram.h"

void showRegisters(uint32_t *registers, size_t len)
{
	
	int i;
	move(0,COLS/2-15);
	attron(COLOR_PAIR(3));
	printw("  Emulador procesador Cortex M0  ");
	mvprintw(2,2,"Registros en hexadecimal ");	
	mvprintw(LINES-2,(COLS/5)-5,"Correr = u");
	mvprintw(LINES-2,(COLS*2/5)-4,"Parar = p");
	mvprintw(LINES-2,(COLS*3/5)-4,"Salir = q");
	mvprintw(LINES-2,(COLS*4/5)-7,"Mostar RAM = r");
	mvprintw(LINES-3,(COLS/2)-28,"presione e para entrar en perifericos de entrada y salida");
	refresh();

	if(!registers)
		return;

	for(i=0; i<len; i++)
	{
		attron(COLOR_PAIR(1));
		move(i+3,4);
		printw("R%-2d:", i);
		refresh();
		attron(COLOR_PAIR(2));		
		printw("%.8X", registers[i]);//Para hexadecimal  "%.8X\t"
		refresh();
	
	}	
	
	return;
}
