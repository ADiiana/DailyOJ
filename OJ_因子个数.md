# OJ_因子个数

[因子个数 牛客网](https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d)

~~~C
// write your code here cpp
#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,k,i;
	while(cin >> n){
		k=0;
		for(i = 2; i <= sqrt(n); i++) {
			if ((n % i) == 0) {
				while((n % i) == 0){
					n=n/i;
				}
			k++;
			}
		}
		if(n!=1)
			k++;
		cout<<k<<endl;
	}
	return 0;
}
~~~

