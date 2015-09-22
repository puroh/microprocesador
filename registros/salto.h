#include <stdint.h>
/*
void B(uint32_t *pc,uint32_t valor);
void BEQ(uint32_t *pc,uint32_t valor);
void BNE(uint32_t *pc,uint32_t valor);
void BCS(uint32_t *pc,uint32_t valor);
void BCC(uint32_t *pc,uint32_t valor);
void BMI(uint32_t *pc,uint32_t valor);
void BPL(uint32_t *pc,uint32_t valor);
void BVS(uint32_t *pc,uint32_t valor);
void BVC(uint32_t *pc,uint32_t valor);
void BHI(uint32_t *pc,uint32_t valor);
void BLS(uint32_t *pc,uint32_t valor);
void BGE(uint32_t *pc,uint32_t valor);
void BLT(uint32_t *pc,uint32_t valor);
void BGT(uint32_t *pc,uint32_t valor);
void BLE(uint32_t *pc,uint32_t valor);
void BAL(uint32_t *pc,uint32_t valor);
void BL(uint32_t *pc,uint32_t valor);
void BX(uint32_t *pc);*/

/**
*	\brief Función que realiza un salto en una dirección especifica.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void B(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea Z == 1.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BEQ(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea Z == 0.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BNE(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea C == 1.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BCS(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea C == 0.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BCC(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea N == 1.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BMI(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea N == 0.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BPL(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea V == 1.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BVS(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea V == 0.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BVC(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que las banderas sean C == 1 y Z == 0.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BHI(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que las banderas sean C == 0 o Z==1.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BLS(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea N == V.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BGE(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que la bandera sea N != V.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BLT(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que las banderas sean Z == 1 y N == V.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BGT(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que realiza un salto teniendo en cuenta que las banderas sean Z == 0 o N != V.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BLE(uint32_t *pc,uint32_t valor);
/**
*	\brief Función Función que realiza siempre un salto no se tiene condición.
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BAL(uint32_t *pc,uint32_t valor);
/**
*	\brief Función que llama a una subrutina que se encuentra en una dirección relativa al pc .
*	\param pc Contador del programa.
*	\param valor Es un valor inmediato sin signo de 32 bits.
*/
void BL(uint32_t *pc,uint32_t valor);
/**
*	\brief Función Función que realiza un salto a una dirección especifica por un registro.
*	\param pc Contador del programa.
*/
void BX(uint32_t *pc);

