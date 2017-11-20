#include "stdafx.h"
#include "Grid.h"
#include <conio.h>//changes color
#include <Windows.h>
#include <iostream>



Grid::Grid(const int l, const string f) : Length(l), Face(f)
{
	totalTerms = pow(Length, 2);
	GameGrid(totalTerms);
	PrintGameGrid(-1, "");
}

void Grid::GameGrid(int totalTerms)
{
	gameGrid = new string[totalTerms];
	for (int i = 0; i < totalTerms; i++) {
		string loc = (i < 9) ? "[" + to_string(i + 1) + " ]" : "[" + to_string(i + 1) + "]"; // formatted numbers
		string pad = "    ";			// four spaces padding
		gameGrid[i] = loc + pad + Face + pad;
	}
}

void Grid::PrintGameGrid(int choice, string unhide)
{
	system("cls");
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
	Print();
	cout << endl << endl << endl << "\t"; // start 3 down, 1 tabs, right
	SetConsoleTextAttribute(console, 30); // set color for the next print
	for (int i = 0; i < Length; i++) {

		for (int j = 0; j < Length; j++) {
			int gridlocation = j + i*Length;
			if (gridlocation == choice) {
				SetConsoleTextAttribute(console, 15); // set color for the next print
				cout << unhide << "      ";
				SetConsoleTextAttribute(console, 30); // set color for the next print
			}
			else cout << gameGrid[gridlocation];
		}
		cout << endl << "\t"; // Start next line, 1 down, 1 tabs over
		for (int space = 0; space < 20 * Length; space++) cout << " ";
		cout << endl << "\t";
		for (int space = 0; space < 20 * Length; space++) cout << " ";
		cout << endl << "\t";

	}
	SetConsoleTextAttribute(console, 15); // set color to black background, white chars
}

void Grid::Print() const
{
	printf("\n\nI'm a Grid Game of %d hidden terms\n", totalTerms / 2);
}

Grid::~Grid()
{
}

void EasyGrid::Print() const
{
	cout << endl << endl << "\t"; // start 2 down, 1 tabs, right
	printf("Level of difficulty : EASY & SLOW\n\t");
	printf("I'm a Memory match Game with eight hidden word pairs.");
}

void MediumGrid::Print() const
{
	cout << endl << endl << "\t"; // start 2 down, 1 tabs, right
	printf("Level of difficulty : MEDIUM\n\t");
	printf("I'm a Memory match Game with eighteen hidden word pairs.");
}

void DifficultGrid::Print() const
{
	cout << endl << endl << "\t"; // start 2 down, 1 tabs, right
	printf("Level of difficulty : DIFFICULT & FAST\n\t");
	printf("I'm a Memory match Game with thirtytwo hidden word pairs.");
}
