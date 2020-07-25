#include "Shop.h"

Shop::Shop(int ID) :pr_max_connections(3), pr_price(300), Building(ID)
{

}

Shop::Shop(int wifi, int gas, int electicity, int ID) : pr_max_connections(3), pr_price(300), Building(wifi, gas, electicity, ID)
{

}

int Shop::Get_Max_Connections()
{
	return pr_max_connections;
}

int Shop::Get_Price()
{
	return pr_price;
}

bool Shop::Add_WiFi()
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

bool Shop::Remove_WiFi()
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

bool Shop::Add_Gas()
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

bool Shop::Remove_Gas()
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

bool Shop::Add_Electricity()
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

bool Shop::Remove_Electricity()
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
