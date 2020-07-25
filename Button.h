#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
class Button
{
private:
	sf::RectangleShape pr_button;
	sf::Text pr_text_in_button;

public:

	Button();
	Button(std::string TextOnButton, sf::Vector2f size, sf::Color b_color, sf::Color t_color);

	void set_string(std::string TextOnButton);
	void set_size(sf::Vector2f);
	void set_font(sf::Font& font);
	void set_char_size(int size);
	void set_text_position(float ,float);

	void set_button_color(sf::Color color);
	void set_text_color(sf::Color color);

	void set_position(sf::Vector2f position);
	void draw_to(sf::RenderWindow& window);

	bool is_mouse_over(sf::RenderWindow& window);

	void set_text_position(sf::Vector2f position);
	void set_outline_color(sf::Color color);
	void set_outline_thickness(int t);

	~Button();
};

