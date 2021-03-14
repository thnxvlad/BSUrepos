#include <iostream>

using namespace std;

char* func(char* A, char d)
{
	int n = sizeof(A);

	bool s = false;
	int L = 0;
	for (int i = n - 1; i > -1; i--)
	{
		if (A[i] != d) s = true;
		if (A[i] == d)
		{
			L = i + 1;
			break;
		}
	}
	if (!s)
		return NULL;
	else
	{
		char* B = new char[n - L];
		for (int i = 0; i < n - L; i++)
		{
			B[i] = A[L];
			L++;
		}
		return B;
	}
	
}

int main()
{
	char s[7] = { 'a', 'b', ' ', 'c', 'd', 'd', 'f' };
	char d = ' ';
	int n = sizeof(func(s, d))/ sizeof(int);
	for (int i = 0; i < n; i++)
	{
		cout << func(s, d)[i];
	}

}