#pragma once
#include <string>
#include <array>        // std::array
#include <chrono>       // std::chrono::system_clock
#include <conio.h>		//changes color
#include <Windows.h>
#include "Grid.h"
#include "Theme.h"
using namespace std;

class MemoryMatchGame
{
private:
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()

	string themeArray[51];
	int userTheme = 1;		// Two themes- 1 is Capitals, 0 is Symbols
	int userLevel = 0;
	int  flipSpeed=0;
	int seconds = 6000;			//Flipping speed using sleep duration
	Grid  *grid;				// Display time in seconds for Easy is 6, Moderate is 4, Difficult is 2
	int  *wordIndex;
	bool *choiceValidator;
	int userInput;
	array<int, 50> foo{ 50,31,22,3,14,5,41,26,37,18,45,9,40, 11,32,23,4,35,16,27,42,47,38,29,20,1,12,33,24,15,36,17,28,48,39,10,46,21,43,2,13,34,25,6,7,8,44,19,30,49 };
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();


public:

	MemoryMatchGame();
	void createEasyGame();
	void createMediumGame();
	void createDifficultGame();
	void start();

	/* **************************         Input Validator              ****************************************
	*  The input validator checks that number entered is within the valid range of the selected game grid.    *
	*  The choice validator is an array that is tracking all the inputs that are visible on the screen        *
	*   because they can no longer be chosen.																  *
	***********************************************************************************************************/
	bool inputValidator(int totalTerms);
	bool judgeChoice(int userInput, int previousInput); //check if user's current choice matches their previous choice
	string getWord(int choice);//matches the number entered to the theme elements  (and so gets the word)
	
};
