#include <stdint.h>
#include "screen.h"
#include "curses.h"

void showRegisters(uint32_t *registers, size_t len)
{
	/*int i;

	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	if(!registers)
		return;

	for(i=0; i<len; i++)
	{
		if( (i % 4) == 0 )
			printf("\n");
		attron(COLOR_PAIR(1));
		move(i+1,4);
		printw("R%-2d:", i);
		refresh();
		SetConsoleTextAttribute(hCon,WHITE);
		attron(COLOR_PAIR(2));
		printw("%.8X\t", registers[i]);
		refresh();
	}
	printf("\n");*/
}
