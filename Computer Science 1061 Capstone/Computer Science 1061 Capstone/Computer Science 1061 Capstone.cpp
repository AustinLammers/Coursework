//Austin Lammers
//Computer Science 1060
//M5: Final Capstone Programming Assignment
//May 3rd, 2023

#include <iostream>
#include <fstream>
#include "story.h"
#include "level.h"
#include "linkedList.h"

void mainMenu();
void startGame();
void stats();
void storyInit();
void login();
void loginHandler();
using namespace std;

//the total available level count
const int LEVEL_COUNT = 20;
//array to hold the story nodes
nodeType stories[LEVEL_COUNT];
//current level the user is playing
int currLevel = 0;
//A pointer to the storynode the user is on
nodeType* selector;
//output file variable 
ofstream outFile;
//input file variable
ifstream inFile;
//the username of the current user
string currUsername;
void quit();



int main()
{
    
    login();
    storyInit();
    mainMenu();
    
}

//displays welcome menu and handles input errors
void mainMenu() {
    
    int choice;
    cout << "Welcome to the game!\nWhat would you like to do?\n\n1. Play Game\n2. Quit\n\nPlease enter the corresponding integer value of your selection. When in the game, entering 0 at any time will save and quit the game\n";
    try {

        cin >> choice;
        if (choice == 1) {
            system("CLS");
            while (true) startGame();
        }
        else if (choice == 2) {
            return;
        }
        else {
            throw choice;
        }

    }
    catch (int) {

        cout << "We have a rebel on our hands! Let's try to follow instructions this time!\n";
        cin.clear();
        cin.ignore();
        mainMenu();
    }

    
}

//function which runs the game and handles input errors.
void startGame() {
    try {
        int optionChoice;
        optionChoice = selector->play();
        if (optionChoice == 1) {

            selector = selector->link1;
            currLevel = selector->levelNum;
        }
        else if (optionChoice == 2) {

            selector = selector->link2;
            currLevel = selector->levelNum;
        }
        else if (optionChoice == 3) {
            
            selector = selector->link3;
            currLevel = selector->levelNum;
        }
        else if (optionChoice == 4) {
            
            selector = selector->link4;
            currLevel = selector->levelNum;
        }
        else if (optionChoice == 0) {
            
            quit();
        }
        else {
            throw optionChoice;
        }
        
        
    }
    catch (int) {
        
        cout << "Woah there, that doesn't look like a valid choice\n";
        cin.clear();
        cin.ignore(100, '\n');
        startGame();
        
        
    }

}


