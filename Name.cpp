#include "Name.h"
#include<string>

Name::Name()
{
	pr_property_name = nullptr;
	
}

Name::Name(const char* fname)
{
	pr_property_name = new char[strlen(fname) + 1];
	for (int i = 0; fname[i] != '\0'; i++)
	{
		pr_property_name[i] = fname[i];
	}
	pr_property_name[strlen(fname)] = '\0';
}

Name::Name(Name& obj_in)
{
	int size = 0;

	if (obj_in.pr_property_name != nullptr)
	{
		for (int i = 0; obj_in.pr_property_name[i] != '\0'; i++)
		{
			size++;
		}
		pr_property_name = new char[(size)+1];
		for (int i = 0; i < size; i++)
		{
			pr_property_name[i] = obj_in.pr_property_name[i];
		}
		pr_property_name[size] = '\0';
	}
	else
	{
		pr_property_name = nullptr;
	}

}

void Name::Set_name(const char* fname)
{
	if (pr_property_name != nullptr)
	{
		delete[]pr_property_name;
	}
	pr_property_name = new char[strlen(fname) + 1];
	for (int i = 0; fname[i] != '\0'; i++)
	{
		pr_property_name[i] = fname[i];
	}
	pr_property_name[strlen(fname)] = '\0';

}



void Name::CopyName(Name& obj_in)
{
	int size = 0;

	if (obj_in.pr_property_name != nullptr)
	{
		for (int i = 0; obj_in.pr_property_name[i] != '\0'; i++)
		{
			size++;
		}
		pr_property_name = new char[(size)+1];
		for (int i = 0; i < size; i++)
		{
			pr_property_name[i] = obj_in.pr_property_name[i];
		}

		pr_property_name[size] = '\0';
	}
	else
	{
		pr_property_name = nullptr;
	}

}

char* Name::Get_name()
{
	return pr_property_name;
}



ostream& operator<<(ostream& out, Name& obj_in)
{
	if (obj_in.pr_property_name != nullptr)
	{
		out << obj_in.pr_property_name << endl;
	}
	return out;
}

bool Name::operator==(Name& obj_in)
{
	if (strlen(pr_property_name) == strlen(obj_in.pr_property_name))
	{
		for (int i = 0; pr_property_name[i] != '\0'; i++)
		{
			if (pr_property_name[i] != obj_in.pr_property_name[i])
			{
				return false;
			}
		}

		return true;
	}
	else
	{
		return false;
	}
}

Name::~Name()
{
	if (pr_property_name != nullptr)
	{
		delete[]pr_property_name;
	}
}

