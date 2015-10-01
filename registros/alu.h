#include <stdint.h>
#include <stdbool.h>
/**
*	\brief Función que suma
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/
void ADD(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función que resta
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/
void SUB(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función que multiplica
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/
void AND(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función de suma lógica
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/
void ORR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función lógica exclusiva
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/
void EOR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función que mueve un registro a otro
*	\param R0 Operando 1
*	\param R1 Operando 2
*	\return Rd Un entero sin signo con el resultado
*/
/**
*	\brief Función de desplazamiento lógico a la izquierda
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void LSL(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función de desplazamiento lógico a la derecha
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void LSR(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función de rotación a la derecha
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void RORS(uint32_t *Rm,uint32_t Rn);
/**
*	\brief Función de desplazamiento aritmético lógico
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void ASRS(uint32_t *Rm,uint32_t Rn);
/**
*	\brief Función de cambio de orden de a 1 byte
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void REV(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función de cambio de orden de los bytes en cada halfword de 16 bits
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void REV16(uint32_t *Rm,uint32_t *Rn);

void BICS(uint32_t *Rm,uint32_t Rn);

void MVN(uint32_t *Rm,uint32_t *Rn);

void RSBS(uint32_t *Rm,uint32_t Rn);

void NOP(void);
void MOV(uint32_t *Rm,uint32_t *Rn);
void CMP(uint32_t *Rm,uint32_t *Rn);
void ADCS(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
void CMN(uint32_t *Rm,uint32_t *Rn);
void SBC(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
void MOVS(uint32_t *Rm,uint32_t Rn);
void SUBS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn);
void ADDS(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
void TST(uint32_t *Rm,uint32_t *Rn);
void LSLS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn);
void LSRS(uint32_t *Rd,uint32_t *Rm,uint32_t Rn);
void obtenerBandera(bool *bands);
void MULS(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