//Function that initializes all the neccesary data including levels and story nodes
void storyInit() {

    //temporary variables to hold dynamically allocated objects for assignment
    level* levelMiddleMan;
    nodeType* nodeMiddleMan;

    //primary node adding. Sets up the story, ID, level number and links for every node.

    //creating new level object with corresponding story
    levelMiddleMan = new level(0, levels[0]);
    //creating new node object to store the lovel   
    nodeMiddleMan = new nodeType;
    //storing level
    nodeMiddleMan->info = *levelMiddleMan;
    //setting appropriate links
    nodeMiddleMan->link1 = &stories[1];
    nodeMiddleMan->link2 = &stories[2];
    nodeMiddleMan->link3 = &stories[3];
    nodeMiddleMan->link4 = &stories[4];
    //setting level number
    nodeMiddleMan->levelNum = 0;
    //storing node into node array
    stories[0] = *nodeMiddleMan;

    //pattern repeats
    levelMiddleMan = new level(1, levels[1]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[5];
    nodeMiddleMan->link2 = &stories[6];
    nodeMiddleMan->link3 = &stories[6];
    nodeMiddleMan->link4 = &stories[6];
    nodeMiddleMan->levelNum = 1;
    stories[1] = *nodeMiddleMan;

    levelMiddleMan = new level(2, levels[2]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[16];
    nodeMiddleMan->link2 = &stories[17];
    nodeMiddleMan->link3 = &stories[18];
    nodeMiddleMan->link4 = &stories[19];
    nodeMiddleMan->levelNum = 2;
    stories[2] = *nodeMiddleMan;

    levelMiddleMan = new level(3, levels[3]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[6];
    nodeMiddleMan->link2 = &stories[6];
    nodeMiddleMan->link3 = &stories[6];
    nodeMiddleMan->link4 = &stories[6];
    nodeMiddleMan->levelNum = 3;
    stories[3] = *nodeMiddleMan;

    levelMiddleMan = new level(4, levels[4]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 4;
    stories[4] = *nodeMiddleMan;

    levelMiddleMan = new level(5, levels[5]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[6];
    nodeMiddleMan->link2 = &stories[6];
    nodeMiddleMan->link3 = &stories[6];
    nodeMiddleMan->link4 = &stories[6];
    nodeMiddleMan->levelNum = 5;
    stories[5] = *nodeMiddleMan;

    levelMiddleMan = new level(6, levels[6]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[7];
    nodeMiddleMan->link2 = &stories[8];
    nodeMiddleMan->link3 = &stories[9];
    nodeMiddleMan->link4 = &stories[10];
    nodeMiddleMan->levelNum = 6;
    stories[6] = *nodeMiddleMan;

    levelMiddleMan = new level(7, levels[7]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[11];
    nodeMiddleMan->link2 = &stories[12];
    nodeMiddleMan->link3 = &stories[13];
    nodeMiddleMan->link4 = &stories[14];
    nodeMiddleMan->levelNum = 7;
    stories[7] = *nodeMiddleMan;

    levelMiddleMan = new level(8, levels[8]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 8;
    stories[8] = *nodeMiddleMan;

    levelMiddleMan = new level(9, levels[9]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[7];
    nodeMiddleMan->link2 = &stories[8];
    nodeMiddleMan->link3 = &stories[9];
    nodeMiddleMan->link4 = &stories[10];
    nodeMiddleMan->levelNum = 9;
    stories[9] = *nodeMiddleMan;

    levelMiddleMan = new level(10, levels[10]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[11];
    nodeMiddleMan->link2 = &stories[11];
    nodeMiddleMan->link3 = &stories[11];
    nodeMiddleMan->link4 = &stories[11];
    nodeMiddleMan->levelNum = 10;
    stories[10] = *nodeMiddleMan;

    levelMiddleMan = new level(11, levels[11]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 11;
    stories[11] = *nodeMiddleMan;

    levelMiddleMan = new level(12, levels[12]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 12;
    stories[12] = *nodeMiddleMan;

    levelMiddleMan = new level(13, levels[13]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 13;
    stories[13] = *nodeMiddleMan;

    levelMiddleMan = new level(14, levels[14]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 14;
    stories[14] = *nodeMiddleMan;

    levelMiddleMan = new level(15, levels[15]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 15;
    stories[15] = *nodeMiddleMan;

    levelMiddleMan = new level(16, levels[16]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 16;
    stories[16] = *nodeMiddleMan;

    levelMiddleMan = new level(17, levels[17]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 17;
    stories[17] = *nodeMiddleMan;

    levelMiddleMan = new level(18, levels[18]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 18;
    stories[18] = *nodeMiddleMan;

    
    levelMiddleMan = new level(19, levels[19]);
    nodeMiddleMan = new nodeType;
    nodeMiddleMan->info = *levelMiddleMan;
    nodeMiddleMan->link1 = &stories[0];
    nodeMiddleMan->link2 = &stories[0];
    nodeMiddleMan->link3 = &stories[0];
    nodeMiddleMan->link4 = &stories[0];
    nodeMiddleMan->levelNum = 19;
    stories[19] = *nodeMiddleMan;

    //sets the level selector to the users last played level, or 0 if the user is new
    selector = &stories[currLevel];

}

//function to handle to login process
void login() {
    
    try {
        //variable to stroe the confirmation character
        char confirm;
        cout << "Welcome, please enter your Username ending with '~' below: \n";
        //reads multi-worded usernames
        getline(cin, currUsername, '~');
        //ask for confirmation so users can ensure they open the correct user
        cout << "You have entered " << currUsername << ". Would you like to proceed? (Y/N): ";
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //if confirmed, open the file and call loginHandler, if not, generate an error
        if (confirm == 'y' || confirm == 'Y') {

            inFile.open(currUsername);
            loginHandler();
            return;
        }
        else throw(confirm);

    }
    //if input is incorrect or confirmation denied, retry login
    catch (char) {
        system("CLS");
        cout << "Confirmation Failed!\n";
        login();
    }


    system("CLS");
}

//reads users information from their file 
void loginHandler() {
    try {
        //if file is empty, set the current level to zero
        if (inFile.peek() == EOF) throw (currLevel);
        inFile >> currLevel;
    }
    catch (int) {
        currLevel = 0;
    }

    inFile.close();
}

//save user data and close the program
void quit() {
    outFile.open(currUsername);
    outFile << currLevel;
    outFile.close();
    exit(EXIT_SUCCESS);

}