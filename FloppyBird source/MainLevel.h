#ifndef MAINLEVEL_H
#define MAINLEVEL_H
#include <SFML/Graphics.hpp>

#include "RoomManager.h"
#include "Player.h"
#include "PipeSpawner.h"
#include "StarSpawner.h"

class MainLevel: public Room{
private:
	sf::RenderWindow* renderWindow;
	RoomManager* roomManager;
	PipeSpawner* pipeSpawner;
	StarSpawner* starSpawner;

	Player* bird;
	int currentPipeIndex;
	int pipeSpeed;
	int levelRelays;

	std::vector<GameObject*> activeObjects;
	
	sf::Font mechaFont;
	sf::Text miscText;

public:
	MainLevel(sf::RenderWindow* window, RoomManager* manager);
	void update();
	void clearRoom();
};

#endif