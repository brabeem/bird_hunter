#include <SFML/Graphics.hpp>

#ifndef MENU_H
#define MENU_H

#define MAX_NUMBER_OF_ITEMS 4

using namespace sf;
class Menu
{
public:
	Menu(float width, float height);

	virtual ~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int  GetPressedItem() { return selectedItemIndex; }

protected:

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif // MENU_H
