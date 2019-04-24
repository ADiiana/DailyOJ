# OJ_模拟实现atoi

360的笔试题，超简单的、没考虑完全。。要面壁。。

[模拟实现atoi 牛客网](https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking)

~~~C
class Solution {
public:
    int StrToInt(string str) {
        int num = 0;
        int flag = 1;
        for(size_t i = 0; i < str.size(); i++){
            if(str[i] == '0' && i == 0){
                while(str[i] == '0'){
                    i++;
                }
            }
            if(str[i] == '+' && i == 0){
                flag = 1;
                i++;
            }
            if(str[0] == '-' && i == 0){
                flag = -1;
                i++;
            }
            if(str[i] >= '0' && str[i] <= '9'){
                num = num * 10 + str[i] - '0';
            }
            else{
                num = 0;
                break;
            }
        }
        return num * flag;
    }
};
~~~

