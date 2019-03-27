# OJ_字符串反转

[字符串反转 牛客网](https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking)

**题解：**

~~~C
#include<string>
#include<iostream>
using namespace std;
string reverseString(string s) {
	if (s.empty())
		return s;
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end)
	{
		swap(s[start], s[end]);
		++start;
		--end;
	}
	return s;
}
int main()
{
	string s;
	getline(cin, s);
	cout << reverseString(s) << endl;
	return 0;
}
~~~

