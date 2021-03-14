#pragma once
#ifndef EStack_H;
#define EStack_H

using namespace std;

template<typename T>
struct Item
{
    T value;
    Item<T>* next;
    Item(T x, Item<T>* ptr) : value(x), next(ptr) {}
};

template<typename T>
class EStack
{
private:
    Item<T>* _top;
public:
    EStack() : _top(nullptr) {}
    void push(T x)
    {
        _top = new Item<T>(x, _top);
    }
    T top()
    {
        return _top->value;
    }
    bool empty()
    {
        return _top == nullptr ? true : false;
    }
    void pop()
    {
        Item<T>* temp = _top->next;
        delete _top;
        _top = temp;
    }
};
#endif