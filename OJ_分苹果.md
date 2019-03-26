# OJ_分苹果

[分苹果 牛客网](https://www.nowcoder.com/questionTerminal/a174820de48147d489f64103af152709)

>n 只奶牛坐在一排，每个奶牛拥有 ai个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。 
>
>##### **输入描述:**
>
>```C
>每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），接下来的一行包含 n 个整数 ai（1 <= ai <= 100）。
>```
>
>##### **输出描述:**
>
>```C
>输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 -1。
>```
>
> **示例**
>
>```C
>输入：4
>	 7 15 9 5
>输出：3
>```

<font size = 5 color = red>思路：</font>

这道题的思路很直观，但对我来说还没有抓住其中的核心点，AC（测试用例）90%。

经过修改之后的代码

~~~C
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    //空间要么直接开辟好，要么一边放一遍push_back
    vector<int> apple(n);
    int sum = 0;
    int times = 0;
    
    for(size_t i = 0; i < n; i++){
        cin >> apple[i];
        sum += apple[i];
    }
    //判断是否可以整除
    if(sum % n != 0){
        cout << -1;
    }
    else{
        int averge = sum / n;
        for(size_t i = 0; i < apple.size(); i++){
            //判断每个多出的苹果数，是否可以一次拿两个
            if(apple[i] > averge){
                int diff = apple[i] - averge;
                if(diff % 2 == 0){
                    times += diff / 2;
                }
                else{
                    cout << -1;
                    return 0;
                }
            }
        }
        cout << times;
    }
    system("pause");
    return 0;
}
~~~

