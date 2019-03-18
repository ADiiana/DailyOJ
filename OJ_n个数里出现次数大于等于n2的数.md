# OJ_n个数里出现次数大于等于n/2的数

[牛客网 n个数里出现次数大于等于n/2的数][https://www.nowcoder.com/practice/eac8c671a0c345b38aa0c07aba40097b?tpId=85&&tqId=29866&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking]

>**题目描述：**
>
>输入n个整数，输出出现次数大于等于数组长度一半的数。
>
>**输入描述：**
>
>```
>每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n/2。
>```
>
>**输出描述：**
>
>```
>输出出现次数大于等于n/2的数。
>```
>
>**示例：**
>
>~~~C
>输入
>3 9 3 2 5 6 7 3 2 3 3 3
>输出
>3
>~~~

<font size = 5 color = red>思路：</font>

**思路一：**

寻找出现次数大于等于n/2的数，这个数一定只有一个或两个。

因为每个数字不超过100，范围限定，所以可以用桶排序，以数字为下标，每个数字出现一次，对应该数字为下表的数字元素的值加一，最后求出哪一个元素的对应下标的值大于等于size()的一半即可。O(n)的算法

**思路二：**

比较难理解。

O(n)思想：因为要找过半的数，用一个变量count记录读取每个变量变化的次数，
一个变量temp记录可能过半的数，先让count=1，然后让temp=vec[0]，
然后往后遍历一遍，碰到和temp相同的数就给count++，否则就count--
如果，count变成0，就让temp=vec[i](vec数组遍历过程当前值),并让count=1
如此遍历一遍，因为有一个数过半，所以temp最后肯定存储的是过半的数

**代码1：**

~~~C
#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v;
    int n;
    while(cin >> n){
        v.push_back(n);
    }
	int array[101] = { 0 };
	for (auto e : v){
		array[e]++;
	}
	for (int i = 1; i < 101; i++){
		if (array[i] > v.size() / 2 - 1){
            cout << i;
            break;
        }	
	}
	system("pause");

	return 0;
}
~~~

or

~~~C
#include<iostream>
using namespace std;
int main(){
	int count[100] = { 0 };//数组置0，然后输入n，则对应位置加1，最后遍历数组
	int x = 0, n = 0; //找到大于等于一半次数的那个
	while (cin >> x){
		count[x]++;
		n++;
	}
	for (int i = 0; i<n; i++){
		if (count[i] >= n / 2)
			cout << i << endl;
	}
	return 0;
}
~~~

**代码二：**

~~~C
#include <vector>
#include <iostream>

using namespace std;
int main()
{
	int n;
	vector <int> vec;
	while (cin >> n)
		vec.push_back(n);
	int count = 1;
	int temp = vec[0];
	for (int i = 1; i < vec.size(); ++i){
		if (vec[i] == temp)
			count++;
		else
			count--;
		if (count == 0)
		{
			temp = vec[i];
			count++;
		}
	}
	cout << temp << endl;
	return 0;
}
~~~





