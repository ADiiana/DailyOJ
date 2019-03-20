# OJ_删除公共字符串

[删除公共字符串 牛客网](https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking)

>**题目描述：**
>
>输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
>
>**输入描述：**
>
>```C
>每个测试输入包含2个字符串
>```
>
>**输出描述：**
>
>```C
>输出删除后的字符串
>```
>
>**示例1：**
>
>```C
>输入：They are students. aeiou
>输出：Thy r stdnts.
>```

<font size = 5 color = red>思路：</font>

**思路一：**这道题比较常规，以我以前的想法，是遍历第一个字符串，每发现一个字符是第二个字符串里的元素，就删除，这样做的效率太低，有很多无谓的操作，遍历加erase还容易出错。

**思路二：**用哈希表映射，定义一个有26个元素且都为0的，分别遍历字符串一和字符串二，给元素对应下标的元素加一。再遍历数组元素，**这里有两种做法：1.删除原字符串中字符对应下标的元素值为2的字符。2.挑出源字符串中字符对应下标的元素值为0的字符，+=到一个string类型上，输出。或者直接输出。第二种做法比较好，因为erase方法控制不好容易出错。**

**题解：**

~~~C
#include<iostream>
#include<string>
using namespace std;
int main()
{
	// 注意这里不能使用cin接收，因为cin遇到空格就结束了。
	// oj中IO输入字符串最好使用getline。
		string str1, str2;
	//cin>>str1;
	//cin>>str2;
	getline(cin, str1);
	getline(cin, str2);
	// 使用哈希映射思想先str2统计字符出现的次数
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}
	// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在
	// str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i)
	// 因为边遍历，边erase，容易出错。
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;
	return 0;
}
~~~

