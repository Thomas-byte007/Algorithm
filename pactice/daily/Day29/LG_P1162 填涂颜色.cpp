#include <bits/stdc++.h>
using namespace std;

int n;
int grid[35][35];
bool visited[35][35];
int dx[4] = {-1,0,1,0};//四个方向
int dy[4] = {0,1,0,-1};

void dfs(int x,int y){
    visited[x][y] = true;//标记
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(grid[nx][ny]==0 && !visited[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    //输入
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }
    //从方阵的4条边界开始搜索，只要边界上是0，就说明它是通向外部的，将其连通的所有0都标记
    for(int i=0; i<n; i++){
        //第一行
        if(grid[0][i]==0 && !visited[0][i]) dfs(0,i);
        //最后一行
        if(grid[n-1][i]==0 && !visited[n-1][i]) dfs(n-1,i);
        //第一列
        if(grid[i][0]==0 && !visited[i][0]) dfs(i,0);
        //最后一列
        if(grid[i][n-1]==0 && !visited[i][n-1]) dfs(i,n-1);
    }
    //填涂颜色
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==0 && !visited[i][j]){
                grid[i][j] = 2;
            }
        }
    }
    //输出结果
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << (j==n-1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
