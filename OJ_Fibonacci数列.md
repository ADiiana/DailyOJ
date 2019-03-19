# OJ_Fibonacci数列

[Fibonacci 牛客网](https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking)

>**题目描述：**
>
>Fibonacci数列是这样定义的：
>F[0] = 0
>F[1] = 1
>for each i ≥ 2: F[i] = F[i-1] + F[i-2]
>因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
>
>**输入描述：**
>
>```C
>输入为一个正整数N(1 ≤ N ≤ 1,000,000)
>```
>
>**输出描述：**
>
>```C
>输出一个最小的步数变为Fibonacci数"
>```
>
>**示例**
>
>```C
>15
>```

**注意：**

<font color = blue>fabs</font>

~~~C
fouble fabs (double x);

Returns the absolute value of x: |x|.
    头文件：<tgmath.h>------C
    	   <cmath>--------C++	 
~~~

<font color = blue>abs</font>

~~~C
 	 int abs (int n);
     long int abs (long int n);
long long int abs (long long int n);

Absolute value
Returns the absolute value of parameter n ( /n/ ).
    	头文件：<cmath>
~~~

此题的思路不难，但要注意怎么节约空间。

题解中给出的思路是，边计算费波拉契数，边判断是否满足条件，这种思路明显比开辟好所有的斐波拉契数列好得多。

另外学习，死循环的用法。

**代码1：**

~~~C
/*
从从开始遍历Fibonacci数列，观察其距离是否开始缩小，一旦距离开始增大，则输出
波谷的那个数，再计算距离。
*/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		vector<int> Fib;
		int first = 0;
		int second = 1;
		Fib.push_back(first);
		Fib.push_back(second);
        //计算100个斐波拉契数列，因为测试发现，100次后的数的范围大概在1000000左右
        //这里消耗比较多，穷举并不是最好的方案
		for (int i = 2; i < 100; i++){
				Fib.push_back(Fib[i - 1] + Fib[i - 2]);
		}
		int Min = n;    //即n与第一个斐波拉契数的距离
		int Key = 0;
		for (size_t i = 2; i < Fib.size(); i++){
            //计算n与每一个数的距离
			int cur = (int)fabs(((float)n - (float)Fib[i]));
            //选出最小的数
			if (Min > cur){
				Min = n - Fib[i];
			}
			else{
				Key = i;
				break;
			}
		}
        //输出这个距离
		cout << (int)fabs((float)Min);
	}
	system("pause");
	return 0;
}
~~~

**代码2：**

~~~C
/*
思路：先找到距离N最近的两个Fibonacci数
然后在这两个数中找到距离N最近的数
*/
#include <iostream>
using namespace std;
int main(){
	int N, l, r, f0 = 0, f1 = 1, f;
	cin >> N;
	while (1){
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		//找到比N小且距离N最近的数，求出距离
		if (f < N) l = N - f;
		else{
			//找到比N大且距离N最近的数，求出距离
			r = f - N;
			break;
		}
	}
	//取最小距离
	cout << min(l, r) << endl;
	return 0;
}
~~~

