#ifndef MAINLEVEL_H
#define MAINLEVEL_H
#include <SFML/Graphics.hpp>

#include "RoomManager.h"
#include "MainLevel.h"
#include "Player.h"
#include "Pipe.h"

class MainLevel: public Room{
private:
	sf::RenderWindow* renderWindow;
	RoomManager* roomManager;

	std::vector<GameObject*> activeObjects;
	Player* bird;
	Pipe* upPipe;
	Pipe* upPipe2;
	
	sf::Font mechaFont;
	sf::Text title;

public:
	MainLevel(sf::RenderWindow* window, RoomManager* manager);
	virtual void update();
};


#endif