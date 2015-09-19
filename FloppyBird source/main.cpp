////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

// Game constructs
#include "GameObject.h"
#include "Room.h"
#include "RoomManager.h"

// Rooms/Levels
#include "MainLevel.h"

// Game objects
#include "Player.h"
#include "Pipe.h"


////////////////////////////////////////////////////////////
// Entry point of application
////////////////////////////////////////////////////////////
int main() {
	//==== GAME CONSTANTS & INITS ====//
	const int gameWidth  = 400;
	const int gameHeight = 640;

	
	//==== INITIALIZE GAME WINDOW ====//
	std:: cout << "Playing \"FlOppyBird!\"...\n\n";
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "FlOppy Bird",
							sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	bool isPlaying = false;
	sf::Clock clock;

	//==== ROOM MANAGER ===//
	/* The room manager calls the current room's update
	 * function from the main loop.
	 */
	RoomManager* roomManager = new RoomManager(); 

	//=== INITIALIZE FIRST ROOM ====//
	Room* initialRoom = new MainLevel(&window, roomManager);
	roomManager->changeRoom(initialRoom);

	//==== GAME OBJECTS VECTOR ====//
	/* GameObject type objects placed into this vector
	 * are placed through the update loop.
	 * game objects must have defined "update" funtions
	 */
	std::vector<GameObject*> activeObjects;

	Player* bird = new Player(&window);
	Pipe* upPipe = new Pipe(&window, "down", 280, 3, 0);
	Pipe* upPipe2 = new Pipe(&window, "up", 400, 3, 0);
	
	activeObjects.push_back(bird);
	activeObjects.push_back(upPipe);
	activeObjects.push_back(upPipe2);
	
	std::cout << activeObjects.size() << std::endl;

	sf::Font mechaFont;

	sf::Text title;
	title.setFont(mechaFont);
	title.setCharacterSize(20);
	title.setPosition(30, 50);
	title.setColor(sf::Color::White);
	title.setString("flOppy bird");

	//==== MAIN LOOP ====//
	while (window.isOpen()) {

		//roomManager->update();
		window.clear();

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
		window.display();

		// Handle events, "events" handled by SFML library
		sf::Event event;
		while (window.pollEvent(event)) {
			// If window is closed...
			if ((event.type == sf::Event::Closed) ||
			   ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
				   window.close();
				   break;
			}
		}
	}
}