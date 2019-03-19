# OJ_连续最大和

[连续最大和 牛客网](https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking)

>**题目描述：**
>
>一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
>
>**输入描述：**
>
>```C
>输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
>```
>
>**输出描述：**
>
>```C
>所有连续子数组中和最大的值。
>```
>
>**示例1**
>
>```C
>输入：3 -1 2 1
>输出：3
>```

<font color = red size = 5>思路：</font>

求连续子数组的最大和，每一个元素，除了负数会降低总和，零对和没有影响，只要是正数，多小的正数对总和都是有贡献的。

所以需要找出在两个负数之间的正数最大和。

**需要注意的是，以我之前的思想，找一个最大的和，得先把所有的元素都存起来，再排序，找出最大的，但实际上不需要这样，只要准备两个变量，一个存最新的，一个存之前的元素中最长的，两个比较，判断是否要更新数据，即可。**

<font color = red>这道问题用到了dp问题，我在网上查了一下，是动态规划，具体的学习后续再看</font>

之前的代码写得很差，就不往上贴了。

**题解：**

~~~C
// 经典dp问题
// 假设dp[n]表示以n为最后一个元素的子数组和的最大值，
// 因此， dp[n] = max(dp[n-1],0)+num[n];
// 当然实现的时候，没有必要设置一个数组保存所有的情况，因为只是用到了前一个位置的计算结果。
#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		if (sum > result)
			result = sum;
		if (sum < 0)
			sum = 0;
	}
	cout << result << endl;
	return 0;
}
~~~

