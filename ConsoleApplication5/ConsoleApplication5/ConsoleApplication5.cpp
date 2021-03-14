#include <iostream>

using namespace std;

const int f = 1000;

int main()
{
    int a[2001] = { 0, };
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a[x + f]++;
    }
    for (int i = 0; i < 2001; i++)
        if(a[i] > 0)
        cout << i - f << " : " << a[i] << '\n';
}
