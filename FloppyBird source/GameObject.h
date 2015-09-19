#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject{
public:
	GameObject();
	virtual void update();
	int xpos;
	int ypos;
};

#endif