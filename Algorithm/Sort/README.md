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
