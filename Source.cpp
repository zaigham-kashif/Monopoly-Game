#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "Bank.h"
#include "Name.h"
#include "TextBox.h"
#include "Button.h"
#include "Board.h"


using namespace std;
using namespace sf;

float resolution = 1.0;

RenderWindow window(VideoMode(3840 / resolution, 2160 / resolution), "Monopoly", Style::Default);
Font         font;
Board        board;

void   Board_Graphics();
string player_name_window(const char*, RectangleShape&, Button&, TextBox&);
void   no_of_player_window(RectangleShape&, Text&, Button&, Button&, Button&);
void   menu_panel_1(Button&, Button&);
void   dice_graphics(int, int);
void   move_player(int);
void   menu_panel_2(Button**, int, Button&);
void   property_information(int, Button&);
char*  int_to_char(int);
void   menu_panel(int, int);
void   chance(int);
void   community_chest(int);
void   text_panel();
void   draw_button(Button&, float, float);
void   remove_button(Button&);
void   property_information(int);
int    string_to_int(const string&);
void draw_button(Button& button, float x_position, float y_position, int char_size);

int main()
{
	int option1 = 0;
	int option_dice = 0;
	int option_show_properties = 0;
	int back_option = 0;
	int bye_option = 0;
	int rent_option = 0;
	int continue_option = 0;
	int pass_option = 0;
	int sell_option = 0;
	int player_id_to_sell = -1;

	int current_card = 0;
	int dice = 0;
	int board_block = 0;
	int no_of_players = 0;
	int current_player = 0;
	int property_id = 0;
	int i = 0;
	int selling_price = 0;

	srand(time(NULL));

	float x_axis = 0;

	window.setMouseCursorVisible(true);
	if (resolution == 2)
	{
		window.setPosition(Vector2i(-20.0 / resolution, -94.0 / resolution));
	}
	else
	{
		window.setPosition(Vector2i(-20.0 / resolution, -85.0 / resolution));
	}

	Texture player_1_piece;
	Texture player_2_piece;
	Texture player_3_piece;
	Texture player_4_piece;
	Texture player_5_piece;

	sf::Sprite Sprite;


	Text text;

	TextBox name_text_box_1(100 / resolution, Color::Black, true);
	TextBox name_text_box_2(100 / resolution, Color::Black, true);
	TextBox name_text_box_3(100 / resolution, Color::Black, true);
	TextBox name_text_box_4(100 / resolution, Color::Black, true);
	TextBox name_text_box_5(100 / resolution, Color::Black, true);
	TextBox price(100, Color::Black, true);


	RectangleShape Name_input_panel;
	RectangleShape No_of_player_input_panel;

	Button *continue_button  = new Button ("Continue", { 600 / resolution,200 / resolution }, Color::Red, Color::White);
	Button *players_3        = new Button ("3", { 300 / resolution,300 / resolution }, Color::Blue, Color::White);
	Button *players_4        = new Button ("4", { 300 / resolution,300 / resolution }, Color::Blue, Color::White);
	Button *players_5        = new Button ("5", { 300 / resolution,300 / resolution }, Color::Blue, Color::White);
	Button *dice_button      = new Button ("Roll dice", { 830 / resolution,100 / resolution }, Color::Red, Color::Blue);
	Button *properties_button= new Button ("Properties", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *back_button_1    = new Button ("Back", { 830 / resolution,100 / resolution }, Color::Red, Color::Blue);
	Button *back_button_2    = new Button ("Back", { 350 / resolution,100 / resolution }, Color::Red, Color::Blue);
	Button *buy_button       = new Button ("Buy", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *rent_button      = new Button ("Pay Rent", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *continue_button_2= new Button ("Continue", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *pass_button      = new Button ("Pass", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *skip_turn		 = new Button ("Skip", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *pay              = new Button ("Pay", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *use_pass         = new Button ("Use Pass", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *mortgage_property= new Button ("Mortgage", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *sell_property    = new Button ("Sell", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	Button *yes              = new Button ("Yes", { 250 / resolution,150 / resolution }, Color::Red, Color::Blue);
	Button *no				 = new Button ("No", { 250 / resolution,150 / resolution }, Color::Red, Color::Blue);
	Button *add_house        = new Button ("Add House", { 200,100 }, Color::Red, Color::Blue);
	Button *add_shop         = new Button ("Add Shop", { 200,100 }, Color::Red, Color::Blue);
	Button *add_hotel        = new Button ("Add Hotel", { 200,100 }, Color::Red, Color::Blue);
	Button *un_mortgage_property= new Button ("Un-mortgage", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);



	Button** players = new Button * [4];
	for (int i = 0; i < 4; i++)
	{
		players[i] = new Button("", { 560 / resolution,200 / resolution }, Color::Red, Color::Blue);
	}
	int player_array[4] = {0};

	Button** all_properties_buttons = new  Button * [28];
	for (int i = 0; i < 28; i++)
	{
		all_properties_buttons[i] = new Button("", { 300 / resolution,100 / resolution }, Color::Red, Color::Black);
	}

	board.shuffle();
	int a = board.get_community_chest_card();


	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << "	Could Not Load Font" << endl;
	}

	if (!player_1_piece.loadFromFile("Images/player_1.PNG"))
	{
		cout << "	Error" << endl;
	}
	
	if (!player_2_piece.loadFromFile("Images/player_2.PNG"))
	{
		cout << "	Error" << endl;
	}

	if (!player_3_piece.loadFromFile("Images/player_3.PNG"))
	{
		cout << "	Error" << endl;
	}

	if (!player_4_piece.loadFromFile("Images/player_4.PNG"))
	{
		cout << "	Error" << endl;
	}

	if (!player_5_piece.loadFromFile("Images/player_5.PNG"))
	{
		cout << "	Error" << endl;
	}

	


	while (window.isOpen())
	{
		sf::Event event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			name_text_box_1.set_selected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			name_text_box_1.set_selected(false);
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::TextEntered)
			{
				if (option1 == 0)
				{
					name_text_box_1.Typed(event);
				}
				else if (option1 == 1)
				{
					name_text_box_2.Typed(event);
				}
				else if (option1 == 2)
				{
					name_text_box_3.Typed(event);
				}
				else if (option1 == 3)
				{
					name_text_box_4.Typed(event);
				}
				else if (option1 == 4)
				{
					name_text_box_5.Typed(event);
				}

				if (sell_option == 1)
				{
					price.Typed(event);
				}
			}
			else if (event.type == sf::Event::MouseMoved)
			{
				if (continue_button->is_mouse_over(window))
				{
					continue_button->set_button_color(Color::Black);
				}
				else
				{
					continue_button->set_button_color(Color::Red);
				}

				if (players_3->is_mouse_over(window))
				{
					players_3->set_button_color(Color::Black);
				}
				else
				{
					players_3->set_button_color(Color::Blue);
				}

				if (players_4->is_mouse_over(window))
				{
					players_4->set_button_color(Color::Black);
				}
				else
				{
					players_4->set_button_color(Color::Blue);
				}

				if (players_5->is_mouse_over(window))
				{
					players_5->set_button_color(Color::Black);
				}
				else
				{
					players_5->set_button_color(Color::Blue);
				}

				if (dice_button->is_mouse_over(window))
				{
					dice_button->set_button_color(Color::Black);
				}
				else
				{
					dice_button->set_button_color(Color::Red);
				}


				if (properties_button->is_mouse_over(window))
				{
					properties_button->set_button_color(Color::Black);
				}
				else
				{
					properties_button->set_button_color(Color::Red);
				}

				if (all_properties_buttons[0]->is_mouse_over(window))
				{
					all_properties_buttons[0]->set_button_color(Color::Black);
				}
				else
				{
					all_properties_buttons[0]->set_button_color(Color::Red);
				}

				if (back_button_1->is_mouse_over(window))
				{
					back_button_1->set_button_color(Color::Black);
				}
				else
				{
					back_button_1->set_button_color(Color::Red);
				}

				if (back_button_2->is_mouse_over(window))
				{
					back_button_2->set_button_color(Color::Black);
				}
				else
				{
					back_button_2->set_button_color(Color::Red);
				}

				if (buy_button->is_mouse_over(window))
				{
					buy_button->set_button_color(Color::Black);
				}
				else
				{
					buy_button->set_button_color(Color::Red);
				}

				if (rent_button->is_mouse_over(window))
				{
					rent_button->set_button_color(Color::Black);
				}
				else
				{
					rent_button->set_button_color(Color::Red);
				}

				if (continue_button_2->is_mouse_over(window))
				{
					continue_button_2->set_button_color(Color::Black);
				}
				else
				{
					continue_button_2->set_button_color(Color::Red);
				}

				if (pass_button->is_mouse_over(window))
				{
					pass_button->set_button_color(Color::Black);
				}
				else
				{
					pass_button->set_button_color(Color::Red);
				}

				if (skip_turn->is_mouse_over(window))
				{
					skip_turn->set_button_color(Color::Black);
				}
				else
				{
					skip_turn->set_button_color(Color::Red);
				}

				if (pay->is_mouse_over(window))
				{
					pay->set_button_color(Color::Black);
				}
				else
				{
					pay->set_button_color(Color::Red);
				}

				if (use_pass->is_mouse_over(window))
				{
					use_pass->set_button_color(Color::Black);
				}
				else
				{
					use_pass->set_button_color(Color::Red);
				}

				if (mortgage_property->is_mouse_over(window))
				{
					mortgage_property->set_button_color(Color::Black);
				}
				else
				{
					mortgage_property->set_button_color(Color::Red);
				}

				if (un_mortgage_property->is_mouse_over(window))
				{
					un_mortgage_property->set_button_color(Color::Black);
				}
				else
				{
					un_mortgage_property->set_button_color(Color::Red);
				}

				if (sell_property->is_mouse_over(window))
				{
					sell_property->set_button_color(Color::Black);
				}
				else
				{
					sell_property->set_button_color(Color::Red);
				}

				if (yes->is_mouse_over(window))
				{
					yes->set_button_color(Color::Black);
				}
				else
				{
					yes->set_button_color(Color::Red);
				}

				if (no->is_mouse_over(window))
				{
					no->set_button_color(Color::Black);
				}
				else
				{
					no->set_button_color(Color::Red);
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{

				if (players_3->is_mouse_over(window) && no_of_players == 0)
				{
					no_of_players = 3;
				}
				
				if (players_4->is_mouse_over(window) && no_of_players == 0)
				{
					no_of_players = 4;
				}

				if (players_5->is_mouse_over(window) && no_of_players == 0)
				{
					no_of_players = 5;
				}

				if (dice_button->is_mouse_over(window) && option_dice == 0 && option_show_properties == 0 && property_id == 0)
				{
					option_dice = 1;
				}

				if (properties_button->is_mouse_over(window) && option_show_properties == 0 /*&& property_id == 0*/)
				{
					option_show_properties = 1;
					property_id = 0;
				}

				if (no_of_players != 0)
				{
					if (continue_button->is_mouse_over(window) && option1 == 0 && option1 < no_of_players - 1)
					{
						option1 = 1;
					}
					else if (continue_button->is_mouse_over(window) && option1 == 1 && option1 < no_of_players - 1)
					{
						option1 = 2;
					}
					else if (continue_button->is_mouse_over(window) && option1 == 2 && option1 < no_of_players - 1)
					{
						option1 = 3;
					}
					else if (continue_button->is_mouse_over(window) && option1 == 3 && option1 < no_of_players - 1)
					{
						option1 = 4;
					}
					else if (continue_button->is_mouse_over(window) && option1 + 1 == no_of_players)
					{
						option1 = 5;
					}
				}

				if (all_properties_buttons[0]->is_mouse_over(window) && option_show_properties == 1 && property_id == 0)
				{
					property_id = 2;
				}
				else if (all_properties_buttons[1]->is_mouse_over(window))
				{
					property_id = 4;
				}
				else if (all_properties_buttons[2]->is_mouse_over(window))
				{
					property_id = 7;
				}
				else if (all_properties_buttons[3]->is_mouse_over(window))
				{
					property_id = 9;
				}
				else if (all_properties_buttons[4]->is_mouse_over(window))
				{
					property_id = 10;
				}
				else if (all_properties_buttons[5]->is_mouse_over(window))
				{
					property_id = 11;
				}
				else if (all_properties_buttons[6]->is_mouse_over(window))
				{
					property_id = 14;
				}
				else if (all_properties_buttons[7]->is_mouse_over(window))
				{
					property_id = 15;
				}
				else if (all_properties_buttons[8]->is_mouse_over(window))
				{
					property_id = 17;
				}
				else if (all_properties_buttons[9]->is_mouse_over(window))
				{
					property_id = 19;
				}
				else if (all_properties_buttons[10]->is_mouse_over(window))
				{
					property_id = 22;
				}
				else if (all_properties_buttons[11]->is_mouse_over(window))
				{
					property_id = 24;
				}
				else if (all_properties_buttons[12]->is_mouse_over(window))
				{
					property_id = 25;
				}
				else if (all_properties_buttons[13]->is_mouse_over(window))
				{
					property_id = 27;
				}
				else if (all_properties_buttons[14]->is_mouse_over(window))
				{
					property_id = 28;
				}
				else if (all_properties_buttons[15]->is_mouse_over(window))
				{
					property_id = 30;
				}
				else if (all_properties_buttons[16]->is_mouse_over(window))
				{
					property_id = 31;
				}
				else if (all_properties_buttons[17]->is_mouse_over(window))
				{
					property_id = 35;
				}
				else if (all_properties_buttons[18]->is_mouse_over(window))
				{
					property_id = 38;
				}
				else if (all_properties_buttons[19]->is_mouse_over(window))
				{
					property_id = 40;
				}
				else if (all_properties_buttons[20]->is_mouse_over(window))
				{
					property_id = 6;
				}
				else if (all_properties_buttons[21]->is_mouse_over(window))
				{
					property_id = 16;
				}
				else if (all_properties_buttons[22]->is_mouse_over(window))
				{
					property_id = 26;
				}
				else if (all_properties_buttons[23]->is_mouse_over(window))
				{
					property_id = 36;
				}
				else if (all_properties_buttons[24]->is_mouse_over(window))
				{
					property_id = 12;
				}
				else if (all_properties_buttons[25]->is_mouse_over(window))
				{
					property_id = 20;
				}
				else if (all_properties_buttons[26]->is_mouse_over(window))
				{
					property_id = 29;
				}
				else if (all_properties_buttons[27]->is_mouse_over(window))
				{
					property_id = 32;
				}

				if (back_button_1->is_mouse_over(window) && option_show_properties == 1)
				{
					option_show_properties = 0;
					property_id = 0;
					for (int i = 0; i < 28; i++)
					{
						remove_button(all_properties_buttons[i][0]);
					}
				}

				if (back_button_2->is_mouse_over(window) && option_show_properties == 1 && property_id != 0)
				{
					property_id = 0;
					option_show_properties = 1;
				}

				if (buy_button->is_mouse_over(window))
				{
					bye_option = 1;
				}

				if (rent_button->is_mouse_over(window))
				{
					rent_option = 1;
				}

				if (continue_button_2->is_mouse_over(window) && continue_option == 0)
				{
					continue_option = 1;
					bye_option = 0;
					rent_option = 0;
				}

				if (pass_button->is_mouse_over(window))
				{
					pass_option = 1;
				}


				if (skip_turn->is_mouse_over(window))
				{
					board.get_player(current_player - 1).remove_in_jail();

					if (current_player >= no_of_players)
					{
						current_player = 0;
					}
					current_player = current_player + (no_of_players)-(no_of_players - 1);
				}

				if (pay->is_mouse_over(window))
				{
					board.get_player(current_player - 1).Reduce_Balance(400);
					board.get_player(current_player - 1).remove_in_jail();
					board.get_player(current_player - 1).remove_in_jail();
				}

				if (use_pass->is_mouse_over(window))
				{
					if (board.get_player(current_player - 1).Get_no_of_jail_Pass() != 0)
					{
						board.get_player(current_player - 1).Remove_Jail_Pass();
						board.get_player(current_player - 1).remove_in_jail();
						board.get_player(current_player - 1).remove_in_jail();
					}
				}

				if (mortgage_property->is_mouse_over(window))
				{
					int mortgage_value = 0;
					board.get_bank()->get_properties()[property_id - 1]->Set_Mortgage_Status(true);
					mortgage_value = (board.get_bank()->get_properties()[property_id - 1]->Get_price() / 2);
					mortgage_value = mortgage_value + (board.get_bank()->get_properties()[property_id - 1]->Get_NoOf_Houses() * 100) / 2;
					mortgage_value = mortgage_value + (board.get_bank()->get_properties()[property_id - 1]->Get_NoOf_Hotel() * 1000) / 2;
					mortgage_value = mortgage_value + (board.get_bank()->get_properties()[property_id - 1]->Get_NoOf_Shopes() * 300) / 2;

					board.get_player(current_player - 1).Add_Balance(mortgage_value);

				}

				if (un_mortgage_property->is_mouse_over(window))
				{
					int un_mortgage_value = 0;
					board.get_bank()->get_properties()[property_id - 1]->Set_Mortgage_Status(true);
					un_mortgage_value = (board.get_bank()->get_properties()[property_id - 1]->Get_price() / 2);
					un_mortgage_value = un_mortgage_value + (board.get_bank()->get_properties()[property_id - 1]->Get_NoOf_Houses() * 100) / 2;
					un_mortgage_value = un_mortgage_value + (board.get_bank()->get_properties()[property_id - 1]->Get_NoOf_Hotel() * 1000) / 2;
					un_mortgage_value = un_mortgage_value + (board.get_bank()->get_properties()[property_id - 1]->Get_NoOf_Shopes() * 300) / 2;

					un_mortgage_value = un_mortgage_value + ((un_mortgage_value / 100) * 20);

					board.get_player(current_player - 1).Reduce_Balance(un_mortgage_value);
				}

				if (sell_property->is_mouse_over(window))
				{
					sell_option = 1;
				}

				if (sell_option == 1)
				{
					

					if (no_of_players == 3)
					{
						if (players[0]->is_mouse_over(window))
						{
							player_id_to_sell = player_array[0];
						}
						else if (players[1]->is_mouse_over(window))
						{
							player_id_to_sell = player_array[1];
						}
					}
					else if (no_of_players == 4)
					{
						if (players[0]->is_mouse_over(window))
						{
							player_id_to_sell = player_array[0];
						}
						else if (players[1]->is_mouse_over(window))
						{
							player_id_to_sell = player_array[1];
						}
						else if (players[2]->is_mouse_over(window))
						{
							player_id_to_sell = player_array[2];
						}
					}
					else if (no_of_players == 5)
					{
						if (players[0]->is_mouse_over(window))
						{
							player_id_to_sell = player_array[0];
						}
						else if (players[1]->is_mouse_over(window))
						{
							player_id_to_sell = player_array[1];
						}
						else if (players[2]->is_mouse_over(window))
						{
							player_id_to_sell = player_array[2];
						}
						else if (players[3]->is_mouse_over(window))
						{
							player_id_to_sell = player_array[3];
						}
					}

					if (no->is_mouse_over(window))
					{
						sell_option = 0;
						property_id = 0;
						player_id_to_sell = -1;
					}
					else if (yes->is_mouse_over(window))
					{
						board.sell_property(current_player - 1, player_id_to_sell, property_id, selling_price);
						sell_option = 0;
						property_id = 0;
						player_id_to_sell = -1;
					}
					
				}
				
			}
		}

		
		if (no_of_players == 0)
		{
			window.clear();
			no_of_player_window(No_of_player_input_panel, text, *players_3, *players_4, *players_5);

			window.display();
		}
		else
		{
			
			if (option1 == 0 && no_of_players > option1)
			{
				window.clear();
				player_name_window("Player # 1", Name_input_panel, *continue_button, name_text_box_1);

				Sprite.setTexture(player_1_piece);
				Sprite.setTextureRect(IntRect(0, 0, 600, 600));
				Sprite.setOrigin(-1650, -300);
				Sprite.setScale(1 / resolution, 1 / resolution);
				Sprite.setRotation(0);
				window.draw(Sprite);

				window.display();

			}
			else if (option1 == 1 && no_of_players > option1)
			{
				window.clear();
				for (static bool first = true; first; first = false)
				{
					cout << name_text_box_1.Get_text() << endl;

				}

				player_name_window("Player # 2", Name_input_panel, *continue_button, name_text_box_2);

				Sprite.setTexture(player_2_piece);
				Sprite.setTextureRect(IntRect(0, 0, 600, 600));
				Sprite.setOrigin(-1650, -320);
				Sprite.setScale(1 / resolution, 1 / resolution);
				Sprite.setRotation(0);
				window.draw(Sprite);

				window.display();
			}
			else if (option1 == 2 && no_of_players > option1)
			{
				window.clear();
				for (static bool first = true; first; first = false)
				{
					cout << name_text_box_2.Get_text() << endl;
				}

				player_name_window("Player # 3", Name_input_panel, *continue_button, name_text_box_3);

				Sprite.setTexture(player_3_piece);
				Sprite.setTextureRect(IntRect(0, 0, 600, 600));
				Sprite.setOrigin(-1650, -280);
				Sprite.setScale(1 / resolution, 1 / resolution);
				Sprite.setRotation(0);
				window.draw(Sprite);

				window.display();
			}
			else if (option1 == 3 && no_of_players > option1)
			{
				window.clear();
				for (static bool first = true; first; first = false)
				{
					cout << name_text_box_3.Get_text() << endl;
				}

				player_name_window("Player # 4", Name_input_panel, *continue_button, name_text_box_4);

				Sprite.setTexture(player_4_piece);
				Sprite.setTextureRect(IntRect(0, 0, 600, 600));
				Sprite.setOrigin(-1600, -320);
				Sprite.setScale(1 / resolution, 1 / resolution);
				Sprite.setRotation(0);
				window.draw(Sprite);

				window.display();
			}
			else if (option1 == 4 && no_of_players > option1)
			{
				window.clear();
				for (static bool first = true; first; first = false)
				{
					cout << name_text_box_4.Get_text() << endl;
				
				}

				player_name_window("Player # 5", Name_input_panel, *continue_button, name_text_box_5);

				Sprite.setTexture(player_5_piece);
				Sprite.setTextureRect(IntRect(0, 0, 600, 600));
				Sprite.setOrigin(-1850, -280);
				Sprite.setScale(0.9 / resolution, 0.9 / resolution);
				Sprite.setRotation(0);
				window.draw(Sprite);

				window.display();
			}
			else if (option1 == 5)
			{
				for (static bool first = true; first; first = false)
				{
					if (no_of_players == 3)
					{
						cout << name_text_box_3.Get_text() << endl;
					}
				}

				for (static bool first = true; first; first = false)
				{
					if (no_of_players == 4)
					{
						cout << name_text_box_4.Get_text() << endl;

					}
				}

				for (static bool first = true; first; first = false)
				{
					if (no_of_players == 5)
					{
						cout << name_text_box_5.Get_text() << endl;

					}
				}

				

				window.clear();
				Board_Graphics();
				if(current_card==0)
				{
					community_chest(0);
					chance(0);
				}
			
				for (static bool first = true; first; first = false)
				{
					board.set_no_of_players(no_of_players);
				}

				for (static bool first = true; first; first = false)
				{
					char* name_ptr = nullptr;
					static int x;
					for (x = 1; x <= no_of_players; x++)
					{
						if (name_ptr != nullptr)
						{
							delete[]name_ptr;
						}

						if (x == 1)
						{
							name_ptr = new char[name_text_box_1.Get_text().length() + 1];
							for (int i = 0; name_text_box_1.Get_text()[i] != '\0'; i++)
							{
								name_ptr[i] = name_text_box_1.Get_text()[i];
							}

							name_ptr[name_text_box_1.Get_text().length()] = '\0';

							board.set_player_name(name_ptr, 1 - 1);
						}
						else if (x == 2)
						{
							name_ptr = new char[name_text_box_2.Get_text().length() + 1];
							for (int i = 0; name_text_box_2.Get_text()[i] != '\0'; i++)
							{
								name_ptr[i] = name_text_box_2.Get_text()[i];
							}

							name_ptr[name_text_box_2.Get_text().length()] = '\0';


							board.set_player_name(name_ptr, 2 - 1);
						}
						else if (x == 3)
						{
							name_ptr = new char[name_text_box_3.Get_text().length() + 1];
							for (int i = 0; name_text_box_3.Get_text()[i] != '\0'; i++)
							{
								name_ptr[i] = name_text_box_3.Get_text()[i];
							}

							name_ptr[name_text_box_3.Get_text().length()] = '\0';

							board.set_player_name(name_ptr, 3 - 1);
						}
						else if (x == 4)
						{
							name_ptr = new char[name_text_box_4.Get_text().length() + 1];
							for (int i = 0; name_text_box_4.Get_text()[i] != '\0'; i++)
							{
								name_ptr[i] = name_text_box_4.Get_text()[i];
							}

							name_ptr[name_text_box_4.Get_text().length()] = '\0';

							board.set_player_name(name_ptr, 4 - 1);
						}
						else if (x == 5)
						{
							name_ptr = new char[name_text_box_5.Get_text().length() + 1];
							for (int i = 0; name_text_box_5.Get_text()[i] != '\0'; i++)
							{
								name_ptr[i] = name_text_box_5.Get_text()[i];
							}

							name_ptr[name_text_box_5.Get_text().length()] = '\0';

							board.set_player_name(name_ptr, 5 - 1);
						}
					}
				}

				for (static bool first = true; first; first = false)
				{

					board.calculate_position(0);
					board.calculate_position(1);
					board.calculate_position(2);
					board.calculate_position(3);
					board.calculate_position(4);

					/*board.get_player(1).set_in_jail();
					board.get_player(1).Add_Jail_Pass();*/

				}

				//do
				{
					
					for (static bool first = true; first; first = false)
					{
						current_player = 1;
					}

					if (option_show_properties == 0)
					{
						menu_panel(current_player,0);
						if (board.get_player(current_player - 1).get_in_jail() != 0)
						{
							text.setCharacterSize(70 / resolution);
							text.setFillColor(Color::Blue);
							text.setString("You Are In Jail");
							x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
							text.setPosition(x_axis, 500);
							window.draw(text);

							text.setString("Select an option from");
							x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
							text.setPosition(x_axis, 590);
							window.draw(text);

							text.setString("the menu below");
							x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
							text.setPosition(x_axis, 680);
							window.draw(text);

							remove_button(*dice_button);
							remove_button(*properties_button);
							draw_button(*skip_turn, 3100, 900);
							draw_button(*pay, 3100, 1200);
							if (board.get_player(current_player - 1).Get_no_of_jail_Pass() >= 1)
							{
								draw_button(*use_pass, 3100, 1500);
							}
						}
						else
						{

							remove_button(*skip_turn);
							remove_button(*pay);
							remove_button(*use_pass);
							remove_button(*back_button_1);

							menu_panel_1(*dice_button, *properties_button);
							dice_graphics(dice, current_player);
							move_player(no_of_players);
						}
					}


					if (option_dice == 1 && option_show_properties == 0)
					{
						if (i == 0 && bye_option == 0 && rent_option == 0)
						{
							dice = board.roll_dice();
							dice_graphics(dice, current_player);
							board_block = board.get_address(current_player - 1);
							board_block = (board_block + dice);
							if (board_block > 40)
							{
								board_block = board_block - 40;
							}
							board.set_address(current_player - 1, board_block);
							board.calculate_position(current_player - 1);
							i = 1;
						}
						
						if (board.get_bank()->get_properties()[board_block - 1]->Get_pType() == 1 || board.get_bank()->get_properties()[board_block - 1]->Get_pType() == 2 && i == 1)
						{
							if (board.get_bank()->get_properties()[board_block - 1]->Get_owned_Status() == false)
							{
								//i = 1;
								menu_panel(current_player,0);
								draw_button(*buy_button, 3100, 900);
								draw_button(*pass_button, 3100, 1200);
								dice_graphics(dice, current_player);
								property_information(board_block);

								if (bye_option == 1)
								{
									board.buy_property(current_player - 1, board_block - 1);
									cout << " player : " << current_player << " bought : " << board_block << endl;

									/*	cout << current_player << endl;
										board.get_plyer(current_player - 1).print_properties();*/

									cout << endl;

									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									rent_option = 0;
									option_dice = 0;
									bye_option = 0;
									i = 0;
									remove_button(*buy_button);
								}
								else if (pass_option == 1)
								{
									for (int i = 0; i < no_of_players; i++)
									{
										

										
									}
								}
							}
							else if(board.get_bank()->get_properties()[board_block - 1]->Get_owned_Status() == true)
							{
								//i = 1;
								menu_panel(current_player, 0);
								draw_button(*rent_button, 3100, 800);
								dice_graphics(dice, current_player);

								if (rent_option == 1)
								{
									board.pay_rent(current_player - 1, board_block - 1);
									cout << " player : " << current_player << " paid rent for : " << board_block << endl;

									/*cout << current_player << endl;
									board.get_plyer(current_player - 1).print_properties();*/

									cout << endl;

									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									option_dice = 0;
									rent_option = 0;
									bye_option = 0;
									i = 0;
									remove_button(*rent_button);
								}
							}
						}
						else if(board.get_bank()->get_properties()[board_block - 1]->Get_pType() == 3)
						{
							//i = 1;
							menu_panel(current_player, 0);
							draw_button(*continue_button_2, 3100, 800);
							dice_graphics(dice, current_player);
							if (current_card == 0)
							{
								community_chest(0);
								chance(0);
							}


							if (board.get_bank()->get_properties()[board_block - 1]->Get_NationalProType() == 1)
							{
								text_panel();
								text.setCharacterSize(200 / resolution);
								text.setString("GO");
								text.setFillColor(Color::Blue);
								x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
								text.setPosition(x_axis, 1200);
								window.draw(text);

								if (continue_option == 1)
								{
									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									current_card = 0;
									continue_option = 0;
									option_dice = 0;
									i = 0;
									remove_button(*continue_button_2);
								}

							}
							else if (board.get_bank()->get_properties()[board_block - 1]->Get_NationalProType() == 2)
							{
								text_panel();
								text.setCharacterSize(100 / resolution);
								text.setString("Community Chest");
								text.setFillColor(Color::Blue);
								x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
								text.setPosition(x_axis, 1200 / resolution);
								window.draw(text);

								chance(0);

								if (current_card == 0)
								{
									current_card = board.get_community_chest_card();
								}
								community_chest(current_card);
								if (continue_option == 1)
								{
									board.community_chest_action(current_card, current_player - 1);

									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									current_card = 0;
									continue_option = 0;
									option_dice = 0;
									i = 0;
									remove_button(*continue_button_2);
								}
							}
							else if (board.get_bank()->get_properties()[board_block - 1]->Get_NationalProType() == 3)
							{
								text_panel();
								text.setCharacterSize(150 / resolution);
								text.setString("Chance");
								text.setFillColor(Color::Blue);
								x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
								text.setPosition(x_axis, 1200 / resolution);
								window.draw(text);

								community_chest(0);

								if(current_card==0)
								{
									current_card = board.get_chance_card();
								}
								chance(current_card);
								if (continue_option == 1)
								{
									board.chance_action(current_card, current_player - 1, dice);

									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									current_card = 0;
									continue_option = 0;
									option_dice = 0;
									i = 0;
									remove_button(*continue_button_2);
								}
							}
							else if (board.get_bank()->get_properties()[board_block - 1]->Get_NationalProType()== 4)
							{
								text_panel();
								text.setCharacterSize(100 / resolution);
								text.setString("Go To Jail");
								text.setFillColor(Color::Blue);
								x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
								text.setPosition(x_axis, 1150 / resolution);
								window.draw(text);

								if (continue_option == 1)
								{
									board.get_player(current_player - 1).set_address(12);
									board.get_player(current_player - 1).set_in_jail();
									move_player(no_of_players);

									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									current_card = 0;
									continue_option = 0;
									option_dice = 0;
									i = 0;
									remove_button(*continue_button_2);
								}
							}
							else if (board.get_bank()->get_properties()[board_block - 1]->Get_NationalProType() == 5)
							{
								text_panel();
								text.setCharacterSize(100 / resolution);
								text.setString("Land Tax");
								text.setFillColor(Color::Blue);
								x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
								text.setPosition(x_axis, 1200 / resolution);
								window.draw(text);

								if (continue_option == 1)
								{
									board.get_player(current_player - 1).Reduce_Balance(board.get_player(current_player - 1).get_land_tax());

									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									current_card = 0;
									continue_option = 0;
									option_dice = 0;
									i = 0;
									remove_button(*continue_button_2);
								}
							}
							else if (board.get_bank()->get_properties()[board_block - 1]->Get_NationalProType() == 6)
							{
								text_panel();
								text.setCharacterSize(80 / resolution);
								text.setString("Property Tax");
								text.setFillColor(Color::Blue);
								x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
								text.setPosition(x_axis, 1200 / resolution);
								window.draw(text);

								if (continue_option == 1)
								{
									board.get_player(current_player - 1).Reduce_Balance(board.get_player(current_player - 1).get_property_tax());

									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									current_card = 0;
									continue_option = 0;
									option_dice = 0;
									i = 0;
									remove_button(*continue_button_2);
								}
							}
							else if (board.get_bank()->get_properties()[board_block - 1]->Get_NationalProType() == 7)
							{
								text_panel();
								text.setCharacterSize(100 / resolution);
								text.setString("Parking");
								text.setFillColor(Color::Blue);
								x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
								text.setPosition(x_axis, 1200 / resolution);
								window.draw(text);

								if (continue_option == 1)
								{
									board.get_player(current_player - 1).Reduce_Balance(10);

									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									current_card = 0;
									continue_option = 0;
									option_dice = 0;
									i = 0;
									remove_button(*continue_button_2);
								}
							}
							else if (board.get_bank()->get_properties()[board_block - 1]->Get_NationalProType() == 8)
							{
								text_panel();
								text.setCharacterSize(100);
								text.setString("Visiting Jail");
								text.setFillColor(Color::Blue);
								x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
								text.setPosition(x_axis, 1200 / resolution);
								window.draw(text);

								if (continue_option == 1)
								{
									if (current_player >= no_of_players)
									{
										current_player = 0;
									}
									current_player = current_player + (no_of_players)-(no_of_players - 1);
									current_card = 0;
									continue_option = 0;
									option_dice = 0;
									i = 0;
									remove_button(*continue_button_2);
								}
							}
						}
					}

					
					

					if (option_show_properties == 1)
					{
						if (property_id == 0 && option_show_properties == 1)
						{
							remove_button(*dice_button);
							menu_panel(current_player,1);
							menu_panel_2(all_properties_buttons, current_player, *back_button_1);
						}
						else if (property_id != 0)
						{
							if (sell_option == 0)
							{
								menu_panel(current_player, 0);
								property_information(property_id, *back_button_2);
								if (board.get_bank()->get_properties()[property_id - 1]->Get_Mortgage_Status() == false)
								{
									remove_button(*un_mortgage_property);
									draw_button(*mortgage_property, 3100, 1300);
								}
								else
								{
									remove_button(*mortgage_property);
									draw_button(*un_mortgage_property, 3100, 1300);
								}

								draw_button(*sell_property, 3100, 1600);

								draw_button(*add_house, 3000, 850);
								draw_button(*add_hotel, 3500, 850);
								draw_button(*add_shop, 3250, 1100);
							}
							else if (sell_option == 1)
							{
								if (player_id_to_sell == -1)
								{
									remove_button(*sell_property);
									remove_button(*mortgage_property);
									remove_button(*un_mortgage_property);

									menu_panel(current_player, 0);

									text.setCharacterSize(70 / resolution);
									text.setFillColor(Color::Blue);
									text.setString("Sell property for : ");
									x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
									text.setPosition(x_axis, 400);
									window.draw(text);

									text.setString("Enter price");
									x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
									text.setPosition(x_axis, 490);
									window.draw(text);

									RectangleShape box;
									box.setOrigin(Vector2f(-3150, -600));
									box.setSize(Vector2f(500, 150));
									box.setFillColor(Color::White);
									box.setOutlineColor(Color::Black);
									box.setOutlineThickness(10);
									window.draw(box);

									price.set_font(font);
									price.set_selected(true);
									price.set_limit(5);
									price.set_position(Vector2f(3200, 600));
									price.draw_to(window);


									text.setString("to who you want to sell");
									x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
									text.setPosition(x_axis, 800);
									window.draw(text);

									int j = 0;
									for (int i = 0; i < no_of_players; i++)
									{
										if (i != current_player - 1)
										{
											players[j]->set_string(board.get_player(i).get_name());
											player_array[j] = i;
											j++;
										}
									}

									for (int i = 0; i < no_of_players - 1; i++)
									{
										draw_button(players[i][0], 3100, (1000) + (300 * i));
									}
								}
								else
								{
									remove_button(*sell_property);
									remove_button(*mortgage_property);
									remove_button(*un_mortgage_property);

									menu_panel(current_player, 0);

									cout << "	" << player_id_to_sell << endl;

									text.setCharacterSize(70 / resolution);
									text.setFillColor(Color::Blue);
									text.setString(board.get_player(player_id_to_sell).get_name());
									x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
									text.setPosition(x_axis, 400);
									window.draw(text);

									text.setString("Do you want to buy");
									x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
									text.setPosition(x_axis, 480);
									window.draw(text);

									text.setString(board.get_bank()->get_properties()[property_id - 1]->Get_PName());
									x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
									text.setPosition(x_axis, 560);
									window.draw(text);

									text.setString("for : ");
									x_axis = ((830 / resolution - (text.getGlobalBounds().width + 70 * 5)) / 2) + 2990 / resolution;
									text.setPosition(x_axis, 640);
									window.draw(text);

									text.setString(price.Get_text());
									x_axis = ((830 / resolution - (text.getGlobalBounds().width - 70 * 5)) / 2) + 2990 / resolution;
									text.setPosition(x_axis, 640);
									window.draw(text);

									selling_price = string_to_int(price.Get_text());

									draw_button(*no,3100,800);
									draw_button(*yes, 3400, 800);

								}
							}
						}
					}

					//if (option_show_properties == 0)
					{
						move_player(no_of_players);
					}
					window.display();
				}
				//} while (1);
			}
			
		}
	}

	for (int i = 0; i < 28; i++)
	{
		delete all_properties_buttons[i];
	}
	delete[]all_properties_buttons;

	delete continue_button;
	delete players_3;
	delete players_4;
	delete players_5;
	delete dice_button;
	delete properties_button;
	delete back_button_1;
	delete back_button_2;
	delete buy_button;
	delete rent_button;
	delete continue_button_2;
	delete pass_button;
	delete skip_turn;
	delete pay;
	delete use_pass;
	delete mortgage_property;
	delete sell_property;
	delete yes;
	delete no;
	delete add_house;
	delete add_shop;
	delete add_hotel;
	delete un_mortgage_property;
}

void Board_Graphics()
{
	static Font    font;
	static Texture Arrow;
	static Texture Train;
	static Texture Question_Mark;
	static Texture Monopoly;
	static Texture Jail;
	static Texture GoJail;
	static Texture Parking;
	static Texture Question_Mark_3;
	static Texture Question_Mark_2;
	static Texture Bus;
	static Texture Railway;
	static Texture Orange_Train;
	static Texture communitychest;
	static Texture LESCO;
	static Texture wifi;
	static Texture wasa;
	static Texture sui;
	static Texture I_tax;
	static Texture L_tax;

	for (static bool first = true; first; first = false)
	{
		if (!font.loadFromFile("Fonts/arial.ttf"))
		{
			cout << "	Could Not Load Font" << endl;
		}

		if (!Arrow.loadFromFile("Images/red_arrow.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Train.loadFromFile("Images/Train.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Question_Mark.loadFromFile("Images/Question_Mark.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Monopoly.loadFromFile("Images/Monopoly.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Jail.loadFromFile("Images/Jail.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!GoJail.loadFromFile("Images/GoJail.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Parking.loadFromFile("Images/Parking.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Question_Mark_2.loadFromFile("Images/Question_Mark_2.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Question_Mark_3.loadFromFile("Images/Question_Mark_3.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Bus.loadFromFile("Images/Bus.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Railway.loadFromFile("Images/Railway.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!Orange_Train.loadFromFile("Images/Orange_Train.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!communitychest.loadFromFile("Images/community_chest.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!LESCO.loadFromFile("Images/LESCO.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!wifi.loadFromFile("Images/wifi.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!wasa.loadFromFile("Images/Tap.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!sui.loadFromFile("Images/gas.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!I_tax.loadFromFile("Images/I_tax.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!L_tax.loadFromFile("Images/L_tax.PNG"))
		{
			cout << "	Error" << endl;
		}
	}

	static Sprite sprite;
	static Text text;

	static RectangleShape BoardBase;
	static RectangleShape Blocks;

	static Color Color1(Color(204, 255, 229));

	BoardBase.setOrigin(Vector2f(-10.0 / resolution, -10.0 / resolution));
	BoardBase.setSize(Vector2f(2960.0 / resolution, 2140.0 / resolution));
	BoardBase.setFillColor(Color(204, 255, 229));
	BoardBase.setOutlineColor(Color::Yellow);
	BoardBase.setOutlineThickness(10.0 / resolution);
	window.draw(BoardBase);


	Blocks.setSize(Vector2f(212.7 / resolution, 240.0 / resolution));
	Blocks.setFillColor(Color1);
	Blocks.setOutlineThickness(10.0 / resolution);
	Blocks.setOutlineColor(Color::Black);

	for (int i = 0; i < 11; i++)
	{
		Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (i * (-222.7))) / resolution, -20 / resolution));
		window.draw((Blocks));

		Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (i * (-222.7))) / resolution, -1900 / resolution));
		window.draw((Blocks));
	}

	Blocks.setSize(Vector2f(240.0 / resolution, 222.8 / resolution));

	for (int i = 0; i < 7; i++)
	{
		Blocks.setOrigin(Vector2f(-20.0, (-20.0 + (-250.0) + (i * -232.8))) / resolution);
		window.draw((Blocks));

		Blocks.setOrigin(Vector2f(-2720.0, (-20.0 + (-250.0) + (i * -232.8))) / resolution);
		window.draw((Blocks));
	}

	Blocks.setSize(Vector2f(240 / resolution, 240 / resolution));

	Blocks.setOrigin(Vector2f(-20 / resolution, -20 / resolution));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f(-2720 / resolution, -20 / resolution));
	window.draw((Blocks));
  
	Blocks.setOrigin(Vector2f(-2720 / resolution, -1900 / resolution));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f(-20 / resolution, -1900 / resolution));
	window.draw((Blocks));

	//Headers in lower Blocks

	Blocks.setSize(Vector2f(212.7 / resolution, 70 / resolution));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 0) / resolution, -1900 / resolution));
	Blocks.setFillColor(Color(102, 51, 0));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 2) / resolution, -1900 / resolution));
	Blocks.setFillColor(Color(102, 52, 0));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 5) / resolution, -1900 / resolution));
	Blocks.setFillColor(Color(204, 255, 255));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 7) / resolution, -1900 / resolution));
	Blocks.setFillColor(Color(204, 255, 255));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 8) / resolution, -1900 / resolution));
	Blocks.setFillColor(Color(204, 255, 255));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 9) / resolution, -1900 / resolution));
	Blocks.setFillColor(Color(255, 102, 178));
	window.draw((Blocks));

	//Headers in upper blocks

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 1) / resolution, (-20.0 + -170.0) / resolution));
	Blocks.setFillColor(Color(255, 255, 51));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 2) / resolution, (-20.0 + -170.0) / resolution));
	Blocks.setFillColor(Color(255, 255, 51));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 4) / resolution, (-20.0 + -170.0) / resolution));
	Blocks.setFillColor(Color(255, 255, 51));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 5) / resolution, (-20.0 + -170.0) / resolution));
	Blocks.setFillColor(Color(255, 51, 51));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 7) / resolution, (-20.0 + -170.0) / resolution));
	Blocks.setFillColor(Color(255, 51, 51));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 8) / resolution, (-20.0 + -170.0) / resolution));
	Blocks.setFillColor(Color(255, 51, 51));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + (-250.0) + (-222.7) * 10) / resolution, (-20.0 + -170.0) / resolution));
	Blocks.setFillColor(Color(255, 153, 51));
	window.draw((Blocks));


	//headers in Left Blocks

	Blocks.setSize(Vector2f(70.0 / resolution, 222.8 / resolution));

	Blocks.setOrigin(Vector2f((-20.0 + -170.0) / resolution, (-20.0 + (-250.0) + -232.8 * 1) / resolution));
	Blocks.setFillColor(Color(0, 153, 76));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + -170.0) / resolution, (-20.0 + (-250.0) + -232.8 * 4) / resolution));
	Blocks.setFillColor(Color(0, 153, 76));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f((-20.0 + -170.0) / resolution, (-20.0 + (-250.0) + -232.8 * 6) / resolution));
	Blocks.setFillColor(Color(0, 153, 76));
	window.draw((Blocks));

	////Headers in Right Blocks
	Blocks.setOrigin(Vector2f(-2720.0 / resolution, (-20.0 + (-250.0) + -232.8 * 1) / resolution));
	Blocks.setFillColor(Color(255, 153, 51));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f(-2720.0 / resolution, (-20.0 + (-250.0) + -232.8 * 3) / resolution));
	Blocks.setFillColor(Color(255, 153, 51));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f(-2720.0 / resolution, (-20.0 + (-250.0) + -232.8 * 5) / resolution));
	Blocks.setFillColor(Color(255, 102, 178));
	window.draw((Blocks));

	Blocks.setOrigin(Vector2f(-2720.0 / resolution, (-20.0 + (-250.0) + -232.8 * 6) / resolution));
	Blocks.setFillColor(Color(255, 102, 178));
	window.draw((Blocks));



	//Go Text
	text.setFont(font);
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold);
	text.setRotation(0);

	text.setCharacterSize(100 / resolution);
	text.setPosition(Vector2f(60 / resolution, 1930 / resolution));
	text.setString("GO");
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold);
	window.draw(text);


	//Arrow Image

	sprite.setRotation(0);

	sprite.setTexture(Arrow);
	sprite.setOrigin(Vector2f(-100, -5050));
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	window.draw(sprite);

	//Train Image
	sprite.setTexture(Train);
	sprite.setTextureRect(IntRect(0, 0, 512, 512));
	sprite.setOrigin(-1170 * 2.5, -1910 * 2.5);
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);

	//LESCO Image
	sprite.setTexture(LESCO);
	sprite.setTextureRect(IntRect(0, 0, 500, 500));
	sprite.setOrigin(-2505 * 2.5, -1920 * 2.5);
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);


	//Bus Image
	sprite.setTexture(Bus);
	sprite.setTextureRect(IntRect(0, 0, 483, 517));
	sprite.setOrigin(-2790.0 * 3.3, -1250.0 * 3.3);
	sprite.setScale(0.3 / resolution, 0.3 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);

	//Income Tax Image
	sprite.setTexture(I_tax);
	sprite.setTextureRect(IntRect(0, 0, 512, 512));
	sprite.setOrigin(-955 * 2.5, -1910 * 2.5);
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);

	//wifi Image
	sprite.setTexture(wifi);
	sprite.setTextureRect(IntRect(0, 0, 239, 239));
	sprite.setOrigin(-2750.0 * 1.25, -280.0 * 1.25);
	sprite.setScale(0.8 / resolution, 0.8 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);


	//Railway Image
	sprite.setTexture(Railway);
	sprite.setTextureRect(IntRect(0, 0, 512, 512));
	sprite.setOrigin(-1610.0 * 2.5, -50.0 * 2.5);
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);

	//wasa image
	sprite.setTexture(wasa);
	sprite.setTextureRect(IntRect(0, 0, 216, 231));
	sprite.setOrigin(-940.0, -50.0);
	sprite.setScale(1 / resolution, 1 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);

	//sui image
	sprite.setTexture(sui);
	sprite.setTextureRect(IntRect(0, 0, 512, 512));
	sprite.setOrigin(-270.0 * 2.5, -50.0 * 2.5);
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);


	//Orange Train Image
	sprite.setTexture(Orange_Train);
	sprite.setTextureRect(IntRect(0, 0, 225, 225));
	sprite.setOrigin(-50.0 * 1.25, -760.0 * 1.25);
	sprite.setScale(0.8 / resolution, 0.8 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);


	//Luxury Tax
	sprite.setTexture(L_tax);
	sprite.setTextureRect(IntRect(0, 0, 512, 512));
	sprite.setOrigin(-45.0 * 2.5, -1440 * 2.5);
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	sprite.setRotation(0);
	window.draw(sprite);

	//Question Mark Image
	sprite.setTexture(Question_Mark);
	sprite.setTextureRect(IntRect(0, 0, 365, 375));
	sprite.setOrigin(-3235, -3810);
	sprite.setScale(0.5 / resolution, 0.5 / resolution);
	window.draw(sprite);

	//Chance Text
	text.setCharacterSize(52 / resolution);
	text.setPosition(Vector2f(1620 / resolution, 2080 / resolution));
	text.setString("Chance");
	window.draw(text);

	//Question Mark 2 Image
	sprite.setTexture(Question_Mark_2);
	sprite.setTextureRect(IntRect(0, 0, 365, 375));
	sprite.setOrigin(-796 + (-3770), -140);
	sprite.setScale(0.5 / resolution, 0.5 / resolution);
	window.draw(sprite);

	//chance Text
	text.setCharacterSize(52 / resolution);
	text.setPosition(Vector2f((762 * 3) / resolution, 17 / resolution));
	text.setString("Chance");
	window.draw(text);

	//Question Mark 3 Image
	sprite.setTexture(Question_Mark_3);
	sprite.setTextureRect(IntRect(0, 0, 365, 375));
	sprite.setOrigin(-140, -370 + (-1620));
	sprite.setScale(0.5 / resolution, 0.5 / resolution);
	window.draw(sprite);

	//community chest
	sprite.setTexture(communitychest);
	sprite.setTextureRect(IntRect(0, 0, 482, 516));
	sprite.setOrigin(-500 * 2.5, -1920 * 2.5);
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	window.draw(sprite);

	sprite.setOrigin(-2740 * 2.5, -774 * 2.5);
	window.draw(sprite);

	sprite.setOrigin(-50 * 2.5, -300 * 2.5);
	window.draw(sprite);

	//change Text
	text.setCharacterSize(52 / resolution);
	text.setPosition(Vector2f(51 / resolution + (text.getLocalBounds().height), (800 / resolution + text.getLocalBounds().width)));
	text.setString("Chance");
	text.setRotation(90);
	window.draw(text);

	//Jail Image
	sprite.setTexture(Jail);
	sprite.setTextureRect(IntRect(0, 0, 512, 512));
	sprite.setOrigin(-6850, -4800);
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	window.draw(sprite);

	//Go To Jail Image
	sprite.setTexture(GoJail);
	sprite.setTextureRect(IntRect(0, 0, 502, 457));
	sprite.setOrigin(-100, -60);
	sprite.setScale(0.4 / resolution, 0.4 / resolution);
	window.draw(sprite);

	//Go To Jail Text
	text.setCharacterSize(40 / resolution);
	text.setPosition(Vector2f(40 / resolution, 200 / resolution));
	text.setRotation(0);
	text.setString("Go To Jail");
	text.setFillColor(Color::Black);
	window.draw(text);

	//Parking Image
	sprite.setTexture(Parking);
	sprite.setTextureRect(IntRect(0, 0, 990, 1000));
	sprite.setOrigin(-11000, -40);
	sprite.setScale(0.25 / resolution, 0.25 / resolution);
	window.draw(sprite);

	//Monopoly Image
	sprite.setTexture(Monopoly);
	sprite.setTextureRect(IntRect(0, 0, 2542, 668));
	sprite.setOrigin(-418 * 4, -1672);
	sprite.setScale(0.5 / resolution, 0.5 / resolution);
	window.draw(sprite);
}

