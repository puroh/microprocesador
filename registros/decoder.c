#include "decoder.h"
#include "alu.h"
#include "salto.h"
#include <stdint.h>

    uint32_t registers[12];
    uint32_t pc=0,LR;

void decodeInstruction(instruction_t instruction)
{
    printf("\nvalor de PC %d\n",pc);
    if(strncmp(instruction.mnemonic,"B",1)==0){
        if( strcmp(instruction.mnemonic,"BNE") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              BNE(&pc,instruction.op1_value);
                                                     }
        if( strcmp(instruction.mnemonic,"B") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);

                                                     }
        if( strcmp(instruction.mnemonic,"BEQ") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BCS") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              BCS(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BCC") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              BCC(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BMI") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BPL") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              BPL(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BVS") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BVC") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BHI") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BLS") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BGE") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BLT") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BGT") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BLE") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BAL") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              B(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BL") == 0 ){
              printf("instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              BL(&pc,instruction.op1_value);
                                                        }
        if( strcmp(instruction.mnemonic,"BX") == 0 ){
              printf("instruccion :%s %c\n",instruction.mnemonic,instruction.op1_type);
              BX(&pc);
                                                        }


}
    else{
            pc+=2;
        }


	if( strcmp(instruction.mnemonic,"ADD") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          ADD(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
    if( strcmp(instruction.mnemonic,"SUB") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          SUB(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"AND") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          AND(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"ORR") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          ORR(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"EOR") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          EOR(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"MOV") == 0 ){
	       printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
           MOV(&registers[instruction.op1_value],&registers[instruction.op2_value]);
            printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"CMP") == 0 ){
                 printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
                 CMP(&registers[instruction.op1_value],&registers[instruction.op2_value]);
	}
	if( strcmp(instruction.mnemonic,"ADCS") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          ADCS(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"CMN") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          CMN(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"SBC") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          SBC(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"MOVS") == 0 ){
           printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
           MOVS(&registers[instruction.op1_value],instruction.op2_value);
           printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"SUBS") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          SUBS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"ADDS") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          ADDS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"LSR") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          LSR(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"LSL") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          LSL(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"ROR") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          ROR(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"ASRS") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          ASRS(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"REV") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          REV(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"REV16") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          REV16(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"BIC") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          BIC(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"MVN") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          MVN(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"RSBS") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          RSBS(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
	if( strcmp(instruction.mnemonic,"NOP") == 0 ){
	      printf("instruccion :%s\n",instruction.mnemonic);
          NOP();
	}
	if( strcmp(instruction.mnemonic,"TST") == 0 ){
	      printf("instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
          TST(&registers[instruction.op1_value],&registers[instruction.op2_value]);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
    if( strcmp(instruction.mnemonic,"LSLS") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          LSLS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}
    if( strcmp(instruction.mnemonic,"LSRS") == 0 ){
	      printf("instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          LSRS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value);
          printf("valor del registro %d\n",registers[instruction.op1_value]);
	}

}
void obtenerPC(uint32_t *pcount)
{
    *pcount=pc;
}

instruction_t getInstruction(char* instStr)
{
	instruction_t instruction;
	char* split = (char*)malloc(strlen(instStr));
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
			case 1:
				instruction.op1_type  = split[0];
				instruction.op1_value = (uint32_t)strtol(split+1, NULL, 0);
				break;

			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtol(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtol(split+1, NULL, 0);
				break;
		}

		split = strtok(NULL, " ,.");
		num++;
	}

	if(num==3){
		instruction.op3_type  = 'N';
		instruction.op3_value = 0;
	}

	free(split);

	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp)-1;	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc(strlen(buffer)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)
{
	int lines=0;
	int ch;

	while(!feof(fp))
	{
	  ch = fgetc(fp);
	  if(ch == '\n')
		lines++;
	}
	rewind(fp);

	return lines;
}
