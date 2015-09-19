#include "stdafx.h"
#include "Pipe.h"

Pipe::Pipe(sf::RenderWindow* window, std::string type, int y, int initXspeed, int initYspeed) {
	sprite = new sf::Sprite();
	texture = new sf::Texture();

	if(type == "up") {
		texture->loadFromFile("resources/up pipe.png");
		sprite->setOrigin(0, 0);
	}else if (type == "down") {
		texture->loadFromFile("resources/down pipe.png");	
		sprite->setOrigin(0, 640);
	}
	sprite->setTexture(*texture);
	renderWindow = window;
	
	xpos = window->getSize().x;
	ypos = y;
	xspeed = initXspeed;
	yspeed = initYspeed;

	sprite->setPosition(xpos, ypos);

}

void Pipe::update() {
	xpos -= xspeed;
	sprite->setPosition(xpos, ypos);
	renderWindow->draw(*sprite);
}
