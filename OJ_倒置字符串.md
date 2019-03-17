# OJ_倒置字符串

[倒置字符串][https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking]

>题目描述：
>
>将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
>
>输入描述：
>
>```
>每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
>```
>
>输出描述：
>
>```
>依次输出倒置之后的字符串,以空格分割
>```
>
>~~~C
>示例：
>输入：I like beijing.
>输出：beijing. like I
>~~~

<font size = 5 color = red>思路：</font>

倒置由栈的性质可以想到，在操作string函数时一定要注意边界问题，以及最后的输出问题。

理解cin 和getline的区别。

~~~C
//以空格为分割线，入栈。用一个栈实现倒置。
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	//string str("I like beijing.");
	string ret;
	string str, cur;
    
    //两种输入方式
	getline(cin, str);
    /*while (cin >> cur){
		str += cur;
		str += ' ';
	}
    */
	stack<string> v1;
	string::iterator it;
	int j = 0;
    
    //按空格将一句话分成若干个单词，放入栈v1
	for (size_t i = 0; i <= str.size(); i++){
		if (*(str.c_str() + i) == ' ' || *(str.c_str() + i) == NULL){
			//int flag = i;
			v1.push(str.substr(j, i - j));    //这里要注意边界问题
			j = i + 1;
			i++;
		}
	}
    //将栈中的单词pop出即为倒序，因为栈本身就是先进后出的性质
	size_t size = v1.size();
	for (size_t i = 0; i < size; i++){
		ret += v1.top().c_str();
		ret += ' ';
		v1.pop();
	}
    
    //需要erase掉最后一个空格。
    ret.erase(ret.size() - 1);
	cout << ret;
	system("pause");
	return 0;
}
~~~

