#pragma once
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
class Theme
{
private:
	string s1;
	ifstream infile;
	string face;
public:
	Theme(int input, string(&theme)[51]);
	string format20(string s);
	string GetFace(void) { return face; }
};
