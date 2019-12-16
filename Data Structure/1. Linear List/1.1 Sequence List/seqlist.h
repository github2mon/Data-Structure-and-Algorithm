#include<iostream>
using namespace std;

template <class Type> class SeqList
{
private:
	Type *elem;
	int length;
	int listsize;

public:
	SeqList(int size);
	~SeqList(void) { delete[] elem; }

	int isEmpty(void) const { return length == 0; }
	int getLength(void) const { return length; }
	Type& getElem(int i) const { return elem[i - 1] };
	int replaceElem(int i, Type &e);
	int locateElem(Type e);
	int insertElem(int i, Type &e);
	int deleteElem(int i, Type &e);
	void clearList(void) { length = 0; }

	//application
	void merge(SeqList<Type> &la, SeqList<Type> &lb, SeqList<Type> &lc);
};

template<class Type> SeqList<Type>::SeqList(int size) {
	elem = new Type[size];
	if (!elem) { cout << "overflow"; exit(0); }
	listsize = size;
	length = 0;
}

template<class Type> int SeqList<Type>::locateElem(Type e) {
	if (length == 0) return 0;
	int i = 0;
	while (i < length && e != elem[i]) i++;
	if (i < length) return i;
	else return 0;
}

template<class Type> int SeqList<Type>::replaceElem(int i, Type &e) {
	if (i < length) { elem[i] = e; return 1;}
	return 0;
}

template<class Type> int SeqList<Type>::insertElem(int i, Type &e) {
	if (i < 0 || i > length) return 0;
	if (listsize == length) //add more storage space
	{
		Type *p = new Type[listsize++];
		if (!p) { cout << "overflow"; exit(0); }
		for (int j = 0; j < length; j++)
			p[j] = elem[j];
		delete[] elem;
		elem = p;
		p = NULL;
	}
	for (int j = length - 1; j >= i; j--) //backwards elems
		elem[j + 1] = elem[j];
	elem[i] = e;
	length++;
	return 1;
}

template<class Type> int SeqList<Type>::deleteElem(int i, Type &e) {
	if (i < 0 || i > length - 1) return 0;
	e = elem[i];
	for (int j = i; j < length - 1; j++) //forwards elems
		elem[j] = elem[j + 1];
	length--;
	return 1;
}

//application
template<class Type> void SeqList<Type>::merge(SeqList<Type> &la, SeqList<Type> &lb, SeqList<Type> &lc) {
	int la_length = la.getLength();
	int lb_length = lb.getLength();
	for (int i = 0; i < la_length; i++)
		lc.insertElem(i, la.getElem(i));
	int lc_length = lc.getLength();
	for (int i = 0; i < lb_length; i++)
	{
		int data = lb.getElem(i);
		if (!lc.locateElem(data))
			lc.insertElem(lc_length++, data);
	}
}
