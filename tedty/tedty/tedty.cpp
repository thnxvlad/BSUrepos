
#include <iostream>

using namespace std;

struct item
{
    int val;
};

struct tree
{
    item* top = NULL;
    void func(int x, item** curr);
};

int main()
{
    tree tr;
    tr.func(5, &tr.top);
    cout << tr.top -> val;
}

void tree::func(int x, item** curr)
{
    if (*curr == NULL)
    {
        *curr = new item;
        (*curr)->val = x;
    }
}
