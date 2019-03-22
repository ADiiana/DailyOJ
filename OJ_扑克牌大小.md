# OJ_扑克牌大小

[扑克牌大小 牛客网](https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking)

>扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:) 
>3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
>输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
>请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR
>
>基本规则：
>（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
>（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
>（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
>（4）输入的两手牌不会出现相等的情况。
>
>答案提示：
>（1）除了炸弹和对王之外，其他必须同类型比较。
>（2）输入已经保证合法性，不用检查输入是否是合法的牌。
>（3）输入的顺子已经经过从小到大排序，因此不用再排序了.
>
>**输入描述：**
>
>```C
>输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。
>```
>
>**输出描述：**
>
>```C
>输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
>```
>
>**示例1：**
>
>```C
>输入：4 4 4 4-joker JOKER
>```
>
>```C
>joker JOKER
>```

<font size = 5 color  = red>思路：</font>

这道题真的把我难住了，写了很多的重复代码，对string的操作还要再进一步认识，不自觉地在自己造轮子，不去解决真正应该解决的部分，而是把精力都放在”造破轮子“上。

一个string类型，如果非必需，可以不用非把元素类型从char转化成int，**数组映射的方法很好很方便**。

遇到这种比较繁琐的题，题不难，要找规律，而不是简单就一句一句话的实现，那样太挫了。

寻找string中某个元素，再别用string的c_str()一个一个去遍历了，自己写的容易出错，就用**find函数**。

先处理特殊情况，再提取一般情况中的共同点：

这道题的特殊情况是：两副牌中有对王或者炸弹、两副牌的类型不同。

**先给出题解：**

