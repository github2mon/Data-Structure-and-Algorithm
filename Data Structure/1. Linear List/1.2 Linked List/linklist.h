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
	ListNOde(T &e) : data(e), next(NULL) {};
	T& getNodeData() {return data;}
	ListNode<T>* getNodePtr() {return next;}
	void setNodeData(T& e) {data = e;}
	void setNodePtr(ListNode<T>* ptr) {next = ptr;}
};

template <typename T> class LinkList
{

};
