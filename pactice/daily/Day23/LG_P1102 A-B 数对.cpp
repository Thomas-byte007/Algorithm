/**
    url:https://www.luogu.com.cn/problem/P1102
*/

#include <bits/stdc++.h>
using namespace std;
int a[200001];
map<int,int> m;
int main(){
    int n,tar;
    long long ans = 0;
    cin >> n >> tar;
    for(int i=0; i<n; i++){
        cin >> a[i];
        m[a[i]]++;
        a[i]-=tar;
    }
    for(int i=0; i<n; i++){
        ans+=m[a[i]];
    }
    cout << ans << endl;
    return 0;
}