#include "stdafx.h"

#include "RoomManager.h"
#include "Room.h"

#include <vector>
#include <iostream>

RoomManager::RoomManager() {
}

void RoomManager::update() {
	if(currentRoom != nullptr) {
		currentRoom->update();
	}
	else {
		std::cout << "ERR: no room\n";
	}
}

void RoomManager::changeRoom(Room* nextRoom) {
	currentRoom = nextRoom;
}

///////////////////////////////////////////////

Room::Room() {
}

void Room::update() {
	std::cout << "OBJ UPDATE" << std::endl;
}