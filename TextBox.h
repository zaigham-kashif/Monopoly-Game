#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <sstream>
#include <string>

#define DELETE_KEY 8
#define ESC_KEY 27
#define ENTER_KEY 13 


class TextBox
{
private:
	sf::Text pr_textbox;
	std::ostringstream pr_text;
	bool pr_is_box_selected;
	int pr_limit;

	void Input(int inputchar);
	void delete_last_char();

public:
	TextBox();
	TextBox(int size, sf::Color color, bool is_selected);

	void set_font(sf::Font& textbox_font);
	void set_position(sf::Vector2f position);
	void set_limit(int limit);
	void set_selected(bool selected);
	void draw_to(sf::RenderWindow& window);
	void Typed(sf::Event Input);
	void clear_text_box();

	std::string Get_text();
};

