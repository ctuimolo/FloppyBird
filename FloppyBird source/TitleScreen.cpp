#include "stdafx.h"
#include <vector>
#include <iostream>

#include "RoomManager.h"
#include "MainLevel.h"
#include "TitleScreen.h"

TitleScreen::TitleScreen(sf::RenderWindow* window, RoomManager* manager) {
	renderWindow = window;
	roomManager = manager;

	//==== GAME OBJECTS VECTOR ====//
	/* GameObject type objects placed into this vector
	 * are placed through the update loop.
	 * game objects must have defined "update" funtions
	 */
	floor1 = new MovingFloor(renderWindow, 800, renderWindow->getSize().y - 50, 1);
	floor2 = new MovingFloor(renderWindow, 400, renderWindow->getSize().y - 50, 1);
	activeObjects.push_back(floor1);
	activeObjects.push_back(floor2);

	mechaFont.loadFromFile("resources/Mecha_Bold.ttf");
	title.setFont(mechaFont);
	title.setString("flOppy bird\npress space");
	renderWindow->draw(title);

}

void TitleScreen::update() {
	// refresh screen for redrawing
	renderWindow->clear();

	// On key press, proceed to Main Level
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		roomManager->changeRoom(new MainLevel(renderWindow, roomManager));
	}

	renderWindow->draw(title);
	// Active objects update loop
	int index = 0;
	for(std::vector<GameObject*>::iterator current = activeObjects.begin();
			current != activeObjects.end();) {
		GameObject* currentObject = activeObjects.at(index);
		currentObject->update();
		++current;
		++index;
	}

	// display screen update
	renderWindow->display();
}