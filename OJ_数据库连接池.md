# OJ_数据库连接池

[数据库连接池 牛客网](https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e)

~~~C
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		set<string> pool;
		string id, con;
		int maxSize = 0;
		for (int i = 0; i < n; ++i){
			cin >> id >> con;
			if (con == "connect") 
                pool.insert(id);
			else if (con == "disconnect") 
                pool.erase(id);
			int size = pool.size();
			maxSize = max(maxSize, size);
		}
		cout << maxSize << endl;
	}
	return 0;
}
~~~

