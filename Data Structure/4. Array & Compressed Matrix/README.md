# Static Array (静态数组)

>```cpp
>int a[5];
>```

# Dynamic Array (动态数组)
>```cpp
>double** p = new double* [5];
>for(int i=0; i<5; i++)
>	p[i] = new double [10];
>```

# Storage Structure (存储结构)
>```cpp
>a[0][0] ... a[0][n] a[1][0] ... a[1][n] ... ... a[m][0] ... a[m][n]
>```

# Compressed Matrix (压缩矩阵)
>## Special Matrix (特殊矩阵)
>>### Symmetric Matrix
>>```cpp
>>a[i][j] = a[j][i];
>>if(i >= j)
>>	k = i * (i + 1) / 2 + j;
>>else
>>	k = j * (j + 1) / 2 + i;
>>```	
>>```cpp
>>a[0][0] a[1][0] a[1][1] a[2][0] a[2][1] a[2][2] ... a[n][0] ... a[n][n]
>>k= 0       1       2       3       4       5        n(n+1)/2    n(n+3)/2
>>```
>>### Triangular Matrix (三角矩阵)
>>```cpp
>>if(i < j) a[i][j] = c;
>>if(i >= j)
>>	k = i * (i + 1) / 2 + j;
>>else
>>	k = n * (n + 3) / 2 + 1;
>>```	
>>```cpp
>>a[0][0] a[1][0] a[1][1] a[2][0] a[2][1] a[2][2] ... a[n][0] ... a[n][n]  c
>>k= 0       1       2       3       4       5        n(n+1)/2             n(n+3)/2 + 1  
>>```
>>### Diagonal Matrix (对角矩阵)
>>```cpp
>>| a[0][0] a[0][1]                                     |
>>| a[1][0] a[1][1] a[1][2]                             |
>>|         a[2][1] a[2][2] a[2][3]                     |
>>|                 a[3][2] a[3][3]    ...              |
>>|                           ...      ...    a[n-1][n] |
>>|                                 a[n][n-1]  a[n][n]  |
>>
>>k = 2 * i + j
>>```
>>```cpp
>>a[0][0] a[0][1] a[1][0] a[1][1] a[1][2] a[2][1] ... a[i][j] ... a[n][n]
>>k= 0       1       2       3       4       5         2i+j        3n+1
>>```
>## Sparse Matrix (稀疏矩阵)
>```cpp
>| 1 2 0 |
>| 3 0 0 |
>| 0 0 4 |
>
>(row, col, val)
>((0,0,1), (0,1,2), (1,0,3), (2,2,4))
>```
```cpp
ADT SparseMatrix
{
	createSM(&M);
	destorySM(&M);
	transposeSM(M);
	addSM(&M, &N);
	mulSM(&M, &N);
}ADT SparseMatrix
```
