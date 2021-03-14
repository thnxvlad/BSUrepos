#include <iostream>
#include "containers.h"

using namespace containers;
using namespace std;

int main()
{
    QueueLinkedList<int> A{ 5, 6, 7 }, B{5, 6 ,7};
    if (A == B) cout << 4;

}

