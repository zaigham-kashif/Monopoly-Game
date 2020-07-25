#include "TextBox.h"
#include <iostream>
#include <string>

void TextBox::Input(int inputchar)
{
	if (inputchar != DELETE_KEY && inputchar != ESC_KEY && inputchar != ENTER_KEY)
	{
		pr_text << static_cast<char>(inputchar);
	}
	else if (inputchar == DELETE_KEY)
	{
		if (pr_text.str().length() > 0)
		{
			this->delete_last_char();
		}
	}

	pr_textbox.setString(pr_text.str() + "_");
}

void TextBox::delete_last_char()
{
	std::string text= pr_text.str();
	std::string new_text = "";

	for (int i = 0; i < pr_text.str().length() - 1; i++)
	{
		new_text += text[i];
	}

	pr_text.str("");
	pr_text << new_text;

	pr_textbox.setString(pr_text.str());

}

TextBox::TextBox()
{
	pr_is_box_selected = false;
	pr_text << "";
	pr_textbox.setString("");
	pr_limit = 10;
}

TextBox::TextBox(int size, sf::Color color, bool is_selected)
{
	pr_text << "";
	pr_limit = 10;
	pr_textbox.setFillColor(color);
	pr_textbox.setCharacterSize(size);
	pr_is_box_selected = is_selected;

	if (is_selected == true)
	{
		pr_textbox.setString("_");
	}
	else
	{
		pr_textbox.setString("");
	}
}

void TextBox::set_font(sf::Font& textbox_font)
{
	pr_textbox.setFont(textbox_font);
}

void TextBox::set_position(sf::Vector2f position)
{
	pr_textbox.setPosition(position);
}

void TextBox::set_limit(int limit)
{
	pr_limit = limit;
}

void TextBox::set_selected(bool selected)
{
	pr_is_box_selected = selected;
	if (!selected)
	{
		std::string text = pr_text.str();
		std::string new_text = "";

		for (int i = 0; i < pr_text.str().length(); i++)
		{
			new_text += text[i];
		}

		pr_textbox.setString(new_text);
	}
}

void TextBox::draw_to(sf::RenderWindow& window)
{
	window.draw(pr_textbox);
}

void TextBox::Typed(sf::Event Input)
{
	if (pr_is_box_selected)
	{
		int charTyped = Input.text.unicode;
		if (charTyped < 128)
		{
			if (pr_text.str().length() <= pr_limit)
			{
				this->Input(charTyped);
			}
			else if (pr_text.str().length() > pr_limit && charTyped == DELETE_KEY)
			{
				this->delete_last_char();
			}
		}
	}
}

void TextBox::clear_text_box()
{
	pr_text << "";
	pr_textbox.setString("");
}

std::string TextBox::Get_text()
{
	return pr_text.str();
}
