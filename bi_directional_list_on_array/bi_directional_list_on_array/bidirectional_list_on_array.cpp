#include "bidirectional_list_on_array.h"
#include "containers.h"

template<typename T>
void BiDirectionalListOnArray<T>::Clear()
{
    while (!IsEmpty())
        PopBack();
}

template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(initializer_list<T>& List)
{
    for (auto X : List)
        PushBack(X);
}

template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(BiDirectionalListOnArray<T>& A)
{
    Clear();
    Node<T>* temp = A.Front_;
    while (temp)
    {
        PushBack(new Node<T>(temp->value));
        temp = temp->next;
    }
}

template<typename T>
int BiDirectionalListOnArray<T>::Size()
{
    int Result = 0;
    Node<T>* temp = Front_;
    while (temp)
    {
        Result++;
        temp = temp->next;
    }
    return Result;
}

template<typename T>
bool BiDirectionalListOnArray<T>::IsEmpty()
{
    return Front_ == nullptr ? true : false;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushBack(const T& value)
{
    if (Front_) {
        Front_ = Back_ = new Node<T>(value); return;
    }
    Back_->next = new Node<T>(value);
    Back_ = Back_->next;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushBack(T&& value)
{
    if (Front_) {
        Front_ = Back_ = new Node<T>(move(value)); return;
    }
    Back_->next = new Node<T>(move(value));
    Back_ = Back_->next;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushFront(T&& value)
{
    if (Back_) {
        Front_ = Back_ = new Node<T>(move(value)); return;
    }
    Front_->prev = new Node<T>(move(value));
    Front_ = Front_->prev;
}

template<typename T>
void BiDirectionalListOnArray<T>::PopFront()
{
    if (Size() == 0) {
        throw std::exception();
    }
    Node<T>* source_ptr = Front_;
    Front_ = Front_->next_;
    delete source_ptr;
    if (Size() == 0) {
        Back_ = nullptr;
    }
}

template<typename T>
void BiDirectionalListOnArray<T>::PopBack()
{
    if (Size() == 0) {
        throw std::exception();
    }
    Node<T>* source_ptr = Back_;
    Back_ = Back_->prev;
    delete source_ptr;
    if (Size() == 0) {
        Front_ = nullptr;
    }
}

template<typename T>
vector<T> BiDirectionalListOnArray<T>::ToVector()
{
    vector<T> Result;
    Node<T>* temp = Front_;
    while (temp)
    {
        Result.push_back(temp->value);
        temp = temp->next;
    }
    return Result;
}

template<typename T>
void BiDirectionalListOnArray<T>::PushFront(T& value)
{
    if (Back_) {
        Front_ = Back_ = new Node<T>(value); return;
    }
    Front_->prev = new Node<T>(value);
    Front_ = Front_->prev;
}
