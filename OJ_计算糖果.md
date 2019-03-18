# OJ_计算糖果

[牛客网  计算糖果](https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34?tpId=85&&tqId=29857&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking)

>**题目描述：**
>
>A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
>A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
>现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。
>
>**输入描述：**
>
>```C
>输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在-30到30之间(闭区间)。
>```
>
>**输出描述：**
>
>```C
>输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
>```
>
>**示例：**
>
>```C
>输入：1 -2 3 4
>输出：2 1 3
>```

<font size = 5 color = red>思路：</font>

实质上是一个判断三元一次方程的题是否有解并求解的题。

A - B = a    
B - C = b    
A + B = c   
B + C = d    

主要注意代码风格，总结自己写题时一些不好的点：

1. 在输入上浪费太多精力，不能正确的判断输入数据的风格。
2. 很多语句冗余的部分。
3. 代码思想不成熟，上次删完一大段代码，仍然可以跑过，说明那部分根本没起作用。
4. <font color = blue>double类型不能做%运算。</font>

贴上自己的代码，以提醒自己。

~~~C
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){

	int A = 0, B = 0, C = 0;
	string str;//"30 0 0 0");
	getline(cin, str);
	vector<int> num;
	vector<string> strs;
	int index = 0;
	string s(str);
	string::iterator it = str.begin();

	int index2 = 0;
	//分割字符串
	int x = 0;
	int flag = 0;
	int j = 0;
	for (size_t i = 0; i <= str.size(); i++){
		if (*(str.c_str() + i) == ' ' || *(str.c_str() + i) == NULL){
			//int flag = i;
			strs.push_back(str.substr(j, i - j));
			j = i + 1;
			i++;
		}
	}
	for (size_t i = 0; i < strs.size(); i++){
		string ss = strs[i];
		if ((*ss.c_str()) == '-'){
			const char *c = ss.c_str() + 1;
			int a = atoi(c);
			num.push_back(-a);
			continue;
		}
		num.push_back(atoi(ss.c_str()));
	}
	if (num.size() == 4){
		A = (num[0] + num[2]) / 2;
		B = (num[1] + num[3]) / 2;
		C = num[3] - B;
	}
	if ((A % 2) != 0 && (A % 2) != 1){
		cout << "NO";
		return 0;
	}
	if ((B % 2) != 0 && (B % 2) != 1){
		cout << "NO";
		return 0;
	}
	if ((C % 2) != 0 && (C % 2) != 1){
		cout << "NO";
		return 0;
	}
	cout << A << " " << B << " " << C;

	system("pause");
	return 0;
}
~~~

**解答：**

~~~C
#include<iostream>
using namespace std;
// A - B = a
// B - C = b
// A + B = c
// B + C = d
// 这道题目的实质是：判断三元一次方程组是否有解及求解。
// 这里是小学生都会的问题了^^
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;
	if (B1 != B2){
		cout << "No";
	}
	else{
		cout << A << " " << B1 << " " << C;
	}
	return 0;
}
~~~



