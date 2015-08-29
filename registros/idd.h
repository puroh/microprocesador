#include <stdint.h>
<<<<<<< HEAD
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
=======
void LSLS(uint32_t *Rm,uint32_t *Rn);
void LSRS(uint32_t *Rm,uint32_t *Rn);
void ROR(uint32_t *Rm,uint32_t *Rn);
void ASRS(uint32_t *Rm,uint32_t *Rn);
>>>>>>> 617f899605fcc84aef36460062dea83e6bd8de51


