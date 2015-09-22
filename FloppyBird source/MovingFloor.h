#ifndef MOVINGFLOOR_H
#define MOVINGFLOOR_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class MovingFloor: public GameObject {
private:
	sf::Sprite* sprite;
	sf::Texture* texture;
	sf::RenderWindow* renderWindow;
	MovingFloor* otherFloor;

public:
	MovingFloor(sf::RenderWindow* window, int x, int y, int speed);
	void update();
	void changeSpeed(int newSpeed);
	int xspeed;
	bool isActive;
};

#endif