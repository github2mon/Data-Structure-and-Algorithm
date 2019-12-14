template<class Type> SeqList<Type>::SeqList(int size)
{
	elem = new Type[size];
	if(!elem) {cout<<"overflow"; exit(0);}
	listsize = size;
	length = 0;
}

template<class Type> int SeqList<Type>::seqLocateElem(Type e)
{
	
}
