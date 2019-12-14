template <class Type> class SeqList
{
private:
	Type *elem;
	int length;
	int listsize;
	
public:
	SeqList(int size);
	~SeqList(void) {delete [] elem;}
	
	int seqListEmpty(void) const {return length == 0;}
	int seqListLength(void) const {return length;}
	Type& seqGetElem(int i) const {return elem[i-1]};
	int replaceElem(int i, Type &e);
	int seqLocateElem(Type e);
	int seqListInsert(int i, Type &e);
	int seqListInsertAfter(int i, Type &e);
	int seqListDelete(int i, Type &e);
	Type& seqPriorElem(int i);
	Type& seqNextElem(int i);
	void seqListClear(void) {length = 0;}
};
