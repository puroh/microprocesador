<<<<<<< HEAD
#include <stdint.h>
#define MEMORIA 64
#define DIRMAXMEM 255

=======
>>>>>>> master
void inimemoria(uint32_t *memoria,int tama);
void mostrar_memoria(uint32_t *memoria , int tama);
void PUSH(uint32_t *registros,uint32_t *memory,uint8_t *res);
void POP(uint32_t *registros,uint32_t *memory,uint8_t *res);
<<<<<<< HEAD
uint8_t bitcount(uint8_t *R);
=======
int bitcount(int *R);
void inicia_ram(void);
>>>>>>> master
