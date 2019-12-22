#pragma once

#include <iostream>
using namespace std;

template <typename T> class SeqStack
{
private:
	int top;
	T* elem;
	int maxsize;

public:
	SeqStack(int size);
	~SeqStack() { delete elem; }
	int isEmpty() const { return top == -1; }
	void clearStack() { top = -1; }
	int length() { return top + 1; }
	int isFull() { return top == maxsize + 1; }
	T& topElem();
	void pushElem(T& e);
	T& popElem();
};

template <typename T> SeqStack<T>::SeqStack(int size)
	:top(-1), maxsize(size)
{
	elem = new T[maxsize];
	if (!elem) { cout << "memory allocation failed"; exit(0); }
}

template <typename T> T& SeqStack<T>::topElem()
{
	if (isEmpty()) { cout << "stack is empty"; exit(0); }
	return elem[top];
}

template <typename T> void SeqStack<T>::pushElem(T& e)
{
	if (isFull())
	{
		T* p = new T[maxsize + 1];
		if (!p) { cout << "memory overflow"; exit(0); }
		for (int i = 0; i < maxsize; i++)
			p[i] = elem[i];
		delete[] elem;
		elem = p;
		p = NULL;
		maxsize++;
	}
	elem[++top] = e;
}

template <typename T> T& SeqStack<T>::popElem()
{
	if (top == -1) { cout << "stack is empty"; exit(0); }
	return elem[top--];
}
