#include <stdint.h>
uint32_t LSLS(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	Rd=Rm<<Rn;
	return Rd;
}
uint32_t LSRS(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	Rd=Rm>>Rn;
	return Rd;
}
uint32_t ROR(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{
	Rd=Rm<<(32-Rn);
	Rm=Rm>>Rn;
	Rd=Rm|Rd;
    return Rd;
}
uint32_t ASRS(uint32_t Rm,uint32_t Rn,uint32_t Rd)
{

}
