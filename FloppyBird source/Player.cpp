#include "stdafx.h"
#include "Player.h"
#include "Pipe.h"
#include <iostream>
#include <string>

Player::Player(sf::RenderWindow* window) {
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	spriteIndex = 0;
	frameDelay = 0;

	texture->loadFromFile("resources/bird.png");
	sprite->setTexture(*texture);
	state = 1;
	renderWindow = window;

	initialXpos = 115;
	initialYpos = 320;
	xpos = initialXpos;
	ypos = initialYpos;
	lowerBound = 50;

	sprite->setOrigin(32, 32);
	sprite->setPosition(initialXpos, initialYpos);

	collisionRadius = 20;

	canfall = true;
	fallSpeed = 0;
	fallAccel = 0.01;
	flyspeed = -10;
	maxFallSpeed = 20;
	isFlying = false;
	flyLength = 30;

}

bool Player::isAlive() {
	if(state == 1) return true;
		else return false;
}

bool Player::pipeCollision(Pipe* somePipe) {
	if(xpos + collisionRadius > somePipe->xpos &&
		   xpos - collisionRadius < somePipe->xpos + somePipe->depth &&
		   ypos + collisionRadius > somePipe->ypos &&
		   ypos - collisionRadius < somePipe->ypos + somePipe->height) {
		   		state = 0;
				flash();
				return true;
	}
	if(ypos + collisionRadius >= renderWindow->getSize().y - 51 && state != 0) {
		state = 0;
		flash();
		return true;
	}
	return false;
}

void Player::update() {
	// Player clock used for fly acceleration calculations
	playerTime = playerClock.getElapsedTime();
	sprite->setPosition(xpos, ypos);

	// On key press, fly upwards
	if(isAlive()) {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if(frameDelay > 0)
				frameDelay --;
			else {
				frameDelay = 5;
				if(spriteIndex == 1) spriteIndex = 2;
				else spriteIndex = 1;
			}
				playerClock.restart();
			playerTime = playerClock.getElapsedTime();
			fallSpeed = flyspeed;
		}else {
			spriteIndex = 0;
		}
	}else {
		spriteIndex = 3;
	}

	// Collision checks with ends of screen
	if(isAlive()) {
		if(ypos + fallSpeed + collisionRadius > renderWindow->getSize().y - lowerBound) {
				ypos = renderWindow->getSize().y - collisionRadius - lowerBound;
				fallSpeed = 0;
		}
		if(ypos + fallSpeed - collisionRadius < 0) {
			ypos = collisionRadius;
			fallSpeed = 0;
		}
	}else {
		if(ypos > renderWindow->getSize().y + 60) fallSpeed = 0;
	}

	// Player animation handler
	sprite->setTextureRect(sf::IntRect(spriteIndex*64, 0, 64, 64));

	// Update position with fall velocity
	ypos += fallSpeed;

	// Update fall velocity
	if(fallSpeed < maxFallSpeed) {
		if(flyTimer.getElapsedTime().asMilliseconds() < flyLength)
			fallSpeed = flyspeed;
		else {
			if(isAlive()) fallSpeed = fallAccel * playerTime.asMilliseconds();
			else fallSpeed = 5;
		}
	}

	renderWindow->draw(*sprite);
}

bool Player::toGameOver() {
	return (ypos >= 640);
}

void Player::flash() {
	sf::Clock duration;
	sf::RectangleShape flash;
	flash.setSize(sf::Vector2f(640, 640));
	flash.setFillColor(sf::Color::White);
	while(duration.getElapsedTime().asMilliseconds() < 6) {
		renderWindow->draw(flash);
		renderWindow->display();
	}
}