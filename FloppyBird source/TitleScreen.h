#ifndef TITLESCREEN_H
#define TITLESCREEN_H
#include <SFML/Graphics.hpp>

#include "RoomManager.h"
#include "GameObject.h"
#include "MovingFloor.h"

class TitleScreen: public Room{
private:
	sf::RenderWindow* renderWindow;
	RoomManager* roomManager;

	std::vector<GameObject*> activeObjects;
	
	MovingFloor* floor1;
	MovingFloor* floor2;

	sf::Font mechaFont;
	sf::Text title;

public:
	TitleScreen(sf::RenderWindow* window, RoomManager* manager);
	void update();
};


#endif