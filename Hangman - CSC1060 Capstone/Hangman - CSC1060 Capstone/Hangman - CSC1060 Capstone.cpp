
/* 
Austin Lammers
12/10/22
M5 Final Capstone Project
*/

/*
File is organized as follows:

TOTAL GAMES
TOTAL WINS
TOTAL LOSSES
CHARACTERS GUESSED CORRECTLY
TOTAL CHARACTERS GUESSED

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Header.h"
#include <string>



using namespace std;
//variables, Requirement 4
//array of all the statistics, Requirement 5
string statistics[5] = {"0","0","0","0","0"};
//the list of all the words that can be used in the game, Requirement 5.
string WORDS[852] = {"able","about","account","acid","across","act","addition","adjustment","advertisement","after","again","against","agreement","air","all","almost","among","amount","amusement","and","angle","angry","animal","answer","ant","any","apparatus","apple","approval","arch","argument","arm","army","art","as","at","attack","attempt","attention","attraction","authority","automatic","awake","baby","back","bad","bag","balance","ball","band","base","basin","basket","bath","be","beautiful","because","bed","bee","before","behaviour","belief","bell","bent","berry","between","bird","birth","bit","bite","bitter","black","blade","blood","blow","blue","board","boat","body","boiling","bone","book","boot","bottle","box","boy","brain","brake","branch","brass","bread","breath","brick","bridge","bright","broken","brother","brown","brush","bucket","building","bulb","burn","burst","business","but","butter","button","by","cake","camera","canvas","card","care","carriage","cart","cat","cause","certain","chain","chalk","chance","change","cheap","cheese","chemical","chest","chief","chin","church","circle","clean","clear","clock","cloth","cloud","coal","coat","cold","collar","colour","comb","come","comfort","committee","common","company","comparison","competition","complete","complex","condition","connection","conscious","control","cook","copper","copy","cord","cork","cotton","cough","country","cover","cow","crack","credit","crime","cruel","crush","cry","cup","cup","current","curtain","curve","cushion","damage","danger","dark","daughter","day","dead","dear","death","debt","decision","deep","degree","delicate","dependent","design","desire","destruction","detail","development","different","digestion","direction","dirty","discovery","discussion","disease","disgust","distance","distribution","division","do","dog","door","doubt","down","drain","drawer","dress","drink","driving","drop","dry","dust","ear","early","earth","east","edge","education","effect","egg","elastic","electric","end","engine","enough","equal","error","even","event","ever","every","example","exchange","existence","expansion","experience","expert","eye","face","fact","fall","false","family","far","farm","fat","father","fear","feather","feeble","feeling","female","fertile","fiction","field","fight","finger","fire","first","fish","fixed","flag","flame","flat","flight","floor","flower","fly","fold","food","foolish","foot","for","force","fork","form","forward","fowl","frame","free","frequent","friend","from","front","fruit","full","future","garden","general","get","girl","give","glass","glove","go","goat","gold","good","government","grain","grass","great","green","grey","grip","group","growth","guide","gun","hair","hammer","hand","hanging","happy","harbour","hard","harmony","hat","hate","have","he","head","healthy","hear","hearing","heart","heat","help","high","history","hole","hollow","hook","hope","horn","horse","hospital","hour","house","how","humour","I","ice","idea","if","ill","important","impulse","in","increase","industry","ink","insect","instrument","insurance","interest","invention","iron","island","jelly","jewel","join","journey","judge","jump","keep","kettle","key","kick","kind","kiss","knee","knife","knot","knowledge","land","language","last","late","laugh","law","lead","leaf","learning","leather","left","leg","let","letter","level","library","lift","light","like","limit","line","linen","lip","liquid","list","little","living","lock","long","look","loose","loss","loud","love","low","machine","make","male","man","manager","map","mark","market","married","mass","match","material","may","meal","measure","meat","medical","meeting","memory","metal","middle","military","milk","mind","mine","minute","mist","mixed","money","monkey","month","moon","morning","mother","motion","mountain","mouth","move","much","muscle","music","nail","name","narrow","nation","natural","near","necessary","neck","need","needle","nerve","net","new","news","night","no","noise","normal","north","nose","not","note","now","number","nut","observation","of","off","offer","office","oil","old","on","only","open","operation","opinion","opposite","or","orange","order","organization","ornament","other","out","oven","over","owner","page","pain","paint","paper","parallel","parcel","part","past","paste","payment","peace","pen","pencil","person","physical","picture","pig","pin","pipe","place","plane","plant","plate","play","please","pleasure","plough","pocket","point","poison","polish","political","poor","porter","position","possible","pot","potato","powder","power","present","price","print","prison","private","probable","process","produce","profit","property","prose","protest","public","pull","pump","punishment","purpose","push","put","quality","question","quick","quiet","quite","rail","rain","range","rat","rate","ray","reaction","reading","ready","reason","receipt","record","red","regret","regular","relation","religion","representative","request","respect","responsible","rest","reward","rhythm","rice","right","ring","river","road","rod","roll","roof","room","root","rough","round","rub","rule","run","sad","safe","sail","salt","same","sand","say","scale","school","science","scissors","screw","sea","seat","second","secret","secretary","see","seed","seem","selection","self","send","sense","separate","serious","servant","sex","shade","shake","shame","sharp","sheep","shelf","ship","shirt","shock","shoe","short","shut","side","sign","silk","silver","simple","sister","size","skin","skirt","sky","sleep","slip","slope","slow","small","smash","smell","smile","smoke","smooth","snake","sneeze","snow","so","soap","society","sock","soft","solid","some","son","song","sort","sound","soup","south","space","spade","special","sponge","spoon","spring","square","stage","stamp","star","start","statement","station","steam","steel","stem","step","stick","sticky","stiff","still","stitch","stocking","stomach","stone","stop","store","story","straight","strange","street","stretch","strong","structure","substance","such","sudden","sugar","suggestion","summer","sun","support","surprise","sweet","swim","system","table","tail","take","talk","tall","taste","tax","teaching","tendency","test","than","that","the","then","theory","there","thick","thin","thing","this","thought","thread","throat","through","through","thumb","thunder","ticket","tight","till","time","tin","tired","to","toe","together","tomorrow","tongue","tooth","top","touch","town","trade","train","transport","tray","tree","trick","trouble","trousers","true","turn","twist","umbrella","under","unit","up","use","value","verse","very","vessel","view","violent","voice","waiting","walk","wall","war","warm","wash","waste","watch","water","wave","wax","way","weather","week","weight","well","west","wet","wheel","when","where","while","whip","whistle","white","who","why","wide","will","wind","window","wine","wing","winter","wire","wise","with","woman","wood","wool","word","work","worm","wound","writing","wrong","year","yellow","yes","yesterday","you","young","Bernhard","Breytenbach","Android"};
//the selected word to guess
string gameWord;
//input file variable
ifstream inputFile;
//output file variable
ofstream outputFile;
//file I/O related vars, Requirement 4
//total number of games ever played
int games;
//total number of words correctly guessed
int wins;
//total number of fails
int losses;
//total number of characters correctly guessed
int correctchars;
//total number of characters shown to the player
int totalchars;
//Characters guessed during the game
char guessedChars[26];
//array if the indecies of the game word in which the guessed letter matched the particular letter in the word
int index[20];
//array that stores the state of the gameboard
char gameBoard[20];
//number of incorrectly guessed letters
int fails = 0;

int main()
{
	
	getInfo();
	menu();
	
	return 0;
}

//open main menu, present choice between playing game, viewing stats, exiting
void menu() {


	//Requirement 8 and 3
	int choice;
	cout << "Welcome to Hangman! Would you like to Play a game or view your statistics?\n1. PLAY HANGMAN\n2. VIEW STATISTICS\n3. QUIT" << endl;
	cin >> choice;
	if (choice == 1) {

		startGame();
	}
	else if (choice == 2) {

		startStats();
	}
	else if (choice == 3) {


	}
	else {
		cout << "Invalid Input\n";
		menu();
	}
}

//start the game, pick game word, display blank gameboard
void startGame() {
	fails = 0;
	
	//clear guessedChars array, Requirement 7
	for (int i = 0; i < 26; i++) {

		guessedChars[i] = ' ';
	}

	//clear gameboard, Requirement 7
	for (int i = 0; i < 20; i++) {

		gameBoard[i] = NULL;
	}



	int random;
	cout << "GAME STARTING...\n";
	srand(time(NULL));
	random = rand() % 852;
	//Requirement 5
	gameWord = WORDS[random];
	
	
	//print empty characters, Requirement 7
	for (int i = 0; i < gameWord.length(); i++) {

		gameBoard[i] = '_';
		
	}
	cout << gameBoard << "      Fails:" << fails << endl;
	takeInput();
	
}

//open stats page.
void startStats() {

	/*
	File is organized as follows:

	TOTAL GAMES
	TOTAL WINS
	TOTAL LOSSES
	CHARACTERS GUESSED CORRECTLY
	TOTAL CHARACTERS GUESSED


	*/
	cout << "STATS PAGE\n";

	//get current info
	getInfo();


	//Print all the stats with appropriate labels, Requirement 5, 7, and 9
	for (int i = 0; i < 5; i++) {
		switch (i)
		{
		case(0):
			cout << "TOTAL GAMES: " << statistics[i] << endl;
			break;
		case(1):
			cout << "TOTAL WINS: " << statistics[i] << endl;
			break;
		case(2):
			cout << "TOTAL LOSSES: " << statistics[i] << endl;
			break;
		case(3):
			cout << "CORRECT GUESSES: " << statistics[i] << endl;
			break;
		case(4):
			cout << "TOTAL GUESSES: " << statistics[i] << endl;
			break;

		}

	}
	//calculate additional statistics (W/L ratio, Correct % and average guesses per game.
	double wlratio = static_cast<double>(wins) / static_cast<double>(losses);
	double cgp = (static_cast<double>(correctchars) / static_cast<double>(totalchars)) * 100;
	cout << fixed << setprecision(4);
	cout << "WIN/LOSS RATIO: " << wlratio << endl;
	cout << fixed << setprecision(1);
	cout << "CORRECT GUESS PERCENTAGE: " << (cgp) << endl;
	cout << "AVERAGE GUESSES PER GAME: " << (static_cast<double>(totalchars) / static_cast<double>(games)) << endl;
	//await user input
	system("pause");
	main();
}
//accept input from user and check against gameWord
void takeInput() {

	int count = 0;
	char input = ' ';

	cout << "Enter a letter to guess\n";

	// handle white spaces, Requirement 9
	if (cin.peek() == '\n') {

		cin.ignore(1);
		cin.get(input);
	}
	else {
		cin.get(input);
		
	}
	totalchars++;

	//check each individual character against the users guess, Requirement 7 and 9
	for (int i = 0; i < gameWord.length(); i++) {

		if (gameWord[i] == input) {

			index[count] = i;
			count++;
			correctchars++;
			
		}
		
	}
	
	//if no letter matched, the letter is not in the word and the user has guessed incorrectly, Requirement 9
	if (count == 0) {

		cout << "Letter was not found in the word\n";
		guessedChars[fails] = input;
		fails++;
		checkGameFinish();
		takeInput();
		
	}
	else {

		updateGameboard(count, input);
	}
}

