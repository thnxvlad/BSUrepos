#include<iostream>
#include"queue_linked_list.h"

using namespace std;

int main()
{
	QueueLinkedList<int> Q{ 1, 2, 2, 3 }, F{1, 2, 3, 3, 5};
	if (Q == F) cout << 324;
	
}