#include "Building.h"

Building::Building()
{
	pr_NoOf_ElectricConnection = 0;
	pr_NoOf_GasConnection = 0;
	pr_NoOf_WiFi = 0;
	pr_building_ID = 0;
}

Building::Building(int Bulding_ID)
{
	pr_NoOf_ElectricConnection = 0;
	pr_NoOf_GasConnection = 0;
	pr_NoOf_WiFi = 0;
	pr_building_ID = Bulding_ID;
}

Building::Building(int WiFi, int Gas, int Electricity,int Bulding_ID)
{
	pr_NoOf_ElectricConnection = Electricity;
	pr_NoOf_GasConnection = Gas;
	pr_NoOf_WiFi = WiFi;
	pr_building_ID = Bulding_ID;
}

void Building::Set_WiFi(int WiFi)
{
	pr_NoOf_WiFi = WiFi;
}

void Building::Set_Gas(int Gas)
{
	pr_NoOf_GasConnection = Gas;
}

void Building::Set_Electricity(int Electricity)
{
	pr_NoOf_ElectricConnection = Electricity;
}

void Building::Set_Building_ID(int ID)
{
	pr_building_ID = ID;
}

int Building::Get_WiFi()
{
	return pr_NoOf_WiFi;
}

int Building::Get_Gas()
{
	return pr_NoOf_GasConnection;
}

int Building::Get_Electricity()
{
	return pr_NoOf_ElectricConnection;
}

int Building::Get_Building_ID()
{
	return pr_building_ID;
}
