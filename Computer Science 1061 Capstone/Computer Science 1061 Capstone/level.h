#pragma once
#include <string>

//class to hold all the level itself including information about the story and its ID
class level {

public:

	int getID();
	std::string getStoryLine();
	void setStoryLine(std::string);
	void setID(int);
	int play();

	level(int ID = 0, std::string story = "");
	

private:
	std::string storyLine;
	int levelID;
	int nextLevel;


};