//clears the console window and displays the gamboard updated with the guessed letters inserted. Requirement 3
void updateGameboard(int num, char letter) {
	clearWindow();

	switch (fails)
	{
	case(0):
		cout << hangman0 << endl;
		break;
	case(1):
		cout << hangman1 << endl;
		break;
	case(2):
		cout << hangman2 << endl;
		break;
	case(3):
		cout << hangman3 << endl;
		break;
	case(4):
		cout << hangman4 << endl;
		break;
	case(5):
		cout << hangman5 << endl;
		break;
	case(6):
		cout << hangman6 << endl;
		break;
	case(7):
		cout << hangman7 << endl;
		break;
	}

	//populate gameboard with appropriate characters in their respective places
	for (int i = 0; i < num; i++) {

		gameBoard[index[i]] = letter;
	}

	//display gameboard
	cout << gameBoard << "      Fails:" << fails << endl << "Guesses: " << guessedChars << endl;
	if (!checkGameFinish()) {
		takeInput();
	}


	
	

}

//checks gameBoard for remaining underscores and if the max number or fails has been reached, Requirement 3, 7, and 9
bool checkGameFinish() {

	int count = 0;
	for (int i = 0; i < gameWord.length(); i++) {

		if (gameBoard[i] == '_') {

			count++;
		}
	}
	if (count == 0) {
		//the board is full
		cout << "Winner!\n";
		startEnd(true);
		return true;
	}
	else if (fails >= 7) {
		//too many fails
		cout << "You Lose!\n";
		startEnd(false);
		return true;
	}
	else {
		//game has yet to finish
		return false;
	}
}

