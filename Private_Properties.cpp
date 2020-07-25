#include "Private_Properties.h"

Private_Properties::Private_Properties()
{
	pr_Buludings = nullptr;
	pr_cost_price = 0;
	pr_pro_in_group = 0;
	pr_rent = 0;
	pr_NoOf_Buildings = 0;
	pr_owned_status = false;
	pr_mortgage_status = false;
}

Private_Properties::Private_Properties(int price, bool owned_status, int rent, const char* group_name, int pro_in_Group,bool mortgage_status, int BID, const char* Name_of_pro, int Type) :Properties(BID, Name_of_pro, Type)
{
	pr_cost_price = price;
	pr_owned_status = owned_status;
	pr_rent = rent;
	pr_group_name.Set_name(group_name);
	pr_pro_in_group = pro_in_Group;
	pr_mortgage_status = mortgage_status;
	pr_Buludings = nullptr;
	pr_NoOf_Buildings = 0;
}

void Private_Properties::Set_Price(int price)
{
	pr_cost_price = price;
}

void Private_Properties::Set_owned_Status(bool status)
{
	pr_owned_status = status;
}

void Private_Properties::Set_Rent(int Rent)
{
	pr_rent = Rent;
}

void Private_Properties::Set_Group_Name(const char* Name)
{
	pr_group_name.Set_name(Name);
}

void Private_Properties::Set_NoOfProperties(int number)
{
	pr_pro_in_group = number;
}

void Private_Properties::Set_Mortgage_Status(bool status)
{
	pr_mortgage_status = status;
}

int Private_Properties::Get_price()
{
	return pr_cost_price;
}

bool Private_Properties::Get_owned_Status()
{
	return pr_owned_status;
}

int Private_Properties::Get_Rent()
{
	if (pr_Buludings == nullptr)
	{
		return pr_rent;
	}
	else
	{
		int total_rent = 0;
		int total_wifi = 0;
		int total_gas = 0;
		int total_electricity = 0;

		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			if (pr_Buludings[i][0].Get_Building_ID() == 1)
			{
				total_rent = total_rent + ((pr_rent / 100) * 30);
			}
			else if (pr_Buludings[i][0].Get_Building_ID() == 2)
			{
				total_rent = total_rent + ((pr_rent / 100) * 60);
			}
			else if (pr_Buludings[i][0].Get_Building_ID() == 3)
			{
				total_rent = total_rent + ((pr_rent / 100) * 80);
			}
		}

		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			total_wifi = total_wifi + pr_Buludings[i][0].Get_WiFi();
			total_gas = total_gas + pr_Buludings[i][0].Get_Gas();
			total_electricity = total_electricity + pr_Buludings[i][0].Get_Electricity();
		}

		total_rent = total_rent + (total_wifi * ((pr_rent / 100) * 10));
		total_rent = total_rent + (total_gas * ((pr_rent / 100) * 20));
		total_rent = total_rent + (total_electricity * ((pr_rent / 100) * 20));

		return total_rent;
	}
}

const char* Private_Properties::Get_Group_Name()
{
	return pr_group_name.Get_name();
}

int Private_Properties::Get_NoOfProperties()
{
	return pr_pro_in_group;
}

bool Private_Properties::Get_Mortgage_Status()
{
	return pr_mortgage_status;
}

int Private_Properties::Get_NoOf_Houses()
{
	if (pr_Buludings == nullptr)
	{
		return 0;
	}
	else
	{
		int counter = 0;
		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			if (pr_Buludings[i][0].Get_Building_ID() == 1)
			{
				counter++;
			}
		}

		return counter;
	}
}

int Private_Properties::Get_NoOf_Shopes()
{
	if (pr_Buludings == nullptr)
	{
		return 0;
	}
	else
	{
		int counter = 0;
		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			if (pr_Buludings[i][0].Get_Building_ID() == 2)
			{
				counter++;
			}
		}

		return counter;
	}
}

int Private_Properties::Get_NoOf_Hotel()
{
	if (pr_Buludings == nullptr)
	{
		return 0;
	}
	else
	{
		int counter = 0;
		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			if (pr_Buludings[i][0].Get_Building_ID() == 3)
			{
				counter++;
			}
		}

		return counter;
	}
}

