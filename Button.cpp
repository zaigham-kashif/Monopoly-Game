#include "Button.h"

Button::Button()
{
	pr_text_in_button.setString("");
	pr_button.setFillColor(sf::Color::Black);
}

Button::Button(std::string TextOnButton, sf::Vector2f size, sf::Color b_color, sf::Color t_color)
{
	pr_text_in_button.setString(TextOnButton);
	pr_text_in_button.setFillColor(t_color);


	pr_button.setSize(size);
	pr_button.setFillColor(b_color);
}

void Button::set_string(std::string TextOnButton)
{
	pr_text_in_button.setString(TextOnButton);
}

void Button::set_size(sf::Vector2f position)
{
	pr_button.setPosition(position);
}

void Button::set_font(sf::Font& font)
{
	pr_text_in_button.setFont(font);
}

void Button::set_char_size(int size)
{
	pr_text_in_button.setCharacterSize(size);
}

void Button::set_text_position(float x, float y)
{
	float xPos = (pr_button.getPosition().x + pr_button.getGlobalBounds().width / 2) - (pr_text_in_button.getGlobalBounds().width / 2) + (x);
	float yPos = (pr_button.getPosition().y + pr_button.getGlobalBounds().height / 2) - (pr_text_in_button.getGlobalBounds().height / 2) + (y);
	pr_text_in_button.setPosition({ xPos, yPos });
}

void Button::set_button_color(sf::Color color)
{
	pr_button.setFillColor(color);
}

void Button::set_text_color(sf::Color color)
{
	pr_text_in_button.setFillColor(color);
}

void Button::set_position(sf::Vector2f position)
{
	pr_button.setPosition(position);

	float xPos = (position.x + pr_button.getGlobalBounds().width / 2) - (pr_text_in_button.getGlobalBounds().width / 2);
	float yPos = (position.y + pr_button.getGlobalBounds().height / 2) - (pr_text_in_button.getGlobalBounds().height / 2);
	pr_text_in_button.setPosition({xPos, yPos});
}

void Button::draw_to(sf::RenderWindow& window)
{
	window.draw(pr_button);
	window.draw(pr_text_in_button);
}

bool Button::is_mouse_over(sf::RenderWindow& window)
{
	float MouseX = sf::Mouse::getPosition(window).x;
	float MouseY = sf::Mouse::getPosition(window).y;

	float ButtonX = pr_button.getPosition().x;
	float ButtonY = pr_button.getPosition().y;

	float ButtonWidth = pr_button.getPosition().x + pr_button.getLocalBounds().width;
	float ButtonHeight = pr_button.getPosition().y + pr_button.getLocalBounds().height;

	if (MouseX<ButtonWidth && MouseX>ButtonX && MouseY<ButtonHeight && MouseY>ButtonY)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Button::set_text_position(sf::Vector2f position)
{
	pr_text_in_button.setPosition(position);
}

void Button::set_outline_color(sf::Color color)
{
	pr_button.setOutlineColor(color);
}

void Button::set_outline_thickness(int t)
{
	pr_button.setOutlineThickness(t);
}

Button::~Button()
{
	delete& pr_button;
	delete& pr_text_in_button;
}

