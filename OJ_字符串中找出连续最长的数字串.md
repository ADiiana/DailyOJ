# OJ_字符串中找出连续最长的数字串

[牛客网 字符串中找出连续最长的数字串][https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking]

>题目描述：
>
>读入一个字符串str，输出字符串str中的连续最长的数字串
>
>输入描述：
>
>```
>个测试输入包含1个测试用例，一个字符串str，长度不超过255。
>```
>
>输出描述：
>
>```
>在一行内输出str中里连续最长的数字串。
>```
>
>**示例：**
>
>~~~C
>输入
>abcd12345ed125ss123456789
>输出
>123456789
>~~~

<font size = 5 color = red>思路：</font>

1. 效率不怎么高的思路：

   1. 将所有的数字序列从原string中切割出来，存入一个vector<string>中
   2. 找出这个c\<string>中最长的序列即可。

2. 拾人牙慧：

   算法思想：用max表示经过的数字长度最大值，count表示数字计数器，当为字母时重置为0
   *end表示数字尾部，每次满足数字时，对max进行判断，当max小于于count时，更新max和end

3. <font color = blue >经典思路：</font>准备两个string，res、cur。其中res总是保留两者中最长的数字序列，cur再去发现下一个数字序列，判断是否要更新res，直到遍历结束。输出res；

**代码1：**

~~~C
/*对一个字符串进行分割，从数字开始，如果是数字，则存入vector<string>中
直到是非数字则截止，开始下一轮遍历。
最后找出vector中的最长的string,输出。
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    
    string str;
    cin >> str;        //接收str
    
	vector<string> strs;
	string::iterator ite;
	ite = str.begin();
    
	while (ite != str.end()){
        //每满足数字要求进行一个内循环
        //每遇到一个字母，则要进行一个外循环，并且判断得内循环的条件不满足
		string s;
		if (*ite >= '0' && *ite <= '9'){
			while (ite != str.end()){
				if (*ite >= '0' && *ite <= '9'){
					s += *ite;
					ite++;
				}
				else{
                    //遇到非数字段则跳过
					break;
				}
			}
            //将输入序列按一段数字一段数字放入strs中
			strs.push_back(s);
		}
        //跳出循环的情况有两种，
        //1.不满足数字条件，2.已经遍历到str的最后一个位置了
		if (ite == str.end()){
			break;
		}
		else{
            //没有到最后一个位置，继续循环。
			ite++;
		}
	}
    //此时已经得到一个strs，存放若干个数字序列
    //只需要得到这个集合中，最长的序列即可
    size_t key = 0;
    size_t max_len = strs[0].length();
    for(size_t i = 0; i < strs.size(); i++){
        if(max_len < strs[i].length()){
            key = i;
            max_len = strs[i].length();
        }
    }
    cout << strs[key];

	system("pause");
	return 0;
}
~~~

**代码2：**

~~~C

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string str, res, cur;
    cin >> str;
    
    //这里只有一个循环，不管是数字还是其它字符，都要判断一次。
    for(size_t i = 0; i <= str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            cur.push_back(str[i]);
        }
        else{
            if(res.length() < cur.length()){
                //res总是保留两者中最长的数字序列。
                res = cur;
            }
            else{
                cur.clear();
            }
        }
    }
    cout << res;
    
	system("pause");
	return 0;
}
~~~

