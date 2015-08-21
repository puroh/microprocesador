#include "screen.h"

void showRegisters(long int *registers, size_t len)
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
		printf("R%-2d:", i);
		SetConsoleTextAttribute(hCon,WHITE);
		printf("%.8X\t", registers[i]);
	}
	printf("\n");

	return;
}
