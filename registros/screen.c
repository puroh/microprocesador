#include "screen.h"
#include "curses.h"

void showRegisters(unsigned long int *registers, size_t len)
{
	int i;

	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	if(!registers)
		return;

	for(i=0; i<len; i++)
	{
		if( (i % 4) == 0 )
			printf("\n");
		SetConsoleTextAttribute(hCon,GREEN);
		attron(COLOR_PAIR(1));
		printw("R%-2d:", i);
		refresh();
		SetConsoleTextAttribute(hCon,WHITE);
		attron(COLOR_PAIR(2));
		printw("%.8X\t", registers[i]);
		refresh();
	}
	printf("\n");

	return;
}
