```cpp
void swap(int* a, int* b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}
void swap(int* a, int* b)
{
    *a = *a + *b; //be care of int + int = long
    *b = *a - *b;
    *a = *a - *b;
}
```
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
            swap(a[j], a[j+1]);
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
## 2.2 Source Code
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
# 3. Selection Sort
## 3.1 Algorithm Steps
* Find out the minimum element, and exchange with the first element of the unordered array
* Find out the minimum element in the remaining elements, and exchange with the first element of the remaining unordered array
* Repeat the second step until ordered
## 3.2 Source Code
```cpp
for(int i=0; i<len; i++)
{
    int min = i;
    for(int j=i+1; j<len; j++)
        min = a[j]<a[min] ? j : min; //return the minimum sequence
    if(i != min)
        swap(a[i], a[min]);
}
``` 
# 4. Quick Sort
## 4.1 Algorithm Steps
* Choose an element as the pivot
* Partition operate: put all smaller elements at left, and all biggers right
* Do not care about the equaled elements
* Exchange the pivot element with the first of right-array
* Recursive sort the left and right sub-array until the size of sub-array equals to 1
## 4.2 Source Code
```cpp
int partition(int a[], int left, int right)
{
    int l = left, r = right - 1;
    while(l <= r)
    {
        while(a[l] < a[right])
            l++;
        while(a[r] > a[right])
            r--;
        if(l < r)
            swap(a[l++], a[r--]);
        else
            r--;
    }
    swap(a[right], a[l]);
    return l;
}

void quickSort(int a[], int left, int right)
{
    if(left > right)
        return;
    int index = partition(a, left, right);
    quickSort(a, left, index-1);
    quickSort(a, index+1, right);
}
```
