#pragma once
#include"Name.h"
class Properties
{
	private:
		int pr_basic_id;
		Name pr_property_name;
		int pr_property_type;
	public:
		Properties();
		Properties(int, const char*, int);

		void Set_PName(const char*);
		void Set_BID(int);
		void Set_pType(int);

		virtual void Set_Price(int);
		virtual void Set_owned_Status(bool);
		virtual void Set_Rent(int);
		virtual void Set_Group_Name(const char*);
		virtual void Set_NoOfProperties(int);
		virtual void Set_NationalProType(int);
		virtual void Set_Mortgage_Status(bool);


		const char* Get_PName();
		int Get_BID();
		int Get_pType();

		virtual int Get_price();
		virtual bool Get_owned_Status();
		virtual int Get_Rent();
		virtual const char* Get_Group_Name();
		virtual int Get_NoOfProperties();
		virtual int  Get_NationalProType();
		virtual bool Get_Mortgage_Status();
		virtual int Get_NoOf_Houses();
		virtual int Get_NoOf_Shopes();
		virtual int Get_NoOf_Hotel();

		virtual void Add_Building(int);
		virtual void Add_Building(int, int, int, int);
		virtual void Remove_Building(int);
		virtual void Convert_To_Shop();
		virtual void Convert_TO_Hotel();


};

