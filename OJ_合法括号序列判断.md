# OJ_合法括号序列判断

[合法括号序列判断 牛客网](https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking)

>对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
>
>给定一个字符串**A**和它的长度**n**，请返回一个bool值代表它是否为一个合法的括号串。
>
>测试样例：
>
>```C
>"(()())",6
>返回：true
>```
>
>测试样例：
>
>```C
>"()a()()",7
>返回：false
>```
>
>测试样例：
>
>```C
>"()(()()",7
>返回：false
>```

容器pop元素时，一定要判空。

**代码：**

~~~C
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
 
		string str(A);
		stack<char> sign;
		if (n % 2 == 0){    //首先判断字符串的序列是否成对
			for (int i = 0; i < n; i++){
				char ch = *(str.c_str() + i);
				if (ch != '(' && ch != ')')    //判断非括号字符串
					return false;
				if (ch == '('){
					sign.push(ch);       //右括号则入栈
				}
				if (ch == ')' && sign.empty() != 1){
					sign.pop();    //左括号出栈，但要保证栈不为空
				}
			}
			if (sign.empty() == 1){    //当遍历一遍后，栈为空则说明合法
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
};
~~~

题解中用到了switch语句和短路语句，相对来说代码的效率和可读性好。

~~~C
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> sc;
		for (auto ele : A) {
			switch (ele) {
			case '(':
				sc.push(ele);
				break;
			case ')':
			{
				if (sc.empty() || sc.top() != '(')
					return false;
				else
					sc.pop();
			}
				break;
			default:			//处理默认情况
				return false;
			}
		}
		return true;
	}
};
~~~



