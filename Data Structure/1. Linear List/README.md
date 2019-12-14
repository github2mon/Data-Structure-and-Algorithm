```cpp
ADT List{
	//create an empty Linear List L
	listInit(&L);
	//determine whether L is empty, if true, return 1; else return 0;
	listEmpty(L);
	//get the length of L
	listLength(L);
	//get the value of ith element
	getElem(L, i);
	//replace the value of ith element as e
	replaceElem(L, i, e);
	//locate the sequence num of elem e
	locateElem(L, e);
	//insert e before ith elem
	listInset(&L, i, e);
	//insert e after ith elem
	listInsertAfter(&L, i, e);
	//get the value of ith elem, then delete it
	listDelete(&L, i, &e);
	//get the prior elem of ith
	priorElem(L, i);
	//get the next elem of ith
	nextElem(L, i);
	//delete all elems of list, make it empty
	listClear(&L);
	//destory list, always equals to destructor（析构函数）
	listDestory(&L);
}ADT List
```
