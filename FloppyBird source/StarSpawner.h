#ifndef STARSPAWNER_H
#define STARSPAWNER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"

class Star: public GameObject {
private:
	sf::RenderWindow* renderWindow;
	sf::Clock twinkleClock;
public:
	Star(sf::RenderWindow* window, int y);
	void update();
};

class StarSpawner: public GameObject {
private:
	sf::RenderWindow* renderWindow;
	int numStars;
	std::vector<Star*> starVector;
	sf::Clock spawnTimer;
public:
	bool isActive;
	StarSpawner(sf::RenderWindow* window);
	void update();
};

#endif