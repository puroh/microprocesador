#include <stdbool.h>
#include <stdint.h>
#define C 0
#define Z 1
#define N 2
#define V 3

/**
*	\brief Funcion que determina las banderas (C,Z y N)
*	\param Rd Direccion que contiene el operador sin signo de 32 bits
*	\param Rm Direccion que contiene el operador sin signo de 32 bits
*	\param Rn Direccion que contiene el operador sin signo de 32 bits
*	\return banderas Un booleano con el resultado (0 y 1) dependiendo el caso
*/
void flag(uint32_t *Rd,uint32_t *Rm,uint32_t *Rn,bool *banderas,uint8_t *compar);

