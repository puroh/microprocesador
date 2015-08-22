#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "ALU.h"

int main(void)
{
   unsigned long int registers[12];

   showRegisters(registers, 12);

    printf("\nsuma:%d\tresta:%d\tAND:%d\tOR:%d\tXOR:%d\n",suma(registers[1],registers[2]),resta(registers[1],registers[2]),ANDS(registers[1],registers[2]),ORES(registers[1],registers[2]),XOR(registers[1],registers[2]));
}
