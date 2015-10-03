/**
*	\brief Funcion que extrae 4 valores de la pila dependiendo de la suma de las direcciones con valor inmediato
*	\param Rt Es la direccion de donde se extrae los valores
*	\param Rn Dirección de registro
*   \param inm Es el inmediato, el cual se le realiza una extension de ceros
*/
void LDR(uint_32 Rt,uint_32 Rn,uint_32 imm);
/**
*	\brief Funcion que extrae un valor de la pila dependiendo de la suma de la direccion con otra direccion de registro
*	\param Rt Es la direccion de donde se extrae el valor
*	\param Rn Dirección de registro 1
*   \param Rm Direccion de registro 2
*/
void LDRB (uint_32 Rt,uint_32 Rn,uint_32 imm);
/**
*	\brief Funcion que extrae dos valores de la pila dependiendo de la suma de la direccion con un valor inmediato adicionalmente se realiza extension de ceros
*	\param Rt Es la direccion de donde se extrae los valores
*	\param Rn Direccion del registro
*   \param inm Es el inmediato, el cual se le realiza una extension de ceros
*/
void LDRH (uint_32 Rt,uint_32 Rn,uint_32 imm);
/**
*	\brief Funcion que extrae un valor de la pila dependiendo de la suma de la direccion con un valor inmediato, adicionalmente se realiza extensin de signo
*	\param Rt Es la direccion de donde se extrae el valor
*	\param Rn Direccion del registro 1
*   \param Rm Direccion del registro 2
*/
void LDRSB (uint_32 Rt,uint_32 Rn,uint_32 Rm);
/**
*	\brief Funcion que extrae dos valores de la pila dependiendo de la suma de la direccion de un registro con la direccion de otro registro, adicionalmente se realiza extensin de signo
*	\param Rt Es la direccion de donde se extrae los valores
*	\param Rn Direccion del registro 1
*   \param Rm Direccion del registro 2
*/
void LDRSH (uint_32 Rt,uint_32 Rn,uint_32 Rm);
/**
*	\brief Funcion que almacena 4 valores en la pila 
*	\param Rt Es la direccion donde se almacenaran los datos
*	\param Rn Direccion del registro 1
*   \param Rm Direccion del registro 2
*   \param inm Es el inmediato, el cual se le realiza una extension de ceros
*/
void STR (uint_32 Rt,uint_32 Rn,uint_32 imm, uint_32 Rm,uint_32 Sp);
/**
*	\brief Funcion que almacena un valore en la pila ya sea los primeros 8 bit o los 8 bit ultimos
*	\param Rt Es la direccion donde se almacenaran los datos
*	\param Rn Direccion del registro 1
*   \param Rm Direccion del registro 2
*   \param inm Es el inmediato, el cual se le realiza una extension de ceros|
*/
void STRB (uint_32 Rt,uint_32 Rn,uint_32 imm,uint_32 Rm);
/**
*	\brief Funcion que almacena dos valores en la pila ya sea los 16 primeros 16bit o los ultimos 16 bits 
*	\param Rt Es la direccion donde se almacenaran los datos
*	\param Rn Direccion del registro 1
*   \param Rm Direccion del registro 2
*   \param inm Es el inmediato, el cual se le realiza una extension de ceros|
*/
void STRH (uint_32 Rt,uint_32 Rn,uint_32 imm,uint_32 Rm);


