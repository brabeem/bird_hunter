#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("data/font/Quicksand-Regular.otf"))//
	{
		//handle errorsf::Color::White
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Goli Thok: Nepal Wars");
	menu[0].setPosition(sf::Vector2f(width / 2.6, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Play");
	menu[1].setPosition(sf::Vector2f(width / 2.2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));


	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Options");
	menu[2].setPosition(sf::Vector2f(width / 2.2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width / 2.2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	selectedItemIndex = 0;
}

Menu::~Menu()
{
	//dtor
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}


void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 1)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}


void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

