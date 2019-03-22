# OJ_完美数计算

[完美数计算 牛客网](https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84?tpId=37&&tqId=21279&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking)

>完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
>
>它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
>
>例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
>
>给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
>
>返回n以内完全数的个数。 异常情况返回-1
>
>**示例1：**
>
>```C
>输入：1000
>```
>
>```C
>输出：3
>```

<font color = red size = 5 >思路：</font>

这道题真的很简单，但我写的程序还需要3个优化点：

1. 要判断n的范围；
2. 对于n的范围，可以取n，取n/2，取sqrt(n)，算法效率依次提高，内部sum的加法就要做相应处理。
3. 调用函数次数太多会造成栈溢出，这种循环可以放在函数里。

**代码1：**

~~~C
/*
>Plan:完全数计算
>Author:ADiiana
>Time:2019/3/22
*/

#include<iostream>
using namespace std;

//判断一个数是否为完美数
int isPerfectNom(int num);
int isPerfectNom(int num){
	int count = 0;
	int sum = 0;
    //需要修改的点2.
	for (int i = 1; i < num; i++){
		if (num % i == 0){
			sum += i;
		}
	}
	if (sum == num){
		count++;
	}
	return count;
}
int main(){
	int n;
	while (cin >> n){
        //需要修改的点1->判断n是否满足条件
		int count = 0;
        //判断范围n内的数是否为完美数
        //需要修改的点3.
		for (int i = 1; i < n; i++){
			count += isPerfectNom(i);
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
~~~

**正解：**

~~~C
/*
约数计算可以遍历sqrt(n)的范围
*/
#include<iostream>
#include<algorithm>
using namespace std;
int count(int n) {
	int cnt = 0;
	if ((n < 0) | (n>500000))
		return -1;
	else {
		for (int i = 2; i <= n; i++) {
			int sum = 0;
			//遍历范围
			int sq = sqrt(i);
			for (int j = 2; j <= sq; j++) {
				if (i%j == 0) {
					//如果j^2 = i，说明两个约数相同，只加一个
					if (i / j == j)
						sum += j;
					else
						//否则，两个不同的约数都要相加
						sum += j + (i / j);
				}
			}
			if (sum + 1 == i)
				cnt++;
		}
		return cnt;
	}
}
int main() {
	int input;
	while (cin >> input)
		cout << count(input) << endl;
	system("pause");
	return 0;
}
~~~

