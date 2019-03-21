# OJ_查找输入整数二进制中1的个数

[查找输入整数二进制中1的个数 牛客网](https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&&tqId=21285&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking)

>请实现如下接口
>
>​     **public**   **static**   **int**  findNumberOf1( **int** num)
>
>​    {
>
>​         /*  请实现  */
>
>​         **return**  0;
>
>​    } 譬如：输入5 ，5的二进制为101，输出2
>
> 
>
>**涉及知识点：**
>
>**输入描述：**
>
>```C
>输入一个整数
>```
>
>**输出描述：**
>
>```C
>计算整数二进制中1的个数
>```
>
>**示例1**
>
>```C
>输入：5
>输出：2
>```

<font size = 5 color = red >思路： </font>

这道题的思路比较简单，但我的做法还是有几处不合理的地方：除2操作尽量用左移。

**代码：**

~~~C
#include<iostream>
using namespace std;
int main(){
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n)
		{
			if ((n & 1) == 1)
				count += 1;
			n >>= 1;
		}
		cout << count << endl;
	}
	return 0;
}
~~~

