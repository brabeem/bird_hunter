#include "animationClass.h"
#include<iostream>
#include<SFML/Graphics.hpp>

const int renderWindowWidth = 1960;
const int renderWindowHeight = 1080;
const int basePos = 725;

using namespace std;

animationClass::animationClass() {
	frameCountAnimation = 1;
	countEnteredTimes = false;
	posX = 0;
	posY = 0;
	textureHeight = 0;
	textureWidth = 0;
}

void animationClass::calculateTextureSize(sf::Texture& playertexture,int fca ) {
	frameCountAnimation = fca;
	sf::Vector2u textureSize = playertexture.getSize();
	textureSize.x /= frameCountAnimation;
	textureWidth = textureSize.x;
	textureHeight = textureSize.y;
}

void animationClass:: recordPosition(int c, backGroundMovingClass& backGroundUp1) {

	if (c == 0) {
		posX = backGroundUp1.returnXpos();
	}

}
void animationClass:: leftKeyPressed(backGroundMovingClass& backGroundUp1) {
    posX = backGroundUp1.returnXpos();
}


void animationClass:: decreasePixelPos(backGroundMovingClass& backGroundUp1) {
	if (countEnteredTimes == 1) {
		posX = posX - 5;
		countEnteredTimes = 0;
	}
}

void animationClass::checkIfReady(int animationCounter, sf::RectangleShape& player, backGroundMovingClass& backGroundUp1) {
	static int frameIndex;
	        if ((player.getPosition().y+100 >= basePos)) {
		       if (animationCounter == 0) {
			     frameIndex = 0;
			     countEnteredTimes = false;
		       }
			   if (posX <= -renderWindowWidth) {
				   posX = renderWindowWidth - 5.0;
			   }
		
			   if (posX >= backGroundUp1.returnXpos()) {
				player.setTextureRect(sf::IntRect(frameIndex * textureWidth, 0 * textureHeight, textureWidth, textureHeight));
				posX = backGroundUp1.returnXpos();
				frameIndex++;
				countEnteredTimes = true;
			   }
	    
		       if (frameIndex == frameCountAnimation) {
			   frameIndex = 0;
		       }
			}
}