void Private_Properties::Add_Building(int Bulding_Type)
{
	if (pr_Buludings == nullptr)
	{
		pr_Buludings = new Building * [1];
		if (Bulding_Type == 1)
		{
			pr_Buludings[0] = new House(1);
		}
		if (Bulding_Type == 1)
		{
			pr_Buludings[0] = new Shop(2);
		}
		if (Bulding_Type == 1)
		{
			pr_Buludings[0] = new Hotel(3);
		}

		pr_NoOf_Buildings++;
	}
	else
	{
		Building** Temp_Buildings = new Building * [pr_NoOf_Buildings];
		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			Temp_Buildings[i] = pr_Buludings[i];
		}

		delete[]pr_Buludings;
		pr_Buludings = nullptr;

		pr_Buludings = new Building * [pr_NoOf_Buildings + 1];
		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			pr_Buludings[i] = Temp_Buildings[i];
		}

		if (Bulding_Type == 1)
		{
			pr_Buludings[pr_NoOf_Buildings] = new House(1);
		}
		else if (Bulding_Type == 1)
		{
			pr_Buludings[pr_NoOf_Buildings] = new Shop(2);
		}
		else if (Bulding_Type == 1)
		{
			pr_Buludings[pr_NoOf_Buildings] = new Hotel(3);
		}

		pr_NoOf_Buildings++;

		delete[]Temp_Buildings;
		Temp_Buildings = nullptr;
	}
}

void Private_Properties::Add_Building(int NO_WiFI, int NO_Gas, int NO_Electricity, int Bulding_Type)
{
	if (pr_Buludings == nullptr)
	{
		pr_Buludings = new Building * [1];
		if (Bulding_Type == 1)
		{
			pr_Buludings[0] = new House(NO_WiFI, NO_Gas, NO_Electricity, 1);
		}
		if (Bulding_Type == 1)
		{
			pr_Buludings[0] = new Shop(NO_WiFI, NO_Gas, NO_Electricity, 2);
		}
		if (Bulding_Type == 1)
		{
			pr_Buludings[0] = new Hotel(NO_WiFI, NO_Gas, NO_Electricity, 3);
		}

		pr_NoOf_Buildings++;
	}
	else
	{
		Building** Temp_Buildings = new Building * [pr_NoOf_Buildings];
		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			Temp_Buildings[i] = pr_Buludings[i];
		}

		delete[]pr_Buludings;
		pr_Buludings = nullptr;

		pr_Buludings = new Building * [pr_NoOf_Buildings + 1];
		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			pr_Buludings[i] = Temp_Buildings[i];
		}

		if (Bulding_Type == 1)
		{
			pr_Buludings[pr_NoOf_Buildings] = new House(NO_WiFI, NO_Gas, NO_Electricity, 1);
		}
		else if (Bulding_Type == 1)
		{
			pr_Buludings[pr_NoOf_Buildings] = new Shop(NO_WiFI, NO_Gas, NO_Electricity, 2);
		}
		else if (Bulding_Type == 1)
		{
			pr_Buludings[pr_NoOf_Buildings] = new Hotel(NO_WiFI, NO_Gas, NO_Electricity, 3);
		}

		pr_NoOf_Buildings++;

		delete[]Temp_Buildings;
		Temp_Buildings = nullptr;
	}
}

