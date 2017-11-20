#include "stdafx.h"
#include "Theme.h"


Theme::Theme(int input, string(&theme)[51])
{
	switch (input) {
	case 1:
		infile.open("USstates.txt", ios::in);
		face = "US State";
		break;
	default :
		infile.open("ElementSymbols.txt", ios::in);
		face = "Elements";
	}

	if (!infile) {
		cout << "Error opening file for User Choice:" << input << "\n";
	}
	cout << "File " << input << " opened \n";

	for (int i = 0; i <= 50; i++) {
		infile >> s1;
		theme[i] = format20(s1);
		

	}
	infile.close();
}

string Theme::format20(string s)
{
	int len = 2;	
	int padSize = (20 - len) / 2;
	string padding = "";
	for (int i = 0; i < padSize; i++) padding += " ";

	return padding + s + padding;
}
