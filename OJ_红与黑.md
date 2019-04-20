# OJ_红与黑

[红与黑 牛客网](https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a)

~~~C
/*dfs问题*/
// write your code here cpp
#include<iostream>
#include<vector>
#include<vector>
#include <queue>
using namespace std;

struct pos{
    int x;
    int y;
};

int dfs(vector<vector<char> > & map, vector<vector<bool> > & visit, pos & start){
    const int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
    queue<pos> que;
    int count = 0;
    int m = map.size(), n = map[0].size();
    que.push(start);
    visit[start.x][start.y] = true; ++count;
    while (!que.empty()){
        pos cur = que.front(), next;
        que.pop();
        for (int i = 0; i < 4; ++i){
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
                !visit[next.x][next.y] && map[next.x][next.y] == '.'){
                que.push(next);
                visit[next.x][next.y] = true;
                ++count;
            }
        }
    }
    return count;
}

int main(){
    int m, n;
    while(cin >> m >> n && (m * n)){
        pos start;
        vector<vector<char> > map(m, vector<char>(n));
        vector<vector<bool> > visit(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                visit[i][j] = false;
                cin >> map[i][j];
                if(map[i][j] == '@'){
                    start.x = i;
                    start.y = j;
                }
            }
        }
        cout << dfs(map, visit, start) << endl;
    }
    return 0;
}

~~~

