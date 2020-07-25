#pragma once
#include<iostream>
#include"Properties.h"
#include"Private_Properties.h"
#include"Community_Properties.h"
#include"National_Propesties.h"
#include<fstream>

using namespace std;

class Bank
{
	private:
		long int pr_TotalMoney;
		int pr_No_Of_Properties;
		Properties **pr_list_of_Propertie;
	public:
		Bank();
		Bank(long int, int);

		void Get_All_Properties_From_Files();
		void Add_Property(int, int, int, int, int, int, bool, bool, const char*, const char*);

		Properties* Sell_Property(int);

		bool Mortgage_Property(int);
		bool Cheak_Owned_Status(int);
		bool Cheak_Mortgage_Status(int);

		void Print_All_Properties();

		Properties** get_properties();

		~Bank();
};

