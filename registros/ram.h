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
*   \param res Direccion de registro
*/
void PUSH(uint32_t *registros,uint32_t *memory,uint32_t *res);
/**
*	\brief Funcion que permite realizar el POP en la memoria
*	\param registros Direccion de los registros que van del 0 al 15
*	\param memoria Direccion en la cual se almacenan los datos en la memoria
*   \param res Direccion de registro
*/
void POP(uint32_t *registros,uint32_t *memory,uint32_t *res);
uint32_t bitcount(uint32_t *R);
/** 
*   \brief Funcion POP dentro de la interrupcion
*   \param registros Registros del 0 al 15
*   \param memoria Direccion de memoria
*   \param rest Registros en memoria
*/
void POPINTERRUPT(uint32_t *registros,uint32_t *memory,uint32_t *res);
/** 
*   \brief Funcion POP dentro de la interrupcion
*   \param registros Registros del 0 al 15
*   \param memoria Direccion de memoria
*   \param res Registros en memoria
*/
void PUSHINTERRUPT(uint32_t *registros,uint32_t *memory,uint32_t *res);
/**
*	\brief Funcion que extrae 4 valores de la pila dependiendo de la suma de las direcciones
*	\param Rt Es la direccion de donde se extrae los valores
*	\param Rn Dirección que contien el valor del registro a operar
*   \param Rm Dirección que contien el valor del registro a operar
*	\param memory Direccion donde se ubicara en memoria para obtener el valor
*/
void LDR(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory);
/**
*	\brief Funcion que extrae un valor de la pila dependiendo de la suma de la direccion con otra direccion de registro
*	\param Rt Es la direccion de donde se extrae el valor
*	\param Rn Dirección que contien el valor del registro a operar
*   \param Rm Dirección que contien el valor del registro a operar
*	\param memory Direccion donde se ubicara en memoria para obtener el valor
*/
void LDRB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory);
/**
*	\brief Funcion que extrae dos valores de la pila dependiendo de la suma de la direccion con un valor inmediato adicionalmente se realiza extension de ceros
*	\param Rt Es la direccion de donde se extrae los valores
*	\param Rn Dirección que contien el valor del registro a operar
*   \param Rm Dirección que contien el valor del registro a operar
*	\param memory Direccion donde se ubicara en memoria para obtener el valor
*/
void LDRH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint32_t *memory);
/**
*	\brief Funcion que almacena 4 valores en la pila 
*	\param Rt Es la direccion donde se almacenaran los datos
*	\param Rn Dirección que contien el valor del registro a operar
*   \param Rm Dirección que contien el valor del registro a operar
*	\param memory Direccion donde se ubicara en memoria para almacenar el valor
*/
void STR(uint32_t *Rt, uint32_t Rn, uint32_t Rm, uint32_t *memory);
/**
*	\brief Funcion que almacena un valore en la pila ya sea los primeros 8 bit o los 8 bit ultimos
*	\param Rt Es la direccion donde se almacenaran los datos
*	\param Rn Dirección que contien el valor del registro a operar
*   \param Rm Dirección que contien el valor del registro a operar
*	\param memory Direccion donde se ubicara en memoria para almacenar el valor
*/
void STRB(uint32_t *Rt, uint32_t Rn, uint32_t Rm, uint32_t *memory);
/**
*	\brief Funcion que almacena dos valores en la pila ya sea los 16 primeros 16bit o los ultimos 16 bits 
*	\param Rt Es la direccion donde se almacenaran los datos
*	\param Rn Dirección que contien el valor del registro a operar
*   \param Rm Dirección que contien el valor del registro a operar
*	\param memory Direccion donde se ubicara en memoria para almacenar el valor
*/
void STRH(uint32_t *Rt, uint32_t Rn, uint32_t Rm, uint32_t *memory);
