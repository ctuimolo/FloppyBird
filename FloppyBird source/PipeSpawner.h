#ifndef PIPESPAWNER_H
#define PIPESPAWNER_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Pipe.h"
#include "Player.h"
#include "MovingFloor.h"
#include <vector>

class PipeSpawner: public GameObject{
private:
	sf::RenderWindow* renderWindow;
	std::vector<GameObject*>* objectVector;
	std::vector<Pipe*> pipeVector;
	MovingFloor* floor1;
	MovingFloor* floor2;

	Player* thePlayer;
	int changeDistance;
	int numPipes;
	int pipesPassed;
	bool active;
	int levelRepeats;
	int pipeSpeed;
	int score;
public:
	PipeSpawner(sf::RenderWindow* window, std::vector<GameObject*>* activeObjects, Player* player); 
	void update();
	int returnScore();
};

#endif