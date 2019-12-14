```cpp
ADT List{
	//create an empty Linear List L
	ListInit(&L);
	//determine whether L is empty, if true, return 1; else return 0;
	ListEmpty(L);
	//get the length of L
	ListLength(L);
	//get the value of ith element
	GetElem(L, i);
	//replace the value of ith element as e
	ReplaceElem(L, i, e);
	//locate the sequence num of elem e
	LocateElem(L, e);
	//insert e before ith elem
	ListInset(&L, i, e);
	//insert e after ith elem
	ListInsertAfter(&L, i, e);
	//get the value of ith elem, then delete it
	ListDelete(&L, i, &e);
	//get the prior elem of ith
	PriorElem(L, i);
	//get the next elem of ith
	NextElem(L, i);
	//delete all elems of list, make it empty
	ListClear(&L);
	//destory list, always equals to destructor（析构函数）
	ListDestory(&L);
}ADT List
```
