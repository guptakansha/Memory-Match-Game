#include "stdafx.h"
#include "MemoryMatchGame.h"
#include <string>
#include <iostream>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <Windows.h>   //sleep


using namespace std;


MemoryMatchGame::MemoryMatchGame()
{

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	cout << endl << endl << endl << "\t"; // start 3 down, 1 tabs, right
	SetConsoleTextAttribute(console, 30); // set color for the next print
	cout << "**************MEMORY MATCH GAME STARTING*****************" << endl;
	cout << "************** CHOOSE YOUR THEME FOR THE GAME *****************" << endl;
	cout << "\tChoices : [0] for Elements, and [1] for US States. Type 0 or 1 \t :";
	cin >> userTheme;

	Theme gametheme(userTheme, themeArray);
	cout << endl << endl << endl << "\t"; // start 3 down, 1 tabs, right

	cout << "************** CHOOSE YOUR GRID LEVEL *****************" << endl;
	cout << "\tChoices : [0] for EASY (4X4), [1] for Moderate (6X6), and [2] for Difficult (8X8),  Type 0, 1 or 2 \t :";
	cin >> userLevel;
	cout << endl << endl << endl << "\t"; // start 3 down, 1 tabs, right

	cout << "************** CHOOSE YOUR FLIP SPEED *****************" << endl;
	cout << "\tChoices : [0] for SLOW (6 seconds), [1] for Moderate (4 seconds), and [2] for Fast (2 secconds),  Type 0, 1 or 2 \t :";
	cin >> flipSpeed;

	switch (userLevel) {
	case 1:
		grid = new MediumGrid(gametheme.GetFace()); createMediumGame();
		break;
	case 2:
		grid = new DifficultGrid(gametheme.GetFace()); createDifficultGame();
		break;
	default:
		grid = new EasyGrid(gametheme.GetFace()); createEasyGame();
	}

	switch (flipSpeed) {
	case 1:
		seconds= 4000; 
		break;
	case 2:
		seconds=2000; 
		break;
	default:
		seconds = 6000;
	}
	
	system("pause");
}

void MemoryMatchGame::createEasyGame()
{
	choiceValidator = new bool[16];
	array<int, 16> a;
	wordIndex = new int[16];
	for (unsigned int i = 0; i < 8; i++) {
		a[i] = foo[i]; a[i + 8] = a[i];
	}
	shuffle(a.begin(), a.end(), default_random_engine(seed));
	//printf("\nShuffled game\n");
	for (unsigned int i = 0; i < 16; i++) {
		choiceValidator[i] = false;
		wordIndex[i] = a[i];
		//printf("%d\t", wordIndex[i]);
	}
}

void MemoryMatchGame::createMediumGame()
{
	choiceValidator = new bool[36];
	array<int, 36> a;
	wordIndex = new int[36];
	for (unsigned int i = 0; i < 18; i++) {
		a[i] = foo[i]; a[i + 18] = a[i];
	}
	shuffle(a.begin(), a.end(), default_random_engine(seed));
	//printf("\nShuffled game\n");
	for (unsigned int i = 0; i < 36; i++) {
		choiceValidator[i] = false;
		wordIndex[i] = a[i];
		//printf("%d\t", wordIndex[i]);
	}
}

void MemoryMatchGame::createDifficultGame()
{
	choiceValidator = new bool[64];
	array<int, 64> a;
	wordIndex = new int[64];
	for (unsigned int i = 0; i < 32; i++) {
		a[i] = foo[i]; a[i + 32] = a[i];
	}
	shuffle(a.begin(), a.end(), default_random_engine(seed));
	//printf("\nShuffled game\n");
	for (unsigned int i = 0; i < 64; i++) {
		choiceValidator[i] = false;
		wordIndex[i] = a[i];
		//printf("%d\t", wordIndex[i]);
	}
}

void MemoryMatchGame::start()
{
	int validRange = grid->totalTerms;
	int possibleScore = validRange / 2;
	int score = 0;
	int previousChoice = -1;
	double duration;
	clock_t start = clock();
	while ( inputValidator(validRange) ) {
		unsigned int choice = userInput - 1;
		if (previousChoice != -1 && judgeChoice(choice, previousChoice)) {
			score++;
			previousChoice = -1;
		}
		else {
			grid->PrintGameGrid(choice, getWord(choice));
			previousChoice = choice;
			Sleep(seconds);
		}
		grid->PrintGameGrid(-1, "");
		duration = (clock() - start); //clocks per second
		cout << endl << endl << "Current Score: " << score << "/"<< possibleScore<< "correct matches. Elasped Time: " << duration/1000 <<"seconds" << endl;

	}
	duration = (clock() - start) / CLOCKS_PER_SEC;
	SetConsoleTextAttribute(console, 30); // set color for the next print
	cout << endl << endl << endl << "\t**************MEMORY MATCH GAME ENDED **************************************" << endl;
	cout << endl << endl << "\tFinal Score: " << score << " correct matches. Elasped Time " << duration << " seconds";
}

bool MemoryMatchGame::inputValidator(int validRange)
{
bool isValid = false;
cout << endl << endl;
cout << " ********GAME TIMER ON, YOU CAN QUIT THE MEMORY MATCH GAME AT ANY TIME BY selecting 0 *******  " << endl;
cout << endl << endl;
do {
	cout << "Choose from the numbers available in your Game Grid ";
	cin >> userInput;

	while (!cin) {
		cout << "That was not a number, please enter a valid number from grid above: ";
		cin.clear();
		cin.ignore();
		cin >> userInput;
	}


	if (userInput >= 1 && userInput <= validRange && !choiceValidator[userInput - 1]) {
		isValid = true;
	}
	else {

		cout << "Enter only the numbers available in Game Grid. If you'd like to quit the game, enter 0.";
	}
} while (!isValid && userInput != 0);
return isValid;
}

bool MemoryMatchGame::judgeChoice(int userInput, int previousInput)
	{
	int match = false;

	if (wordIndex[userInput] == wordIndex[previousInput] && userInput!= previousInput) {
		grid->gameGrid[userInput] = getWord(userInput);    //populating game grid to make the words visible
		grid->gameGrid[previousInput] = getWord(previousInput);//also populating game grid to make the words visible
		match = true;
		choiceValidator[userInput] = true;// corresponding grid number can't be selected anymore
		choiceValidator[previousInput] = true;// corresponding grid number can't be selected anymore
	}

	return match;
}

string MemoryMatchGame::getWord(int choice)
{
		//string result = "Error";
		int index = wordIndex[choice];
	
		return themeArray[index];
}
