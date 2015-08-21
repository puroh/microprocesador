#include <stdio.h>
#include <stdlib.h>
#include "registros.h"

int main(void)
{
   long int registers[12];

	showRegisters(registers, 12);
    printf("%d",registers);


}