string player_name_window(const char* ptr, RectangleShape& Name_input_panel, Button& continue_button, TextBox& Name_text_box)
{
	static Text text;

	Name_input_panel.setOrigin({ (-1920 / 2) / resolution,-10 / resolution });
	Name_input_panel.setSize({ 1900 / resolution,((1080 * 2) - 20) / resolution });
	Name_input_panel.setFillColor(Color::Cyan);
	Name_input_panel.setOutlineColor(Color::Yellow);
	Name_input_panel.setOutlineThickness(10 / resolution);
	window.draw(Name_input_panel);

	Name_input_panel.setOrigin({ -2400 / resolution,-1400 / resolution });
	Name_input_panel.setSize({ -1000 / resolution,-200 / resolution });
	Name_input_panel.setFillColor(Color::White);
	Name_input_panel.setOutlineColor(Color::Black);
	Name_input_panel.setOutlineThickness(10 / resolution);
	window.draw(Name_input_panel);

	text.setFillColor(Color::Blue);
	text.setFont(font);
	text.setString("Enter your name");
	text.setPosition(1500 / resolution, 800 / resolution);
	text.setCharacterSize(100 / resolution);
	text.setStyle(Text::Bold);
	window.draw(text);

	text.setFillColor(Color::Blue);
	text.setFont(font);
	text.setString(ptr);
	text.setPosition(1670 / resolution, 100 / resolution);
	text.setCharacterSize(100 / resolution);
	text.setStyle(Text::Bold);
	window.draw(text);


	Name_text_box.set_font(font);
	Name_text_box.set_position(Vector2f(1570 / resolution, 1200 / resolution));
	Name_text_box.draw_to(window);

	continue_button.set_font(font);
	continue_button.set_position({ 1600 / resolution,1600 / resolution });
	continue_button.set_char_size(80 / resolution);
	continue_button.draw_to(window);

	return Name_text_box.Get_text();
}

