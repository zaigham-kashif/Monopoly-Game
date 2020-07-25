#pragma once
#include"Properties.h"

class National_Propesties:public Properties
{
	private:
		int pr_National_Pro_Type;
	public:
		National_Propesties();
		National_Propesties(int, int, const char*, int);

		void Set_NationalProType(int) override;

		int  Get_NationalProType() override;
};

