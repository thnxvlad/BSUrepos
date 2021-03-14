#include <iostream>

using namespace std;

template<typename T>
struct Item
{
    T value;
    Item<T>* next;
};

template<typename T>
Item<T>* Make_Item(T x)
{
    Item<T>* temp = new Item<T>;
    temp->value = x;
    temp->next = NULL;
    return temp;
};

template<typename T>
class MySt
{
public:
    Item<T>* first;
    MySt() { first = NULL; }
    void push(T x)
    {
        if (first == NULL)
            first = Make_Item(x);
        else
        {
            Item<T> *temp = first;
            first = Make_Item(x);
            first->next = temp;
        }
    }
    T top()
    {
        if (empty())
        {
            cout << "Stack is empty!\n";
            return NULL;
        };
        return first->value;
    }
    bool empty()
    {
        if (first == NULL)
            return true;
        return false;
    }
    void pop()
    {
        if (empty()) return;
        Item<T>* temp = first->next;
        delete first;
        first = temp;
    }
};

int main()
{
    MySt<int> q;
    while (true)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int x; cin >> x;
            q.push(x);
        }
        if (type == 2)
        {
            q.pop();
        }
        if (type == 3)
        {
            cout << q.top() << '\n';
        }
        if (type == -1)
        {
            return 0;
        }
    }
}
