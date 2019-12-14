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
