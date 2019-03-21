# OJ_手套

[手套 牛客网](https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking)

>在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
>
>给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。
>
>测试样例：
>
>```C
>4,[0,7,1,6],[1,5,0,6]
>返回：10(解释：可以左手手套取2只，右手手套取8只)
>```

<font size = 5 color = red > 思路：</font>

这道题我想了很久，最后领悟了一点思路，但还是想复杂了，每次的思路似乎总是在“凑测试用例”，思路也只局限于测试用例。

我的思路是，对于left和right两个数组：left:	{0，7， 1， 6}；

​								    right:   {1，5， 0， 6}；

总是确定右边的数组是的和是最小的，累加右边的数组元素，除了最大的一个数，再加一，保证右边数组的每种颜色的手套都至少取到一个，得到right_num;

左边数组只需要加最小元素，再多加一个。

=.=事实证明，这样的思路是行不通，思路本身就是错解。

**<font color = red>正解：</font>**

手套问题的中心思路可以转化为对一个非0递增序列a1, a2……,an，要最终取值覆盖每个种类。

要全部覆盖，每一步都要覆盖最大的，再从最小的一个里取一个即可。

n = sum(a1……an)  -  a1 + 1;

**对于左右手套的颜色各有数量的序列，取左边和右边的最小值即可。**

~~~C


class Gloves {
public:
	//对于非0递增序列a1,a2...an，要想最终取值覆盖每一个种类
	//n = sum(a1...an) - a1 + 1（也就是总数减去最小值之后加一）
	//所以对于左右手手套颜色都有数量的序列，取左边和右边的最小值即可
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;

//遍历每一种颜色的左右手套序列
for (int i = 0; i<n; i++){
	//对于有0存在的颜色手套，累加
	if (left[i] * right[i] == 0)
		sum += left[i] + right[i];
	//对于左右手都有的颜色手套，执行上面的策略
	//找到最小值和总数
	else{
		left_sum += left[i];
		right_sum += right[i];
		left_min = min(left_min, left[i]);
		right_min = min(right_min, right[i]);
	}
}
//结果为有左右都有数量的手套序列的结果+有0存在的手套数+最后再加一肯定就能保证了
return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
}
};
~~~



