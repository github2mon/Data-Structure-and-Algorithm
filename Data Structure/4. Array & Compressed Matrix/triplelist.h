#pragma once

template <typename T> class TripleList;
template <typename T> class Triple
{
	friend class TripleList<T>;
private:
	int row, col;
	T value;
};

template <typename T> class TripleList
{
private:
	int rows, cols, terms;
	Triple<T>* array;
	int size;
public:
	TripleList(int maxSize);
	~TripleList() { delete[] array; }
	TripleList<T>* transpose();
	TripleList<T>* fastTranspose();
	TripleList<T>* addMatrix(TripleList<T>& b);
	TripleList<T>* multiMatrix(TripleList<T>& b);
};

template<typename T> TripleList<T>::TripleList(int maxSize)
{
	if (maxSize < 1) { cout << "init error"; exit(0); }
	size = maxSize;
	array = new Triple<T>[maxSize];
	rows = cols = terms = 0;
}
