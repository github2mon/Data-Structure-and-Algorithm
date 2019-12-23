#pragma once

#include <iostream>
using namespace std;

template <typename T> class LinkStack;
template <typename T> class StackNode
{
	friend class LinkStack;

private:
	T data;
	StackNode<T>* next;

public:
	StackNode<T>(T& e, StackNode<T>* ptr = NULL)
	{
		data = e;
		next = ptr;
	}
};

template <typename T> class LinkStack
{
private:
	StackNode<T>* top;

public:
	LinkStack<T>() : top(NULL) {}
	~LinkStack();
	int isEmpty() const { return top == NULL; }
	int length() const;
	T& topElem();
	void pushElem(T& e);
	T& popElem();
	void clearStack();
};

template <typename T> LinkStack<T>::~LinkStack()
{
	StackNode<T>* p;
	while (top)
	{
		p = top;
		top = top->next;
		delete p;
	}
}

template <typename T> int LinkStack<T>::length() const
{
	if (!top) return 0;
	StackNode<T>* p;
	p = top;
	int len = 0;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

template <typename T> T& LinkStack<T>::topElem()
{
	if (!top) { cout << "Stack is empty"; exit(0); }
	return top->data;
}

template <typename T> void LinkStack<T>::pushElem(T& e)
{
	top = new StackNode<T>(e, top);
	if (!top) { cout << "node allocation failed"; exit(0); }
}

template <typename T> T& LinkStack<T>::popElem()
{
	if (!top) { cout << "stack is empty"; exit(0); }
	StackNode<T>* p = top;
	top = top->next;
	T* q = new T; //T&
	*q = p->data;
	delete p;
	return *q;
}
