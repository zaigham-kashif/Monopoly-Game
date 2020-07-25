#include "Player.h"

Player::Player()
{
	pr_Player_ID = 0;
	pr_Balance = 5000;
	pr_owned_Properties = nullptr;
	pr_no_of_owned_Properties = 0;
	pr_Jail_Pass = 0;
	pr_position_x = 0;
	pr_position_y = 0;
	pr_address = 1;
	pr_in_jail = 0;
}

void Player::Set_player_ID(int ID)
{
	pr_Player_ID = ID;
}

void Player::Add_Jail_Pass()
{
	pr_Jail_Pass = pr_Jail_Pass + 1;
}

void Player::Remove_Jail_Pass()
{
	if (pr_Jail_Pass != 0)
	{
		pr_Jail_Pass = pr_Jail_Pass - 1;
	}
}

void Player::Add_Balance(int amount)
{
	pr_Balance = pr_Balance + amount;
}

void Player::Reduce_Balance(int amount)
{
	pr_Balance = pr_Balance - amount;
}

void Player::Set_Balance(int Balance)
{
	pr_Balance = Balance;
}

void Player::Set_Position(float x, float y)
{
	pr_position_x = x;
	pr_position_y = y;
}

void Player::set_name(const char* name)
{
	pr_player_name.Set_name(name);
}

void Player::set_address(int address)
{
	pr_address = address;
}

void Player::print_properties()
{
	for (int i = 0; i < pr_no_of_owned_Properties; i++)
	{
		cout<<pr_owned_Properties[i]->Get_PName();
	}
}

void Player::set_in_jail()
{
	pr_in_jail = 2;
}

void Player::remove_in_jail()
{
	if (pr_in_jail == 2)
	{
		pr_in_jail = 1;
	}
	else if (pr_in_jail == 1)
	{
		pr_in_jail = 0;
	}
}

void Player::remove_property(int pro_id)
{
	int key = -1;

	for (int i = 0; i < pr_no_of_owned_Properties; i++)
	{
		if (pr_owned_Properties[i]->Get_BID() == pro_id)
		{
			key = i;
			break;
		}
	}

	if (key != -1)
	{
		if (pr_no_of_owned_Properties == 1)
		{
			delete []pr_owned_Properties;
			pr_owned_Properties = nullptr;
			pr_no_of_owned_Properties = 0;
		}
		else
		{
		

				Properties** temp_all_properties = new Properties * [pr_no_of_owned_Properties];

				for (int i = 0; i < pr_no_of_owned_Properties; i++)
				{
					temp_all_properties[i] = pr_owned_Properties[i];
				}

				delete[]pr_owned_Properties;
				pr_owned_Properties = nullptr;

				pr_owned_Properties = new Properties * [pr_no_of_owned_Properties - 1];

				for (int i = 0; i < key; i++)
				{
					pr_owned_Properties[i] = temp_all_properties[i];
				}

				for (int j = key + 1; j < pr_no_of_owned_Properties; j++)
				{
					pr_owned_Properties[j - 1] = temp_all_properties[j];
				}

				pr_no_of_owned_Properties--;

				delete[]temp_all_properties;
				temp_all_properties = nullptr;
		}

	}
	
}

int Player::get_no_of_properties()
{
	return pr_no_of_owned_Properties;
}

int Player::Get_no_of_jail_Pass()
{
	return pr_Jail_Pass;
}

int Player::Get_Balance()
{
	return pr_Balance;
}

int Player::get_address()
{
	return pr_address;
}

int Player::get_in_jail()
{
	return pr_in_jail;
}

int Player::get_land_tax()
{

	if (pr_owned_Properties == nullptr)
	{
		return 0;
	}
	else
	{
		int tax = 0;

		for (int i = 0; i < pr_no_of_owned_Properties; i++)
		{
			tax = (pr_owned_Properties[i]->Get_price() / 100) * 20 + tax;
		}
		return tax;
	}
}

int Player::get_property_tax()
{

	if (pr_owned_Properties == nullptr)
	{
		return 0;
	}
	else
	{
		int land_tax = 0, house_tax = 0, hotel_tax = 0, shop_tax = 0;

		for (int i = 0; i < pr_no_of_owned_Properties; i++)
		{
			land_tax  =  ((pr_owned_Properties[i]->Get_price() / 100) * 10) + land_tax;
			house_tax =  ((pr_owned_Properties[i]->Get_NoOf_Houses() / 100) * 20) + house_tax;
			hotel_tax =  ((pr_owned_Properties[i]->Get_NoOf_Hotel() / 100) * 30) + hotel_tax;
			shop_tax  =  ((pr_owned_Properties[i]->Get_NoOf_Shopes() / 100) * 30) + shop_tax;
		}
		return (land_tax + house_tax + hotel_tax + shop_tax);

	}
}

Properties* Player::get_property(int property_id)
{
	return pr_owned_Properties[property_id];
}

bool Player::Cheak_Property(int BID)
{
	for (int i = 0; i < pr_no_of_owned_Properties; i++)
	{
		if (pr_owned_Properties[i]->Get_BID() == BID)
		{
			return true;
		}
	}
	return false;
}

bool Player::Cheak_Mortgage_status(int BID)
{
	if (this->Cheak_Property(BID) == true)
	{
		if (pr_owned_Properties[BID]->Get_Mortgage_Status() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Player::Add_Property(Properties* Property_in)
{
	if (pr_owned_Properties == nullptr)
	{
		pr_owned_Properties = new Properties * [1];
		pr_owned_Properties[0] = Property_in;
		pr_no_of_owned_Properties++;
	}
	else
	{
		Properties** Temp_owned_Properties = new Properties * [pr_no_of_owned_Properties];

		for (int i = 0; i < pr_no_of_owned_Properties; i++)
		{
			Temp_owned_Properties[i] = pr_owned_Properties[i];
		}

		delete[]pr_owned_Properties;
		pr_owned_Properties = nullptr;

		pr_owned_Properties = new Properties * [pr_no_of_owned_Properties + 1];

		for (int i = 0; i < pr_no_of_owned_Properties; i++)
		{
			pr_owned_Properties[i] = Temp_owned_Properties[i];
		}

		pr_owned_Properties[pr_no_of_owned_Properties] = Property_in;

		pr_no_of_owned_Properties++;

		delete[]Temp_owned_Properties;
		Temp_owned_Properties = nullptr;
	}
}

void Player::Mortgage_Property(int BID)
{
	if (this->Cheak_Property(BID) == true)
	{
		pr_owned_Properties[BID]->Set_Mortgage_Status(true);
	}
}

char* Player::get_name()
{
	return pr_player_name.Get_name();
}

float Player::get_position_x()
{
	return pr_position_x;
}

float Player::get_position_y()
{
	return pr_position_y;
}




