#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
class backGroundMovingClass {
protected:
	double xAcc;
	double yAcc;
	double xVel;
	double yVel;
	double xPos;
	double yPos;
	double timeX;
	double timeY;
public:
	backGroundMovingClass();
    double returnXpos();
	double returnYpos();
	void howLongKeyPressedX(double );
	void howLongKeyPressedY(double );
	void intializePosition(double , double );
	void backgroundMovementVariables();
	void _backGroundMove(sf::RectangleShape& );

};

