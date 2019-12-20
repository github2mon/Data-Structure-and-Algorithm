#pragma once

#include<iostream>
using namespace std;

template <typename T> class LinkList;
template <typename T> class ListNode
{
	friend class LinkList<T>;
private:
	T data;
	ListNode<T> *next;
public:
	ListNode() : next(NULL) {};
	ListNode(T &e) : data(e), next(NULL) {};
	T& getNodeData() { return data; }
	ListNode<T>* getNodePtr() { return next; }
	void setNodeData(T& e) { data = e; }
	void setNodePtr(ListNode<T>* ptr) { next = ptr; }
};

template <typename T> class LinkList
{
private:
	ListNode<T>* head;
public:
	LinkList() { head = new ListNode<T>(); }
	LinkList(LinkList<T>& List);
	~LinkList() { clearList(); delete head; }
	void clearList();
	int getLength() const;
	ListNode<T>* locateElem(T e) const;
	ListNode<T>* getElem(int i) const;
	int insert(int i, T& e);
	int deleteElem(int i);
	bool isEmpty(void) { return !(head->next); }
	LinkList<T>& operator = (LinkList<T>& List);
};

template <typename T> LinkList<T>::LinkList(LinkList<T>& List)
{
	head = new ListNode<T>();
	ListNode<T>* p = List.head->next, *q = head, *s;
	while (p)
	{
		s = new ListNode<T>();
		s->data = p->data;
		q->next = s;
		q = s;
		p = p->next;
	}
	q->next = NULL;
}

template <typename T> void LinkList<T>::clearList()
{
	ListNode<T>* p;
	while (head->next)
	{
		p = head->next;
		head->next = p->next;
		delete p;
	}
}

template <typename T> int LinkList<T>::getLength() const
{
	ListNode<T>* p = head;
	int cnt = 0;
	while (p)
	{
		p = p->next;
		cnt++;
	}
	return cnt;
}

template <typename T> ListNode<T>* LinkList<T>::getElem(int i) const
{
	if (i < 0) return NULL;
	if (i == 0) return head;
	ListNode<T>* p = head->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

template <typename T> ListNode<T>* LinkList<T>::locateElem(T e) const
{
	ListNode<T> *p = head;
	while (p && p->data != e)
		p = p->next;
	return p;
}

template <typename T> int LinkList<T>::insert(int i, T& e)
{
	ListNode<T>* p = getElem(i - 1);
	if (!p) return 0;
	ListNode<T> *s = new ListNode<T>(e);
	s->next = p->next;
	p->next = s;
	return 1;
}

template <typename T> int LinkList<T>::deleteElem(int i)
{
	ListNode<T> *p = getElem(i - 1), *s;
	if (!p || p->next == NULL) return 0;
	s = p->next;
	p->next = s->next;
	delete s; //avoid memory leak
	return 1;
}

template <typename T> LinkList<T>& LinkList<T>::operator = (LinkList<T>& List)
{
	if (this == &List) return *this;
	clearList();
	ListNode<T>* p = List.head->next, *q = head, *s;
	while (p)
	{
		s = new ListNode<T>();
		s->data = p->data;
		q->next = s;
		q = s;
		p = p->next;
	}
	q->next = NULL;
	return *this;
}
