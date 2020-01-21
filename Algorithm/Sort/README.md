# 0. Prepare
```cpp
srand((unsigned int)time(nullptr)); //include <ctime>
for(int i = 0; i < NUM; i++)
    array[i] = rand() % 100 + 1; //include <algorithm>
```
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
# 5. Merge Sort
## 5.1 Algorithm Steps
* devide the unordered array into two sub-array
* finally each sub-array contains only one element, which must be sorted
* merge the two ordered array (left-array & right-array)
## 5.2 Source Code
```cpp
void merge(int* a, int l, int m, int r)
{
    if (a == nullptr)
        return;
    int* temp = new int[r - l + 1];
    int pl = l, pr = m + 1, p = 0;
    while (pl <= m && pr <= r)
        temp[p++] = a[pl] <= a[pr] ? a[pl++] : a[pr++];

    if (pl <= m)
        memcpy(temp + p, a + pl, sizeof(int) * (m - pl + 1));
    else if (pr <= r)
        memcpy(temp + p, a + pr, sizeof(int) * (r - pr + 1));

    memcpy(a + l, temp, sizeof(int) * (r - l + 1));

    delete[] temp;
    temp = nullptr;
}

void mergeSort(int* a, int l, int r)
{
    if (!a || l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
```
# 6. Heap Sort
## 6.1 Algorithm Steps
* Creat the Maxheap, each parent node is larger than the child nodes
* Exchange the root and the last element
* re-build the Maxheap for the first `len-1` elements
## 6.2 Source Code
```cpp
void buildMaxHeap(int* a, int i, int len)
{
    int left  = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < len && a[left] > a[largest])
        largest = left;
    if (right < len && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(a, i, largest);
        buildMaxHeap(a, largest, len);
    }
}

void heapSort(int* a, int len)
{
    for (int i = len / 2; i >= 0; i--)
        buildMaxHeap(a, i, len);
    while(len - 1)
    {
        swap(a, 0, len - 1);
        buildMaxHeap(a, 0, --len);
    }
}

```
