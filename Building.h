#pragma once
class Building
{
protected:
	int pr_building_ID;
	int pr_NoOf_WiFi;
	int pr_NoOf_GasConnection;
	int pr_NoOf_ElectricConnection;
public:
	Building();
	Building(int);
	Building(int, int, int, int);

	void Set_WiFi(int);
	void Set_Gas(int);
	void Set_Electricity(int);
	void Set_Building_ID(int);

	int Get_WiFi();
	int Get_Gas();
	int Get_Electricity();
	int Get_Building_ID();

	virtual bool Add_WiFi() = 0;
	virtual bool Remove_WiFi() = 0;
	virtual bool Add_Gas() = 0;
	virtual bool Remove_Gas() = 0;
	virtual bool Add_Electricity() = 0;
	virtual bool Remove_Electricity() = 0;

};

