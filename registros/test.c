#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "alu.h"
#include "salto.h"
#include "decoder.h"

int main(void)
{
	int i, num_instructions;
	ins_t read;
	char** instructions;
	instruction_t instruction;
	uint32_t pcou=0;
	uint32_t memoria=500;
	num_instructions = readFile("code.txt", &read);
	if(num_instructions==-1)
	{
		return 0;
	}
	if(read.array==NULL)
	{
		return 0;
	}
	instructions = read.array; //Arreglo con las instrucciones 

	// Ejemplo de uso
	//	Llama la funcion que separa el mnemonico y los operandos
	//	Llama la instruccion que decodifica y ejecuta la instruccion
	
	instruction = getInstruction(instructions[1]); // Instruccion en la posici�n 0
    for(i=0; i<num_instructions;i++)
	{
		printw("\ninstruccion %d : %s",i,instructions[i]);
	}
    while(pcou<memoria)
	{
		if(pcou>=num_instructions)
		{
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
	// Libera la memoria reservada para las instrucciones 
	for(i=0; i<num_instructions;i++)
	{
		free(read.array[i]);
	}
	free(read.array);
	return 0;
}

