#include <stdint.h>
#include "screen.h"
#include <curses.h>

void showRegisters(uint32_t *registers, size_t len)
{

	/*
	int i;

	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);

=======
	int i;
	move(0,COLS/2-15);
	printw("Emulador procesador Cortex M0 %d \n",COLS);
	mvprintw(2,2,"Registros ");
>>>>>>> curses
	if(!registers)
		return;

	for(i=0; i<len; i++)
	{
		if( (i % 4) == 0 )
			printw("\n");
		attron(COLOR_PAIR(1));
		move(i+3,4);
		printw("R%-2d:", i);
		refresh();
		attron(COLOR_PAIR(2));
		printw("%.8X\t", registers[i]);
		refresh();
	}

	printf("\n");	
	refresh();

	return;*/
}
