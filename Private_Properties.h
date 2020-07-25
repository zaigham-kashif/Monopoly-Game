#pragma once

#include"Name.h"
#include"Properties.h"
#include"Building.h"
#include"House.h"
#include"Shop.h"
#include"Hotel.h"

class Private_Properties:public Properties
{
	private:
		int pr_cost_price;
		int pr_rent;
		int pr_pro_in_group;
		bool pr_owned_status;
		bool pr_mortgage_status;
		Name pr_group_name;
		Building** pr_Buludings;
		int pr_NoOf_Buildings;

	public:
		Private_Properties();
		Private_Properties(int, bool, int, const char*, int, bool, int, const char*, int);


		void Set_Price(int) override;
		void Set_owned_Status(bool) override;
		void Set_Rent(int) override;
		void Set_Group_Name(const char*) override;
		void Set_NoOfProperties(int) override;
		void Set_Mortgage_Status(bool) override;

		int  Get_price() override;
		bool Get_owned_Status() override;
		int  Get_Rent() override;
		const char* Get_Group_Name() override;
		int  Get_NoOfProperties() override;
		bool Get_Mortgage_Status() override;
		int  Get_NoOf_Houses() override;
		int  Get_NoOf_Shopes() override;
		int  Get_NoOf_Hotel() override;


		void Add_Building(int) override;
		void Add_Building(int, int, int, int) override;
		void Remove_Building(int) override;
		void Convert_To_Shop() override;
		void Convert_TO_Hotel() override;
		


};

