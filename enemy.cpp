#include<iostream>
#include<SFML/Graphics.hpp>
#include"enemy.h"
using namespace std;

const int renderWindowWidth = 1960;
const int renderWindowHeight = 1080;

enemy::enemy(int a, int b, int c, int e) :isInHighlight(true), textureWidth(a), texturHeight(b), birdPos(renderWindowWidth, e), randomSeeder(c) {}
void enemy::randomDistGenerate() {
	srand(randomSeeder++);
	randDist = rand() % 200 + 600;
}

void enemy::_moveBird(sf::RectangleShape& rectBird) {
	birdPos = rectBird.getPosition();

	if (birdPos.y < 750) {
		srand(randomSeeder++);
		rectBird.move(-(rand() % 5 + 1), 0);
	}
	else {
		rectBird.move(0, -(rand() % 5 + 2));
	}
}

void enemy::BirdAnimation(sf::RectangleShape& bird) {
	static int frameCount = 0;
	bird.setTextureRect(sf::IntRect(frameCount * textureWidth, 0, textureWidth, texturHeight));
	frameCount++;
	if (frameCount == 5) {
		frameCount = 0;
	}
}

bool enemy::checkIfReady(sf::RectangleShape& bird, enemy* a) {
	birdPos = bird.getPosition();
	if (birdPos.x + a->randDist <= renderWindowWidth) {
		return true;
	}
	else {
		isInHighlight = false;
		return false;
	}
}

enemy::~enemy() {}

bool enemy::enemyLimit(sf::RectangleShape& bird) {
	birdPos = bird.getPosition();
	if (birdPos.x < -100 || birdPos.y < -100) {
		return true;
	}
	else
		return false;
}
