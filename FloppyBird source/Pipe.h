#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Pipe: public GameObject{
private:
	sf::Sprite* sprite;
	sf::Texture* texture;
	sf::RenderWindow* renderWindow;
	int xspeed;
	int yspeed;
	std::string type;

public:
	Pipe(sf::RenderWindow* window, std::string type, int y, int initXspeed, int initYspeed);
	void update();
};

#endif