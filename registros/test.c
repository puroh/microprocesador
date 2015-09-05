#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "alu.h"
#include "idd.h"
#include "curses.h"

void test(void){
    initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */
    start_color();	/* Permite manejar colores */
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2,COLOR_YELLOW,COLOR_BLACK);

   uint32_t registers[12];
   showRegisters(registers, 12);
   registers[0]=20;
   registers[1]=2147483647;
   attron(COLOR_PAIR(1));
   ADD(&registers[0],&registers[1]);

    move(5,15);
    attron(COLOR_PAIR(1));
    printw("Resultado de la operacion ADD=%d\n",registers[0]);
    refresh();
    getch();
    endwin();
   /*registers[0]=24;
   registers[1]=68;
   SUB(&registers[0],&registers[1]);
   printf("--(%d)--",registers[0]);
   registers[0]=24;
   registers[1]=68;
   AND(&registers[0],&registers[1]);
   printf("--(%d)--",registers[0]);
   registers[0]=1;
   registers[1]=1;
   ORR(&registers[0],&registers[1]);
   printf("--orr    (%d)--",registers[0]);
   registers[0]=24;
   registers[1]=68;
   EOR(&registers[0],&registers[1]);
   printf("--(%d)--\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   MOV(&registers[0],&registers[1]);
   printf("--(%d)--",registers[0]);*/

}

