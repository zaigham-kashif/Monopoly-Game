#include "National_Propesties.h"

National_Propesties::National_Propesties()
{
	pr_National_Pro_Type = 0;
}

National_Propesties::National_Propesties(int ProType, int BID, const char* Name, int Type) :Properties(BID, Name, Type)
{
	pr_National_Pro_Type = ProType;
}

void National_Propesties::Set_NationalProType(int ProType)
{
	pr_National_Pro_Type = ProType;
}

int National_Propesties::Get_NationalProType()
{
	return pr_National_Pro_Type;
}
