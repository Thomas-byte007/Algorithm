/**
	url:https://www.luogu.com.cn/problem/B3612
*/

#include <bits/stdc++.h>
using namespace std;
int sum[100005];
int main(){
    int n,x,num=0,m;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x;
        num+=x;
        sum[i] = num;
    }
    int a,b;
        cin >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        if(a==b){
            cout << sum[a]-sum[a-1] << endl;
            continue;
        }
        cout << sum[b] - sum[a-1] << endl;
    }
    
    return 0;
}
