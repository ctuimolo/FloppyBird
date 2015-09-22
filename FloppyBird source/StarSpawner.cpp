#include "stdafx.h"
#include <vector>
#include <iostream>
#include "StarSpawner.h"

StarSpawner::StarSpawner(sf::RenderWindow* window) {
	renderWindow = window;
	xpos = 0;
	ypos = 0;
	isActive = true;
}

void StarSpawner::update() {
	numStars = starVector.size();
	if(isActive) {
		for(int i = 0; i < starVector.size(); i++) {
			Star* currentStar = starVector[i];
			currentStar->update();
		}
		if(spawnTimer.getElapsedTime().asMilliseconds() > 200 && numStars < 50) {
			starVector.push_back(new Star(renderWindow, std::rand() % renderWindow->getSize().y - 20 + 1));
			spawnTimer.restart();
		}
	}
}

Star::Star(sf::RenderWindow* window, int y) {
	renderWindow = window;
	xpos = window->getSize().x;
	ypos = y;
}

void Star::update() {
	xpos -= 1;
	if(xpos < 0) {
		xpos = renderWindow->getSize().x;
		ypos = (std::rand() % renderWindow->getSize().y - 20) + 1;
	}
	sf::RectangleShape twinkleStar;
	twinkleStar.setSize(sf::Vector2f(1,1));
	if(twinkleClock.getElapsedTime().asMicroseconds() % 2 == 0) {
		twinkleStar.setFillColor(sf::Color::White);
	}else twinkleStar.setFillColor(sf::Color::Black);
	twinkleStar.setPosition(xpos, ypos);
	renderWindow->draw(twinkleStar);
}