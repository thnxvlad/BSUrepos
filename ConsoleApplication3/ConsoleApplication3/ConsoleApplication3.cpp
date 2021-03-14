#include <iostream>

using namespace std;

const int INF = 2e9;

struct item
{
	item *next = NULL, *prev = NULL;
	int val = -1;
};

struct dynlist
{
	item *first = NULL, *last = NULL;
	void add_back(int x);
	void add_front(int x);
	void display();
	void replace(int x, int y);
	void delete_front();
	void bubble_sort();
};

int main()
{
	dynlist dl;
	while (true)
	{
		int type;
		cin >> type;
		if (type < 0)
			break;
		if (type == 1) // 1 - добавить элемент в конец
		{
			int x; cin >> x;
			dl.add_back(x);
		}
		if (type == 2) // 2 - вывести на экран
		{
			dl.display();
		}
		if (type == 3) // 3 - поменять значения 2-х элементов
		{
			int x, y; cin >> x >> y;
			dl.replace(x, y);
		}
		if (type == 4) // 4 - добавить элемент в начало
		{
			int x; cin >> x;
			dl.add_front(x);
		}
		if (type == 5) // 5 - удалить элемент в начале
		{
			dl.delete_front();
		}
		if (type == 6)
		{
			dl.bubble_sort();
		}
	}
}

void dynlist::add_back(int x)
{
	item* temp = new item;
	temp->next = NULL; temp->prev = last;
	temp->val = x;
	if (first == NULL)
	{
		first = last = temp;
		return;
	}
	last->next = temp;
	last = temp;
}

void dynlist::display()
{
	item* curr = first;
	while (curr)
	{
		cout << curr->val << ' ';
		curr = curr->next;
	}
	cout << '\n';
}

void dynlist::replace(int x, int y)
{
	item* curr = first, * item1 = NULL, * item2 = NULL;

	int index = 1;
	while (curr)
	{
		if (index == x || index == y)
		{
			if (item1 == NULL)
				item1 = curr;
			else
			{
				item2 = curr;
				break;
			}
		}
		curr = curr->next;
		index++;
	}

	int temp;
	temp = item1->val;
	item1->val = item2->val;
	item2->val = temp;
}

void dynlist::add_front(int x)
{
	item* temp = new item;
	temp->next = first; temp->prev = NULL;
	temp->val = x;
	if (first == NULL)
	{
		first = last = temp;
		return;
	}
	first->prev = temp;
	first = temp;
}

void dynlist::delete_front()
{
	item* temp = first;
	first = first->next;
	first->prev = NULL;
	delete temp;
}

void dynlist::bubble_sort()
{
	while (true)
	{
		int continue_cond = false;
		item* curr = first;
		while (curr)
		{
			if (curr == last) break;
			if (curr->val > curr->next->val)
			{
				swap(curr->val, curr->next->val);
				continue_cond = true;
			}
			curr = curr->next;
		}
		if (!continue_cond) break;
	}
}