//carga y almacenamineto


void LDR(uint32_t Rt,uint32_t Rn,int imm)//Rn =direciones de los registros
	{
		int offset_addr;
		imm=(imm<<2)|31;
		offset_addr=Rn+&imm;
		Rt=memU[offset_addr,4];
	}

void LDRB (uint32_t Rt,uint32_t )
