#pragma once

template <typename T> class LinkQueue;
template <typename T> class QueueNode
{
	friend class LinkQueue<T>;

private:
	T data;
	QueueNode<T>* next;

public:
	QueueNode(T& e, QueueNode<T>* p == NULL)
	{
		data = e;
		next = p;
	}
};

template <typename T> class LinkQueue
{
private:
	QueueNode<T> *front, *tail;
	
public:
	LinkQueue() : front(NULL), tail(NULL) {}
	~LinkQueue();
	int isEmpty() const { return front == NULL; }
	int length() const;
	T& frontElem();
	void enQueue(T& e);
	T& deQueue();
	void clearQueue();
};
