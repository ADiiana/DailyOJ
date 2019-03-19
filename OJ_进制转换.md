# OJ_进制转换

[牛客网 进制转换](https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking)

>给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
>
>**输入描述：**
>
>```c
>输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
>```
>
>**输出描述**
>
>```C
>为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
>```

>**示例：**
>
>~~~C
>输入 7 2
>输出 111
>~~~

<font size = 5 color = red>思路：</font>

我的思路和题解的思路类似，但没有考虑负数的情况，另外，代码冗余太严重了，仍然是删掉一大部分代码还能跑过，特别是数据输入，和数据存储。

定义一个数组，存放"0123456789ABCDEF"，当输入数据m和n时，用除和取余计算m的n进制，再将以结果为小标的数组元素逆向输出。

应当注意的是，如果m是一个负数，要标记一下，并将负数转化成正数，再计算其n进制，输出时，如果发现该数在进制转化前是个负数，在输出结果时，也要添加负号。

**代码：**

~~~C
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;
		// 如果是负数，则转成正数，并标记一下
	if (m < 0)
	{
		m = 0 - m;		//将负数转换成正数的方法值得借鉴
		flag = true;
	}
	// 按进制换算成对应的字符添加到s
	while (m)
	{
		s += table[m%n];
		m /= n;
	}
	if (flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
~~~

**总结自己的代码：**

~~~C
//通过70%的测试用例
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
    //数据输入太繁琐，冗余，而没有一点作用
    int m = 0;
    int n = 0;
    cin >> m >> n;
    vector<int> num;
    num.push_back(m);
    num.push_back(n);
    
	vector<int> ret;	//输出数组下标
    //将m、n替换成num[0]、num[1]反而降低代码的可读性。
	if (num[0] == 0)
		return 0;
    //在处理进制转换的过程也繁琐，思路不清晰
	while (num[0] >= num[1]){
		ret.push_back(num[0] % num[1]);

		if (num[0] < num[1]){
			ret.push_back(num[0]);
			break;
		}
		num[0] /= num[1];
	}
	if (num[0] < num[1]){
		ret.push_back(num[0]);
	}
    
	const char *array = "0123456789ABCDEF";
	for (int i = ret.size() - 1; i >= 0; i--){
		cout << array[ret[i]];
	}
	system("pause");
	return 0;
}
~~~

修改之后：

~~~C
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m = 0;
    int n = 0;
    cin >> m >> n;    //输入数据
    int flag = 0;
    
    if(m < 0){
        m = 0 - m;
        flag = 1;
    }
    vector<int> ret;
    while(m){
        ret.push_back(m % n);
        m /= n;
    }
	const char *array = "0123456789ABCDEF";
    if(flag == 1){
        cout << "-";
    }
	for (int i = ret.size() - 1; i >= 0; i--){
		cout << array[ret[i]];
	}
	system("pause");
	return 0;
}
~~~

