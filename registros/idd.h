#include <stdint.h>
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
/**
*	\brief Función 
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void BIC(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función 
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void MVN(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función 
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void RSBS(uint32_t *Rm,uint32_t *Rn);
/**
*	\brief Función 
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void NOP(void);

