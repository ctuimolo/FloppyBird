#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Player: public GameObject{
private:
	sf::Sprite* sprite;
	sf::Texture* texture;
	sf::Clock playerClock;
	sf::Time playerTime;
	bool state;
	sf::RenderWindow* renderWindow;
	
	int initialXpos;
	int initialYpos;

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
	void update();
	void fly();
};

#endif