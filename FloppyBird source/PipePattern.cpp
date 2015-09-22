#include "stdafx.h"
#include "PipePattern.h"
#include "Pipe.h"
#include <vector>

PipePattern::PipePattern() {
}

PipePattern01::PipePattern01(sf::RenderWindow* window, int initXspeed) {
	vector.push_back(new Pipe(window, "up", 400, 400, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 600, 380, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 900, -500, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 900, 380, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 1200, -300, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 1500, -560, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 1500, 320, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 1800, 500, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 1800, -300, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 2000, -220, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 2200, 500, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 2280, 310, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 2280, -480, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 2380, -470, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 2400, 540, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 2600, 600, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 2600, -500, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 2280, 300, initXspeed, 0));

	vector.push_back(new Pipe(window, "up", 2480, 300, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 2480, -500, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 2680, 380, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 2680, -420, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 2880, -480, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 2800, 500, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 3050, -300, initXspeed, 0));
	vector.push_back(new Pipe(window, "down", 3220, -280, initXspeed, 0));
	vector.push_back(new Pipe(window, "up", 3650, 300, initXspeed, 0));


	changeDistance = 3650;
	numPipes = vector.size();
}