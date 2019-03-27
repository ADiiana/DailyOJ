# OJ_查找组成一个偶数最接近的两个素数

[查找组成一个偶数最接近的两个素数 牛客网](https://www.nowcoder.com/questionTerminal/f8538f9ae3f1484fb137789dec6eedb9)

>链接：
>
>https://www.nowcoder.com/questionTerminal/f8538f9ae3f1484fb137789dec6eedb9
>
>来源：牛客网
>
>任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对 
>
>##### **输入描述:**
>
>```C
>输入一个偶数
>```
>
>##### **输出描述:**
>
>```C
>输出两个素数
>```
>
>**示例**
>
>```C
>输入：20
>输出：7
>     13
>```

<font size = 5 color = red>思路：</font>

判断素数不难，遍历一个数的组成数也不难，这道题的主要注意点是用什么思想，找出来最近的两个素数组合。

我采用了最笨的一一记录，判断，再由标兵跟踪输出的方法。

题解给出的思路，是从偶数的一半开始，肯定得到的是最近两个素数。

这里给出求素数的两种方法：

1. 判断一个数是否为素数，即一个数不能被2 ~ m - 1的每一个整数去除

~~~C
#include <stdio.h>

int main(){
    int a=0;  // 素数的个数
    int num=0;  // 输入的整数

    printf("输入一个整数：");
    scanf("%d",&num);

    for(int i=2;i<num;i++){
        if(num%i==0){
            a++;  // 素数个数加1
        }
    }

    if(a==0){
        printf("%d是素数。\n", num);
    }else{
        printf("%d不是素数。\n", num);
    }

    return 0;
}
~~~

2. 简化，不必被2 ~ m-1 的每一个整数去除，只需被 2 ~ 根号m之间的每一个整数去除就可以了。

~~~C
#include <stdio.h>
#include <math.h>
void main(){
    int m;  // 输入的整数 
    int i;  // 循环次数
    int k;  // m 的平方根 

    printf("输入一个整数：");
    scanf("%d",&m);

    // 求平方根，注意sqrt()的参数为 double 类型，这里要强制转换m的类型 
    k=(int)sqrt( (double)m );
    for(i=2;i<=k;i++)
        if(m%i==0)
            break;

    // 如果完成所有循环，那么m为素数
    // 注意最后一次循环，会执行i++，此时 i=k+1，所以有i>k 
    if(i>k)
        printf("%d是素数。\n",m);
    else
        printf("%d不是素数。\n",m);

    return 0;
}
~~~

**我的代码：**

~~~C
/*
	>Plan:查找组成一个偶数最接近的两个素数
	>Author:ADiiana
	>Time:2019-3-26
	>记得保存代码
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool IsPrime(int num){
    int i;
    int k = (int)sqrt((double)num);
    for(i = 2; i <= k; i++){
        if(num % i == 0)
            break;
    }
    if(i > k){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    while(cin >> n){
        int PrimeA = 0;
    int PrimeB = 0;
    vector<int> len;
    vector<int> Prim;
    for(int i = 1; i <= n; i++){
        if(IsPrime(i) && IsPrime(n - i)){
            len.push_back(abs(n - 2 * i));
            Prim.push_back(i);
        }
    }
    int key = 0;
    if(!len.empty()){
        int min = len[0];
        for(size_t i = 0; i < len.size(); i++){
            if(len[i] < min){
                min = len[i];
                key = i;
            }
        }
        cout << Prim[key] << endl;
        cout << n - Prim[key] << endl;
    }    
    }
    
	system("pause");
	return 0;
}

~~~

**题解：**

~~~C
#include<iostream>
#include<algorithm>
using namespace std;
//判断素数
bool isPrime(int num)
{
	int tmp = sqrt(num);
	//只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除
	for (int i = 2; i <= tmp; i++)
	{
		if (num %i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		//从中间向两边找
		for (i = half; i > 0; i--)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}
~~~

