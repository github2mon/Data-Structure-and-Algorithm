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
	
};
