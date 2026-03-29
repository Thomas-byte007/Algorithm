#include <bits/stdc++.h>
using namespace std;

struct Plane{
    int t,d,l;
};
const int MAX = 15;
int n;
bool found;
Plane plane[MAX];
bool visited[MAX];

void dfs(int count,int tim){//已降落飞机数量，当前跑道空余时间
    if(found) return;
    if(count==n){
        found = true;
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;

        int start = max(plane[i].t,tim);
        if(start<=plane[i].t + plane[i].d){
            visited[i] = true;

            dfs(count+1,start+plane[i].l);

            visited[i] = false;

            if(found) return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> plane[i].t >> plane[i].d >> plane[i].l;
            visited[i] = false;
        }
        found = false;
        dfs(0,0);
        if(found){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
