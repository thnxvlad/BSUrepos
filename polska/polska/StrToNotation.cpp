#include "Polish_Notation.h"

void Polska_Not::StrToNotation(string &s)
{
	int pos = 0;
	NotationData = VectorToNotation(StrToVector(s), pos);
}

