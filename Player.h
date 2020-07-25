#pragma once
#include "Name.h"
#include"Properties.h"
#include"Private_Properties.h"
#include"Community_Properties.h"
#include"National_Propesties.h"

class Player
{
	private:
		int pr_Player_ID;
		long int pr_Balance;
		Properties **pr_owned_Properties;
		int pr_no_of_owned_Properties;
		int pr_Jail_Pass;
		float pr_position_x;
		float pr_position_y;
		int pr_address;
		Name pr_player_name;
		int pr_in_jail;

	public:
		Player();

		void Set_player_ID(int);
		void Add_Jail_Pass();
		void Remove_Jail_Pass();
		void Add_Balance(int);
		void Reduce_Balance(int);
		void Set_Balance(int);
		void Set_Position(float, float);
		void set_name(const char*);
		void set_address(int);
		void print_properties();
		void set_in_jail();
		void remove_in_jail();
		void remove_property(int);

		int get_no_of_properties();
		int Get_no_of_jail_Pass();
		int Get_Balance();
		int get_address();
		int get_in_jail();
		int get_land_tax();
		int get_property_tax();
		Properties* get_property(int);

		bool Cheak_Property(int);
		bool Cheak_Mortgage_status(int);

		void Add_Property(Properties*);
		void Mortgage_Property(int);

		char* get_name();
		float get_position_x();
		float get_position_y();
};

