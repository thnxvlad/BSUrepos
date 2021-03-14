#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

string q[100];
int begin_ = 0, end_ = 0;

void add(string& s)
{
	q[end_++] = s;
}

void del()
{
	begin_++;
	cout << "OK\n";
}

void clean()
{
	for (int i = 0; i <= end_ - begin_; i++)
		q[i] = q[begin_ + i];
	end_ = end_ - begin_ - 1;
	begin_ = 0;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ifstream fin("input.txt");
	ofstream fout("input.txt");

	string s;
	while (fin >> s) add(s);
	
	while (true)
	{
		int type; cin >> type;
		if (type == 1)
		{
			cin >> s;
			add(s);
		}
		else if (type == 2) del();
		else
		{
			for (int i = begin_; i < end_; i++)
				fout << q[i] << " ";
			return 0;
		}
		if (begin_ > 1)
			clean();
	}
}