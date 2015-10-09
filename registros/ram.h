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
void PUSH(uint32_t *registros,uint32_t *memory,uint8_t *res);
/**
*	\brief Funcion que permite realizar el POP en la memoria
*	\param registros Direccion de los registros que van del 0 al 15
*	\param memoria Direccion en la cual se almacenan los datos en la memoria
*   \param res Direccion
*/
void POP(uint32_t *registros,uint32_t *memory,uint8_t *res);
uint8_t bitcount(uint8_t *R);
