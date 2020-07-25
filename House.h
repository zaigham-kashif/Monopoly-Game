#pragma once
#include"Building.h"

class House:public Building
{                       
	private:
		const int pr_max_connections;
		const int pr_price;
	public:
		House(int);
		House(int, int, int, int);

		int Get_Max_Connections();
		int Get_Price();

		bool Add_WiFi() override;
		bool Remove_WiFi() override;
		bool Add_Gas() override;
		bool Remove_Gas() override;
		bool Add_Electricity() override;
		bool Remove_Electricity() override;

};

