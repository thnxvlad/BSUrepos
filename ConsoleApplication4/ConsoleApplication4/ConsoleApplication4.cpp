#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int ConsoleReaderInteger()
{
	string s; cin >> s;
	int x = 0, mn = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		x += int(s[i] - '0') * mn;
		mn *= 10;
	}
	return x;
}

bool IsNonIncreasingOrder(int n)
{
	int prev = -1;
	n = abs(n);
	while (n > 0)
	{
		int x = n % 10;
		if (prev > x) return false;
		prev = x;
		n /= 10;
	}
	return true;
}
template<typename T>
vector<T> FindItems(T a, T b)
{
	vector<T> res;
	for (int i = a; i <= b; i++)
		if (IsNonIncreasingOrder(i)) res.push_back(i);
	return res;
}
template<typename T>
void FileWriter(vector<T> vec, int m)
{
	ofstream fout("output_file.txt");
	for (int i = 0; i < vec.size(); i++)
	{
		fout << setw(10)<< right << vec[i];
		(i + 1) % m == 0 ? fout << '\n' : fout << ' ';
	}
}
template<typename T>
vector<T> SortCollection(vector<T> a, int n)
{
	auto comp = [](int a, int b, int n)
	{
		a = stoi(to_string(a).substr(0, n));
		b = stoi(to_string(b).substr(0, n));
		if (a > b) return true;
		else return false;
	};
	int size = a.size();
	for(int i  = 0; i < size - 1; i++)
		for(int j = i + 1; j < size; j++)
			if(!comp(a[i], a[j], n))
				swap(a[i], a[j]);
	return a;
}
int main()
{
	int k = ConsoleReaderInteger();
	int n = ConsoleReaderInteger();
	FileWriter(FindItems(-k, k), n);
}