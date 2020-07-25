#include "House.h"

House::House(int ID) :pr_max_connections(1), pr_price(100), Building(ID)
{

}

House::House(int wifi, int gas, int electicity, int ID) : pr_max_connections(1), pr_price(100), Building(wifi, gas, electicity, ID)
{

}

int House::Get_Max_Connections()
{
	return pr_max_connections;
}

int House::Get_Price()
{
	return pr_price;
}

bool House::Add_WiFi()
{
	if (pr_NoOf_WiFi < pr_max_connections)
	{
		pr_NoOf_WiFi++;
		return true;
	}
	else
	{
		return false;
	}
}

bool House::Remove_WiFi()
{
	if (pr_NoOf_WiFi == 0)
	{
		return false;
	}
	else
	{
		pr_NoOf_WiFi--;
		return true;
	}
}

bool House::Add_Gas()
{
	if (pr_NoOf_GasConnection < pr_max_connections)
	{
		pr_NoOf_GasConnection++;
		return true;
	}
	else
	{
		return false;
	}
}

bool House::Remove_Gas()
{
	if (pr_NoOf_GasConnection == 0)
	{
		return false;
	}
	else
	{
		pr_NoOf_GasConnection--;
		return true;
	}
}

bool House::Add_Electricity()
{
	if (pr_NoOf_ElectricConnection < pr_max_connections)
	{
		pr_NoOf_ElectricConnection++;
		return true;
	}
	else
	{
		return false;
	}
}

bool House::Remove_Electricity()
{
	if (pr_NoOf_ElectricConnection == 0)
	{
		return false;
	}
	else
	{
		pr_NoOf_ElectricConnection--;
		return true;
	}
}


