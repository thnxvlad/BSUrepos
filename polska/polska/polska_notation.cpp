#include "polska_notation.h"

int Polska_Not::CalcExpression(const vector<string>& Data) const
{
	stack <int> st;
	for (auto s : Data)
	{
		if (s != "+" && s != "-" && s != "*" && s != "/")
		{
			int x = stoi(s);
			st.push(x);
		}
		else
		{
			int y = st.top(); st.pop();
			int x = st.top(); st.pop();
			if (s == "+") x += y;
			else if (s == "-") x -= y;
			else if (s == "*") x *= y;
			else if (s == "/") x /= y;
			st.push(x);
		}
	}
	return st.top();
}

vector<string> Polska_Not::StrToNotation(string& s)const
{
	s += ' ';
	string st;
	vector<string> result;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '(' || s[i] == ')')
			st += ' ' + s[i] + ' ';
		else if (s[i] >= '0' && s[i] <= '9' && (s[i - 1] <= '0' || s[i - 1] >= '9'))
			st += ' ' + s[i];
		else if ((s[i] >= '0' && s[i] <= '9' && (s[i + 1] <= '0' || s[i + 1] >= '9')))
			st += s[i] + ' ';
		else st += s[i];

	int pos = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' && i - pos > 0)
		{
			result.push_back(s.substr(pos, i - pos));
		}
		if(s[i] == ' ') pos = i + 1;
	}
	pos = 0;
	return StrToNotation(result, pos);
}

vector<string> Polska_Not::StrToNotation(vector<string> &vec, int& pos)const
{
	stack<string> sign;
	vector<string> result;
	for (; pos <= vec.size(); pos++)
	{
		if (vec[pos] == "(")
		{
			for (auto z : StrToNotation(vec, ++pos))
			{
				result.push_back(z);
			}
		}
		else if (vec[pos] == ")")
		{
			pos++;
			return result;
		}
		if (vec[pos][0] >= '0' && vec[pos][0] <= '9')
		{

		}

	}
	return result;
}

string Polska_Not::OutputNotation(const vector<string>& Data) const
{

	return string();
}
