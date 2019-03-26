# OJ_回文串

[回文串 牛客网](https://www.nowcoder.com/questionTerminal/655a43d702cd466093022383c24a38bf)

>链接：
>
>https://www.nowcoder.com/questionTerminal/655a43d702cd466093022383c24a38bf
>
>来源：牛客网
>
>给定一个字符串，问是否能通过添加一个字母将其变为回文串。
>
>##### **输入描述:**
>
>```C
>一行一个由小写字母构成的字符串，字符串长度小于等于10。
>```
>
>##### **输出描述:**
>
>```C
>输出答案(YES\NO).
>```
>
>**示例:**
>
>```C
>输入：coco
>输出: YES
>```

<font size = 5 color = red>思路:</font>

**判断回文串的方法还可以更简单一些:**

~~~C
bool isPa(const string& s){
    string r = s;
    reverse(r.begin(), r.end());
    return r == s;
}
~~~



判断回文串的题目变形很多,这道题的主要点是怎么添加字母,添加哪个字母?

<font color = blue >思路1(时间复杂度O(n)): </font>**双指针**,在字符串的前面和后面各一个指针,判断其所指向的字符是否相等,不相等则在指针1或指针2处添加一个对应的字符,再判断是否为回文串,如果有一次是回文串,则输出YES,若双指针相遇还没有找到,则输出NO.

(思路比较麻烦的是,再添加指针1还是在指针2处添加字符是不可知的,需要尝试后再判断)

<font color = blue>思路2:</font>添加和删除的效果相同,可以从头遍历字符串,依次删除一个字符,删除之后判断,如果有一次为回文串,则输出YES,否则输出NO.

<font color = blue>思路3:</font>这个思路并不容易想到,利用回文串的特性.将字符串逆置,再与源字符串匹配,如果两个字符串的公共字符串比源字符串的长度相等或小1,则为回文串.

**代码1**

~~~C
/*
>Plan:回文串
>Author:ADiiana
>Time:2019-3-25
>记得保存代码
*/
#include<iostream>
#include<string>
using namespace std;
 
//判断回文字符串
bool IsCircle(string str){
    int key = 0;
    for (size_t i = 0; i < str.size() / 2; i++){
        if (str[i] == str[str.size() - i - 1]){
            key++;
        }
    }
    if (key == str.size() / 2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string str;
    while (cin >> str){
        //"尾部"插入
        for (size_t i = 0; i < str.size() / 2; i++){
            if (str[i] != str[str.size() - i - 1]){
                str.push_back(str[i]);
                break;
            }
        }
  		//不是回文串,则"头部"插入
        if (IsCircle(str)){
            cout << "YES" << endl;
        }
        else{
            str.pop_back();
            for (size_t i = 0; i < str.size() / 2; i++){
                if (str[i] != str[str.size() - i - 1]){
                    str.insert(str.begin(), str[str.size() - i - 1]);
                    break;
                }
            }
            if (IsCircle(str)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        str.clear();
    }
    system("pause");
    return 0;
}

~~~

**代码2:**

~~~C
/*
>Plan:回文串
>Author:ADiiana
>Time:2019-3-25
>记得保存代码
*/
#include<iostream>
#include<string>
using namespace std;

//判断回文字符串
bool IsCircle(string str){
	int key = 0;
	for (size_t i = 0; i < str.size() / 2; i++){
		if (str[i] == str[str.size() - i - 1]){
			key++;
		}
	}
	if (key == str.size() / 2){
		return true;
	}
	else{
		return false;
	}
}
//只要有一次是回文串就输出YES，所有情况都判断完不是回文串则为NO
int main(){
	string str;
	while (cin >> str){
        string copy(str);
        //删除str中的每个字符后判断是否为回文串
		for(size_t i = 0; i < str.size(); i++){
            str.erase(i, 1);
            if (IsCircle(str)){
				cout << "YES" << endl;
                break;
			}
            str = copy;
        }
        if (!IsCircle(str))
			cout << "NO" << endl;
        str.clear();
    }
	system("pause");
	return 0;
}

~~~

