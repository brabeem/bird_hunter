#include "gravity.h"
#include<SFML/Graphics.hpp>
#include<iostream>

const int basePos = 635;
gravity::gravity(sf::Vector2f playerPos) :posX(playerPos.x), posY(playerPos.y) {}

void gravity::gravityCalc(int counter) {

	if (counter == 0) {
		timeInUsY = 0;
	}
	timeInUsY++;

	if (posY < basePos) {

		posY = posY + 0.5 * accDueToGravity * timeInUsY * timeInUsY * (0.000001);

	}
	if (posY >= basePos) {
		posY = basePos;
		timeInUsY = 0;
	}
}

void gravity:: gravityAction(sf::RectangleShape& player2) {
	player2.setPosition(posX, posY);
}