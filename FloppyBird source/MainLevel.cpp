#include "stdafx.h"
#include <vector>
#include <iostream>

#include "MainLevel.h"
#include "RoomManager.h"
#include "TitleScreen.h"
#include "GameOverScreen.h"
#include "Player.h"
#include "PipePattern.h"
#include "PipeSpawner.h"
#include "StarSpawner.h"
#include <vector>

MainLevel::MainLevel(sf::RenderWindow* window, RoomManager* manager) {
	renderWindow = window;
	roomManager = manager;
	pipeSpeed = 3;
	levelRelays = 0;

	//==== GAME OBJECTS VECTOR ====//
	/* GameObject type objects placed into this vector
	 * are placed through the update loop.
	 * game objects must have defined "update" funtions
	 */
	bird = new Player(renderWindow);
	pipeSpawner = new PipeSpawner(renderWindow, &activeObjects, bird);
	starSpawner = new StarSpawner(renderWindow);
	activeObjects.push_back(starSpawner);
	activeObjects.push_back(pipeSpawner);
	activeObjects.push_back(bird);

	mechaFont.loadFromFile("resources/Mecha_Bold.ttf");

	miscText.setFont(mechaFont);
	miscText.setCharacterSize(20);
	miscText.setPosition(2, 2);
	miscText.setColor(sf::Color::White);
	miscText.setString("<esc> return to title");

}

void MainLevel::update() {
	// refresh screen for redrawing
	renderWindow->clear();
	renderWindow->draw(miscText);

	// On key(esc) press, clear room and change to title screen
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->clearRoom();
		roomManager->changeRoom(new TitleScreen(renderWindow, roomManager));
	}

	// On player death trigger, move to Game Over Screen
	if(bird->toGameOver()) {
		roomManager->changeRoom(new GameOverScreen(renderWindow, roomManager, pipeSpawner->returnScore()));
	}

	// Active objects update loop
	int index = 0;
	for(std::vector<GameObject*>::iterator current = activeObjects.begin();
			current != activeObjects.end();) {
		GameObject* currentObject = activeObjects.at(index);
		if(currentObject->xpos < -200) {
			current = activeObjects.erase(current);
		}else {
			currentObject->update();
			++current;
			++index;
		}
	}

	// display screen update
	renderWindow->display();
}

void MainLevel::clearRoom() {
	// iterate over active objects and delete
	for(std::vector<GameObject*>::iterator current = activeObjects.begin();
			current != activeObjects.end();) {
		GameObject* currentObject = activeObjects.at(0);
		current = activeObjects.erase(current);
		}
}
