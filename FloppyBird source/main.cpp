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
#include "TitleScreen.h"
#include "MainLevel.h"
#include "GameOverScreen.h"

// Game objects
#include "Player.h"
#include "Pipe.h"
#include "PipeSpawner.h"


////////////////////////////////////////////////////////////
// Entry point of application
////////////////////////////////////////////////////////////
int main() {
	//==== GAME CONSTANTS & INITS ====//
	const int gameWidth  = 400;
	const int gameHeight = 640;
	int gameScore = 0;
	
	//==== INITIALIZE GAME WINDOW ====//
	std:: cout << "Playing \"FlOppyBird!\"...\n\n";
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "FlOppy Bird",
							sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	bool isPlaying = false;
	sf::Clock clock;

	//==== ROOM MANAGER ===//
	/* The room manager calls the current room's update
	 * function from the main loop.
	 */
	RoomManager* roomManager = new RoomManager(); 

	//=== INITIALIZE FIRST ROOM ====//
	Room* initialRoom = new TitleScreen(&window, roomManager);
	Room* mainLevel = new MainLevel(&window, roomManager);
	roomManager->changeRoom(initialRoom);
	roomManager->changeRoom(mainLevel);
	roomManager->changeRoom(initialRoom);
	
	//==== MAIN LOOP ====//
	while (window.isOpen()) {

		roomManager->update();

		// Handle events, "events" handled by SFML library
		sf::Event event;
		while (window.pollEvent(event)) {
			// If window is closed...
			if (event.type == sf::Event::Closed) {
				   window.close();
				   break;
			}
		}
	}
}