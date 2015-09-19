#include "stdafx.h"
#include "Player.h"

Player::Player(sf::RenderWindow* window) {
	sprite = new sf::Sprite();
	texture = new sf::Texture();

	texture->loadFromFile("resources/bird.png");
	sprite->setTexture(*texture);
	state = 1;
	renderWindow = window;

	initialXpos = 115;
	initialYpos = 320;
	xpos = initialXpos;
	ypos = initialYpos;

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

void Player::update() {
	// Player clock used for fly acceleration calculations
	playerTime = playerClock.getElapsedTime();
	sprite->setPosition(xpos, ypos);

	// On key press, fly upwards
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		flyTimer.restart();
		playerClock.restart();
		playerTime = playerClock.getElapsedTime();
		fallSpeed = flyspeed;
	}


	// Collision checks with ends of screen
	if(ypos + fallSpeed + collisionRadius > renderWindow->getSize().y) {
		ypos = renderWindow->getSize().y - collisionRadius;
		fallSpeed = 0;
	}
	if(ypos + fallSpeed - collisionRadius < 0) {
		ypos = collisionRadius;
		fallSpeed = 0;
	}

	// Update position with fall velocity
	ypos += fallSpeed;

	// Update fall velocity
	if(fallSpeed < maxFallSpeed) {
		if(flyTimer.getElapsedTime().asMilliseconds() < flyLength)
			fallSpeed = flyspeed;
		else fallSpeed = fallAccel * playerTime.asMilliseconds();
	}

	renderWindow->draw(*sprite);
}