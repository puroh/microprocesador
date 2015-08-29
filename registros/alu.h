#include <stdint.h>
/**
*	\brief Función que suma
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/ 
uint32_t ADD(uint32_t Rm,uint32_t Rn,uint32_t Rd);
/**
*	\brief Función que resta
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/ 
uint32_t SUB(uint32_t Rm,uint32_t Rn,uint32_t Rd);
/**
*	\brief Función que multiplica
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/ 
uint32_t AND(uint32_t Rm,uint32_t Rn,uint32_t Rd);
/**
*	\brief Función de suma lógica
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/  
uint32_t ORR(uint32_t Rm,uint32_t Rn,uint32_t Rd);
/**
*	\brief Función lógica exclusiva 
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/ 
uint32_t EOR(uint32_t Rm,uint32_t Rn,uint32_t Rd);
/**
*	\brief Función que mueve un registro a otro 
*	\param R0 Operando 1
*	\param R1 Operando 2
*	\return Rd Un entero sin signo con el resultado
*/ 
uint32_t MOV(uint32_t Rm,uint32_t Rn,uint32_t Rd);
