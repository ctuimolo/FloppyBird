#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Pipe.h"

class Player: public GameObject{
private:
	sf::Sprite* sprite;
	sf::Texture* texture;
	sf::Clock playerClock;
	sf::Time playerTime;
	bool state;
	sf::RenderWindow* renderWindow;
	int spriteIndex;
	int frameDelay;
	
	int initialXpos;
	int initialYpos;
	int lowerBound;

	int collisionRadius;

	bool canfall;
	int fallSpeed;
	int maxFallSpeed;
	float fallAccel;
	int flyspeed;
	sf::Clock flyTimer;
	bool isFlying;
	int flyLength;

public:
	Player(sf::RenderWindow* window);
	bool isAlive();
	bool toGameOver();
	bool pipeCollision(Pipe* somePipe);
	void update();
	void fly();
	void flash();
};

#endif