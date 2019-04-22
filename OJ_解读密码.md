# OJ_解读密码

[解读密码 牛客网](https://www.nowcoder.com/cts/16268951/summary?id=5CEBC66D850C37AF#4/{%22uid%22%3A%225CEBC66D850C37AF%22%2C%22type%22%3A%224%22%2C%22index%22%3A0})

~~~C
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    while(getline(cin, str)){
        for(size_t i = 0; i < str.size(); i++){
            if(str[i] <= '9' && str[i] >= '0'){
                cout << str[i];
            }
    }
        cout << endl;
    }
    return 0;
}
~~~

