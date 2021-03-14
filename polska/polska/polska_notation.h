#pragma once
#ifndef polska_notation   // TODO все імена давать на корректном англійском языке
#define polska_notation
#include <string>
#include <vector>
#include <map>
#include "EStack.h"

using namespace std;

class Polska_Not
{
private:
	vector<string> NotationData;   //TODO G style
	map<string, int> Priority
	{
		{"*", 5},
		{"/", 5},
		{"%", 5},
		{"+", 6},
		{"-", 6},
		{"<<", 7},
		{">>", 7},
		{"&", 10},
		{"^", 11},
		{"|", 12},
		{"nan", 13}
	};
public:
	int CalcExpression() const;

	void StrToNotation(string &s);

	vector<string> StrToVector(string s);

	vector<string> VectorToNotation(const vector<string>& vec, int& pos);
	
	string GetNotation() const;
};

#endif
