/**
	url:https://www.luogu.com.cn/problem/P1135#ide
	tags:bfs(适用于求解一下边权相同，数量有限的最短路径问题)
*/

#include <bits/stdc++.h>
using namespace std;
struct state{
    int floor;
    int step;
};
int main(){
    int N,A,B;
    cin >> N >> A >> B;
    //输入
    vector<int> k(N+1);
    for(int i=1; i<=N; i++){
        cin >> k[i];
    }
    queue<state> q;
    vector<bool> visit(N+1,false);

    q.push({A,0});
    visit[A] = true;

    while(!q.empty()){
        state cur = q.front();
        q.pop();

        if(cur.floor == B){
            cout << cur.step << endl;
            return 0;
        }
        //判断向上可不可行
        int up = cur.floor+k[cur.floor];
        if(up<=N && !visit[up]){
            q.push({up,cur.step+1});
            visit[up] = true;
        }
        //判断向下可不可行
        int down = cur.floor - k[cur.floor];
        if(down>=1 && !visit[down]){
            q.push({down,cur.step+1});
            visit[down] = true;
        }
    }

    cout << "-1" << endl;
    
    return 0;
}
