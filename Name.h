#pragma once
#include<iostream>

using namespace std;

class Name
{
private:
	char* pr_property_name;
	
public:
	Name();
	Name(const char*);
	Name(Name&);

	void Set_name(const char*);
	void CopyName(Name&);

	char* Get_name();

	friend ostream& operator <<(ostream&, Name&);
	bool operator ==(Name&);

	~Name();

};


