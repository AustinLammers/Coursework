#pragma once
#include "level.h"
#include <string>
#include <iostream>

//abstract data type to package all relavant information about a level into one object.
struct nodeType {

	//holds the level object
	level info;
	//the four links corresponding to the four choices the user has at each stage
	nodeType* link1;
	nodeType* link2;
	nodeType* link3;
	nodeType* link4;
	//level number
	int levelNum;
	//displays the level story and takes input to be retruned to a error handling algorithm. Replaces level::play()
	int play() {
		int selection;
		std::cout << info.getStoryLine();
		std::cin >> selection;
		return selection;

	}

};






