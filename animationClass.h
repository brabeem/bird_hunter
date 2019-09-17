#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"backgroundMovingClass.h"

class animationClass {
private:
	int frameCountAnimation;
	double posX;
	double posY;
	double textureHeight;
	double textureWidth;
	bool countEnteredTimes;
public:
	animationClass();
	void calculateTextureSize(sf::Texture& , int);

	void recordPosition(int ,backGroundMovingClass& );


	void leftKeyPressed(backGroundMovingClass& );
	void decreasePixelPos(backGroundMovingClass& );

	void checkIfReady(int , sf::RectangleShape& , backGroundMovingClass& );
};

		
		
