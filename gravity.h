#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;


class gravity {
private:
	const double accDueToGravity = 9.8;
	double timeInUsY;
	double posX;
	double posY;
public:
	gravity(sf::Vector2f);

	void gravityCalc(int);

	void gravityAction(sf::RectangleShape&);
};

