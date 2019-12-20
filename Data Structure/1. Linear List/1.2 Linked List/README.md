Dual Linked List
---
```cpp
template <typename T> class ListNode
{
	friend class LinkList<T>;
private:
	T data;
	//ListNode<T> *prior; dual linked list
	ListNode<T> *next;
 }
 ```
 
 Circle Linked List
 ---
 ```cpp
     head->next = head;
 ```