void no_of_player_window(RectangleShape& No_of_player_input_panel, Text& text, Button& players_3, Button& players_4, Button& players_5)
{

	No_of_player_input_panel.setOrigin({ (-1920 / 2) / resolution,-10 / resolution });
	No_of_player_input_panel.setSize({ 1900 / resolution,(1080 * 2) - 20 / resolution });
	No_of_player_input_panel.setFillColor(Color::Cyan);
	No_of_player_input_panel.setOutlineColor(Color::Yellow);
	No_of_player_input_panel.setOutlineThickness(10 / resolution);

	players_3.set_char_size(100 / resolution);
	players_4.set_char_size(100 / resolution);
	players_5.set_char_size(100 / resolution);

	players_3.set_position({ 1200 / resolution,1500 / resolution });
	players_4.set_position({ 1750 / resolution,1500 / resolution });
	players_5.set_position({ 2300 / resolution,1500 / resolution });

	players_3.set_font(font);
	players_4.set_font(font);
	players_5.set_font(font);

	players_3.set_text_position({ 1320 / resolution, 1600 / resolution });
	players_4.set_text_position({ 1870 / resolution, 1600 / resolution });
	players_5.set_text_position({ 2420 / resolution, 1600 / resolution });

	players_3.set_outline_color(Color::Yellow);
	players_3.set_outline_thickness(10 / resolution);

	players_4.set_outline_color(Color::Yellow);
	players_4.set_outline_thickness(10 / resolution);

	players_5.set_outline_color(Color::Yellow);
	players_5.set_outline_thickness(10 / resolution);

	window.draw(No_of_player_input_panel);

	players_3.draw_to(window);
	players_4.draw_to(window);
	players_5.draw_to(window);

	text.setFont(font);
	text.setFillColor(Color::Blue);
	text.setOrigin({ 0,0 });
	text.setCharacterSize(120 / resolution);
	text.setStyle(Text::Underlined);
	text.setStyle(Text::Bold);


	text.setPosition(1350 / resolution, 800 / resolution);
	text.setString("Select No of Players");
	window.draw(text);

	text.setPosition(1300 / resolution, 400 / resolution);
	text.setString("Welcome To Monopoly!");
	window.draw(text);
}

