#include <stdint.h>
/**
*	\brief Función que suma.
*	\param Rm Operador con signo de 32 bits.
*	\param Rn Operador con signo de 32 bits.
*	\return Rd Un entero con signo de 32 bits que contiene el resultado.
*/
void ADD(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función que resta.
*	\param Rm Operador con signo de 32 bits.
*	\param Rn Operador con signo de 32 bits.
*	\return Rd Un entero con signo de 32 bits que contiene el resultado.
*/
void SUB(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función que multiplica.
*	\param Rm Operador sin signo de 32 bits.
*	\param Rn Operador sin signo de 32 bits.
*	\return Rd Un entero sin signo de 32 bits que contiene el resultado.
*/
void AND(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función de suma lógica.
*	\param Rm Operador sin signo de 32 bits.
*	\param Rn Operador sin signo de 32 bits.
*	\return Rd Un entero sin signo de 32 bits que contiene el resultado.
*/
void ORR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función lógica exclusiva.
*	\param Rm Operador sin signo de 32 bits.
*	\param Rn Operador sin signo de 32 bits.
*	\return Rd Un entero sin signo de 32 bits que contiene el resultado.
*/
void EOR(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función que mueve un registro a otro.
*	\param Rm Operando sin signo de 32 bits.
*	\param Rn Operando sin signo de 32 bits.
*/
void MOV(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función.
*	\param Rm Operando sin signo de 32 bits.
*	\param Rn Operando sin signo de 32 bits.
*/
void CMP(uint32_t *Rm,uint32_t *Rn);
