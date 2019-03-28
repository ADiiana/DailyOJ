# OJ_汽水瓶

[汽水瓶 牛客网](https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking)

~~~C
#include<iostream>
#include<string>
using namespace std;
int calculateNum(int num)
{
	//总兑换数
	int sum = 0;
	while (num > 1)
	{
		//每三瓶换一瓶
		int result = num / 3;
		//剩余不足三瓶的先保留
		int reminder = num % 3;
		sum = sum + result;
		//下一次可以兑换的空瓶
		num = result + reminder;
		if (num == 2)
		{
			++sum;
			break;
		}
	}
	return sum;
}
int main(){
	int number;
	while (cin >> number)
	{
		cout << calculateNum(number) << endl;
	}
	return 0;
}
~~~

