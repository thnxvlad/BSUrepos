#include "Polish_Notation.h"

string Polska_Not :: GetNotation() const
{
	string s = "";
	for (auto z : NotationData)
		s = s + z + " ";
	return s;
}