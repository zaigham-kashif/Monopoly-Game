#include "Board.h"
#include <time.h>

Board::Board()
{
	pr_bank = new Bank[1];
	pr_bank->Get_All_Properties_From_Files();
	pr_players = nullptr;
	pr_no_of_players = 0;
	pr_shuffled_numbers[14] = { 0 };

	for (int i = 0; i < 15; i++)
	{
		pr_shuffled_numbers[i] = i + 1;
	}
	pr_chance = 0;
	pr_community_chest = 0;
}

void Board::set_no_of_players(int no_of_players)
{
	pr_no_of_players = no_of_players;

	if (pr_players == nullptr)
	{
		pr_players = new Player[pr_no_of_players];
	}
	else
	{
		delete[]pr_players;
		pr_players = new Player[pr_no_of_players];
	}
}

bool Board::buy_property(int player_id, int property_id)
{
	if (player_id <= pr_no_of_players)
	{
		if (pr_bank->get_properties()[property_id]->Get_pType() == 1 || pr_bank->get_properties()[property_id]->Get_pType() == 2)
		{
			if (pr_bank->get_properties()[property_id]->Get_owned_Status() == false)
			{
				if (pr_players[player_id].Get_Balance() >= pr_bank->get_properties()[property_id]->Get_price())
				{
					pr_players[player_id].Add_Property(pr_bank->Sell_Property(property_id));
					pr_players[player_id].Set_Balance(pr_players[player_id].Get_Balance() - pr_bank->get_properties()[property_id]->Get_price());
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

bool Board::sell_property(int player_selling_pro, int player_buying_pro, int pro_sold, int price)
{
	pr_players[player_selling_pro].remove_property(pro_sold);
	pr_bank->get_properties()[pro_sold - 1]->Set_owned_Status(false);
	pr_players[player_selling_pro].Add_Balance(price);

	pr_players[player_buying_pro].Add_Property(pr_bank->Sell_Property(pro_sold - 1));
	pr_players[player_buying_pro].Reduce_Balance(price);

	return true;
}

bool Board::pay_rent(int player_id, int block_address)
{
	int player_id_toRent = 0;
	int id = 0;
	int rent;
	if (pr_bank->get_properties()[block_address]->Get_owned_Status() == true)
	{
		for (int i = 0; i < pr_no_of_players; i++)
		{
			for (int j = 0; j < pr_players[i].get_no_of_properties(); j++)
			{
				if (pr_players[i].get_property(j)->Get_BID() == block_address + 1)
				{
					player_id_toRent = i;
					id = j;
					break;
				}
			}
		}

		if (player_id_toRent != player_id)
		{
			rent = pr_players[player_id_toRent].get_property(id)->Get_Rent();
			pr_players[player_id].Reduce_Balance(rent);
			pr_players[player_id_toRent].Add_Balance(rent);
			return true;
		}
		else
		{
			return false;
		}


	}
	else
	{
		false;
	}
}

void Board::set_address(int player_id, int address_of_cell)
{
	pr_players[player_id].set_address(address_of_cell);
}

void Board::calculate_position(int player_id)
{
	int block_address = pr_players[player_id].get_address();
	if (block_address > 40)
	{
		pr_players[player_id].set_address(block_address - 40);
	}

	if (block_address == 1)
	{
		if (player_id == 0)
		{
			pr_players[player_id].Set_Position(155, 1890);
		}
		else if (player_id == 1)
		{
			pr_players[player_id].Set_Position(165, 2045);
		}
		else if (player_id == 2)
		{
			pr_players[player_id].Set_Position(87.5, 1960.5);

		}
		else if (player_id == 3)
		{
			pr_players[player_id].Set_Position(20, 1890);

		}
		else if (player_id == 4)
		{
			pr_players[player_id].Set_Position(20, 2030);
		}
	}
	else if (block_address == 13)
	{
		if (player_id == 0)
		{
			pr_players[player_id].Set_Position(155 + 2700, 1890);
		}
		else if (player_id == 2)
		{
			pr_players[player_id].Set_Position(165 + 2700, 2045);
		}
		else if (player_id == 3)
		{
			pr_players[player_id].Set_Position(87.5 + 2700, 1960.5);

		}
		else if (player_id == 4)
		{
			pr_players[player_id].Set_Position(20 + 2700, 1890);

		}
		else if (player_id == 5)
		{
			pr_players[player_id].Set_Position(20 + 2700, 2030);
		}
	}
	else if (block_address == 21)
	{
		if (player_id == 0)
		{
			pr_players[player_id].Set_Position(155 + 2700, 1890 - 1870);
		}
		else if (player_id == 1)
		{
			pr_players[player_id].Set_Position(165 + 2700, 2045 - 1870);
		}
		else if (player_id == 2)
		{
			pr_players[player_id].Set_Position(87.5 + 2700, 1960.5 - 1870);

		}
		else if (player_id == 3)
		{
			pr_players[player_id].Set_Position(20 + 2700, 1890 - 1870);

		}
		else if (player_id == 4)
		{
			pr_players[player_id].Set_Position(20 + 2700, 2030 - 1870);
		}
	}
	else if (block_address == 33)
	{
		if (player_id == 0)
		{
			pr_players[player_id].Set_Position(155, 1890 - 1870);
		}
		else if (player_id == 1)
		{
			pr_players[player_id].Set_Position(165, 2045 - 1870);
		}
		else if (player_id == 2)
		{
			pr_players[player_id].Set_Position(87.5, 1960.5 - 1870);

		}
		else if (player_id == 3)
		{
			pr_players[player_id].Set_Position(20, 1890 - 1870);

		}
		else if (player_id == 4)
		{
			pr_players[player_id].Set_Position(20, 2030 - 1870);
		}
	}
	else if (block_address >= 2 && block_address <= 12)
	{
		float x = 0;
		float y = 0;
		x = 320 + (222.7) * (block_address - 2.0);
		y = 1785;

		pr_players[player_id].Set_Position(x, y);
	}
	else if (block_address >= 14 && block_address <= 20)
	{
		float x = 0;
		float y = 0;

		y = 1790 - (232.8) * (block_address - 14.0);
		x = 2600;

		pr_players[player_id].Set_Position(x, y);
	}
	else if (block_address >= 22 && block_address <= 32)
	{
		float x = 0;
		float y = 0;

		x = 2650 - (222.7) * (block_address - 22.0);
		y = 380;

		pr_players[player_id].Set_Position(x, y);
	}
	else if (block_address >= 34 && block_address <= 40)
	{
		float x = 0;
		float y = 0;

		y = 340 + (232.8) * (block_address - 34.0);
		x = 380;

		pr_players[player_id].Set_Position(x, y);
	}
}

void Board::set_position(int player_id, float x, float y)
{
	pr_players[player_id].Set_Position(x, y);
}


bool Board::mortgage_property(int player_id, int property_id)
{
	if (pr_bank->get_properties()[property_id]->Get_pType() == 1 || pr_bank->get_properties()[property_id]->Get_pType() == 2)
	{
		
	}
	else
	{
		return false;
	}
}

void Board::set_player_name(const char* player_name, int player_id)
{
	pr_players[player_id].set_name(player_name);
}

char* Board::get_player_name(int player_id)
{
	return pr_players[player_id].get_name();
}

int Board::roll_dice()
{
	return 1 + (rand() % 6);
}

void Board::community_chest_action(int card_number, int player_id)
{
	if (card_number == 1)
	{
		pr_players[player_id].set_address(1);
		this->calculate_position(player_id);
		pr_players[player_id].Add_Balance(400);
	}
	else if (card_number == 2)
	{
		pr_players[player_id].Add_Balance(200);
	}
	else if (card_number == 3)
	{
		pr_players[player_id].Reduce_Balance(200);
	}
	else if (card_number == 4)
	{
		pr_players[player_id].Add_Balance(50);
	}
	else if (card_number == 5)
	{
		pr_players[player_id].Add_Jail_Pass();
	}
	else if (card_number == 6)
	{
		pr_players[player_id].Add_Balance(150);
	}
	else if (card_number == 7)
	{
		pr_players[player_id].Add_Balance(200);
	}
	else if (card_number == 8)
	{
		pr_players[player_id].Reduce_Balance(100);
	}
	else if (card_number == 9)
	{
		pr_players[player_id].Reduce_Balance(200);
	}
	else if (card_number == 10)
	{
		pr_players[player_id].Add_Balance(50);
	}
	else if (card_number == 11)
	{
		int no_of_houses = 0;
		int no_of_hotel = 0;

		for (int i = 0; i < pr_players[player_id].get_no_of_properties(); i++)
		{
			no_of_houses = no_of_houses + pr_players[player_id].get_property(i)->Get_NoOf_Houses();
			no_of_hotel = no_of_hotel + pr_players[player_id].get_property(i)->Get_NoOf_Hotel();
		}

		pr_players[player_id].Reduce_Balance(no_of_houses * 50);
		pr_players[player_id].Reduce_Balance(no_of_hotel * 125);

	}
	else if (card_number == 12)
	{
		pr_players[player_id].Add_Balance(300);
	}
	else if (card_number == 13)
	{
		pr_players[player_id].Reduce_Balance(50);
	}
	else if (card_number == 14)
	{
		pr_players[player_id].Reduce_Balance(80);
	}
	else if (card_number == 15)
	{
		pr_players[player_id].Reduce_Balance(50);
	}
}

void Board::chance_action(int card_number, int player_id, int no_on_dice)
{
	if (card_number == 1)
	{
		pr_players[player_id].set_address(1);
		this->calculate_position(player_id);
		pr_players[player_id].Add_Balance(300);
	}
	else if (card_number == 2)
	{
		pr_players[player_id].set_address(28);
		this->calculate_position(player_id);
	}
	else if (card_number == 3)
	{
		int current_address = pr_players[player_id].get_address();
		while (pr_bank->get_properties()[current_address]->Get_pType() != 2 && pr_bank->get_properties()[current_address]->Get_Group_Name() == "UTILITY")
		{
			current_address++;
		}

		pr_players[player_id].set_address(current_address);
		this->calculate_position(player_id);

		if (pr_bank->get_properties()[current_address]->Get_owned_Status() == false)
		{

		}
		else if (pr_bank->get_properties()[current_address]->Get_owned_Status() == true)
		{
			for (int i = 0; i < no_on_dice * 5; i++)
			{
				this->pay_rent(player_id, current_address);
			}
		}
	}
	else if (card_number == 4 || card_number == 5)
	{
		int current_address = pr_players[player_id].get_address();
		while (pr_bank->get_properties()[current_address]->Get_pType() != 2 && pr_bank->get_properties()[current_address]->Get_Group_Name() == "STATION")
		{
			current_address++;
		}

		pr_players[player_id].set_address(current_address);
		this->calculate_position(player_id);

		if (pr_bank->get_properties()[current_address]->Get_owned_Status() == false)
		{

		}
		else if (pr_bank->get_properties()[current_address]->Get_owned_Status() == true)
		{
			this->pay_rent(player_id, current_address);
		}
	}
	else if (card_number == 6)
	{
		if (pr_players[player_id].get_address() < 17)
		{
			pr_players[player_id].set_address(17);
			this->calculate_position(player_id);
		}
		else
		{
			pr_players[player_id].set_address(17);
			this->calculate_position(player_id);

			pr_players->Add_Balance(300);
		}
	}
	else if (card_number == 7)
	{
		pr_players[player_id].Add_Balance(100);
	}
	else if (card_number == 8)
	{
		pr_players[player_id].Add_Jail_Pass();
	}
	else if (card_number == 9)
	{
		pr_players[player_id].set_address(pr_players[player_id].get_address() - 4);
	}
	else if (card_number == 10)
	{
		int no_of_houses = 0;
		int no_of_hotel = 0;

		for (int i = 0; i < pr_players[player_id].get_no_of_properties(); i++)
		{
			no_of_houses = no_of_houses + pr_players[player_id].get_property(i)->Get_NoOf_Houses();
			no_of_hotel = no_of_hotel + pr_players[player_id].get_property(i)->Get_NoOf_Hotel();
		}

		pr_players[player_id].Reduce_Balance(no_of_houses * 50);
		pr_players[player_id].Reduce_Balance(no_of_hotel * 100);
	}
	else if (card_number == 11)
	{
		pr_players[player_id].Reduce_Balance(25);
	}
	else if (card_number == 12)
	{
		pr_players[player_id].Reduce_Balance(25 * (pr_no_of_players - 1));
		for (int i = 0; i < pr_no_of_players; i++)
		{
			if (i != player_id)
			{
				pr_players[i].Add_Balance(25);
			}
		}
	}
	else if (card_number == 13)
	{
		pr_players[player_id].Add_Balance(150);
	}
	else if (card_number == 14)
	{

	}
	else if (card_number == 15)
	{
		pr_players[player_id].set_address(6);
		this->calculate_position(player_id);
	}
}

int Board::get_address(int player_id)
{
	return pr_players[player_id].get_address();
}

float Board::get_position_x(int player_id)
{
	return pr_players[player_id].get_position_x();
}

float Board::get_position_y(int player_id)
{
	return pr_players[player_id].get_position_y();
}

Bank* Board::get_bank()
{
	return pr_bank;
}

Player& Board::get_player(int player_id)
{
	return pr_players[player_id];
}



void Board::shuffle()
{
	//int random_number = 0;
	//int i = 0;
	//bool flag = true;


	/*for (i = 0; i < 15; i++)
	{

		srand(time(0));
		random_number = rand() % 15 + 1;
		flag = true;

		for (int j = 0; j < i; j++)
		{
			if (pr_shuffled_numbers[j] == random_number)
			{
				flag = false;
				break;
			}
		}

		if (flag == true)
		{
			pr_shuffled_numbers[i] = random_number;
		}
		else
		{
			i--;
		}
	}*/

	
	size_t i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 15 - 1; i++)
	{
		size_t j = i + rand() / (RAND_MAX / (15 - i) + 1);
		int t = pr_shuffled_numbers[j];
		pr_shuffled_numbers[j] = pr_shuffled_numbers[i];
		pr_shuffled_numbers[i] = t;
	}
}

int Board::get_chance_card()
{
	if (pr_chance == 14)
	{
		this->shuffle();
		pr_chance = 0;
	}

	return pr_shuffled_numbers[pr_chance++];
}

int Board::get_community_chest_card()
{
	if (pr_community_chest == 14)
	{
		this->shuffle();
		pr_community_chest = 0;
	}

	
	return pr_shuffled_numbers[pr_community_chest++];
}

Board::~Board()
{
	delete pr_bank;
	delete[]pr_players;
}