void menu_panel(int player_id,int option)
{
	static RectangleShape right_panel;
	right_panel.setOrigin(-2980 / resolution, -10 / resolution);
	right_panel.setSize(Vector2f(850 / resolution, 2140 / resolution));
	right_panel.setFillColor(Color(204, 255, 229));
	right_panel.setOutlineColor(Color::Yellow);
	right_panel.setOutlineThickness(10.0 / resolution);
	window.draw(right_panel);

	static RectangleShape Headers;
	Headers.setSize(Vector2f(830 / resolution, 100 / resolution));
	Headers.setFillColor(Color::Red);
	Headers.setOutlineColor(Color::Black);
	Headers.setOutlineThickness(10 / resolution);

	Headers.setOrigin(-2990 / resolution, -20 / resolution);
	window.draw(Headers);

	

	static Text text;
	text.setCharacterSize(80 / resolution);
	text.setFillColor(Color::Blue);
	text.setFont(font);

	text.setPosition(3150 / resolution, 20 / resolution);
	text.setString(board.get_player_name(player_id - 1));
	window.draw(text);

	static Text text2;
	text2.setCharacterSize(80 / resolution);
	text2.setFillColor(Color::Blue);
	text2.setFont(font);

	text2.setPosition(text.getLocalBounds().width + 3150 / resolution, 20 / resolution);
	text2.setString(" 's turn");
	window.draw(text2);

	if (option == 0)
	{
		Headers.setOrigin(-2990 / resolution, -120 / resolution);
		window.draw(Headers);

		text.setPosition(3100 / resolution, 120 / resolution);
		text.setString("Balance : ");
		window.draw(text);

		text2.setPosition(3450 / resolution, 120 / resolution);
		text2.setString(int_to_char(board.get_player(player_id - 1).Get_Balance()));
		window.draw(text2);
	}

}

