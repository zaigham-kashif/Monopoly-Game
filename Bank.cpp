#include "Bank.h"

Bank::Bank()
{
	pr_TotalMoney = 100000;
	pr_No_Of_Properties = 0;
	pr_list_of_Propertie = nullptr;
}

Bank::Bank(long int total_money, int no_of_pro)
{
	pr_TotalMoney = total_money;
	pr_No_Of_Properties = no_of_pro;
	pr_list_of_Propertie = nullptr;
}

void Bank::Add_Property(int pro_type, int BID, int cost_price, int pro_rent, int pro_in_group, int national_pro_type, bool owned_status, bool mortgage_status, const char* pro_name , const char* pro_group)
{
	if (pr_list_of_Propertie == nullptr)
	{
		pr_list_of_Propertie = new Properties * [1];

		if (pro_type == 1)
		{
			pr_list_of_Propertie[0] = new Private_Properties(cost_price, owned_status, pro_rent, pro_group, pro_in_group, mortgage_status, BID, pro_name, pro_type);
		}
		else if (pro_type == 2)
		{
			pr_list_of_Propertie[0] = new Community_Properties(cost_price, owned_status, pro_rent, pro_group, pro_in_group, mortgage_status, BID, pro_name, pro_type);
		}
		else if (pro_type == 3)
		{
			pr_list_of_Propertie[0] = new National_Propesties(national_pro_type, BID, pro_name, pro_type);
		}

		pr_No_Of_Properties++;
	}
	else
	{
		Properties** Temp_list_of_properties = new Properties * [pr_No_Of_Properties];

		for (int i = 0; i < pr_No_Of_Properties; i++)
		{
			Temp_list_of_properties[i] = pr_list_of_Propertie[i];
		}

		delete[]pr_list_of_Propertie;
		pr_list_of_Propertie = nullptr;
		pr_list_of_Propertie = new Properties * [pr_No_Of_Properties + 1];

		for (int i = 0; i < pr_No_Of_Properties; i++)
		{
			pr_list_of_Propertie[i] = Temp_list_of_properties[i];
		}
		
		if (pro_type == 1)
		{
			pr_list_of_Propertie[pr_No_Of_Properties] = new Private_Properties(cost_price, owned_status, pro_rent, pro_group, pro_in_group, mortgage_status, BID, pro_name, pro_type);
		}
		else if (pro_type == 2)
		{
			pr_list_of_Propertie[pr_No_Of_Properties] = new Community_Properties(cost_price, owned_status, pro_rent, pro_group, pro_in_group, mortgage_status, BID, pro_name, pro_type);
		}
		else if (pro_type == 3)
		{
			pr_list_of_Propertie[pr_No_Of_Properties] = new National_Propesties(national_pro_type, BID, pro_name, pro_type);
		}

		pr_No_Of_Properties++;

		delete[]Temp_list_of_properties;
		Temp_list_of_properties = nullptr;
	}
}

