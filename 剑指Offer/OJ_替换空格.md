# OJ_替换空格

[替换空格](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

>请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

<font color = red size = 5>思路:</font>

从前往后，先查找，将有效的字符串放入数组中，再将有效字符串和"%20"拼接，即为有替换后的字符串。

<font color = red size = 5>坑：</font>

1. 在函数内部的字符串拼接无误，也将值赋给参数str，但传出后并没有该改变，原因有以下几点：

   - 刚开始，考虑到内存问题，认为将空格替换成"%20"，其本身占有的内存是变大了，所以要对内存进行扩容：

   1. realloc扩容：**这种做法不能在调试中体现出来**，原因很简单，一次测试用例中给你的str字符串的地址，不是系统通过malloc分配给你的，你并不知道这个地址在栈上还是堆上，如果占用了内核内存，是不可能使用的，**准确的说，这个地址是牛客网的服务器中一个字符串的地址，而不是你自己主机的**，不可能在这个基础上进行realloc操作。
   2. <font color = red>第一点之前的想法，第二点是纠正，事实上，本地测试是能办到的，在分析过程中，确实提交的代码要放在牛客网的服务器上运行，但是关于本机测试描述的并不对</font>。<font color = blue>在本地测试中，因为我传过去的str是常量区的变量，第一就算我强制类型转换改变其非常变量，也不能在函数调用内部真正的给常量赋值。。。就像一个传进一个数字，通过函数将数字的值能变成其他值吗。。。。这点我总是想着还是可以改变的，需要再斟酌吧。。</font>
   3. 题目描述中并没有提到，所以内存的情况不用顾虑，也许在跑测试用例的过程中会检测出来，并自动申请，但这点还是应该说明的。
   4. 使用malloc，这个完全改变了strA的地址，在本地上是可以的，但还是没有想到str的地址其实是一台服务器上的，使用malloc就完全改变的str的值为B，例如：strB上的字符串内容确实是想要的答案，但服务器只需要这个答案存放在strA上。
   5. 这个传进来的值没有被赋值，容易被想成变量作用域的问题，函数内部修改的栈上的内容，只有改变堆上的内容才是输出。**但是没想到在点击运行的过程中，代码并不是在本机上跑的。**

2. 关于STL_string和C语言字符串的接口：find、substr、strtok等等，还有memset、strcpy等，参数和返回值等需要再记忆熟悉。

3. 这道题不难，但是注意的点很多，另外也有一段时间没写代码了。

4. 占用内存有些多，定义了很多变量，这点需要优化。

5. 通过这道题熟悉了mac下vscode和gdb的使用，需要写文档了，不然总是看网上的总结，对自己复习来说效率不高。

**个人题解**：

~~~C++
#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<stdlib.h>

class Solution {
public:
        void replaceSpace(char *str,int length) {
        std::vector<std::string> ret;
        std::string value(str);
        int i;
        int pos = -1;

        for(i = 0; i < value.length(); i = pos + 1){
            if(value.find(" ", pos + 1) != std::string::npos){
                pos = value.find(" ", pos + 1);
                ret.push_back(value.substr(i, pos - i) + "");
        }
        else{
            ret.push_back(value.substr(i));
            break;
            }
        }
        if(pos + 1 == value.length()){
            ret.resize(ret.size() + 1);
        }
        //str = (char*)malloc(ret.size() * 3 + length);
        std::string tmp;
        for(i = 0; i < ret.size(); i++){
            tmp += ret[i];
            if(i + 1 == ret.size()){
                break;    
            }
            tmp += "%20";
        }
        memcpy(str, (char*)tmp.c_str(), (tmp.length() + 1));
    }
};

int main(){
    Solution slove;
    const char* tmp = "hello world";
    slove.replaceSpace((char*)tmp, strlen(tmp));
    std::cout<< tmp << std::endl;

    return 0;
}
~~~

