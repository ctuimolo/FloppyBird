#include "stdafx.h"
#include <vector>
#include <iostream>

#include "RoomManager.h"
#include "stdafx.h"
#include "MainLevel.h"
#include "Player.h"
#include "Pipe.h"

MainLevel::MainLevel(sf::RenderWindow* window, RoomManager* manager) {
	std::cout << "MAIN LEVEL CREATED\n";

	renderWindow = window;
	roomManager = manager;

	//==== GAME OBJECTS VECTOR ====//
	/* GameObject type objects placed into this vector
	 * are placed through the update loop.
	 * game objects must have defined "update" funtions
	 */
	std::vector<GameObject*> activeObjects;

	Player* bird = new Player(renderWindow);
	//Pipe* upPipe = new Pipe(*renderWindow, "down", 280, 3, 0);
	//Pipe* upPipe2 = new Pipe(*renderWindow, "up", 400, 3, 0);
	
	activeObjects.push_back(bird);
	//activeObjects.push_back(upPipe);
	//activeObjects.push_back(upPipe2);
	
	std::cout << activeObjects.size() << std::endl;

	sf::Font mechaFont;

	sf::Text title;
	title.setFont(mechaFont);
	title.setCharacterSize(20);
	title.setPosition(30, 50);
	title.setColor(sf::Color::White);
	title.setString("flOppy bird");

	renderWindow->draw(title);

}

void MainLevel::update() {
	// refresh screen for redrawing
	renderWindow->clear();

	renderWindow->draw(title);

	// Active objects update loop
	int index = 0;
	for(std::vector<GameObject*>::iterator current = activeObjects.begin();
			current != activeObjects.end();) {
		std::cout << "Iterating over Active Objects\n";
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