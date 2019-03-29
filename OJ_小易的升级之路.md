# OJ_小易的升级之路

[小易的升级之路](https://www.nowcoder.com/profile/538270428/codeBookDetail?submissionId=44079614)

~~~C
/*
>Plan:小易的升级之路
>Author:ADiiana
>Time:2019-3-29
>记得保存代码
>Idea:写一个子函数：求最大公约数。
*/
 
#include<iostream>
#include<vector>
using namespace std;
 
int ComDiv(int a, int b){
    if (a<b)
    {
        int t = a;
        a = b;
        b = t;
    }
    int c = a%b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}
int main(){
    int n = 0;
    while (cin >> n){
        int init = 0;
        cin >> init;
        int ability = init;
        vector<int> monster(n);
        for (size_t i = 0; i < n; i++){
            cin >> monster[i];
            if (ability >= monster[i]){
                ability += monster[i];
            }
            else{
                ability += ComDiv(ability, monster[i]);
            }
        }
        cout << ability << endl;
    }
    system("pause");
    return 0;
}
~~~

