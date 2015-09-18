/****************************************************************
*****************************************************************/
//#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "screen.h"
#include "alu.h"
#include "idd.h"
#include "curses.h"

int main(void)
{
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */
    start_color();	/* Permite manejar colores */
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);
	uint32_t registers[12];
	showRegisters(registers, 12);
	attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    getch();
    endwin();
>>>>>>> master
    return 0;
}
