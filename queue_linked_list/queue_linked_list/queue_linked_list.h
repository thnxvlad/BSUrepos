#pragma once
#include <initializer_list>
#include <cassert>
#include <vector>


namespace containers
{
	using namespace std;
	template<typename T>
	class QueueLinkedList
	{
		template<typename T>
		struct Node
		{
		public:
			T value;
		private:
			Node<T>* next;
			Node(T x) : value(x), next(nullptr) {}
			friend class QueueLinkedList;
		};
	public:
		Node<T>* Head, * Tail;
		QueueLinkedList() : Head(nullptr), Tail(nullptr) {};
		QueueLinkedList(const QueueLinkedList& Q) : Head(Q.Head), Tail(Q.Tail) {};
		QueueLinkedList& operator=(const QueueLinkedList& Q)
		{
			Head = Q.Head;
			Tail = Q.Tail;
		}
		QueueLinkedList(const initializer_list<T>& list) : Head(nullptr), Tail(nullptr)
		{
			for (auto X : list)
				Push(X);
		}

		int Size()
		{
			int Result = 0;
			Node<T>* temp = Head;
			while (temp)
			{
				Result++;
				temp = temp->next;
			}
			return Result;
		}
		bool IsEmpty()
		{
			return Head == nullptr ? true : false;
		}

		void Push(const T& value)
		{
			if (Head == nullptr) {
				Head = Tail = new Node<T>(value); return;
			}
			Tail->next = new Node<T>(value);
			Tail = Tail->next;

		}
		void Push(T&& value)
		{
			if (Head == nullptr) {
				Head = Tail = new Node<T>(move(value)); return;
			}
			Tail->next = new Node<T>(move(value));
			Tail = Tail->next;
		}
		void Pop()
		{
			if (IsEmpty()) {
				throw exception();
			}
			Node<T>* ptr = Head->next;
			delete Head;
			Head = ptr;
		}
		int Find(const T& value)
		{
			int Pos = 0;
			Node<T>* temp = Head;
			while (temp)
			{
				Pos++;
				if (temp->value == value)
				{
					return Pos;
				}
				temp = temp->next;
			}
			return -1;
		}
		vector<int> FindAll(const T& value)
		{
			vector<int> res;
			int Pos = 0;
			Node<T>* temp = Head;
			while (temp)
			{
				Pos++;
				if (temp->value == value)
					res.push_back(Pos);
				temp = temp->next;
			}
			return res;
		}

		Node<T> operator[] (int Index)
		{
			assert(Index <= Size());
			assert(Index > 0);
			int Pos = 0;
			Node<T>* temp = Head;
			while (temp)
			{
				Pos++;
				if (Pos == Index)
					return temp;
				temp = temp->next;
			}
		}

		bool operator==(QueueLinkedList<T> Q)
		{
			if (Size() != Q.Size()) return false;
			int Pos = 0;
			Node<T>* temp = Head, * Qtemp = Q.Head;
			while (temp)
			{
				Pos++;
				if (temp->value != Qtemp->value)
					return false;
				temp = temp->next;
				Qtemp = Qtemp->next;
			}
			return true;
		}
		const bool operator!=(const QueueLinkedList<T> Q)
		{
			return this == Q ? false : true;
		}

		~QueueLinkedList()
		{
			while (Head)
			{
				Pop();
			}
		}
	};
}

