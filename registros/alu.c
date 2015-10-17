#include <stdint.h>
#include <stdbool.h>
#include "flags.h"
#include <curses.h>

bool banderas[4]; //Declara banderas booleanas
uint8_t comp=0; //Variable que se crea para no modificar algunas banderas 
void ADD(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero internamente realiza la operacion suma 
{
    *Rd=*Rm+*Rn; //Suma entre las direcciones que contiene  el valor de los registros a operar 
	comp=0; //Modifica todas las banderas
	flag(Rd,Rm,Rn,banderas,&comp); //Se dirige a la funcion flag para determinar si en el resultado hay banderas 
} 
void SUB(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero internamente realiza la operacion resta
{   
	uint32_t rn; //Se declara rn sin signo
	//attrset(COLOR_PAIR(2 ));  
	*Rd=*Rm+((~*Rn)+1); //Resta entre las dirección de Rm y Rn realizando complemento a 2
	rn=((~*Rn)+1); //Se realiza complemento a 2 al valor contenido en Rn
	comp=0; //Modifica todas las banderas 
    flag(Rd,Rm,&rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void AND(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero internamente realiza la operación de multiplicacion
{
    *Rd=*Rm&*Rn; //Multiplicación entre las direcciones que contiene  el valor de los registros a operar 
	comp=1; //Modifica solo una bandera
	flag(Rd,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas
}
void ORR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero internamente realiza la ORR entre las direcciones 
{
    *Rd=*Rm|*Rn; //Operador propio de Codeblocks que se encarga de hacer la operación ORR 
	comp=1; //Modifica solo una bandera
	flag(Rd,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas
}
void EOR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero internamente realiza la EOR entre las direcciones 
{
    *Rd=*Rm^*Rn; //Operador propio de Codeblocks que se encarga de hacer la operacion EOR
	comp=1; //Modifica solo una bandera
	flag(Rd,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas
}
void ADCS(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero internamnete realiza una suma con carry 
{
    *Rd=*Rm+*Rn+banderas[C]; //Suma las direciones mas el valor que se encuentre el la bandera del Carry 
    comp=1; //Modifica solo una bandera 
    flag(Rd,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas
}
void CMN(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero internamente realiza una suma que solo modifica las banderas sin guardar el resultado
{
    uint32_t R; //Se declara una variable auxiliar para determinar los valores de las banderas 
    R=*Rm+*Rn; //Suma los valores de las direcciones Rm y Rn 
    comp=0; //Modifica todas banderas 
    flag(&R,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas
}
void SBC(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero internamnete realiza una resta con carry 
{
    *Rd=*Rm+((~*Rn)+1)+banderas[C]; //Resta las direciones mas el valor que se encuentre el la bandera del Carry
    comp=0; //Modifica todas las banderas 
    flag(Rd,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void MOVS(uint32_t *Rm,uint32_t Rn) //Funcion que no retorna pero escribe un valor en un registro 
{
    *Rm=Rn; //Escribe el valor que tenga Rn en la direccion de Rm
    comp=2; //Modifica solo dos banderas 
    flag(Rm,Rm,&Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void SUBS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn) //Funcion que no retorna pero internamente realiza una resta entre el valor de la direccion Rm y un valor inmediato
{
    *Rd=*Rm+((~Rn)+1); //Resta complemento a 2 con un valor inmediato 
	Rn=((~Rn)+1); //Se realiza complemento a 2
	comp=0; //Modifica todas las banderas 
    flag(Rd,Rm,&Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void ADDS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn) //Funcion que no retorna pero internamente realiza una suma entre el valor de la direccion Rm y un valor inmediato
{
    *Rd=*Rm+Rn; //Suma con un valor inmediato 
    comp=0; //Modifica todas las banderas 
    flag(Rd,Rm,&Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void LSL(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero realiza un desplazamiento logico a la derecha 
{
	*Rm=*Rm<<*Rn; //Desplaza a la izquierda el dato de la direccion Rm tantas veces sea el valor de la direccion Rn
	comp=3; //Modifica solo una bandera
	flag(Rm,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void LSR(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero realiza un desplazamiento logico a la izquierda 
{
	*Rm=*Rm>>*Rn; //Desplaza a la derecha el dato de la direccion Rm tantas veces sea el valor de la direccion Rn
	comp=1; //Modifica solo una bandera 
	flag(Rm,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void RORS(uint32_t *Rm,uint32_t Rn) //Funcion que no retorna pero realiza una rotacion de los datos 
{
	uint32_t a1,a2; //Se declaran nuevas variables que se usaran para la rotacion de datos
    a1=*Rm>>Rn; //Desplaza el valor que haiga en Rm segun el valor de Rn 
    a2=*Rm<<(32-Rn); //Desplaza el valor segun sea el valor de la resta entre 32 y Rn
    *Rm=a1|a2; //Realiza una OR entre los valores desplazados anteriormente
    comp=1; //Modifica solo una bandera
    flag(Rm,Rm,&Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
    banderas[C]=(*Rm>>(Rn-1))&1; //Se dirije a la funcion flag para determinar si en el resultado hay banderas
}
void ASRS(uint32_t *Rm,uint32_t Rn) //Funcion que no retorna pero realiza un desplazamiento aritmetico a la derecha
{
	*Rm=(*Rm>>Rn); //Desplazamiento de Rm segun el valor de Rn y se guarda en la direccion de Rm 
	Rn=~0<<(32-Rn); //Resta 32 bits al valor en Rn y hace un corrimiento de 0 negado guardando el resultado en la dirección de Rn
	*Rm|=Rn; //Realiza la opercion OR entre las direcciones Rm y Rn, y el resultado se guarda en la direccion Rm
	comp=1; //Modifica solo una bandera
	flag(Rm,Rm,&Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
	banderas[C]=(*Rm>>(Rn-1))&1; //Se dirije a la funcion flag para determinar si en el resultado hay banderas
}
void MOV(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero desplaza el valor en Rm las veces del valor Rn
{
    *Rm=*Rn; //Igualacion de las direcciones para copiar el valor de Rn en la direccion de Rm 
	comp=2; //Modifica solo dos banderas 
	flag(Rm,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void CMP(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero internamente realiza una resta que solo modifica las banderas sin guardar el resultado
{
    uint32_t R,rn; //Se declara una variable auxiliar para determinar los valores de las banderas 
    R=*Rm+((~*Rn)+1); //Resta complemento a 2
	rn=((~*Rn)+1); //Se realiza complemento a 2 al valor que contenga Rn
	comp=0; //Modifica todas las banderas 
	flag(&R,Rm,&rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void REV(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero cambia el orden de los Bytes 
{
    *Rn=*Rm<<24; //Desplaza el valor en Rm 24 bits a la izquierda 
    *Rn=*Rn|*Rm>>24; //Realiza la operacion OR entre el valor en Rn y el desplazamiento de 24 bit a la derecha del valor en Rm 
    *Rm=*Rn|((((*Rm<<8)>>24)<<8)|(((*Rm<<16)>>24)<<16)); //Mueve los bytes en la posicion deseada realizando una OR como ultima operacion 
}
void REV16(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero cambia el orden de los Bytes en cada halfword de 16 bits
{
    *Rn=((*Rm<<24)>>16)|((*Rm<<16)>>24); //Realiza una OR entre los desplazamientos de bits deseados 
    *Rm=*Rn|(((*Rm>>24)<<16)|((*Rm>>16)<<24)); //Realiza una OR entre los desplazamientos de bits deseados 
}
void BICS(uint32_t *Rm,uint32_t Rn) //Funcion que no retorna pero realiza internamente una AND entre un registro y el complemento del otro
{
	*Rm &= ~Rn; //Operacion AND entre el registro Rm y el complemento del registro Rn 
	comp=1; //Modifica solo una bandera
    flag(Rm,Rm,&Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void MVN(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero guarda el complemento de un registro
{
	*Rm=~*Rn; //Igualacion de la direccion Rm con el complemneto en la direccion de Rn 
	comp=1; //Modifica solo una bandera
    flag(Rm,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void RSBS(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero obtiene el complemento a dos de un numero 
{
	*Rm=(~*Rn)+1; //Iguala la direccion Rm con el valor a complemento 2 de la direccion Rn 
}
void NOP(void) //Funcion que no hace nada 
{
}
void TST(uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero realiza la operacion AND bit a bit cambiando el valor de las banderas sin guardar el resultado
{
    uint32_t R; //Variable auxiliar qiue se usa para determinar el valor de las banderas sin guardar en registro 
    R=*Rm&*Rn; //Operacion AND entre las direcciones Rm y Rn 
    comp=1; //Modifica solo una bandera 
    flag(&R,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}
void LSLS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn) //Funcion que no retorna pero realiza un desplazamiento logico a la izquierda de un valor inmediato 
{
    uint32_t a1,aux;  //Se declaran dos variables que serviran como auxiliares  
    aux=*Rm; //Se declara una auxiliar con el valor contenido en Rm
    (*Rd)=(*Rm)<<(Rn); //Desplaza el valor en la direccion Rm las veces del valor inmediato Rn 
    printw("alu_linea164.resultado en la alu %u",*Rd); //Imprime en pantalla haciendo uso de la libreria curses
    comp=1; //Modifica solo una bandera 
    flag(Rd,Rm,&Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
    a1=((aux<<(Rn-1))&(1<<31))>>31; //Operacion que permitira determinar si hay banderas
    banderas[C]=a1; //Se dirije a la funcion flag para determinar si en el resultado hay banderas
}
void LSRS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn) //Funcion que no retorna pero realiza un desplazamiento logico a la derecha de un valor inmediato 
{
    uint32_t aux; //Se declara una variable que servira como auxiliar 
    aux=*Rm; //Se declara una variables auxiliar con la direccion de Rm
    *Rd=*Rm>>Rn; //Desplaza el valor en la direccion Rm las veces del valor inmediato Rn 
    comp=1; //Modifica solo una bandera 
    flag(Rm,Rm,&Rn,banderas,&comp); //Se dirije a la función flag para determinar si en el resultado hay banderas 
    banderas[C]=(aux>>(Rn-1))&1; //Se dirije a la funcion flag para determinar si en el resultado hay banderas
}
void obtenerBandera(bool *bands) //Funcion que se crea para modificar las banderas en otros archivos dentro del proyecto 
{
    bands=banderas; //Manda al archivo salto la modificacio|n de las banderas 
}
void MULS(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn) //Funcion que no retorna pero realiza la multiplicacion entre las direcciones de los dos registros 
{
    *Rd=(*Rm)*(*Rn); //Multiplica el valor que se encuentre en las direcciones de Rm y Rn y lo guarda en la direccion de Rd 
    comp=2; //Modifica dos banderas 
    flag(Rd,Rm,Rn,banderas,&comp); //Se dirije a la funcion flag para determinar si en el resultado hay banderas 
}

