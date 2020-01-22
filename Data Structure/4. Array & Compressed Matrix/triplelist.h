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

template<typename T> TripleList<T>* TripleList<T>::transpose();
{
	TripleList<T>* b = new TripleList<T>(size);
	b->cols = rows;
	b->rows = cols;
	b->terms = terms;
	if (terms > 0)
	{
		int cur = 0;
		for(int col = 0; col < cols; col++)
			for(int p = 0; p < terms; p++)
				if (array[p].col == col)
				{
					b->array[cur].row = array[p].col;
					b->array[cur].col = array[p].row;
					b->array[cur].value = array[p].value;
					cur++;
				}
	}
	return b;
}

