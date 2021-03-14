#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack <int> st;

	while (true)
	{
		string s;
		cin >> s;
		if (s == "end") break;
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
	cout << st.top();
	return 0;
}