#include "Polish_Notation.h"
#include <iostream>

int main()
{
	Polska_Not Exp;
	string s;
	getline(cin, s);
	Exp.StrToNotation(s);
	cout << Exp.GetNotation() << '\n';
	cout << Exp.CalcExpression();
}
