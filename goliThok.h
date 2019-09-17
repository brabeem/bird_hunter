#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;

class goliThok {
private:
	double bulletVel;
	double mousePosX;
	double mousePosY;
	double movX;
	double movY;
	sf::Vector2f playerPos;
	sf::Vector2f bulletMovementVector;

public:


	goliThok();
	~goliThok();
	void copyPlayerPos(sf::RectangleShape& , sf::RectangleShape&,int,int );
	void unitVectorCalc();
	bool bulletLimit(sf::RectangleShape&);
	void bulletAction(sf::RectangleShape&);
};