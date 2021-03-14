#pragma once
#ifndef BI_DIRECTIONAL_LIST_ON_ARRAY_H
#define BI_DIRECTIONAL_LIST_ON_ARRAY_H
#include <initializer_list>
#include <exception>
#include <cassert>
#include <vector>
#include "containers.h"
using namespace std;

template<typename T>
class BiDirectionalListOnArray
{
private:
	template<typename T>
	struct Node
	{
	public:
		T value;
	private:
		Node<T>* next, * prev;
		Node() : next(nullptr), prev(nullptr) {}
		Node(T x) : value(x), next(nullptr), prev(nullptr) {}
		Node(T x, Node<T>* next_, Node<T>* prev_) : value(x), next(next_), prev(prev_) {}
		friend class BiDirectionalListOnArray;
	};
public:
	Node<T> * Front_, * Back_;
	BiDirectionalListOnArray() : Front_(nullptr), Back_(nullptr) {};
	BiDirectionalListOnArray(initializer_list<T>& List);
	BiDirectionalListOnArray(BiDirectionalListOnArray<T>& A);

    void Clear();

	T* Front()
	{
		return &Front_->value;
	}
	T* Back()
	{
		return &Back_->value;
	}
	int Size();
	bool IsEmpty();

	void PushBack(const T& value);
	void PushBack(T&& value);

	void PushFront(T& value);
	void PushFront(T&& value);

	void PopFront();
	void PopBack();

	void InsertBefore(Node<T>* element, const T& value)
	{
		Node<T>* temp = element->prev;
		temp->next = new Node<T>(value, temp->next, element);
		element->prev = temp->next;
	}
	void InsertBefore(Node<T>* element, const T&& value)
	{
		Node<T>* temp = element->prev;
		temp->next = new Node<T>(move(value), temp->next, element);
		element->prev = temp->next;
	}
	void InsertAfter(Node<T>* element, const T& value)
	{
		Node<T>* temp = element->next;
		temp->prev = new Node<T>(value, temp->prev, element);
		element->next = temp->prev;
	}
	void InsertAfter(Node<T>* element, const T&& value)
	{
		Node<T>* temp = element->next;
		temp->prev = new Node<T>(move(value), temp->prev, element);
		element->next = temp->prev;
	}
	void Erase(Node<T>* element)
	{
		Node<T> *temp1 = element->prev, * temp2 = element->next;
		delete element;
		temp1->next = temp2;
		temp2->prev = temp1;
	}

	vector<T> ToVector();

	T* operator[] (int Index)
	{
		assert(Index <= Size());
		assert(Index > 0);
		int Pos = 0;
		Node<T>* temp = Front_;
		while (temp)
		{
			Pos++;
			if (Pos == Index)
				return &temp->value;
			temp = temp->next;
		}
	}

};
#endif
