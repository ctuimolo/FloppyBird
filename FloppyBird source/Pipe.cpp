#include "stdafx.h"
#include "Pipe.h"
#include <iostream>

Pipe::Pipe(sf::RenderWindow* window, std::string type, int x, int y, int initXspeed, int initYspeed) {
	sprite = new sf::Sprite();
	texture = new sf::Texture();

	if(type == "up") {
		texture->loadFromFile("resources/up pipe.png");
	}else if (type == "down") {
		texture->loadFromFile("resources/down pipe.png");	
	}
	sprite->setOrigin(0,0);
	height = 640;
	sprite->setTexture(*texture);
	renderWindow = window;
	
	OGxpos = x;
	OGypos = y;
	OGxspeed = initXspeed;
	OGyspeed = initYspeed;
	isActive = false;
	scored = false;

	depth = 64;
	xpos = x;
	ypos = y;
	xspeed = initXspeed;
	yspeed = initYspeed;

	passingTimes = 0;

	sprite->setPosition(xpos, ypos);

}

void Pipe::update() {
	if(xpos <= -200)
		passingTimes++;
	xpos -= xspeed;
	ypos += yspeed;
	sprite->setPosition(xpos, ypos);
	renderWindow->draw(*sprite);
}

void Pipe::reset(int newXspeed, int newYspeed) {
	activeClock.restart();
	xpos = OGxpos;
	ypos = OGypos;
	xspeed = newXspeed;
	yspeed = newYspeed;
}