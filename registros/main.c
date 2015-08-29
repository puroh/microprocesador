#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "alu.h"

int main(void)
{
   uint32_t registers[12],j=1;
   registers[0]=2;
   registers[1]=2;
   showRegisters(registers, 12);
}
