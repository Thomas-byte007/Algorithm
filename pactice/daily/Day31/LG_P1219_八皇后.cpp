/**
* url:https://www.luogu.com.cn/problem/P1219#ide
* tags:回溯
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int total = 0;
vector<int> path;

// 标记数组：判断某个位置是否冲突
bool col[20];           // col[j]=true 表示第j列已有棋子
bool diag1[40];         // 主对角线 ↘ (i-j可能为负，所以开2倍空间)
bool diag2[40];         // 副对角线 ↙ (i+j最大为2n)

void printSolution(){
    if(total<=3){
        for (int i = 1; i <= n; ++i) {
            cout << path[i];
            if(i<n) cout << "";
        }
        cout << endl;
    }
}

void dfs(int row){
    if(row>n){
        total++;
        printSolution();
        return;
    }
    //在第row行的每一列放置旗子
    for (int c = 0; c <=n ; ++c) {
        int d1 = row - c +n;
        int d2 = row +c;

        if(col[c] || diag1[d1] || diag2[d2]){
            continue;
        }

        path[row] = c;
        col[c] = diag1[d1] = diag2[d2] = true;

        dfs(row+1);

        col[c] = diag1[d1] = diag2[d2] = false;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    path.resize(n+1);

    dfs(1);//从第一行开始

    cout << total << endl;

    return 0;
}