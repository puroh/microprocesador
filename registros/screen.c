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
	mvprintw(2,2,"Registros ");
	mvprintw(LINES-2,COLS/8,"Correr = u");
	mvprintw(LINES-2,COLS/2-4,"Parar = p");
	mvprintw(LINES-2,COLS*6/8,"Salir = q");
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
		printw("%d", registers[i]);//Para hexadecimal  "%.8X\t"
		refresh();
	}		
	return;
}
