#pragma once
#include"Name.h"
#include"Properties.h"

class Community_Properties:public Properties
{
	private:
		int pr_cost_price;
		bool pr_owned_status;
		bool pr_mortgage_status;
		int pr_rent;
		Name pr_group_name;
		int pr_pro_in_group;
	public:
		Community_Properties();
		Community_Properties(int, bool, int, const char*, int, bool, int, const char*, int);

		void Set_Price(int) override;
		void Set_owned_Status(bool) override;
		void Set_Rent(int) override;
		void Set_Group_Name(const char*) override;
		void Set_NoOfProperties(int) override;
		void Set_Mortgage_Status(bool) override;

		int Get_price() override;
		bool Get_owned_Status() override;
		int Get_Rent() override;
		const char* Get_Group_Name() override;
		int Get_NoOfProperties() override;
		bool Get_Mortgage_Status() override;


};

