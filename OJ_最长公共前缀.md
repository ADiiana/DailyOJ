# OJ_最长公共前缀

[Leetcode 最长公共前缀][https://leetcode-cn.com/problems/longest-common-prefix/solution/]

>编写一个函数来查找字符串数组中的最长公共前缀。
>
>如果不存在公共前缀，返回空字符串 `""`。
>
>**示例 1:**
>
>```
>输入: ["flower","flow","flight"]
>输出: "fl"
>```
>
>**示例 2:**
>
>```
>输入: ["dog","racecar","car"]
>输出: ""
>解释: 输入不存在公共前缀。
>```
>
>**说明:**
>
>所有输入只包含小写字母 `a-z` 。

<font color = red size = 5>思路：</font>

**思路1：**

1. 如果该单词序列有大于等于两个的单词，取单词序列中最短的单词word，遍历word的每个字母，判断每个单词和这个字母是公共前缀，是则将公共字母逐字母+=在common上，否则直接返回。
2. 如果只有一个单词，或者序列为空，则直接返回。
3. 算法复杂度：O(n + n*m)

**拾人牙慧：**

1、所求的最长公共前缀子串一定是每个字符串的前缀子串。所以随便选择一个字符串作为标准，把它的前缀串，与其他所有字符串进行判断，看是否是它们所有人的前缀子串。这里的时间性能是O(m\*n*m)。

2、列出所有的字符串的前缀子串，将它们合并后排序，找出其中个数为n且最长的子串。时间性能为O(n*m+m*n\*log(m*n))

3、纵向扫描：从下标0开始，判断每一个字符串的下标0，判断是否全部相同。直到遇到不全部相同的下标。时间性能为O(n*m)。

4、横向扫描：前两个字符串找公共子串，将其结果和第三个字符串找公共子串……直到最后一个串。时间性能为O(n*m)。

5、借助trie字典树。将这些字符串存储到trie树中。那么trie树的第一个分叉口之前的单分支树的就是所求。

**代码1：**

~~~C
class Solution {
public:
	//用长度最短的单词比较，拿去和剩下的单词一一对比，全部符合，则存入公共字符串空间，依次直到第一个字母结束。
	//否则直接retrun NULL，
	string longestCommonPrefix(vector<string>& strs) {
		string common;
		int flag = 1;
		char c;
		if(strs.size() == 0){
            return "";
        }
        else if(strs.size() == 1){
            return strs[0];
        }
		else{
			//vector中有大于等于2个string类的单词，需要比较长度。
			int length = strs[0].size();
			int key = 0;	
            //找到最短的单词 O(n)
			for (int i = 1; i < strs.size(); i++){
				if (length > strs[i].size())
					key = i;
			}
			const char* word = strs[key].c_str();
            //算法复杂度O(m*n)
			for (int i = 0; i < strs[key].size(); i++){
                //计算总共有多少个单词
				flag = strs.size();
                
                //以最短的单词为基
				for (size_t j = 0; j < strs.size(); j++){
					if (*(word + i) == *(strs[j].c_str() + i)){
						flag--;                     //判断所有的单词是否满足一个共同字母的条件
						c = *(word + i);
					}
                    else
                        break;
				}
                //flag 为 0，表示所有单词都有c这个字母。
				if (flag == 0){
                    
					common += c;    //将公共单词都赋值给common
				}
				else{
					break;
				}
			}
			return common;
		}
        //如果只有一个单词，就直接返回。
		return strs[0];
	}
};
~~~

