#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Pipe: public GameObject{
private:
	sf::Sprite* sprite;
	sf::Texture* texture;
	sf::RenderWindow* renderWindow;
	sf::Clock activeClock;

public:
	std::string type;

	bool scored;
	int height;
	int depth;
	int OGxpos;
	int OGypos;
	int OGxspeed;
	int OGyspeed;
	int OGtimer;
	int passingTimes;
	int xspeed;
	int yspeed;
	Pipe(sf::RenderWindow* window, std::string type, int x, int y, int initXspeed, int initYspeed);
	void update();
	bool isActive;
	void reset(int newXspeed, int newYspeed);
};

#endif