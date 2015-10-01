#include <stdint.h>
#define MEMORIA 64
#define DIRMAXMEM 255

void inimemoria(uint32_t *memoria,int tama);
void mostrar_memoria(uint32_t *memoria , int tama);
void PUSH(uint32_t *registros,uint32_t *memory,uint8_t *res);
void POP(uint32_t *registros,uint32_t *memory,uint8_t *res);
uint8_t bitcount(uint8_t *R);
