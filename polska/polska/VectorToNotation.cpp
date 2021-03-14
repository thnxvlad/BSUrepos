#include "Polish_Notation.h"

vector<string> Polska_Not::VectorToNotation(const vector<string>& vec, int& pos)
{
	EStack<string> sign;
	vector<string> result;
	sign.push("nan");
	for (; pos < vec.size(); pos++)
	{
		if (vec[pos] == "(")
		{
			for (auto z : VectorToNotation(vec, ++pos))
			{
				if (z != "nan")
					result.push_back(z);
			}
		}
		else if (vec[pos] == ")")
		{
			break;
		}
		else if (vec[pos][0] >= '0' && vec[pos][0] <= '9')
		{
			result.push_back(vec[pos]);
		}
		else
		{
			if (!sign.empty() && Priority[vec[pos]] < Priority[sign.top()])
			{
				sign.push(vec[pos]);
				if (vec[pos + 1] != "(")
					result.push_back(vec[++pos]);
			}
			else
			{
				while (!sign.empty() && Priority[vec[pos]] >= Priority[sign.top()])
				{
					if (sign.top() != "nan")
						result.push_back(sign.top());
					sign.pop();
				}
				sign.push(vec[pos]);
			}

		}
	}
	while (!sign.empty())
	{
		if (sign.top() != "nan")
			result.push_back(sign.top());
		sign.pop();
	}
	return result;
}