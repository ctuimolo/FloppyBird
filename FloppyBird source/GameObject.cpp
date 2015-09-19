#include "stdafx.h"
#include <iostream>

#include "GameObject.h"


GameObject::GameObject() {
}

void GameObject::update() {
	std::cout << "OBJ UPDATE" << std::endl;
}