#include "Hotel.h"

Hotel::Hotel(int ID) :pr_max_connections(10), pr_price(1000), Building(ID)
{

}

Hotel::Hotel(int wifi, int gas, int electicity, int ID) : pr_max_connections(10), pr_price(1000), Building(wifi, gas, electicity, ID)
{

}

int Hotel::Get_Max_Connections()
{
	return pr_max_connections;
}

int Hotel::Get_Price()
{
	return pr_price;
}

bool Hotel::Add_WiFi()
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

bool Hotel::Remove_WiFi()
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

bool Hotel::Add_Gas()
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

bool Hotel::Remove_Gas()
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

bool Hotel::Add_Electricity()
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

bool Hotel::Remove_Electricity()
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
