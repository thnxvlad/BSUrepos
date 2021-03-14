#include <iostream>

using namespace std;

struct item
{
    item* right, * left;
    int value;
};

item* NullPtr = NULL;

struct bin_tree {
    item* top = NULL; int mh = -1;
    void add(int value, item** curr, item** prev);
    void find_item(int value, item** curr);
    void clean(item** curr);
    void max_height(item** curr, int height);
};

int main()
{
    bin_tree tree;
    while (true)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int x; cin >> x;
            tree.add(x, &tree.top, &NullPtr);
            continue;
        }
        if (type == 2)
        {
            int x; cin >> x;
            tree.find_item(x, &tree.top);
            continue;
        }
        if (type == 3)
        {
            tree.max_height(&tree.top, 0);
            cout << tree.mh << '\n';
        }
        if (type == -1)
        {
            break;
        }
    }
    tree.clean(&tree.top);
}
void bin_tree::add(int val, item** curr, item** prev)
{
    if (*curr == NULL)
    {
        *curr = new item;
        (*curr)->value = val;
        (*curr)->left = (*curr)->right = NULL;

        if (*prev != NULL)
        {
            if ((*prev)->value > val)
                (*prev)->left = *curr;
            else (*prev)->right = *curr;
        }
        return;
    }
    if (val > (*curr)->value) add(val, &(*curr)->right, &*curr);
    else add(val, &(*curr)->left, &*curr);
}

void bin_tree::find_item(int val, item** curr)
{
    if (*curr == NULL) {
        cout << "Not Found\n";
        return;
    }
    if (val > (*curr)->value) find_item(val, &(*curr)->right);
    else if (val < (*curr)->value) find_item(val, &(*curr)->left);
    else
    {
        cout << "Found\n";
        return;
    }
}

void bin_tree::clean(item** curr)
{
    if (*curr == NULL) return;
    clean(&(*curr)->left);
    clean(&(*curr)->right);
    delete* curr;
}

void bin_tree::max_height(item** curr, int height)
{
    if (*curr != NULL)
        height++;
    else return;
    mh = mh < height ? mh = height : mh = mh;
    max_height(&(*curr)->left, height);
    max_height(&(*curr)->right, height);
}