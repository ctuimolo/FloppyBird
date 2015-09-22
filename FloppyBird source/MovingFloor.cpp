#include "stdafx.h"
#include "MovingFloor.h"
#include <iostream>

MovingFloor::MovingFloor(sf::RenderWindow* window, int x, int y, int speed) {
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	texture->loadFromFile("resources/floor.png");
	sprite->setTexture(*texture);

	renderWindow = window;

	sprite->setOrigin(800, 0);
	xpos = x;
	ypos = y;
	xspeed = speed;
	isActive = true;
}

void MovingFloor::update() {
	if(isActive) {
		sprite->setPosition(xpos, ypos);
		xpos -= xspeed;
		if(sprite->getPosition().x <= 0) {
			xpos = 799;
		}
	}
	renderWindow->draw(*sprite);
}

void MovingFloor::changeSpeed(int newSpeed) {
	xspeed = newSpeed;
}