Properties* Bank::Sell_Property(int BID)
{
	if (pr_list_of_Propertie[BID][0].Get_pType() != 3)
	{
		if (pr_list_of_Propertie[BID][0].Get_owned_Status() == false)
		{
			pr_list_of_Propertie[BID][0].Set_owned_Status(true);
			return pr_list_of_Propertie[BID];
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}

bool Bank::Mortgage_Property(int BID)
{
	if (pr_list_of_Propertie[BID - 1][0].Get_pType() != 3)
	{
		if (pr_list_of_Propertie[BID - 1][0].Get_owned_Status()==true && pr_list_of_Propertie[BID - 1][0].Get_Mortgage_Status() == false)
		{
			pr_list_of_Propertie[BID - 1][0].Set_Mortgage_Status(true);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Bank::Cheak_Owned_Status(int BID)
{
	for (int i = 0; i < pr_No_Of_Properties; i++)
	{
		if (pr_list_of_Propertie[i]->Get_BID() == BID)
		{
			if (pr_list_of_Propertie[i]->Get_owned_Status() == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Bank::Cheak_Mortgage_Status(int BID)
{
	for (int i = 0; i < pr_No_Of_Properties; i++)
	{
		if (pr_list_of_Propertie[i]->Get_BID() == BID)
		{
			if (pr_list_of_Propertie[i]->Get_Mortgage_Status() == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

void Bank::Get_All_Properties_From_Files()
{
	int BID = 0, pro_type = 0, cost_price = 0, pro_rent = 0, pro_in_group = 0, national_pro_type = 0;
	bool owned_status = 0, mortgage_status = 0;
	char* Name_ofPro = new char[50];
	char* Name_ofGroup = new char[50];

	ifstream fin;
	fin.open("Properties.txt");

	while (!fin.eof())
	{
		fin >> pro_type;

		if (pro_type == 1)
		{
			fin.ignore();
			fin.getline(Name_ofPro, 50);
			fin >> BID;
			fin >> cost_price;
			fin >> pro_rent;
			fin >> pro_in_group;
			fin >> owned_status;
			fin >> mortgage_status;
			fin >> Name_ofGroup;
		}
		else if (pro_type == 2)
		{
			fin.ignore();
			fin.getline(Name_ofPro, 50);
			fin >> BID;
			fin >> cost_price;
			fin >> pro_rent;
			fin >> pro_in_group;
			fin >> owned_status;
			fin >> mortgage_status;
			fin >> Name_ofGroup;
		}
		else if (pro_type == 3)
		{
			fin.ignore();
			fin.getline(Name_ofPro, 50);
			fin >> BID;
			fin >> national_pro_type;
		}

		this->Add_Property(pro_type, BID, cost_price, pro_rent, pro_in_group, national_pro_type, owned_status, mortgage_status, Name_ofPro, Name_ofGroup);
	}

	delete[]Name_ofGroup;
	delete[]Name_ofPro;
	
}

void Bank::Print_All_Properties()
{
	int type = 0;
	for (int i = 0; i < pr_No_Of_Properties; i++)
	{
		type = pr_list_of_Propertie[i][0].Get_pType();
		if (type == 1)
		{
			cout << "	Private Property" << endl;
			cout << "	Name : "<<pr_list_of_Propertie[i][0].Get_PName() << endl;
			cout << "	Cost : " << pr_list_of_Propertie[i][0] .Get_price()<< endl;
			cout << "	Rent : " << pr_list_of_Propertie[i][0].Get_Rent() << endl;
			if (pr_list_of_Propertie[i][0].Get_owned_Status() == false)
			{
				cout << "	Sold : No" << endl;
			}
			else
			{
				cout << "	Sold : Yes" << endl;
			}

			if (pr_list_of_Propertie[i][0].Get_Mortgage_Status() == false)
			{
				cout << "	Mortgage : No" << endl;
			}
			else
			{
				cout << "	Mortgage : Yes" << endl;
			}

			cout << endl;
		}
		else if (type == 2)
		{
			cout << "	Community Property" << endl;
			cout << "	Name : " << pr_list_of_Propertie[i][0].Get_PName() << endl;
			cout << "	Cost : " << pr_list_of_Propertie[i][0].Get_price() << endl;
			cout << "	Rent : " << pr_list_of_Propertie[i][0].Get_Rent() << endl;
			if (pr_list_of_Propertie[i][0].Get_owned_Status() == false)
			{
				cout << "	Sold : No" << endl;
			}
			else
			{
				cout << "	Sold : Yes" << endl;
			}

			if (pr_list_of_Propertie[i][0].Get_Mortgage_Status() == false)
			{
				cout << "	Mortgage : No" << endl;
			}
			else
			{
				cout << "	Mortgage : Yes" << endl;
			}
			cout << endl;
		}
		else if (type == 3)
		{
			cout << "	National Property" << endl;
			cout << "	Name : " << pr_list_of_Propertie[i][0].Get_PName() << endl;
			cout << "	ID   : " << pr_list_of_Propertie[i][0].Get_NationalProType() << endl;
			cout << endl;
		}
	}
}

Properties** Bank::get_properties()
{
	return pr_list_of_Propertie;
}

Bank::~Bank()
{
	for (int i = 0; i < pr_No_Of_Properties; i++)
	{
		delete pr_list_of_Propertie[i];
	}
	delete[]pr_list_of_Propertie;
}
