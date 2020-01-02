`SOURCE: bacbababaabcbab`
---
`TARGET: ababaca`
---
查询TARGET第一次在SOURCE中出现的位置
---
Example: [028_implement-strstr](https://github.com/github2mon/Leetcode-note-cpp/blob/master/028_implement-strstr.cpp)
---
![](https://github.com/github2mon/Data-Structure-and-Algorithm/blob/master/Algorithm/KMP/string%20matching.jpg)  
  
Violent Matching
---
```cpp
for (int i = 0; i < strlen(source); i++)
{
	if (source[i] == target[0])
	{
		for (int j = 0; j < strlen(target); j++)
		{
			if (source[i + j] != target[j])
				break;
			if (j == strlen(target) - 1 && source[i + j] == target[j])
				return i;
		}
	}
}
```
  
KMP
---
`前缀函数next`  
(a) 根据第三步k个匹配字符的已有信息，可推知k+1的偏移是无效的，但k+2的偏移可能有效；  
(b) 推导中使用的有用信息可以通过模式自身的为预计算；  
(c) 发现字符串前三位是能构成前五位后缀的最长前缀，这些信息可以被预先计算出来，并用数组next来表示，即next[5]=3，在偏移s有k个字符成功匹配，则下一个可能有效的偏移为s’=s+(k-next[k])，如第四步所示。  
```cpp
int k = -1;
for (int i = 0; i < strlen(s); i++)
{
	while (k >= 0 && t[k + 1] != s[i])
		k = next[k];
	if (t[k + 1] == s[i])
		k++;
	if (k == strlen(t) - 1)
	{
		return i - strlen(t) + 1;
		//k = next[k]; //用于寻找下一个匹配字符串
	}
}
```
  
`计算最长前缀长度`  
P = ababa  
前缀：{ a, ab, `aba`, abab }  
后缀：{ a, ba, `aba`, baba }  
最长前缀为aba，长度为3  
  
P = ababaca  
前缀：{ `a`, ab, aba, abab, ababa, ababac }  
后缀：{ `a`, ca, aca, baca, abaca, babaca }  
最长前缀为a，长度为1  
  
因此可以得出以下表格  
![](https://github.com/github2mon/Data-Structure-and-Algorithm/blob/master/Algorithm/KMP/calculate%20next%20array.jpg)  
```cpp
next[0] = -1;
int k = -1, len = strlen(p);
for (int i = 1; i < len; i++)
{
	while (k >= 0 && p[k + 1] != p[i]) 
		k = next[k]; //递归下一项为当前最长前缀的最长后缀
	if (p[k + 1] == p[i])
		k++;
	next[i] = k;
}
```
