#pragma once
#include <string>
using namespace std;

class Grid
{
public:
	const int Length;
	const string Face;
	int totalTerms;
	string *gameGrid;		// Grid size for Easy is 4X4, Moderate is 6X6, Difficult is 8X8

public:
	~Grid();
	Grid(const int l, const string f);
	void GameGrid(int totalTerms);
	void PrintGameGrid(int choice, string unhide);
	virtual void Print() const; // this is virtual method
};

class EasyGrid : public Grid
{
public:
	EasyGrid(string face) : Grid(4, face) { }
	void Print() const;
};

class MediumGrid : public Grid
{
public:
	MediumGrid(string face) : Grid(6, face) { }
	void Print() const;
};

class DifficultGrid : public Grid
{
public:
	DifficultGrid(string face) : Grid(8, face) { }
	void Print() const;
};
