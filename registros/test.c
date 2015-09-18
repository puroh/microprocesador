#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "alu.h"
#include "salto.h"
#include "decoder.h"

int main(void){




		int i, num_instructions;
		ins_t read;
		char** instructions;
		instruction_t instruction;
		uint32_t pcou=0;
		uint32_t memoria=500;
		num_instructions = readFile("code.txt", &read);
		if(num_instructions==-1)
			return 0;

		if(read.array==NULL)
			return 0;

		instructions = read.array; /* Arreglo con las instrucciones */




	/* Ejemplo de uso
		Llama la función que separa el mnemonico y los operandos
		Llama la instrucción que decodifica y ejecuta la instrucción
	*/
	instruction = getInstruction(instructions[1]); /* Instrucción en la posición 0*/
     for(i=0; i<num_instructions;i++){
		printw("\ninstruccion %d : %s",i,instructions[i]);
	}
        while(pcou<memoria){
            if(pcou>=num_instructions){
                printw("\nLimite de instrucciones alcanzado\n");
                getch();
                break;
            }
            printw("\n_________________________________\n");
            instruction = getInstruction(instructions[pcou]);
            decodeInstruction(instruction);
            getch();
            printw("\n_________________________________\n");
            obtenerPC(&pcou);

        }

	/* Libera la memoria reservada para las instrucciones */
	for(i=0; i<num_instructions;i++){
		free(read.array[i]);
	}
	free(read.array);
/*
=======
#include "idd.h"
#include <curses.h>

int main(void){

   uint32_t registers[12];
   registers[0]=24;
   registers[1]=68;
   ADD(&registers[0],&registers[1],&registers[0]);
   printw("Suma--(%d)--\n\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   SUB(&registers[0],&registers[0],&registers[1]);
   printw("Resta--(%d)--\n\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   AND(&registers[0],&registers[1],&registers[0]);
   printw("And--(%d)--\n\n",registers[0]);
   registers[0]=1;
   registers[1]=1;
   ORR(&registers[0],&registers[1],&registers[0]);
   printw("--orr(%d)--\n\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   EOR(&registers[0],&registers[1],&registers[0]);
   printw("EOR--(%d)--\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   MOV(&registers[0],&registers[1]);
   printw("MOV--(%d)--\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   printw("CMP=");
   CMP(&registers[0],&registers[1]);
>>>>>>> master
   return 0;*/
}

