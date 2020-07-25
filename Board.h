#pragma once
#include "Bank.h"
#include "Player.h"

class Board
{
private:
	Bank* pr_bank;
	Player* pr_players;
	int pr_no_of_players;

	int pr_shuffled_numbers[15];
	int pr_chance;
	int pr_community_chest;

public:
	Board();

	void set_no_of_players(int);
	void set_address(int, int);
	void calculate_position(int);
	void set_position(int, float, float);
	void shuffle();

	int get_chance_card();
	int get_community_chest_card();

	char* get_player_name(int);

	bool buy_property(int, int);
	bool sell_property(int, int, int, int);
	bool pay_rent(int, int);

	bool mortgage_property(int, int);

	void set_player_name(const char*, int);



	int roll_dice();
	void community_chest_action(int, int);
	void chance_action(int, int, int);

	int get_address(int);
	float get_position_x(int);
	float get_position_y(int);

	Bank* get_bank();
	Player& get_player(int);

	~Board();

};

