#include "decoder.h"
#include "alu.h"
#include "salto.h"
#include <stdint.h>
#include "screen.h"
#include "ram.h"
#include "NVIC.h"

    uint32_t registers[15];
    uint32_t memoria[MEMORIA];//se define el program counter y el LR que se modifica con BL
    uint8_t  guardar[16]={1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1};
    uint8_t i,indicador=0;
    uint8_t exnum[16]={0};
    uint16_t bin=0;

void iniciaram(void) //Funcion que inicia la ram
{
	inimemoria(memoria,MEMORIA); //paramteros memoria y MEMORIA que son los encargados del almacenamiento de la ram
}
void decodeInstruction(instruction_t instruction)
{
    if(registers[13]==0)
	{
		registers[13]=DIRMAXMEM+1;
	}
    if(indicador==0)
		NVIC_EnableIRQ(exnum,0);
            for(i=0;i<16;i++)
			{
				if(exnum[i]==1 && indicador==0)
				{
                    indicador++;
                    strcpy(instruction.mnemonic,"hola");
                    if(indicador==1)
                    PUSHINTERRUPT(registers,memoria,guardar);
                    break;
                }
            }
	attron(COLOR_PAIR(2));//Se mofifica el color del printw
    mvprintw(4,40,"Valor de PC %d\n",registers[14]);//se imprime en pantalla en la posicion 4,40
    if( strcmp(instruction.mnemonic,"PUSH") == 0 ){

            for(i=0;i<8;i++)
        {
			bin+=(instruction.registers_list[i]<<i);
            mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
        }
		bin+=(11<<12)+(1<<10)+(instruction.registers_list[14]<<8);
        mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
	    mvprintw(9,40,"instruccion :%s ",instruction.mnemonic);
        //mostrar_memoria(memoria,MEMORIA);
        PUSH(registers,memoria,instruction.registers_list);
        // mostrar_memoria(memoria,MEMORIA);
	}
	if( strcmp(instruction.mnemonic,"POP") == 0 )
	{
		for(i=0;i<8;i++)
        {
			bin+=(instruction.registers_list[i]<<i);
            mvprintw(15,40,"Instruccion binaria :%.8X ",bin);
        }
		bin=(11<<12)+(3<<10)+(instruction.registers_list[15]<<8);
        mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
	    mvprintw(10,40,"instruccion :%s ",instruction.mnemonic);
        POP(registers,memoria,instruction.registers_list);
        //mostrar_memoria(memoria,MEMORIA)
	}
if( strcmp(instruction.mnemonic,"ADD") == 0 ) // compara el mnemonico con ADD
	{
		bin=(1<<14)+(1<<10)+(instruction.op2_value<<3)+((8&instruction.op1_value)<<4)+(7&instruction.op1_value);
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        ADD(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);//ejecuta la funcion ADD localizada en alu.c
        mvprintw(8,40,"valor del registers %d",registers[instruction.op1_value]);//muestra el resultado de la operacion
	}

	if( strcmp(instruction.mnemonic,"MULS") == 0 ){
			bin=(1<<14)+(13<<6)+(instruction.op2_value<<3)+instruction.op3_value;
            mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	      mvprintw(5,40,"instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
          MULS(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);
          mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]);
	}
    if( strcmp(instruction.mnemonic,"SUB") == 0 ) // compara el mnemonico con SUB
	{
		bin=(13<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        SUB(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);//ejecuta la funcion SUB localizada en alu.c
        mvprintw(8,40,"valor del registers %d",registers[instruction.op1_value]);//muestra el resultado de la operacion
	}
	if( strcmp(instruction.mnemonic,"AND") == 0 ) //compara el mnemonico con AND
	{
		bin=(1<<14)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        AND(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);//ejecuta la funcion AND
        mvprintw(8,40,"valor del registers %d",registers[instruction.op1_value]);//muestra el resultado de la operacion
	}
	if( strcmp(instruction.mnemonic,"ORR") == 0 ) //compara el mnemonico con ORR
	{
		bin=(1<<14)+(3<<8)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        ORR(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);//ejecuta la funcion ORR
        mvprintw(8,40,"valor del registers %d",registers[instruction.op1_value]);//muestra el resultado de la operacion
	}
	if( strcmp(instruction.mnemonic,"EOR") == 0 ) //compara el mnemonico con EOR
	{
		bin=(1<<14)+(1<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        EOR(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]);//ejecuta la funcion EOR
        mvprintw(8,40,"valor del registers %d",registers[instruction.op1_value]);//muestra el resultado de la operacion
	}
	if( strcmp(instruction.mnemonic,"MOV") == 0 ) //compara el mnemonico con MOV
	{
		bin=(1<<14)+(3<<9)+(instruction.op2_value<<3)+(7&instruction.op1_value)+((8&instruction.op1_value)<<4);
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        MOV(&registers[instruction.op1_value],&registers[instruction.op2_value]);//ejecuta la operacion MOV
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]);//muestra el resultado de la operacion
	}
	if( strcmp(instruction.mnemonic,"CMP") == 0 ) //compara el mnemonico con CMP
	{
		bin=(1<<14)+(5<<8)+(instruction.op2_value<<3)+(7&instruction.op1_value)+((8&instruction.op1_value)<<4);
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

        mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        CMP(&registers[instruction.op1_value],&registers[instruction.op2_value]);//ejecuta la funcion CMP
	}
	if( strcmp(instruction.mnemonic,"ADCS") == 0 ) //compara el mnemocio con ADCS
	{
		bin=(1<<14)+(5<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        ADCS(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]); //ejecuta la operacción ADCS
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]);//muestra el resultado de la operacion
	}
	if( strcmp(instruction.mnemonic,"CMN") == 0 ) //compara el mnemocio con CMN
	{
		bin=(1<<14)+(11<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        CMN(&registers[instruction.op1_value],&registers[instruction.op2_value]); //ejecuta la operación CMN
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operacion
	}
	if( strcmp(instruction.mnemonic,"SBC") == 0 ) //compara el mnemocio con CMN
	{	
		bin=(1<<14)+(3<<7)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        SBC(&registers[instruction.op1_value],&registers[instruction.op2_value],&registers[instruction.op3_value]); //ejecuta la operación SBC
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operacion
	}
	if( strcmp(instruction.mnemonic,"MOVS") == 0 ) //compara el mnemocio con MOVS
	{
		bin=(1<<13)+(instruction.op1_value<<8)+instruction.op2_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

        mvprintw(5,40,"Instruccion :%s %c%d,%c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        MOVS(&registers[instruction.op1_value],instruction.op2_value); //ejecuta la función MOVS
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"SUBS") == 0 ) //compara el mnemocio con SUBS
	{
		bin=(15<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        SUBS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value); //ejecuta la operación SUBS
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"ADDS") == 0 ) //compara el mnemocio con ADDS
	{
		bin=(7<<10)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);


	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        ADDS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value); //ejecuta la operación ADDS
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"LSR") == 0 ) //compara el mnemocio con LSR
	{
		bin=(1<<14)+(3<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        LSR(&registers[instruction.op1_value],&registers[instruction.op2_value]); //ejecuta el desplazamiento LSR
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado del desplazamiento
	}
	if( strcmp(instruction.mnemonic,"LSL") == 0 ) //compara el mnemocio con LSL
	{
		bin=(1<<14)+(1<<7)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        LSL(&registers[instruction.op1_value],&registers[instruction.op2_value]); //ejecuta el desplazamiento LSR
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado del desplazamiento
	}
	if( strcmp(instruction.mnemonic,"RORS") == 0 ) //compara el mnemocio con ROR
	{
		bin=(1<<14)+(7<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        RORS(&registers[instruction.op1_value],instruction.op2_value); //ejecuta la operación ROR
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"ASRS") == 0 ) //compara el mnemocio con ASRS
	{
		bin=(1<<12)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        ASRS(&registers[instruction.op1_value],instruction.op2_value); //ejecuta la operación ASRS
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"REV") == 0 ) //compara el mnemocio con REV
	{	
		bin=(11<<12)+(5<<9)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        REV(&registers[instruction.op1_value],&registers[instruction.op2_value]); //ejecuta la operación REV
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"REV16") == 0 )  //compara el mnemocio con REV16
	{
		bin=(11<<12)+(5<<9)+(1<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);


	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        REV16(&registers[instruction.op1_value],&registers[instruction.op2_value]); //ejecuta la operación REV16
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"BICS") == 0 ) //compara el mnemocio con BIC
	{
		bin=(1<<14)+(14<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        BICS(&registers[instruction.op1_value],instruction.op2_value); //ejecuta la operación BIC
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"MVN") == 0 ) //compara el mnemocio con MVN
	{
		bin=(1<<14)+(15<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);



        MVN(&registers[instruction.op1_value],&registers[instruction.op2_value]); //ejecuta la operación MVN
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"RSBS") == 0 ) //compara el mnemocio con RSBS
	{
		bin=(1<<14)+(9<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        RSBS(&registers[instruction.op1_value],&registers[instruction.op2_value]); //ejecuta la operación RSBS
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
	if( strcmp(instruction.mnemonic,"NOP") == 0 ) //compara el mnemocio con NOP
	{
		bin=(11<<12)+(15<<8);
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s\n",instruction.mnemonic); //muestra el resultado de la operación
        NOP(); //ejecuta la operación NOP
	}
	if( strcmp(instruction.mnemonic,"TST") == 0 ) //compara el mnemocio con TST
	{
		bin=(1<<14)+(1<<9)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value);
        TST(&registers[instruction.op1_value],&registers[instruction.op2_value]); //ejecuta la operación TST
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
    if( strcmp(instruction.mnemonic,"LSLS") == 0 ) //compara el mnemocio con LSLS
	{
		bin=(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        LSLS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value); //ejecuta el desplazamiento LSLS con valor inmediato
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}
    if( strcmp(instruction.mnemonic,"LSRS") == 0 ) //compara el mnemocio con LSRS
	{
		bin=(1<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);


	    mvprintw(5,40,"Instruccion :%s %c%d,%c%d,%c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);
        LSRS(&registers[instruction.op1_value],&registers[instruction.op2_value],instruction.op3_value); //ejecuta el desplazamiento LSRS con valor inmediato
        mvprintw(8,40,"valor del registers %d\n",registers[instruction.op1_value]); //muestra el resultado de la operación
	}


	if( strcmp(instruction.mnemonic,"LDR") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            bin=(13<<11)+((instruction.op3_value&0xFF)<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            instruction.op3_value<<=2;
            if(((*(registers+instruction.op2_value)+instruction.op3_value)>=0x20000000)&&((*(registers+instruction.op2_value)+instruction.op3_value)<0x40000000))
            {
                LDR(registers+instruction.op1_value,(*(registers+instruction.op2_value))&0xFF,instruction.op3_value&0xFF,memoria);
            }
            if((*(registers+instruction.op2_value)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registers+instruction.op2_value)+instruction.op3_value)>=0x40000000)
            {

            }
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='S') && (instruction.op3_type=='#'))
        {
            bin=(19<<11)+(instruction.op1_value<<8)+(instruction.op3_value&0xFF);
            instruction.op3_value<<=2;
            if(((*(registers+13)+instruction.op3_value)>=0x20000000)&&((*(registers+13)+instruction.op3_value)<0x40000000))
            {
                LDR(registers+instruction.op1_value,(*(registers+13))&0xFF,instruction.op3_value&0xFF,memoria);
            }
            if((*(registers+13)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registers+13)+instruction.op3_value)>=0x40000000)
            {

            }
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='P') && (instruction.op3_type=='#')) // label
        {
            bin=(9<<11)+(instruction.op1_value<<8)+(instruction.op3_value&0xFF);
            instruction.op3_value<<=2;
            if(((*(registers+15)+instruction.op3_value)>=0x20000000)&&((*(registers+15)+instruction.op3_value)<0x40000000))
            {
                LDR(registers+instruction.op1_value,(*(registers+15))&0xFF,instruction.op3_value&0xFF,memoria);
            }
            if((*(registers+15)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registers+15)+instruction.op3_value)>=0x40000000)
            {

            }
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {
            bin=(11<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            if(((*(registers+instruction.op2_value)+*(registers+instruction.op3_value))>=0x20000000)&&(*(registers+instruction.op2_value)+*(registers+instruction.op3_value)<0x40000000))
            {
                LDR(registers+instruction.op1_value,(*(registers+instruction.op2_value))&0xFF,(*(registers+instruction.op3_value))&0xFF,memoria);
            }
            if((*(registers+instruction.op2_value)+*(registers+instruction.op3_value))<0x20000000)
            {

            }
            if((*(registers+instruction.op2_value)+*(registers+instruction.op3_value))>=0x40000000)
            {

            }
        }
    }
    if( strcmp(instruction.mnemonic,"LDRB") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            bin=(15<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            if(((*(registers+instruction.op2_value)+instruction.op3_value)>=0x20000000)&&((*(registers+instruction.op2_value)+instruction.op3_value)<0x40000000))
            {
                LDRB(registers+instruction.op1_value,(*(registers+instruction.op2_value))&0xFF,instruction.op3_value&0xFF,memoria);
            }
            if((*(registers+instruction.op2_value)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registers+instruction.op2_value)+instruction.op3_value)>=0x40000000)
            {

            }

        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {
            bin=(1<<14)+(7<<10)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            if(((*(registers+instruction.op2_value)+*(registers+instruction.op3_value))>=0x20000000)&&(*(registers+instruction.op2_value)+*(registers+instruction.op3_value)<0x40000000))
            {
                LDRB(registers+instruction.op1_value,(*(registers+instruction.op2_value))&0xFF,(*(registers+instruction.op3_value))&0xFF,memoria);
            }
            if((*(registers+instruction.op2_value)+*(registers+instruction.op3_value))<0x20000000)
            {

            }
            if((*(registers+instruction.op2_value)+*(registers+instruction.op3_value))>=0x40000000)
            {

            }
        }

    }
    if( strcmp(instruction.mnemonic,"LDRH") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            bin=(1<<15)+(1<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            instruction.op3_value<<=1;
            if(((*(registers+instruction.op2_value)+instruction.op3_value)>=0x20000000)&&((*(registers+instruction.op2_value)+instruction.op3_value)<0x40000000))
            {
                LDRH(registers+instruction.op1_value,(*(registers+instruction.op2_value))&0xFF,instruction.op3_value&0xFF,memoria);
            }
            if((*(registers+instruction.op2_value)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registers+instruction.op2_value)+instruction.op3_value)>=0x40000000)
            {

            }
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {
            bin=(5<<12)+(5<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            if(((*(registers+instruction.op2_value)+*(registers+instruction.op3_value))>=0x20000000)&&(*(registers+instruction.op2_value)+*(registers+instruction.op3_value)<0x40000000))
            {
                LDRH(registers+instruction.op1_value,(*(registers+instruction.op2_value))&0xFF,(*(registers+instruction.op3_value))&0xFF,memoria);
            }
            }
            if((*(registers+instruction.op2_value)+*(registers+instruction.op3_value))<0x20000000)
            {

            }
            if((*(registers+instruction.op2_value)+*(registers+instruction.op3_value))>=0x40000000)
            {

            }
    }



    if( strcmp(instruction.mnemonic,"STR") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            STR(registers+instruction.op1_value,(*(registers+instruction.op2_value))&0xFF,(*(registers+instruction.op3_value))&0xFF,memoria);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='S') && (instruction.op3_type=='#'))
        {
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {
        }
    }
    if( strcmp(instruction.mnemonic,"STRB") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {

        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {

        }
    }
    if( strcmp(instruction.mnemonic,"STRH") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {

        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {

        }
    }



	if(strncmp(instruction.mnemonic,"B",1)==0) //se compara  con strncmp para comparar la primer letra del mnemonico con B para no aumentar pc si se ejecuta un B
	{

        if( strcmp(instruction.mnemonic,"BNE") == 0 )//compara BNE con el mnemonico. Si es igual ejecuta las instrucciones
		{
			bin=(13<<12)+(1<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BNE(&registers[15],instruction.op1_value);//ejecuta la operacion BNE
        }
        if( strcmp(instruction.mnemonic,"B") == 0 ) //compara B con el mnemonico en en code.txt en el valor del arreglo definido por PC. Si es igual ejecuta las instrucciones
		{
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            B(&registers[15],instruction.op1_value); //ejecuta la operacion B
        }
        if( strcmp(instruction.mnemonic,"BEQ") == 0 ) //compara BEQ con el mnemonico de las instrucciones en el .txt
		{
			bin=(13<<12)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BEQ(&registers[15],instruction.op1_value);//ejecuta la funcion BEQ de salto.c
        }
        if( strcmp(instruction.mnemonic,"BCS") == 0 ) //compara el mnemonico con BCS
		{
			bin=(13<<12)+(2<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BCS(&registers[15],instruction.op1_value);//ejecuta la funcion BCS de salto.c
        }
        if( strcmp(instruction.mnemonic,"BCC") == 0 ) //compara el mnemonico con BCC
		{
			bin=(13<<12)+(3<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BCC(&registers[15],instruction.op1_value);//ejecuta la operacion BCC de salto.c
        }

        if( strcmp(instruction.mnemonic,"BMI") == 0 ) //compara el mnemonico con BMI
		{
			bin=(13<<12)+(4<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BMI(&registers[15],instruction.op1_value);//ejecuta la operacion BMI de salto.c
        }
        if( strcmp(instruction.mnemonic,"BPL") == 0 ) //compara el mnemonico con BPL
		{
			bin=(13<<12)+(5<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BPL(&registers[15],instruction.op1_value);//ejecuta la funcion BPL de salto.c
        }
        if( strcmp(instruction.mnemonic,"BVS") == 0 ) //compara el mnemonico con BVS
		{
			bin=(13<<12)+(6<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BVS(&registers[15],instruction.op1_value);//ejecuta la funcion BVS
        }
        if( strcmp(instruction.mnemonic,"BVC") == 0 ) //compara el mnemocico con BVC
		{
			bin=(13<<12)+(7<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BVC(&registers[15],instruction.op1_value);//ejecuta la funcion BVC
        }
        if( strcmp(instruction.mnemonic,"BHI") == 0 ) //compara el mnemonico con BHI
		{
			bin=(13<<12)+(8<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BHI(&registers[15],instruction.op1_value);//ejecuta BLS
        }
        if( strcmp(instruction.mnemonic,"BLS") == 0 ) //compara el mnemonico con BLS
		{
			bin=(13<<12)+(9<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BLS(&registers[15],instruction.op1_value);//ejecuta la funcion BLS de salto.c
        }
        if( strcmp(instruction.mnemonic,"BGE") == 0 ) //compara el mnemonico con BGE
		{
			bin=(13<<12)+(10<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BGE(&registers[15],instruction.op1_value); //ejecuta BGE
        }
        if( strcmp(instruction.mnemonic,"BLT") == 0 ) //compara el mnemonico con BLT
		{
			bin=(13<<12)+(11<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BLT(&registers[15],instruction.op1_value); //ejecuta BLT
        }
        if( strcmp(instruction.mnemonic,"BGT") == 0 ) //compara el mnemonico con BGT
		{
			bin=(13<<12)+(12<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BGT(&registers[15],instruction.op1_value);//ejecuta la funcion BGT en salto.c
        }
        if( strcmp(instruction.mnemonic,"BLE") == 0 ) //compara el mnemonico con BLE
		{
			bin=(13<<12)+(13<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BLE(&registers[15],instruction.op1_value);//ejecuta la funcion BLE en salto.c
        }
        if( strcmp(instruction.mnemonic,"BAL") == 0 ) //compara el mnemonico con BAL
		{
			bin=(13<<12)+(14<<8)+instruction.op1_value;
		    mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);
            mvprintw(5,40,"Instruccion :%s %c%d\n",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
            BAL(&registers[15],instruction.op1_value);//ejecuta la funcion BAL en salto.c
        }
        if( strcmp(instruction.mnemonic,"BL") == 0 ){
			bin=(31<<11)+(2047&instruction.op1_value);
            mvprintw(15,40,"Instruccion binaria :%.8X ",bin);

              mvprintw(5,40,"Instruccion :%s %c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value);
              BL(&registers[15],instruction.op1_value,&registers[14]);
                                                        }
        if( strcmp(instruction.mnemonic,"BX") == 0 ){
			bin=(1<<14)+(14<<7)+(instruction.op1_value<<3);
            mvprintw(15,40,"Instruccion binaria :%.8X \n",bin);

              mvprintw(5,40,"Instruccion :%s %c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value);

              NVIC_DisableIRQ(exnum,0);

              POPINTERRUPT(registers,memoria,guardar);

              mostrar_memoria(memoria,MEMORIA);

              BX(&registers[15],&registers[14]);
                                                        }
}
    else //si no se ejecuta alguna funcion B el pc sigue aumentando
	{
        registers[15]+=2; //incrementa el valor del pc
    }
showRegisters(registers,16);
}
void obtenerPC(uint32_t *pcount)// Función para obtener el program counter desde el main 
{
*pcount=registers[15];
}
void obtener_registros(uint32_t *pcount)
{
    uint32_t i;
    for(i=0;i<16;i++){
    pcount[i]=registers[i];}
}
void obtener_memoria(uint32_t *pcount)
{
	 uint8_t i;
    for(i=0;i<MEMORIA;i++){
    pcount[i]=memoria[i];}
}


instruction_t getInstruction(char* instStr)
{

	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;

	strcpy(split, instStr);
	// Obtiene el mnemonico de la instrucción 
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	// Separa los operandos 
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;

						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}
				break;

			case 2:

			    if(split[0] == '[')
					split++;

				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}
	}

	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}

	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);

	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	// Puntero a un archivo  
	int lines;	// Cantidad de líneas del archivo 
	int line=0;	// Línea leida 
	char buffer[50]; // Almacena la cadena leida 

	fp = fopen(filename, "r");	// Abrir el archivo como solo lectura 
	if( fp==NULL )
		return -1;	// Error al abrir el archivo 

	lines = countLines(fp)-1;	// Cantidad de líneas

	// Asignación dinámica de memoria para cada instrucción 
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines )
	{
        instructions->array[line] = (char*)malloc(strlen(buffer)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	// Cierra el archivo 

	return lines;
}
int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}