void Private_Properties::Remove_Building(int Building_Type)
{
	if (pr_NoOf_Buildings == 1)
	{
		if (pr_Buludings[0][0].Get_Building_ID() == Building_Type)
		{
			delete pr_Buludings[0];
			delete[]pr_Buludings;
			pr_Buludings = nullptr;
			pr_NoOf_Buildings = 0;
		}
		else
		{
			
		}

		
	}
	else
	{
		int key = -1;

		for (int i = 0; i < pr_NoOf_Buildings; i++)
		{
			if (pr_Buludings[i][0].Get_Building_ID() == Building_Type)
			{
				key = i;
				break;
			}
		}

		if (key != -1)
		{
			Building** Temp_Buildings = new Building * [pr_NoOf_Buildings - 1];

			for (int i = 0; i < key; i++)
			{
				Temp_Buildings[i] = pr_Buludings[i];
			}

			for (int i = key + 1; i < pr_NoOf_Buildings; i++)
			{
				Temp_Buildings[i - 1] = pr_Buludings[i];
			}

			delete pr_Buludings[key];
			delete[]pr_Buludings;
			pr_Buludings = nullptr;

			pr_NoOf_Buildings--;
			pr_Buludings = new Building * [pr_NoOf_Buildings];

			for (int i = 0; i < pr_NoOf_Buildings; i++)
			{
				pr_Buludings[i] = Temp_Buildings[i];
			}

			delete[]Temp_Buildings;
			Temp_Buildings = nullptr;
		}
		else
		{

		}
	}
}

void Private_Properties::Convert_To_Shop()
{
	int wifi = 0;
	int gas = 0;
	int electricity = 0;
	int counter = 0;

	if (this->Get_NoOf_Houses() >= 3)
	{
		for (int i = 0; (i < pr_NoOf_Buildings) && (counter <= 3); i++)
		{
			if (pr_Buludings[i][0].Get_Building_ID() == 1)
			{
				counter++;

				wifi = wifi + pr_Buludings[i][0].Get_WiFi();
				gas = gas + pr_Buludings[i][0].Get_Gas();
				electricity = electricity + pr_Buludings[i][0].Get_Electricity();
			}
		}

		this->Remove_Building(1);
		this->Remove_Building(1);
		this->Remove_Building(1);
		
		this->Add_Building(wifi, gas, electricity, 2);
	}

}

void Private_Properties::Convert_TO_Hotel()
{
	int wifi = 0;
	int gas = 0;
	int electricity = 0;
	int counter = 0;

	if (this->Get_NoOf_Houses() >= 4 && this->Get_NoOf_Shopes() >= 2)
	{
		counter = 0;

		for (int i = 0; (i < pr_NoOf_Buildings) && (counter <= 4); i++)
		{
			if (pr_Buludings[i][0].Get_Building_ID() == 1)
			{
				counter++;

				wifi = wifi + pr_Buludings[i][0].Get_WiFi();
				gas = gas + pr_Buludings[i][0].Get_Gas();
				electricity = electricity + pr_Buludings[i][0].Get_Electricity();
			}
		}

		counter = 0;

		for (int i = 0; (i < pr_NoOf_Buildings) && (counter <= 2); i++)
		{
			if (pr_Buludings[i][0].Get_Building_ID() == 2)
			{
				counter++;

				wifi = wifi + pr_Buludings[i][0].Get_WiFi();
				gas = gas + pr_Buludings[i][0].Get_Gas();
				electricity = electricity + pr_Buludings[i][0].Get_Electricity();
			}
		}

		this->Remove_Building(1);
		this->Remove_Building(1);
		this->Remove_Building(1);
		this->Remove_Building(1);

		this->Remove_Building(2);
		this->Remove_Building(2);

		this->Add_Building(wifi, gas, electricity, 3);
	}
	else if (this->Get_NoOf_Houses() >= 10)
	{
		counter = 0;

		for (int i = 0; (i < pr_NoOf_Buildings) && (counter <= 10); i++)
		{
			if (pr_Buludings[i][0].Get_Building_ID() == 1)
			{
				counter++;

				wifi = wifi + pr_Buludings[i][0].Get_WiFi();
				gas = gas + pr_Buludings[i][0].Get_Gas();
				electricity = electricity + pr_Buludings[i][0].Get_Electricity();
			}
		}

		this->Remove_Building(1);
		this->Remove_Building(1);
		this->Remove_Building(1);

		this->Remove_Building(1);
		this->Remove_Building(1);
		this->Remove_Building(1);

		this->Remove_Building(1);
		this->Remove_Building(1);
		this->Remove_Building(1);
		this->Remove_Building(1);

		this->Add_Building(wifi, gas, electricity, 3);

	}
}
