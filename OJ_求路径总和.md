# OJ_求路径总和

[求路径总和](https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking)

>请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
>
>```C
>示例：
>输入：
>2
>2
>输出：
>6
>```

<font size = 5 color = red>思路：</font>

这道题用递归的思路：

~~~C
    1   2   3
  -------------
1 | 1 | 2 | 3 |
  -------------
2 | 4 | 5 | 6 |
  -------------
3 | 7 | 8 | 9 |
  -------------
~~~

经过思考，发现路径总和并不是2的多少次方。

- 而对于每一次输入的格子规格来说，要达到\[n][m]格有两种途径，一个是\[n - 1][m]向下走，一个是\[n][m - 1]向右走。对于\[n - 1][m]格来说，也有两种途径，分别是\[n - 1][m - 1]和\[n - 2][m]格……，直到n为1，或m为1时，就停止递归。
- 如果格子为 1\*m，或 n*1，画图可知，此时的路线数为 m + n。

代码如下：

~~~C
#include<iostream>
using namespace std;
int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		//b情况，递归
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		// a情况，终止条件
		return n + m;
	else
		//格子为0时， 路径为0
		return 0;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	}
	return 0;
}
~~~