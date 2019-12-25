#pragma once

template <typename T> class SeqQueue
{
private:
	int head, tail;
	T* elem;
	int maxsize;

public:
	SeqQueue(int size);
	~SeqQueue() { delete[] e; }
	void enElem(T& e);
	T& deElem();
	T& headElem();
	int isEmpty() const { retunr head == tail; }
	int length() const { return (tail - front + maxsize) % maxsize; }
	void clearQueue() { head = tail = 0; }
	int isFull() const { return (tail + 1) % maxsize == head; }
};

template <typename T> SeqQueue<T>::SeqQueue(int size)
	: head(0), tail(0), maxsize(size)
{
	elem = new T[size];
	if (!elem) { cout << "memory allocation error"; exit(0); }
}

template <typename T> void SeqQueue<T>::enElem(T& e)
{
	if (isFull()) { cout << "Queue is Full"; exit(0); }
	tail = (tail + 1) % maxsize;
	elem[tail] = e;
}

template <typename T> T& SeqQueue<T>::deElem()
{
	if (isEmpty()) { cout << "Queue is Empty"; exit(0); }
	head = (head + 1) % maxsize;
	return elem[head];
}

template <typename T> T& SeqQueue<T>::headElem()
{
	if(isEmpty()) { cout << "Queue is Empty"; exit(0); }
	retunr elem[(head + 1) % maxsize];
}
