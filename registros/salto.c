#include <stdint.h>
#include "flags.h"
#include "alu.h"
#include <stdbool.h>

bool banderas[3];
obtenerBandera(banderas);

void B(uint32_t *pc,uint32_t valor)
{
    *pc+=valor<<1;
}
void BEQ(uint32_t *pc,uint32_t valor)
{
	if(banderas[Z]==1)}
	{
		pc+=valor<<1;
	}
}
void BNE(uint32_t *pc,uint32_t valor)
{
    if(banderas[Z]==0)
	{
    }
}
void BCS(uint32_t *pc,uint32_t valor)
{
    if(banderas[C]==1)
	{
    }
}
void BCC(uint32_t *pc,uint32_t valor)
{
    if(banderas[C]==0)
	{
    }
}
void BMI(uint32_t *pc,uint32_t valor)
{
    if(banderas[N]==1)
	{
    }
}
void BPL(uint32_t *pc,uint32_t valor)
{
    if(banderas[N]==0)
	{
    }
}
void BVS(uint32_t *pc,uint32_t valor)
{
    if(banderas[V]==1)
	{
    }
}
void BVC(uint32_t *pc,uint32_t valor)
{
    if(banderas[V]==0)
	{
    }
}
void BHI(uint32_t *pc,uint32_t valor)
{
    if((banderas[C]==1)&&(banderas[Z]==0))
	{
    }
}
void BLS(uint32_t *pc,uint32_t valor)
{
    if((banderas[C]==0)&&(banderas[Z]==1))
	{
    }
}
void BGE(uint32_t *pc,uint32_t valor)
{
    if(banderas[N]==banderas[V])
	{
    }
}
void BLT(uint32_t *pc,uint32_t valor)
{
    if(banderas[N]!=banderas[V])
	{
    }
}
void BGT(uint32_t *pc,uint32_t valor)
{
    if(banderas[Z]==0)
	{
    }
}
void BLE(uint32_t *pc,uint32_t valor)
{
    if((banderas[Z]==0)&&(banderas[N]==banderas[V]))
	{
    }
}
void BAL(uint32_t *pc,uint32_t valor)
{

}

