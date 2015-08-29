#include <stdint.h>
/**
*	\brief Función de desplazamiento lógico a la izquierda
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/ 
uint32_t LSLS(uint32_t Rm,uint32_t Rn,uint32_t Rd);
/**
*	\brief Función de desplazamiento lógico a la derecha 
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/ 
uint32_t LSRS(uint32_t Rm,uint32_t Rn,uint32_t Rd);
/**
*	\brief Función de rotación a la derecha
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/ 
uint32_t ROR(uint32_t Rm,uint32_t Rn,uint32_t Rd);
/**
*	\brief Función de desplazamiento aritmético lógico
*	\param Rm Operador con signo de 32 bits
*	\param Rn Operador con signo de 32 bits
*	\return Rd Un entero con signo de 32 bits que contiene el resultado
*/ 
uint32_t ASRS(uint32_t Rm,uint32_t Rn,uint32_t Rd);
/**
*	\brief Función de desplazamiento lógico a la izquierda
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/ 
void LSLS(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función de desplazamiento lógico a la derecha
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/ 
void LSRS(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función de rotación a la derecha
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/ 
void ROR(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función de desplazamiento aritmético lógico
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/ 
void ASRS(uint32_t *Rm,uint32_t *Rn);



