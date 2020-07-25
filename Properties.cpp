#include "Properties.h"
#include<string.h>

Properties::Properties()
{
	pr_basic_id = 0;
	pr_property_type = 0;
}

Properties::Properties(int BID, const char* Name, int Type)
{
	pr_basic_id = BID;
	pr_property_name.Set_name(Name);
	pr_property_type = Type;
}

void Properties::Set_PName(const char* Name)
{
	pr_property_name.Set_name(Name);
}

void Properties::Set_BID(int BID)
{
	pr_basic_id = BID;
}

void Properties::Set_pType(int Type)
{
	pr_property_type = Type;
}

void Properties::Set_Price(int)
{
}

void Properties::Set_owned_Status(bool)
{
}

void Properties::Set_Rent(int)
{
}

void Properties::Set_Group_Name(const char*)
{
}

void Properties::Set_NoOfProperties(int)
{
}

void Properties::Set_NationalProType(int)
{
}

void Properties::Set_Mortgage_Status(bool)
{
}

const char* Properties::Get_PName()
{
	return pr_property_name.Get_name();
}

int Properties::Get_BID()
{
	return pr_basic_id;
}

int Properties::Get_pType()
{
	return pr_property_type;
}

int Properties::Get_price()
{
	return 0;
}

bool Properties::Get_owned_Status()
{
	return false;
}

int Properties::Get_Rent()
{
	return 0;
}

const char* Properties::Get_Group_Name()
{
	return nullptr;
}

int Properties::Get_NoOfProperties()
{
	return 0;
}

int Properties::Get_NationalProType()
{
	return 0;
}

bool Properties::Get_Mortgage_Status()
{
	return false;
}

int Properties::Get_NoOf_Houses()
{
	return 0;
}

int Properties::Get_NoOf_Shopes()
{
	return 0;
}

int Properties::Get_NoOf_Hotel()
{
	return 0;
}

void Properties::Add_Building(int)
{
}

void Properties::Add_Building(int, int, int, int)
{
}

void Properties::Remove_Building(int)
{
}

void Properties::Convert_To_Shop()
{
}

void Properties::Convert_TO_Hotel()
{
}
