/**
    url:https://www.luogu.com.cn/problem/P1918#ide
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100001];
map<LL,LL> mp;
int main(){
    int n,Q;
    LL m;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        mp[a[i]] = i;
    }
    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> m;
        if(mp.find(m)!=mp.end()){
            cout << mp[m] << "\n";
        }else{
            cout << "0\n";
        } 
    }

    return 0;
}
