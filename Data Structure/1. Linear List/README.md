```cpp
ADT List{
	//create an empty Linear List L
	init(&L);
	//determine whether L is empty, if true, return 1; else return 0;
	isEmpty(L);
	//get the length of L
	length(L);
	//get the value of ith element
	getElem(L, i);
	//replace the value of ith element as e
	replaceElem(L, i, e);
	//locate the sequence num of elem e
	locateElem(L, e);
	//insert e before ith elem
	inset(&L, i, e);
	//insert e after ith elem
	insertAfter(&L, i, e);
	//get the value of ith elem, then delete it
	delete(&L, i, &e);
	//get the prior elem of ith
	prior(L, i);
	//get the next elem of ith
	next(L, i);
	//delete all elems of list, make it empty
	clear(&L);
	//destory list, always equals to destructor（析构函数）
	destory(&L);
}ADT List
```
