#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H
#include <SFML/Graphics.hpp>

#include "RoomManager.h"
#include "GameObject.h"

class GameOverScreen: public Room{
private:
	sf::RenderWindow* renderWindow;
	RoomManager* roomManager;
	
	sf::Font mechaFont;
	sf::Text scoreText;
	sf::Text miscText;

public:
	GameOverScreen(sf::RenderWindow* window, RoomManager* manager, int Score);
	void update();
	static int highScore;
};

#endif