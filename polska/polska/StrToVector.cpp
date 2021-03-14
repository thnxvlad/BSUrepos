#include "Polish_Notation.h"

vector<string> Polska_Not::StrToVector(string s)
{
	s = " " + s + " ";
	string st;
	vector<string> result;
	for (int i = 0; i < s.length(); i++)    // добавляет пробелы между арифметическими объектами, чтобы позже я смог лекго обработать и поместить в вектор
		if (s[i] == '(' || s[i] == ')')
			st = st + " " + s[i] + " ";
		else if (s[i] >= '0' && s[i] <= '9' && (s[i - 1] <= '0' || s[i - 1] >= '9'))
			st = st + " " + s[i];
		else if ((s[i] >= '0' && s[i] <= '9' && (s[i + 1] <= '0' || s[i + 1] >= '9')))
			st = st + s[i] + " ";
		else st = st + s[i];

	int pos = 0;
	for (int i = 0; i < st.length(); i++)  // помещаю в вектор с помощью обычного алгоритма деления на слова
	{
		if (st[i] == ' ' && i - pos > 0)
		{
			result.push_back(st.substr(pos, i - pos));
		}
		if (st[i] == ' ') pos = i + 1;
	}
	return result;
}