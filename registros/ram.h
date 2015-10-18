#include <stdint.h>
#define MEMORIA 64
#define DIRMAXMEM 255
/**
*	\brief Funcion que inicia la memoria, es decir comienza a desde el valor maximo y va disminuye (descendente)
*	\param memoria Direccion en la cual se almacenan los datos en la memoria
*	\param tama Es el tamaño de los datos a almacenar
*/
void inimemoria(uint32_t *memoria,int tama);
/**
*	\brief Funcion que permite mostrar los valores almacenados en la memoria
*	\param memoria Direccion en la cual se almacenan los datos en la memoria
*	\param tama Es el tamaño de los datos a almacenar
*/
void mostrar_memoria(uint32_t *memoria , int tama);
/**
*	\brief Funcion que permite realizar el PUSH en la memoria
*	\param registros Direccion de los registros que van del 0 al 15
*	\param memoria Direccion en la cual se almacenan los datos en la memoria
*   \param res Direccion 
*/
void PUSH(uint32_t *registros,uint32_t *memory,uint32_t *res);
/**
*	\brief Funcion que permite realizar el POP en la memoria
*	\param registros Direccion de los registros que van del 0 al 15
*	\param memoria Direccion en la cual se almacenan los datos en la memoria
*   \param res Direccion
*/
void POP(uint32_t *registros,uint32_t *memory,uint32_t *res);
uint32_t bitcount(uint32_t *R);
void POPINTERRUPT(uint32_t *registros,uint32_t *memory,uint32_t *res);
void PUSHINTERRUPT(uint32_t *registros,uint32_t *memory,uint32_t *res);
void LDR(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory);

void LDRB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory);

void LDRH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory);

void STR(uint32_t *Rt, uint32_t Rn, uint32_t Rm, uint32_t *memory);

void STRB(uint32_t *Rt, uint32_t Rn, uint32_t Rm, uint32_t *memory);

void STRH(uint32_t *Rt, uint32_t Rn, uint32_t Rm, uint32_t *memory);
