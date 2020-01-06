# 1. Bubble Sort
## 1.1 Algorithm Steps
* Compare adjacent elements. If the first one is bigger, exchange them.
* After the first step, the last element would be the biggest.
* Repeat the above steps for all elements except the last one.
* If the remaining unprocessed elements is ordered, the `flag` would be true, and `break;`
## 1.2 Source Code
```cpp
int a[] = {1,2,5,4,3};
int len = sizeof(a)/sizeof(int);
for(int i=1; i<len; i++) //Repeat times
{
	bool ordered = true; //flag
	for(int j=0; j<len-i; j++)
	{
		if(a[j] > a[j+1]) //Compare adjacent elements.
		{
			int tmp = a[j];
			a[j] = a[j+1];
			a[j+1] = tmp;
			ordered = false; //if unordered, continue; else break;
		}
	}
	if(ordered)
		break;
}
```
# 2. Insertion Sort
## 2.1 Algorithm Steps
* Regard the first element as an `ordered array`, and the remaining elements as an `unordered array`.
* Scan the unordered array, and insert to the ordered array.
* If the  element to be inserted is equal to one of the element of ordered array, it should be inserted behind.
## 1.2 Source Code
```cpp
for(int i=1; i<len; i++) //Regard the first element as an ordered array
{
	int tmp = a[i];
	for(int j=i-1; j>=0; j--) //Scan the unordered array
	{
		if(a[j] > tmp)
			a[j+1] = a[j];
		else
		{
			a[j+1] = tmp; //insert behind the equal one or smaller one
			break;
		}
	}
}
```
