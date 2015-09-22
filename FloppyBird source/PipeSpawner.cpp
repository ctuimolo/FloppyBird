#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

#include "PipeSpawner.h"
#include "GameObject.h"
#include "PipePattern.h"
#include "Pipe.h"

PipeSpawner::PipeSpawner(sf::RenderWindow* window, std::vector<GameObject*>* activeObjects, Player* player) {
	renderWindow = window;
	objectVector = activeObjects;
	thePlayer = player;
	pipeSpeed = 3;
	levelRepeats = 0;

	floor1 = new MovingFloor(renderWindow, 800, renderWindow->getSize().y - 50, 0);
	floor2 = new MovingFloor(renderWindow, 400, renderWindow->getSize().y - 50, 0);

	PipePattern pipePattern = PipePattern01(renderWindow, pipeSpeed);

	pipeVector = pipePattern.vector;
	changeDistance = pipePattern.changeDistance;
	numPipes = pipePattern.numPipes;

	pipesPassed = 0;
	xpos = 0;
	ypos = 0;
	score = 0;

}

void PipeSpawner::update() {
	sf::Font mechaFont;
	mechaFont.loadFromFile("resources/Mecha_Bold.ttf");
	sf::Text playerScore;
	playerScore.setFont(mechaFont);
	playerScore.setString(std::to_string(static_cast<long long>(score)));
	playerScore.setPosition(renderWindow->getSize().x - playerScore.getGlobalBounds().width - 80, 10);
	playerScore.setCharacterSize(80);
	renderWindow->draw(playerScore);


	if(active) {
		for(int i = 0; i < pipeVector.size(); i++) {
			Pipe* currentPipe = pipeVector[i];
			currentPipe->update();
			floor1->changeSpeed(currentPipe->xspeed);
			floor2->changeSpeed(currentPipe->xspeed);
			if(thePlayer->pipeCollision(currentPipe)) {
				active = false;
			}
			if(currentPipe->xpos+64 < thePlayer->xpos - 20 && !currentPipe->scored){
				currentPipe->scored = true;
				score++;
			}
			if(i == pipeVector.size() - 1 && currentPipe->xpos < -200) {
				for(int other_i = 0; other_i < pipeVector.size(); ++other_i) {
					Pipe* other_currentPipe = pipeVector[other_i];
					other_currentPipe->scored = false;
					other_currentPipe->passingTimes++;
					other_currentPipe->xpos = other_currentPipe->OGxpos;
					other_currentPipe->xspeed = other_currentPipe->xspeed + 1;
				}
			}
		}
	}else {
		for(int i = 0; i < pipeVector.size(); i++) {
			Pipe* currentPipe = pipeVector[i];
			currentPipe->xspeed = 0;
			currentPipe->update();
		}
		floor1->isActive = false;
		floor2->isActive = false;
	}
	floor2->update();
	floor1->update();
}

int PipeSpawner::returnScore() {
	return score;
}
