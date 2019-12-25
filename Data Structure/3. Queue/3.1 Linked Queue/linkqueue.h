#pragma once

template <typename T> class LinkQueue;
template <typename T> class QueueNode
{
	friend class LinkQueue<T>;

private:
	T data;
	QueueNode<T>* next;

public:
	QueueNode(T& e, QueueNode<T>* p = NULL)
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
};

template <typename T> LinkQueue<T>::~LinkQueue()
{
	QueueNode<T>* p;
	while (front)
	{
		p = front;
		front = front->next;
		delete p;
	}
}

template <typename T> int LinkQueue<T>::length() const
{
	QueueNode<T>* p = front;
	int cnt = 0;
	while (p)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

template <typename T> T& LinkQueue<T>::frontElem()
{
	if (!front) { cout << "Queue is empty"; exit(0); }
	return front->data;
}

template <typename T> void LinkQueue<T>::enQueue(T& e)
{
	if (!front)
		front = tail = new QueueNode<T>(e, NULL);
	else
		tail = tail->next = new QueueNode<T>(e, NULL);
}

template <typename T> T& LinkQueue<T>::deQueue()
{
	if(!front) { cout << "Queue is empty"; exit(0); }
	QueueNode<T>* p = front;
	front = front->next;
	if (tail == p) tail = front;
	T* q = new T;
	q = p->data;
	delete p;
	return *q;
}
