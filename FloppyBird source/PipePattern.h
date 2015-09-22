#ifndef PIPEPATTERN_H
#define PIPEPATTERN_H

#include <SFML/Graphics.hpp>
#include "Pipe.h"
#include <vector>

class PipePattern {
public:
	PipePattern();
	std::vector<Pipe*> vector;
	int changeDistance;
	int numPipes;
};

class PipePattern01: public PipePattern {
public:
	PipePattern01(sf::RenderWindow* window, int initXspeed);
};

#endif