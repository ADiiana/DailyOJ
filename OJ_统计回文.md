# OJ_统计回文

[统计回文 牛客网](https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking)

>例如：
>A = “aba”，B = “b”。这里有4种把B插入A的办法：
>* 在A的第一个字母之前: "baba" 不是回文 
>* 在第一个字母‘a’之后: "abba" 是回文 
>* 在字母‘b’之后: "abba" 是回文 
>* 在第二个字母'a'之后 "abab" 不是回文 
>所以满足条件的答案为2
>
>**输入描述：**
>
>```C
>每组输入数据共两行。
>第一行为字符串A
>第二行为字符串B
>字符串长度均小于100且只包含小写字母
>```
>
>**输出描述：**
>
>```C
>输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数
>```
>
>**示例1：**
>
>```C
>输入：aba
>输出：b
>```

**注意：**

这道题比较简单，自己的答案基本上与题解相同。

但发现一个问题，要注意函数名，起一个合适的变量名来表达自己的思想，有时候至关重要，比如有时候，有的值需要一个长一点的表达式来表示，就应该另起变量。

函数名不要用拼音。

**题解：**

~~~C
#include<iostream>
#include<string>
using namespace std;
// 判断是否是回文
bool IsCircleText(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;
		++begin;
		--end;
	}
	return true;
}
int main()
{
	std::string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	size_t count = 0;
	for (size_t i = 0; i <= str1.size(); ++i)
	{
		// 将字符串2插入到字符串1的每个位置，再判断是否是回文
		string str = str1;
		str.insert(i, str2);
		if (IsCircleText(str))
			++count;
	}
	cout << count << endl;
	return 0;
}
~~~

**代码：**

~~~C
/*
写一个判断回文的子函数，尝试将字符串插入后再一一判断。
字符串A、B不需要一定是回文串。
*/
#include<iostream>
#include<string>
using namespace std;
int ishuiwen(string &str){
	int time = str.size() / 2;
	int key = str.size() / 2;
	
	for (size_t i = 0; i < str.size() / 2; i++){
		if (str[i] == str[str.size() - 1 - i]){
			key--;
		}
		else{
			return 0;
		}
	}
	return 1;
}
int main(){
	string A, B;
	getline(cin, A);
	getline(cin, B);
	int flag = 1;
	int mian_key = 0;
	for (size_t i = 0; i <= A.size(); i++){
		string str(A);
		str.insert(i, B);
		if (flag == ishuiwen(str)){
			mian_key++;
		}
	}

	cout << mian_key;
	system("pause");
	return 0;
}
~~~

