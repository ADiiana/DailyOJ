# OJ_罗马数字转整数

[罗马数字转整数][https://leetcode-cn.com/problems/roman-to-integer/]

>题目描述：
>
>罗马数字包含以下七种字符: `I`， `V`， `X`， `L`，`C`，`D` 和 `M`。
>
>```
>字符          数值
>I             1
>V             5
>X             10
>L             50
>C             100
>D             500
>M             1000
>```
>
>例如， 罗马数字 2 写做 `II` ，即为两个并列的 1。12 写做 `XII` ，即为 `X` + `II` 。 27 写做  `XXVII`, 即为 `XX` + `V` + `II` 。
>
>通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 `IIII`，而是 `IV`。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 `IX`。这个特殊的规则只适用于以下六种情况：
>
>- `I` 可以放在 `V` (5) 和 `X` (10) 的左边，来表示 4 和 9。
>- `X` 可以放在 `L` (50) 和 `C` (100) 的左边，来表示 40 和 90。 
>- `C` 可以放在 `D` (500) 和 `M` (1000) 的左边，来表示 400 和 900。
>
>给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
>
>~~~C
>示例：
>输入: "III"
>输出: 3
>输入: "IV"
>输出: 4
>输入: "IX"
>输出: 9
>输入: "LVIII"
>输出: 58
>解释: L = 50, V= 5, III = 3.
>输入: "MCMXCIV"
>输出: 1994
>解释: M = 1000, CM = 900, XC = 90, IV = 4.
>~~~

<font size = 5 color = red>思路：</font>

​	用选择switch语句，再用if语句对特殊情况做处理。

​	但该代码的效率不高，map似乎是比较好的解决方案。

代码：

~~~C
class Solution {
public:
	int romanToInt(string s) {
		int flag = 0;
		const char *str = "IVXLCDM";
		const char *temp = str;
		string cur(s);
		int ret = 0;		const char *copy = cur.c_str();

		while (*copy){
			str = temp;
			char ch = *copy;
			while (*str){
				if (ch == *str){
					flag = str - temp;      //确定flag值，进入switch语句。、
					break;
				}
				str++;
			}
			//此时的copy依然是从字符串首开始

			switch (flag){
			case 0:
				if (*(copy + 1) == 'V'){    //判断是否需要处理特殊情况
					ret += 4;
					copy++;
					break;
				}
				if (*(copy + 1) == 'X'){
					ret += 9;
					copy++;
					break;
				}
				ret += 1;
				break;
			case 1:
				ret += 5;
				break;
			case 2:
				if (*(copy + 1) == 'L'){
					ret += 40;
					copy++;
					break;
				}
				if (*(copy + 1) == 'C'){
					ret += 90;
					copy++;
					break;
				}
				ret += 10;
				break;
			case 3:
				ret += 50;
				break;
			case 4:
				if (*(copy + 1) == 'D'){
					ret += 400;
					copy++;
					break;
				}
				if (*(copy + 1) == 'M'){
					ret += 900;
					copy++;
					break;
				}
				ret += 100;
				break;
			case 5:
				ret += 500;
				break;
			case 6:
				ret += 1000;
				break;
            default:
                break;
			}
			copy++;
		}
		return ret;
	}
};

~~~

