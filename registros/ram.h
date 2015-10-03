#include <stdint.h>
#define MEMORIA 64
#define DIRMAXMEM 255
/**
*	\brief Función de cambio de orden de los bytes en cada halfword de 16 bits
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void inimemoria(uint32_t *memoria,int tama);
/**
*	\brief Función de cambio de orden de los bytes en cada halfword de 16 bits
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void mostrar_memoria(uint32_t *memoria , int tama);
/**
*	\brief Función de cambio de orden de los bytes en cada halfword de 16 bits
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void PUSH(uint32_t *registros,uint32_t *memory,uint8_t *res);
/**
*	\brief Función de cambio de orden de los bytes en cada halfword de 16 bits
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
void POP(uint32_t *registros,uint32_t *memory,uint8_t *res);
/**
*	\brief Función de cambio de orden de los bytes en cada halfword de 16 bits
*	\param Rm Dirección que contiene el operador con signo de 32 bits
*	\param Rn Dirección que contiene el operador con signo de 32 bits
*/
uint8_t bitcount(uint8_t *R);
