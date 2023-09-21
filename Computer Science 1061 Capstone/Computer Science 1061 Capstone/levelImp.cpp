#include "level.h"
#include <iostream>
using namespace std;

//return the ID of the level
int level::getID() {

	return levelID;
}

//return the storyline of the level
std::string level::getStoryLine() {

	return storyLine;

}

//change the storyline associated with a level
void level::setStoryLine(std::string newStory) {

	storyLine = newStory;

}

//change the ID of a level
void level::setID(int newID) {

	levelID = newID;

}


//constructor which sets the ID and storyline of the level
level::level(int ID, std::string story) {

	levelID = ID;
	storyLine = story;
}

//displays the storyline of the level and takes in choices (NOT USED)
int level::play() {

    
    int choice;
	cout << storyLine;
    try {
        cin >> choice;
        if (choice == 1) {
            if (levelID == 1) {

                return 5;
            }
            else return levelID += 1;
        }
        else if (choice == 2) {
            if (levelID == 1) {

                return 6;
            }
            else return levelID += 2;

        }
        else if (choice == 3) {
            return levelID + 3;

        }
        else if (choice == 4) {
            return levelID + 4;
            
        }
        else {

            throw choice;
        }
    }
    catch (int) {

        throw choice;
    }

    


}