#include <stdint.h>
/** 
*   \brief Funcion que activa las interrupciones
*   \param Exnum Direccion a la cual accede para iniciar la interrupcion
*	\param numb numero entero sin signo de 8 bits
*/
void NVIC_EnableIRQ(uint8_t *Exnumb,uint8_t numb);
/** 
*   \brief Funcion que ejecuta la regresion al codigo principal 
*   \param Exnum Direccion a la cual regresar al codigo principal
*	\param numb numero sin signo de 8 bits
*/
void NVIC_DisableIRQ(uint8_t *Exnumb,uint8_t numb);

