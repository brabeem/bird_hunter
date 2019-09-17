#include "backgroundMovingClass.h"
#include<SFML/Graphics.hpp>
#include<iostream>


const int renderWindowWidth = 1960;
const int renderWindowHeight = 1080;
const int basePos = 725;
using namespace std;

backGroundMovingClass::	backGroundMovingClass() {
		xAcc = 0.01;
		yAcc = 0.01;
		xVel = 100;
		yVel = 500;
		xPos = 0;
		yPos = 0;
		timeX = 0.0;
		timeY = 0.0;
	}


	double backGroundMovingClass:: returnXpos() {
		return xPos;
	}
	double backGroundMovingClass:: returnYpos() {
		return yPos;
	}
	void backGroundMovingClass::howLongKeyPressedX(double a) {

		timeX = a / 1000000.0;
	}
	void backGroundMovingClass:: howLongKeyPressedY(double b) {

		timeY = b / 1000000.0;

	}
	void  backGroundMovingClass:: intializePosition(double a, double b) {
		xPos = a;
		yPos = b;

	}
	void backGroundMovingClass::backgroundMovementVariables() {
		xAcc = xAcc + timeX;
		yAcc = yAcc + timeY;


		xVel = xVel + xAcc * timeX;
		yVel = yVel + yAcc * timeY;
		if (xVel > 160) {
			xVel = 160;
		}

		xPos = xPos + xVel * timeX;
		yPos = yPos + yVel * timeY;

		
		if (yPos < 0) {
			yPos = 0;
			timeY = -timeY;
		}
	}

	void backGroundMovingClass:: _backGroundMove(sf::RectangleShape& player) {
		player.setPosition(xPos, yPos);
	}