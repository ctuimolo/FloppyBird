#include "stdafx.h"
#include <vector>
#include <iostream>
#include "GameOverScreen.h"
#include "TitleScreen.h"
#include "MainLevel.h"

int GameOverScreen::highScore = 0;

GameOverScreen::GameOverScreen(sf::RenderWindow* window, RoomManager* manager, int score) {
	renderWindow = window;
	roomManager = manager;
	if(score > highScore)
		highScore = score;
	mechaFont.loadFromFile("resources/Mecha_Bold.ttf");
	scoreText.setFont(mechaFont);
	scoreText.setString(std::to_string(static_cast<long long>(highScore)));
	scoreText.setPosition(150, 160);
	scoreText.setCharacterSize(120);

	miscText.setFont(mechaFont);
	miscText.setString("your best score is...\n\n\n\n\n\n\n\n\n<esc> try again");
	miscText.setPosition(40, 140);
	miscText.setCharacterSize(20);
}

void GameOverScreen::update() {
	renderWindow->clear();

	scoreText.setString(std::to_string(static_cast<long long>(highScore)));
	renderWindow->draw(scoreText);
	renderWindow->draw(miscText);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		roomManager->changeRoom(new TitleScreen(renderWindow, roomManager));
	}
	renderWindow->display();
}