//prints code to clear the console window.
void clearWindow() {

	cout << "\x1B[2J\x1B[H";
}


//asks user if they would like to play again or quit to menu at the end of the game. If yes then a new game is generated and if no then the program essentially restarts. 
//Requirement 3
void startEnd(bool winTrue) {
	string dec;
	
	games++;
	if (winTrue) {

		wins++;
	}
	else {
		losses++;
	}
	/*
File is organized as follows:

TOTAL GAMES
TOTAL WINS
TOTAL LOSSES
CHARACTERS GUESSED CORRECTLY
TOTAL CHARACTERS GUESSED


*/

	//Requirement 6
	outputFile.open("statistics.txt");
	outputFile << games << endl << wins << endl << losses << endl << correctchars << endl << totalchars;
	outputFile.close();
	


	cout << "Would you like to play Again (y/n)\n";
	cin >> dec;
	if (dec == "y") {
		startGame();

	}
	else if (dec == "n") {

		clearWindow();
		menu();
	}
	else {

		cout << "INVALID\n";
		menu();
	}

}

//get all the information from the stats file.
void getInfo() {
	//Requirement 6
	inputFile.open("statistics.txt");
	for (int i = 0; !inputFile.eof(); i++) {
		inputFile >> statistics[i];
	}
	inputFile.close();
	//Requirement 7 and 9
	for (int i = 0; i < 5; i++) {
		switch (i)
		{
		case(0):
			games = stoi(statistics[i]);

			break;
		case(1):
			wins = stoi(statistics[i]);

			break;
		case(2):
			losses = stoi(statistics[i]);

			break;
		case(3):
			correctchars = stoi(statistics[i]);

			break;
		case(4):
			totalchars = stoi(statistics[i]);

			break;

		}
	}

}