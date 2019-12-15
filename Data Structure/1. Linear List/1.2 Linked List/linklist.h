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
	T& getNodeData() {return data;}
	ListNode<T>* getNodePtr() {return next;}
	void setNodeData(T& e) {data = e;}
	void setNodePtr(ListNode<T>* ptr) {next = ptr;}
};

template <typename T> class LinkList
{
private:
	ListNode<T>* head;
public:
	LinkList() {head = new ListNode<T>();}
	LinkList<T>(LinkList<T>& List);
	~LinkList() {clearList(); delete head;}
	void clearList();
	int getLength() const;
	ListNode<T>* locateElem(T e) const;
	ListNode<T>* getElem(int i) const;
	int insert(int i, T& e);
	T* delete(int i);
	ListNode<T>* remove(int i);
	int replace(int i, T& e);
	ListNode<T>* prior(int i);
	ListNode<T>* next(int i);
	bool isEmpty(void);
	LinkList<T>& operate = (LinkNode<T>& List);
};
