#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "alu.h"
#include "idd.h"

int main(void){

    uint32_t registers[12];
   registers[0]=24;
   registers[1]=68;
   ADD(&registers[0],&registers[1],&registers[0]);
   printf("Suma--(%d)--\n\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   SUB(&registers[0],&registers[0],&registers[1]);
   printf("Resta--(%d)--\n\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   AND(&registers[0],&registers[1],&registers[0]);
   printf("And--(%d)--\n\n",registers[0]);
   registers[0]=1;
   registers[1]=1;
   ORR(&registers[0],&registers[1],&registers[0]);
   printf("--orr(%d)--\n\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   EOR(&registers[0],&registers[1],&registers[0]);
   printf("EOR--(%d)--\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   MOV(&registers[0],&registers[1]);
   printf("MOV--(%d)--\n",registers[0]);
   registers[0]=24;
   registers[1]=68;
   printf("CMP=");
   CMP(&registers[0],&registers[1]);
   return 0;
}