~~~C
//“输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，
//不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列“
//按照题意牌面类型的确定和大小的比较直接可以转换为牌个数的比较
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string line;
	while (getline(cin, line)){
		//王炸最大，直接输出
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else{
			int dash = line.find('-');
			//分开两手牌
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			//获取空格的次数，牌数为c + 1
			int c1 = count(car1.begin(), car1.end(), ' ');
			int c2 = count(car2.begin(), car2.end(), ' ');
			//拿到第一张牌
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2){
				//只要牌数相等，则第一张牌大的即为大
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
			{
				//牌数不相同，说明类型不同,只有炸弹可以和其它牌比较
				//其它类型都是错误的
				if (c1 == 3)
					cout << car1 << endl;
				else if (c2 == 3)
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}
~~~

这种解法很巧，把个子、对子、三个、炸弹、顺子的情况都结合起来了，很完美。

而我：-.-先想办法把两个字符串分割，又分空格push进vector中，通过判断vector的大小对比，代码冗余太多太多了。

而我的代码，完全就是无脑式的更像是根据测试用例cout的一种。

**以示警示：将自己未完成的代码贴在下面：**

~~~C
/*
>Plan:扑克牌大小
>Author:ADiiana
>Time:2019/3/21
*将判断每副牌牌是什么类型放在一个函数中，每副牌只有一种类型
*/

#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
//判断是否为顺子（连续五张），不是顺子就是个子
int isFive(vector<string> &str){
    if (str[0].compare(str[1].c_str()) == 0 
        && str[0].compare(str[2].c_str()) == 0
       && str[0].compare(str[3].c_str()) == 0
       && str[0].compare(str[4].c_str()) == 0){
		return 1;
	}
	return 0;
}
//判断是否为对子（两张牌，不是对子，不是对王，就是个子）,返回牌面，否则返回0
int isDouble(vector<string> &str){
    if (str[0].compare(str[1].c_str()) == 0){
		return 1;
	}
	return 0;
}
//判断是否为三个（不是三子，就是个子）返回牌面，否则返回0
int isThree(vector<string> &str){
    if (str[0].compare(str[1].c_str()) == 0 && str[0].compare(str[2].c_str()) == 0){
		return 1;
	}
	return 0;
}
//是否为炸弹
int Bomb(vector<string> &str){
	if (str[0].compare(str[1].c_str()) == 0 
        && str[0].compare(str[2].c_str()) == 0
       && str[0].compare(str[3].c_str()) == 0){
		return 1;
	}
	return 0;
}
//判断是否为对王，返回真或假
int isDoubleKing(vector<string> &str){
	if ((str[0].compare("joker") == 0 && (str[1].compare("JOKER") == 0))){
		return 1;
	}
	return 0;
}

//打印vector也需要一个函数
void Print(vector<string> &str){
	for (auto e : str){
		cout << e << " ";
	}
	cout << endl;
}

//将string变成vector存入。
vector<string> StringToV(string str){
	vector<string> strs;
	//int tmp = 0;
	for (size_t i = 0; i < str.size(); i++){
		if ((*(str.c_str() + i) >= '0' && *(str.c_str() + i) <= '9')
			|| *(str.c_str() + i) == 'A'
			|| *(str.c_str() + i) == 'J'
			|| *(str.c_str() + i) == 'Q'
			|| *(str.c_str() + i) == 'K')
		{
			int cur_num = i;
			int cur_i = i;
			while (*(str.c_str() + i) != ' ' && *(str.c_str() + i)){
				cur_num++;
				i++;
			}
			
			//i = cur_i;
			string cur((str.c_str() + cur_i), cur_num - cur_i);
			strs.push_back(cur);
		}
		if (*(str.c_str() + i) == ' '){
			continue;
		}
		if ((*(str.c_str() + i) == 'j' || *(str.c_str() + i) == 'J')
			&& (*(str.c_str() + i + 1) == 'o' || *(str.c_str() + i + 1) == 'O')){
			strs.push_back("joker");
			strs.push_back("JOKER");
			break;
		}
	}
	return strs;
}
int main(){
	//getline一行，再从-处将字符串裁成左右两个字符串
	string str;
	string left_s;
	string right_s;
	getline(cin, str);
	//str = "10-A";
	//str = "4 4 4 4-joker JOKER";
	for (size_t i = 0; i < str.size(); i++){
		if (*(str.c_str() + i) == '-'){
			left_s = str.substr(0, i);
			right_s = str.substr(i + 1);
			break;
		}
	}
	//将string变成vector存入。
	vector<string> left = StringToV(left_s);
	vector<string> right = StringToV(right_s);

	if (right.size() == 2 && isDoubleKing(right) == 1){
		Print(right);
		return 0;
	}
	if (left.size() == 2 && isDoubleKing(left) == 1){
		Print(left);
		return 0;
	}
	if (right.size() == 4 && left.size() == 4){
		if (Bomb(right) && Bomb(left)){
			if (*right[0].c_str() < *left[0].c_str()){
				Print(left);
				return 0;
			}
			else{
				Print(right);
				return 0;
			}
		}
	}
	if ((right.size() == 4 && Bomb(right) == 1)
		&& (isDoubleKing(left) == 0)){
		Print(right);
		return 0;
	}
	else if ((left.size() == 4 && Bomb(left) == 1)
		&& (isDoubleKing(right) == 0)){
		Print(left);
		return 0;
	}
	if (right.size() == 1 && left.size() == 1){
		cout << max(*right[0].c_str(), *left[0].c_str()) << endl;
		return 0;
	}
    if (right.size() == 2 && isDouble(right) == 1
       && left.size() == 2 && isDouble(left) == 1){
		if(max(*right[0].c_str(), *left[0].c_str()) == *left[0].c_str()){
            Print(left);
        }
        else{
            Print(right);
        }
		return 0;
	}
    if (right.size() == 3 && isThree(right) == 1
       && left.size() == 3 && isThree(left) == 1){
		if(max(*right[0].c_str(), *left[0].c_str()) == *left[0].c_str()){
            Print(left);
        }
        else{
            Print(right);
        }
		return 0;
	}
    if (right.size() == 5 && isFive(right) == 1
       && left.size() == 5 && isFive(left) == 1){
		if(max(*right[0].c_str(), *left[0].c_str()) == *left[0].c_str()){
            Print(left);
        }
        else{
            Print(right);
        }
		return 0;
	}
    
	system("pause");
	return 0;
}
~~~

