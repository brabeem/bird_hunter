#include "goliThok.h"
#include<SFML/Graphics.hpp>

const int renderWindowWidth = 1960;
const int renderWindowHeight = 1080;

	goliThok::goliThok() {

		bulletVel = 250;
		movX = 50;
		movY = 50;
	}

	goliThok:: ~goliThok() {}

	void goliThok:: copyPlayerPos(sf::RectangleShape& player, sf::RectangleShape& bullet,int mousePosX,int mousePosY) {
		playerPos = player.getPosition();
		bullet.setPosition(playerPos.x, playerPos.y);
		this->mousePosX = (double)mousePosX;
		this->mousePosY = (double)mousePosY;
	}

	void goliThok:: unitVectorCalc() {
		bulletMovementVector.x = mousePosX- playerPos.x;
		bulletMovementVector.y = mousePosY- playerPos.y;
		double A = (double)pow(bulletMovementVector.x, 2) + (double)pow(bulletMovementVector.y, 2);
		A = abs(sqrt(A));
		bulletMovementVector.x /= A;
		bulletMovementVector.y /= A;
	}

	bool goliThok:: bulletLimit(sf::RectangleShape& bullet) {
		bool limitCrossed = false;
		sf::Vector2f bulletPos = bullet.getPosition();
		if ( bulletPos.x>1960 ||  bulletPos.y>725||bulletPos.x<0||bulletPos.y<0) {
			limitCrossed = 1;
		}
		return limitCrossed;
	}

	void goliThok:: bulletAction(sf::RectangleShape& bullet) {
		double m = abs(sqrt(pow(movX, 2) + pow(movY, 2)));
		bullet.move(sf::Vector2f(m * bulletMovementVector.x, m * bulletMovementVector.y));
	}






