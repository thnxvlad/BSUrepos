#include "Polish_Notation.h"
#include "EStack.h"

int Polska_Not :: CalcExpression() const
{
	EStack <int> st;
	for (auto s : NotationData)
	{
		if (s[0] >= '0' && s[0] <= '9')
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
			else if (s == "%") x %= y;
			else if (s == "<<") x = x << y;
			else if (s == ">>") x = x >> y;
			else if (s == "&") x = x & y;
			else if (s == "^") x = x ^ y;
			else if (s == "|") x = x | y;
			st.push(x);
		}
	}
	return st.top();
}