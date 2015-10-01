#include "decoder.h"
#include "alu.h"
#include "salto.h"
#include <stdint.h>
#include "screen.h"




    uint32_t registers[15];
    uint32_t pc=0,LR;/*se define el program counter y el LR que se modifica con BL*/


void obtener_registros(uint32_t *registros)
{
      registros=registers;

}

void decodeInstruction(instruction_t instruction)
{
	attron(COLOR_PAIR(2));/*Se mofifica el color del printw*/
    mvprintw(4,40,"Valor de PC %d\n",pc);/*se imprime en pantalla en la posicion 4,40*/

    if(strncmp(instruction.mnemonic,"B",1)==0) /*se compara  con strncmp para comparar la primer letra del mnemonico con B para no aumentar pc si se ejecuta un B*/
	{

        if( strcmp(instruction.mnemonic,"BNE") == 0 )/*compara BNE con el mnemonico. Si es igual ejecuta las instrucciones*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BNE(&pc,instruction.op1_value);/*ejecuta la operacion BNE*/
        }
        if( strcmp(instruction.mnemonic,"B") == 0 ) /*compara B con el mnemonico en en code.txt en el valor del arreglo definido por PC. Si es igual ejecuta las instrucciones*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            B(&pc,instruction.op1_value); /*ejecuta la operacion B*/
        }
        if( strcmp(instruction.mnemonic,"BEQ") == 0 ) /*compara BEQ con el mnemonico de las instrucciones en el .txt*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BEQ(&pc,instruction.op1_value);/*ejecuta la funcion BEQ de salto.c*/
        }
        if( strcmp(instruction.mnemonic,"BCS") == 0 ) /*compara el mnemonico con BCS*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BCS(&pc,instruction.op1_value);/*ejecuta la funcion BCS de salto.c*/
        }
        if( strcmp(instruction.mnemonic,"BCC") == 0 ) /*compara el mnemonico con BCC*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BCC(&pc,instruction.op1_value);/*ejecuta la operacion BCC de salto.c*/
        }

        if( strcmp(instruction.mnemonic,"BMI") == 0 ) /*compara el mnemonico con BMI*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BMI(&pc,instruction.op1_value);/*ejecuta la operacion BMI de salto.c*/
        }
        if( strcmp(instruction.mnemonic,"BPL") == 0 ) /*compara el mnemonico con BPL*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BPL(&pc,instruction.op1_value);/*ejecuta la funcion BPL de salto.c*/
        }
        if( strcmp(instruction.mnemonic,"BVS") == 0 ) /*compara el mnemonico con BVS*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BVS(&pc,instruction.op1_value);/*ejecuta la funcion BVS*/
        }
        if( strcmp(instruction.mnemonic,"BVC") == 0 ) /*compara el mnemocico con BVC*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BVC(&pc,instruction.op1_value);/*ejecuta la funcion BVC*/
        }
        if( strcmp(instruction.mnemonic,"BHI") == 0 ) /*compara el mnemonico con BHI*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BHI(&pc,instruction.op1_value);/*ejecuta BLS*/
        }
        if( strcmp(instruction.mnemonic,"BLS") == 0 ) /*compara el mnemonico con BLS*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BLS(&pc,instruction.op1_value);/*ejecuta la funcion BLS de salto.c*/
        }
        if( strcmp(instruction.mnemonic,"BGE") == 0 ) /*compara el mnemonico con BGE*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BGE(&pc,instruction.op1_value); /*ejecuta BGE*/
        }
        if( strcmp(instruction.mnemonic,"BLT") == 0 ) /*compara el mnemonico con BLT*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BLT(&pc,instruction.op1_value); /*ejecuta BLT*/
        }
        if( strcmp(instruction.mnemonic,"BGT") == 0 ) /*compara el mnemonico con BGT*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BGT(&pc,instruction.op1_value);/*ejecuta la funcion BGT en salto.c*/
        }
        if( strcmp(instruction.mnemonic,"BLE") == 0 ) /*compara el mnemonico con BLE*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BLE(&pc,instruction.op1_value);/*ejecuta la funcion BLE en salto.c*/
        }
        if( strcmp(instruction.mnemonic,"BAL") == 0 ) /*compara el mnemonico con BAL*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BAL(&pc,instruction.op1_value);/*ejecuta la funcion BAL en salto.c*/
        }
        if( strcmp(instruction.mnemonic,"BL") == 0 ) /*compara el mnemonico con BL*/
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BL(&pc,instruction.op1_value);/*ejecuta la funcion BL en salto.c*/
        }
        if( strcmp(instruction.mnemonic,"BX") == 0 ) /*compara el mnemonico con BX*/
		{
            mvprintw(5,40,"Instruccion :%s %c\n",instruction.mnemonic,instruction.op1_type);
            BX(&pc);/*ejecuta la funcion BX en salto.c*/
        }
}
    else /*si no se ejecuta alguna funcion B el pc sigue aumentando*/
	{
        pc+=2; /*incrementa el valor del pc*/
    }
	if( strcmp(instruction.mnemonic,"ADD") == 0 ) /* compara el mnemonico con ADD*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        ADD(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);/*ejecuta la funcion ADD localizada en alu.c*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]);/*muestra el resultado de la operacion*/
	}

	if( strcmp(instruction.mnemonic,"MULS") == 0 ){
	      mvprintw(5,40,"instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          MULS(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);
          mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]);
	}
    if( strcmp(instruction.mnemonic,"SUB") == 0 ) /* compara el mnemonico con SUB*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        SUB(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);/*ejecuta la funcion SUB localizada en alu.c*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]);/*muestra el resultado de la operacion*/
	}
	if( strcmp(instruction.mnemonic,"AND") == 0 ) /*compara el mnemonico con AND*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        AND(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);/*ejecuta la funcion AND*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]);/*muestra el resultado de la operacion*/
	}
	if( strcmp(instruction.mnemonic,"ORR") == 0 ) /*compara el mnemonico con ORR*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        ORR(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);/*ejecuta la funcion ORR*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]);/*muestra el resultado de la operacion*/
	}
	if( strcmp(instruction.mnemonic,"EOR") == 0 ) /*compara el mnemonico con EOR*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        EOR(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);/*ejecuta la funcion EOR*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]);/*muestra el resultado de la operacion*/
	}
	if( strcmp(instruction.mnemonic,"MOV") == 0 ) /*compara el mnemonico con MOV*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        MOV(&registers[instruction.op1_value],&registers[instruction.op2_value]);/*ejecuta la operacion MOV*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]);/*muestra el resultado de la operacion*/
	}
	if( strcmp(instruction.mnemonic,"CMP") == 0 ) /*compara el mnemonico con CMP*/
	{
        mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        CMP(&registers[instruction.op1_value],&registers[instruction.op2_value]);/*ejecuta la funcion CMP*/
	}
	if( strcmp(instruction.mnemonic,"ADCS") == 0 ) /*compara el mnemocio con ADCS*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        ADCS(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]); /*ejecuta la operacción ADCS*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]);/*muestra el resultado de la operacion*/
	}
	if( strcmp(instruction.mnemonic,"CMN") == 0 ) /*compara el mnemocio con CMN*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        CMN(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta la operación CMN*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operacion*/
	}
	if( strcmp(instruction.mnemonic,"SBC") == 0 ) /*compara el mnemocio con CMN*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        SBC(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]); /*ejecuta la operación SBC*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operacion*/
	}
	if( strcmp(instruction.mnemonic,"MOVS") == 0 ) /*compara el mnemocio con MOVS*/
	{
        mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        MOVS(&registers[instruction.op1_value],instruction.op2_value); /*ejecuta la función MOVS*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"SUBS") == 0 ) /*compara el mnemocio con SUBS*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        SUBS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value); /*ejecuta la operación SUBS*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"ADDS") == 0 ) /*compara el mnemocio con ADDS*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        ADDS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value); /*ejecuta la operación ADDS*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"LSR") == 0 ) /*compara el mnemocio con LSR*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        LSR(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta el desplazamiento LSR*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado del desplazamiento*/
	}
	if( strcmp(instruction.mnemonic,"LSL") == 0 ) /*compara el mnemocio con LSL*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        LSL(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta el desplazamiento LSR*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado del desplazamiento*/
	}
	if( strcmp(instruction.mnemonic,"ROR") == 0 ) /*compara el mnemocio con ROR*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        ROR(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta la operación ROR*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"ASRS") == 0 ) /*compara el mnemocio con ASRS*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        ASRS(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta la operación ASRS*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"REV") == 0 ) /*compara el mnemocio con REV*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        REV(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta la operación REV*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"REV16") == 0 )  /*compara el mnemocio con REV16*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        REV16(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta la operación REV16*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"BIC") == 0 ) /*compara el mnemocio con BIC*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        BIC(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta la operación BIC*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"MVN") == 0 ) /*compara el mnemocio con MVN*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        MVN(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta la operación MVN*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"RSBS") == 0 ) /*compara el mnemocio con RSBS*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        RSBS(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta la operación RSBS*/ 
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
	if( strcmp(instruction.mnemonic,"NOP") == 0 ) /*compara el mnemocio con NOP*/
	{
	    mvprintw(5,40,"Instruccion :%s\n",instruction.mnemonic); /*muestra el resultado de la operación*/
        NOP(); /*ejecuta la operación NOP*/
	}
	if( strcmp(instruction.mnemonic,"TST") == 0 ) /*compara el mnemocio con TST*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        TST(&registers[instruction.op1_value],&registers[instruction.op2_value]); /*ejecuta la operación TST*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
    if( strcmp(instruction.mnemonic,"LSLS") == 0 ) /*compara el mnemocio con LSLS*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        LSLS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value); /*ejecuta el desplazamiento LSLS con valor inmediato*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
    if( strcmp(instruction.mnemonic,"LSRS") == 0 ) /*compara el mnemocio con LSRS*/
	{
	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        LSRS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value); /*ejecuta el desplazamiento LSRS con valor inmediato*/
        mvprintw(8,40,"valor del registro %d\n",registers[instruction.op1_value]); /*muestra el resultado de la operación*/
	}
showRegisters(registers,15);
}
void obtenerPC(uint32_t *pcount)/* Función para obtener el program counter desde el main */
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
		switch(num)
		{
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
	if(num==3)
	{
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
	while ( fgets(buffer, 50, fp) != NULL && line<lines )
	{
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
