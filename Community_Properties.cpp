#include "Community_Properties.h"
Community_Properties::Community_Properties()
{
	pr_cost_price = 0;
	pr_mortgage_status = false;
	pr_owned_status = false;
	pr_rent = 0;
	pr_pro_in_group = 0;
}

Community_Properties::Community_Properties(int cost, bool status, int rent, const char* Name, int Number, bool mortgage_status, int BID, const char* Name_of_pro, int Type) :Properties(BID, Name_of_pro, Type)
{
	pr_cost_price = cost;
	pr_group_name.Set_name(Name); 
	pr_pro_in_group = Number;
	pr_rent = rent;
	pr_owned_status = status;
	pr_mortgage_status = mortgage_status;
}

void Community_Properties::Set_Price(int price)
{
	pr_cost_price = price;
}

void Community_Properties::Set_owned_Status(bool status)
{
	pr_owned_status = status;
}

void Community_Properties::Set_Rent(int Rent)
{
	pr_rent = Rent;
}

void Community_Properties::Set_Group_Name(const char* Name)
{
	pr_group_name.Set_name(Name);
}

void Community_Properties::Set_NoOfProperties(int number)
{
	pr_pro_in_group = number;
}

void Community_Properties::Set_Mortgage_Status(bool Mortgage_status)
{
	pr_mortgage_status = Mortgage_status;
}

int Community_Properties::Get_price()
{
	return pr_cost_price;
}

bool Community_Properties::Get_owned_Status()
{
	return pr_owned_status;
}

int Community_Properties::Get_Rent()
{
	return pr_rent;
}

const char* Community_Properties::Get_Group_Name()
{
	return pr_group_name.Get_name();
}

int Community_Properties::Get_NoOfProperties()
{
	return pr_pro_in_group;
}

bool Community_Properties::Get_Mortgage_Status()
{
	return pr_mortgage_status;
}
