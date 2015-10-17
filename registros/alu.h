#include <stdint.h>
#include <stdbool.h>
/**
*	\brief Funcion que suma los valores de dos direcciones
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar 
*/
void ADD(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que resta los valores de dos direcciones
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar 
*/
void SUB(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que multiplica los valores de dos direcciones
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar 
*/
void AND(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion de suma logica entre los valores de dos direcciones
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar 
*/
void ORR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion logica exclusiva entre dos direcciones
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar 
*/
void EOR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion de desplazamiento logico a la izquierda
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void LSL(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion de desplazamiento logico a la izquierda 
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void LSR(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion de rotacion a la derecha
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Operador sin signo de 32 bits
*/
void RORS(uint32_t *Rm,uint32_t Rn);
/**
*	\brief Funcion de desplazamiento aritmetico logico a la derecha
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Operador sin signo de 32 bits
*/
void ASRS(uint32_t *Rm,uint32_t Rn);
/**
*	\brief Funcion que cambia el orden de los Bytes
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void REV(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que cambia de orden los bytes en cada halfword de 16 bits
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void REV16(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que ingresa un registro y el complemneto de otro
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Operador sin signo de 32 bits
*/
void BICS(uint32_t *Rm,uint32_t Rn);
/**
*	\brief Funcion que guarda el complemneto de un registro 
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void MVN(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que obtiene el complemento a dos de un numero
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void RSBS(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que no ejecuta ninguna operacion o mas bien no hace nada
*/
void NOP(void);
/**
*	\brief Funcion que escribe un valor en un resgistro
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void MOV(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que resta pero no guarda el resultado solo modifica banderas
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void CMP(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que realiza suma con carry 
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar
*/
void ADCS(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que suma pero no guarda el resultado solo modifica banderas 
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void CMN(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion de resta con carry
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar
*/
void SBC(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que escribe un valor inmediato en un registro
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Operador sin signo de 32 bits
*/
void MOVS(uint32_t *Rm,uint32_t Rn);
/**
*	\brief Funcion que resta un valor inmediato con el valor de direccion Rm
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Operador sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar
*/
void SUBS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn);
/**
*	\brief Funcion que suma un valor inmediato con el valor de direccion Rm
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Operador sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar
*/
void ADDS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn);
/**
*	\brief Funcion que multiplica bit a bit pero no guarad el resultado solo modifica banderas
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*/
void TST(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Funcion que realiza un desplazamiento logico a la izquierda dependiendo del valor inmediato
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Rn Operador sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar
*/
void LSLS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn);
/**
*	\brief Funcion que realiza un desplazamiento logico a la derecha dependiendo del valor inmediato
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Rn Operador sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar
*/
void LSRS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn);
/**
*	\brief Funcion 
*	\param bands
*/
void obtenerBandera(bool *bands);
/**
*	\brief Funcion de multiplicacion y solo guarda los 32 bits menos significativos
*	\param Rm Direccion que contiene el valor sin signo de 32 bits
*	\param Rn Direccion que contiene el valor sin signo de 32 bits
*	\return Rd Direccion que contiene el valor a retornar
*/
void MULS(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
