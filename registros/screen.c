#include <stdint.h>
#include "screen.h"
#include <curses.h>

void showRegisters(uint32_t *registers, size_t len)
{
	
	int i;
	move(0,COLS/2-15);
	attron(COLOR_PAIR(3));
	printw("Emulador procesador Cortex M0 %d ",COLS);
	mvprintw(2,2,"Registros ");
	refresh();

	if(!registers)
		return;

	for(i=0; i<len; i++)
	{
		if( (i % 4) == 0 )
			
		attron(COLOR_PAIR(1));
		move(i+3,4);
		printw("R%-2d:", i);
		refresh();
		attron(COLOR_PAIR(2));		
		printw("%d", registers[i]);//Para hexadecimal  "%.8X\t"
		refresh();
	}	
	//printw("\n");
	refresh();
	return;
}