void menu_panel_1(Button& dice_button,Button& properties_button)
{

	dice_button.set_position({ 2990 / resolution,2040 / resolution });
	dice_button.set_char_size(80 / resolution);
	dice_button.set_outline_color(Color::Black);
	dice_button.set_outline_thickness(10.0 / resolution);
	dice_button.set_font(font);
	dice_button.set_text_position({ 3250 / resolution,2040 / resolution });
	dice_button.draw_to(window);

	
	properties_button.set_position({ 3100 / resolution,500 / resolution });
	properties_button.set_char_size(80 / resolution);
	properties_button.set_outline_color(Color::Black);
	properties_button.set_outline_thickness(10.0 / resolution);
	properties_button.set_font(font);
	properties_button.draw_to(window);


}

void dice_graphics(int number_on_dice, int player_id)
{
	static RectangleShape Headers;
	Headers.setOrigin(-3030 / resolution, -1600 / resolution);
	Headers.setSize(Vector2f(400 / resolution, 400 / resolution));
	Headers.setFillColor(Color::Black);
	window.draw(Headers);


	static RectangleShape dice_base;
	dice_base.setOrigin({ -3080 / resolution,-1650 / resolution });
	dice_base.setSize({ 300 / resolution,300 / resolution });
	dice_base.setFillColor(Color::White);
	window.draw(dice_base);

	dice_base.setOrigin({ -3500 / resolution,-1600 / resolution });
	dice_base.setSize({ 300 / resolution,400 / resolution });
	dice_base.setFillColor(Color::Black);
	window.draw(dice_base);

	static Text text;
	text.setFillColor(Color::White);
	text.setCharacterSize(200 / resolution);
	text.setFont(font);

	text.setString(int_to_char(board.get_address(player_id - 1)));
	float x_axis = (((300 / resolution) - text.getLocalBounds().width) / 2 )+ (3470 / resolution);
	float y_axis = (((400 / resolution) - text.getLocalBounds().height) / 2 )+ (1570 / resolution);

	text.setPosition(x_axis, y_axis);
	window.draw(text);

	static CircleShape dots;
	dots.setFillColor(Color(204, 0, 0));
	dots.setRadius(40 / resolution);

	if (number_on_dice == 1)
	{
		dots.setRadius(50 / resolution);
		dots.setPosition({ 3180 / resolution,1750 / resolution });
		window.draw(dots);

	}
	else if (number_on_dice == 2)
	{
		dots.setPosition({ 3140 / resolution,1750 / resolution });
		window.draw(dots);

		dots.setPosition({ 3250 / resolution,1750 / resolution });
		window.draw(dots);
	}
	else if (number_on_dice == 3)
	{
		dots.setPosition({ 3290 / resolution,1670 / resolution });
		window.draw(dots);

		dots.setPosition({ 3190 / resolution,1760 / resolution });
		window.draw(dots);

		dots.setPosition({ 3090 / resolution,1860 / resolution });
		window.draw(dots);
	}
	else if (number_on_dice == 4)
	{
		dots.setPosition({ 3140 / resolution,1700 / resolution });
		window.draw(dots);

		dots.setPosition({ 3250 / resolution,1700 / resolution });
		window.draw(dots);

		dots.setPosition({ 3140 / resolution,1810 / resolution });
		window.draw(dots);

		dots.setPosition({ 3250 / resolution,1810 / resolution });
		window.draw(dots);
	}
	else if (number_on_dice == 5)
	{
		dots.setPosition({ 3290 / resolution,1670 / resolution });
		window.draw(dots);

		dots.setPosition({ 3190 / resolution,1760 / resolution });
		window.draw(dots);

		dots.setPosition({ 3090 / resolution,1860 / resolution });
		window.draw(dots);

		dots.setPosition({ 3090 / resolution,1670 / resolution });
		window.draw(dots);

		dots.setPosition({ 3290 / resolution,1860 / resolution });
		window.draw(dots);
	}
	else if (number_on_dice == 6)
	{
		dots.setPosition({ 3090 / resolution,1700 / resolution });
		window.draw(dots);

		dots.setPosition({ 3190 / resolution,1700 / resolution });
		window.draw(dots);

		dots.setPosition({ 3290 / resolution,1700 / resolution });
		window.draw(dots);

		dots.setPosition({ 3090 / resolution,1810 / resolution });
		window.draw(dots);

		dots.setPosition({ 3190 / resolution,1810 / resolution });
		window.draw(dots);

		dots.setPosition({ 3290 / resolution,1810 / resolution });
		window.draw(dots);
	}
}

void move_player(int no_of_players)
{
	static Texture player_1_piece;
	static Texture player_2_piece;
	static Texture player_3_piece;
	static Texture player_4_piece;
	static Texture player_5_piece;

	for (static bool first = true; first; first = false)
	{
		if (!player_1_piece.loadFromFile("Images/player_1.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!player_2_piece.loadFromFile("Images/player_2.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!player_3_piece.loadFromFile("Images/player_3.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!player_4_piece.loadFromFile("Images/player_4.PNG"))
		{
			cout << "	Error" << endl;
		}

		if (!player_5_piece.loadFromFile("Images/player_5.PNG"))
		{
			cout << "	Error" << endl;
		}
	}

	static sf::Sprite Sprite;
	static int block_address;

	for (int i = 0; i < no_of_players; i++)
	{
		block_address = board.get_address(i);

		if (i == 0)
		{
			Sprite.setTexture(player_1_piece);
		}
		else if (i == 1)
		{
			Sprite.setTexture(player_2_piece);

		}
		else if (i == 2)
		{
			Sprite.setTexture(player_3_piece);

		}
		else if (i == 3)
		{
			Sprite.setTexture(player_4_piece);
		}
		else if (i == 4)
		{
			Sprite.setTexture(player_5_piece);
		}

		if (block_address==1||block_address==13||block_address==21||block_address==33)
		{
			Sprite.setRotation(0);
		}
		else if (block_address >= 2 && block_address <= 12)
		{
			Sprite.setRotation(0);
		}
		else if (block_address >= 14 && block_address <= 20)
		{
			Sprite.setRotation(270);
		}
		else if (block_address >= 22 && block_address <= 32)
		{
			Sprite.setRotation(180);
		}
		else if (block_address >= 34 && block_address <= 40)
		{
			Sprite.setRotation(90);
		}

		Sprite.setTextureRect(IntRect(0, 0, 600, 600));
		Sprite.setOrigin(+0, +0);
		Sprite.setPosition(board.get_position_x(i) / resolution, board.get_position_y(i) / resolution);
		Sprite.setScale(0.2 / resolution, 0.2 / resolution);
		window.draw(Sprite);
	}
	
}

void menu_panel_2(Button** all_properties_buttons, int current_player, Button& back_button)
{

	back_button.set_position({ 2990 / resolution,2040 / resolution });
	back_button.set_char_size(80 / resolution);
	back_button.set_outline_color(Color::Black);
	back_button.set_outline_thickness(10.0 / resolution);
	back_button.set_font(font);
	back_button.set_text_position(-40 / resolution, -30 / resolution);
	back_button.draw_to(window);

	int property_id = 0;
	int button_id = -1;
	float x_position = 0;


	for (int x = 0; x < board.get_player(current_player - 1).get_no_of_properties(); x++)
	{
		property_id = board.get_player(current_player - 1).get_property(x)->Get_BID();

		if (property_id == 2)
		{
			button_id = 0;
		}
		else if (property_id == 4)
		{
			button_id = 1;
		}
		else if (property_id == 7)
		{
			button_id = 2;
		}
		else if (property_id == 9)
		{
			button_id = 3;
		}
		else if (property_id == 10)
		{
			button_id = 4;
		}
		else if (property_id == 11)
		{
			button_id = 5;
		}
		else if (property_id == 14)
		{
			button_id = 6;
		}
		else if (property_id == 15)
		{
			button_id = 7;
		}
		else if (property_id == 17)
		{
			button_id = 8;
		}
		else if (property_id == 19)
		{
			button_id = 9;
		}
		else if (property_id == 22)
		{
			button_id = 10;
		}
		else if (property_id == 24)
		{
			button_id = 11;
		}
		else if (property_id == 25)
		{
			button_id = 12;
		}
		else if (property_id == 27)
		{
			button_id = 13;
		}
		else if (property_id == 28)
		{
			button_id = 14;
		}
		else if (property_id == 15)
		{
			button_id = 15;
		}
		else if (property_id == 31)
		{
			button_id = 16;
		}
		else if (property_id == 35)
		{
			button_id = 17;
		}
		else if (property_id == 38)
		{
			button_id = 18;
		}
		else if (property_id == 40)
		{
			button_id = 19;
		}
		else if (property_id == 6)
		{
			button_id = 20;
		}
		else if (property_id== 16)
		{
			button_id = 21;
		}
		else if (property_id == 26)
		{
			button_id = 22;
		}
		else if (property_id == 36)
		{
			button_id = 23;
		}
		else if (property_id == 12)
		{
			button_id = 24;
		}
		else if (property_id == 20)
		{
			button_id = 25;
		}
		else if (property_id == 29)
		{
			button_id = 26;
		}
		else if (property_id == 32)
		{
			button_id = 27;
		}

		if (button_id != -1)
		{
			if (button_id == 0 || button_id == 1)
			{
				all_properties_buttons[button_id]->set_button_color(Color(102, 51, 0));
			}
			else if (button_id == 2 || button_id == 3 || button_id == 4)
			{
				all_properties_buttons[button_id]->set_button_color(Color(204, 255, 255));
			}
			else if (button_id == 5 || button_id == 6 || button_id == 7)
			{
				all_properties_buttons[button_id]->set_button_color(Color(255, 102, 178));
			}
			else if (button_id == 8 || button_id == 9 || button_id == 10)
			{
				all_properties_buttons[button_id]->set_button_color(Color(255, 153, 51));
			}
			else if (button_id == 11 || button_id == 12 || button_id == 13)
			{
				all_properties_buttons[button_id]->set_button_color(Color(255, 51, 51));
			}
			else if (button_id == 14 || button_id == 15 || button_id == 16)
			{
				all_properties_buttons[button_id]->set_button_color(Color(255, 255, 51));
			}
			else if (button_id == 17 || button_id == 18 || button_id == 19)
			{
				all_properties_buttons[button_id]->set_button_color(Color(0, 153, 76));
			}
			else
			{
				all_properties_buttons[button_id]->set_button_color(Color::Black);
				all_properties_buttons[button_id]->set_text_color(Color::White);
			}

			x_position = 150 / resolution + (130 / resolution * (button_id / 2));
			if (button_id % 2 == 0)
			{
				all_properties_buttons[button_id]->set_position({ 3050 / resolution,x_position });
			}
			else
			{
				all_properties_buttons[button_id]->set_position({ 3450 / resolution,x_position });
			}

			all_properties_buttons[button_id]->set_string(board.get_player(current_player - 1).get_property(x)->Get_Group_Name());
			all_properties_buttons[button_id]->set_text_position(-20 / resolution, -20 / resolution);
			all_properties_buttons[button_id]->set_char_size(60 / resolution);
			all_properties_buttons[button_id]->set_outline_color(Color::Black);
			all_properties_buttons[button_id]->set_outline_thickness(10.0 / resolution);
			all_properties_buttons[button_id]->set_font(font);
			all_properties_buttons[button_id]->draw_to(window);
		}
	}
}

void property_information(int property_id, Button& back_button)
{
	int temp;

	Text text_1;
	text_1.setFont(font);
	text_1.setCharacterSize(60 / resolution);
	text_1.setFillColor(Color::Red);

	text_1.setString("Name : ");
	text_1.setPosition({ 3000 / resolution,300 / resolution });
	window.draw(text_1);


	text_1.setString(board.get_bank()->get_properties()[property_id - 1]->Get_PName());
	text_1.setPosition({ 3200 / resolution,300 / resolution });
	window.draw(text_1);

	text_1.setString("Rent : ");
	text_1.setPosition({ 3000 / resolution,400 / resolution });
	window.draw(text_1);

	text_1.setString(int_to_char(board.get_bank()->get_properties()[property_id - 1]->Get_Rent()));
	text_1.setPosition({ 3200 / resolution,400 / resolution });
	window.draw(text_1);

	text_1.setString("Cost : ");
	text_1.setPosition({ 3000 / resolution,500 / resolution });
	window.draw(text_1);

	text_1.setString(int_to_char(board.get_bank()->get_properties()[property_id - 1]->Get_price()));
	text_1.setPosition({ 3200 / resolution,500 / resolution });
	window.draw(text_1);

	if (board.get_bank()->get_properties()[property_id - 1]->Get_owned_Status() == true)
	{
		text_1.setString("Sold : Yes");

	}
	else
	{
		text_1.setString("Sold : No");
	}
	text_1.setPosition({ 3000 / resolution,600 / resolution });
	window.draw(text_1);

	if (board.get_bank()->get_properties()[property_id - 1]->Get_Mortgage_Status() == true)
	{
		text_1.setString("Mortgage : Yes");
	}
	else
	{
		text_1.setString("Mortgage : No");
	}
	text_1.setPosition({ 3000 / resolution,700 / resolution });
	window.draw(text_1);

	back_button.set_position({ 3220 / resolution,1930 / resolution });
	back_button.set_char_size(80 / resolution);
	back_button.set_outline_color(Color::Black);
	back_button.set_outline_thickness(10.0 / resolution);
	back_button.set_font(font);
	back_button.set_text_position(-20 / resolution, -30 / resolution);
	back_button.draw_to(window);
}

char* int_to_char(int value)
{
	int size=0;

	int v = value;
	while (v != 0)
	{
		size++;
		v = v / 10;
	}

	char* string_out = new char[size + 1];
	int last_digit = 0;

	for (int i=size-1;i>=0;i--)
	{
		last_digit = value % 10;

		if (last_digit == 0)
		{
			string_out[i] = '0';
		}
		else if (last_digit == 1)
		{
			string_out[i] = '1';
		}
		else if (last_digit == 2)
		{
			string_out[i] = '2';
		}
		else if (last_digit == 3)
		{
			string_out[i] = '3';
		}
		else if (last_digit == 4)
		{
			string_out[i] = '4';
		}
		else if (last_digit == 5)
		{
			string_out[i] = '5';
		}
		else if (last_digit == 6)
		{
			string_out[i] = '6';
		}
		else if (last_digit == 7)
		{
			string_out[i] = '7';
		}
		else if (last_digit == 8)
		{
			string_out[i] = '8';
		}
		else if (last_digit == 9)
		{
			string_out[i] = '9';
		}

		value = value / 10;
	}

	string_out[size] = '\0';

	return string_out;
}

void chance(int card_number)
{
	RectangleShape Blocks;
	Blocks.setSize(Vector2f(700 / resolution, 350 / resolution));
	Blocks.setOrigin(-1850 / resolution, -1350 / resolution);
	Blocks.setFillColor(Color(255, 128, 0));
	Blocks.setOutlineColor(Color::Black);
	Blocks.setOutlineThickness(10.0 / resolution);
	window.draw(Blocks);

	Texture chance;
	sf::Sprite chance_image;

	if (card_number == 0)
	{
		if (!chance.loadFromFile("Images/Chance.PNG"))
		{
			cout << "	Error" << endl;
		}

		chance_image.setTexture(chance);
		chance_image.setTextureRect(IntRect(0, 0, 365, 375));
		chance_image.setScale(0.8 / resolution, 0.8 / resolution);
		chance_image.setPosition(((700 / resolution - chance_image.getGlobalBounds().width) / 2) + 1850 / resolution, ((350 / resolution - chance_image.getGlobalBounds().height) / 2) + 1350 / resolution);
		window.draw(chance_image);
	}

	Text text_on_card;

	text_on_card.setFillColor(Color::Black);
	text_on_card.setCharacterSize(60 / resolution);
	text_on_card.setStyle(Text::Bold);
	text_on_card.setFont(font);

	float x_axis;


	if (card_number == 1)
	{
		text_on_card.setString("Advance to Go");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("and Collect 300 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 2)
	{
		text_on_card.setString("Advance to");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("DHA Phase 1");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 3)
	{
		text_on_card.setCharacterSize(50 / resolution);
		text_on_card.setString("Advance token to nearest");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1370 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("utility.If unowned buy from");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1440 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("Bank.If owned,pay to owner");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1510 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("5x the amount shown on dice.");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1580 / resolution));
		window.draw(text_on_card);

		text_on_card.setCharacterSize(60 / resolution);
	}
	else if (card_number == 4)
	{
		text_on_card.setCharacterSize(50 / resolution);
		text_on_card.setString("Advance token to nearest");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1370 / resolution));
		window.draw(text_on_card);

		text_on_card.setString(" Station. If unowned buy from");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1440 / resolution));
		window.draw(text_on_card);

		text_on_card.setString(" Bank. If owned, pay to");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1510 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("owner the double amount.");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1580 / resolution));
		window.draw(text_on_card);

		text_on_card.setCharacterSize(60 / resolution);
	}
	else if (card_number == 5)
	{
		text_on_card.setCharacterSize(50 / resolution);
		text_on_card.setString("Advance token to nearest");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1370 / resolution));
		window.draw(text_on_card);

		text_on_card.setString(" Station. If unowned buy from");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1440 / resolution));
		window.draw(text_on_card);

		text_on_card.setString(" Bank. If owned, pay to");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1510 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("owner the double amount.");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1580 / resolution));
		window.draw(text_on_card);

		text_on_card.setCharacterSize(60 / resolution);
	}
	else if (card_number == 6)
	{
		text_on_card.setString("Advance to Model");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString(" Town 1.If you pass");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);

		text_on_card.setString(" Go collect 300 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1560 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 7)
	{
		text_on_card.setString("Bank pay you");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("100 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 8)
	{
		text_on_card.setString("Get out of Jail.May");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("be kept until needed ");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("or sold for 500 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1560 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 9)
	{
		text_on_card.setString("Go back 4 blocks");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 10)
	{
		text_on_card.setString("Make repair on your");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1370 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("property. For each");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1440 / resolution));
		window.draw(text_on_card);

		text_on_card.setString(" house pay 50 PKR For");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1510 / resolution));
		window.draw(text_on_card);

		text_on_card.setString(" each hotel pay 100 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1580 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 11)
	{
		text_on_card.setString("Pay small Tax");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("of 25 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 12)
	{
		text_on_card.setString("You have been elected");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("as chairperson. Pay");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("25 PKR to each player.");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1560 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 13)
	{
		text_on_card.setString("Collect 150 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("from the Bank.");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 14)
	{
		text_on_card.setString("Advance to Airport");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("and not");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);

		text_on_card.setString(" pay any Tax there.");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1560 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 15)
	{
		text_on_card.setString("Advance token");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1420 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("to Metro Station.");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 1850 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 1490 / resolution));
		window.draw(text_on_card);
	}
}

void community_chest(int card_number)
{
	RectangleShape Blocks;
	Blocks.setSize(Vector2f(700 / resolution, 350 / resolution));
	Blocks.setOrigin(-450 / resolution, -450 / resolution);
	Blocks.setFillColor(Color(102, 178, 255));
	Blocks.setOutlineColor(Color::Black);
	Blocks.setOutlineThickness(10 / resolution);
	window.draw(Blocks);

	static Texture community_chest;
	sf::Sprite community_chest_image;
	if (card_number == 0)
	{
		for (static bool first = true; first; first = false)
		{
			if (!community_chest.loadFromFile("Images/community_chest.PNG"))
			{
				cout << "	Error" << endl;
			}
		}

		community_chest_image.setTexture(community_chest);
		community_chest_image.setTextureRect(IntRect(0, 0, 482, 516));
		community_chest_image.setScale(0.8 / resolution, 0.8 / resolution);
		community_chest_image.setPosition(((700 / resolution - community_chest_image.getGlobalBounds().width) / 2) + 450 / resolution, ((350 / resolution - community_chest_image.getGlobalBounds().height) / 2) + 450 / resolution);
		window.draw(community_chest_image);
	}

	Text text_on_card;

	text_on_card.setFillColor(Color::Black);
	text_on_card.setCharacterSize(60 / resolution);
	text_on_card.setStyle(Text::Bold);
	text_on_card.setFont(font);

	float x_axis;

	if (card_number == 1)
	{
		text_on_card.setString("Advance To Go And");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("And Collect 400 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 2)
	{
		text_on_card.setString("Collect 200 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("From Bank");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 3)
	{
		text_on_card.setString("Pay Doctor's Fee");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2 / resolution) + 450;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("200 PKR ");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 4)
	{
		text_on_card.setString("Collect 50 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("From Sale");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 5)
	{
		text_on_card.setString("Get Out Of Jail");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 580 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 6)
	{
		text_on_card.setString("Income Tax refund");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("Collect 150 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 7)
	{
		text_on_card.setString("Your health insurance");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("matures collect 200 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 8)
	{
		text_on_card.setString("Pay donation to");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("Hospital 100 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
	}
	else if (card_number == 9)
		{
		text_on_card.setString("Pay Student tax");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("of 200 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
		}
	else if (card_number == 10)
		{
		text_on_card.setString("Collect 50 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("for your services");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
		}
	else if (card_number == 11)
		{
		text_on_card.setString("Pay Street repair charges");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis - 2, 500 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("50 PKR per House");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 570 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("125 PKR per Hotel");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 640 / resolution));
		window.draw(text_on_card);
		}
	else if (card_number == 12)
		{
		text_on_card.setString("You won prize");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("money of 300 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
		}
	else if (card_number == 13)
		{
		text_on_card.setString("Pay internet");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("bill 50 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
		}
	else if (card_number == 14)
		{
		text_on_card.setString("Pay electricity");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("bill of 80 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
		}
	else if (card_number == 15)
	{
		text_on_card.setString("Pay water");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 520 / resolution));
		window.draw(text_on_card);

		text_on_card.setString("bill of 50 PKR");
		x_axis = ((700 / resolution - text_on_card.getGlobalBounds().width) / 2) + 450 / resolution;

		text_on_card.setPosition(Vector2f(x_axis, 590 / resolution));
		window.draw(text_on_card);
	}
}

void text_panel()
{
	RectangleShape blocks;
	blocks.setPosition(Vector2f(2990 / resolution, 1100 / resolution));
	blocks.setSize(Vector2f(830 / resolution, 400 / resolution));
	blocks.setFillColor(Color::Red);
	blocks.setOutlineColor(Color::Black);
	blocks.setOutlineThickness(10.0 / resolution);
	window.draw(blocks);
}

void draw_button(Button& button, float x_position, float y_position)
{
	button.set_position({ x_position / resolution,y_position / resolution });
	button.set_char_size(80 / resolution);
	button.set_outline_color(Color::Black);
	button.set_outline_thickness(10.0 / resolution);
	button.set_font(font);
	button.draw_to(window);
}

void remove_button(Button& button)
{
	button.set_position({ 0,0 });
}

void property_information(int block_id)
{
	float x_axis = 0;

	Text text;
	text.setFont(font);
	text.setCharacterSize(80 / resolution);
	text.setFillColor(Color::Blue);
	text.setString(board.get_bank()->get_properties()[block_id - 1]->Get_PName());
	x_axis = ((830 / resolution - text.getGlobalBounds().width) / 2) + 2990 / resolution;
	text.setPosition(x_axis, 400 / resolution);
	window.draw(text);

	text.setString("Rent : ");
	text.setPosition({ 3200 / resolution,500 / resolution });
	window.draw(text);

	text.setString(int_to_char(board.get_bank()->get_properties()[block_id - 1]->Get_Rent()));
	text.setPosition({ 3450 / resolution,500 / resolution });
	window.draw(text);

	text.setString("Cost : ");
	text.setPosition({ 3200 / resolution,600 / resolution });
	window.draw(text);

	text.setString(int_to_char(board.get_bank()->get_properties()[block_id - 1]->Get_price()));
	text.setPosition({ 3450 / resolution,600 / resolution });
	window.draw(text);
}

int string_to_int(const string& price)
{
	int number = 0;

	for (int i = 0; price[i] != '\0'; i++)
	{
		if (price[i] == '0')
		{
			number = number + 0;
		}
		else if (price[i] == '1')
		{
			number = number + 1;
		}
		else if (price[i] == '2')
		{
			number = number + 2;
		}
		else if (price[i] == '3')
		{
			number = number + 3;
		}
		else if (price[i] == '4')
		{
			number = number + 4;
		}
		else if (price[i] == '5')
		{
			number = number + 5;
		}
		else if (price[i] == '6')
		{
			number = number + 6;
		}
		else if (price[i] == '7')
		{
			number = number + 7;
		}
		else if (price[i] == '8')
		{
			number = number + 8;
		}
		else if (price[i] == '9')
		{
			number = number + 9;
		}

		number = number * 10;
	}
	number = number / 10;

	return number;
}

void draw_button(Button& button, float x_position, float y_position, int char_size)
{
	button.set_position({ x_position / resolution,y_position / resolution });
	button.set_char_size(80 / resolution);
	button.set_outline_color(Color::Black);
	button.set_outline_thickness(10.0 / resolution);
	button.set_font(font);
	button.draw_to(window);
}